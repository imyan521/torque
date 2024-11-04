#include "Tab1Widget.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QDebug>
#include <cmath>
#include <QDateTime>


float Tab1Widget::TORQUE_ZERO = 0.019f;
float Tab1Widget::ANGLE_ZERO = 205.291f;

Tab1Widget::Tab1Widget(Ui::MainWindow *ui, QWidget *parent) :
    QWidget(parent),
    ui(ui),
    tcpSocket(new QTcpSocket(this)),
    timeElapsed(0.0) ,// 初始化经过时间
    lastReceivedTorque(0.0f), // 初始化为0
    lastReceivedAngle(0.0f),  // 初始化为0
    isReceivingData(true),// 初始化为接收数据状态
    isPlottingEnabled(true),
    maxTorque(0.0),
    minTorque(0.0),
    maxAngle(0.0),
    minAngle(0.0)
{

    plotTorque = ui->plotTorque;
    plotAngle =  ui->plotAngle;

// timer.stop();
    // 设置绘图
    setupPlots();

    // 设置定时器
    QTimer *timer = new QTimer(this);

    // connect(timer, &QTimer::timeout, this, &Tab1Widget::updateSampleData);
    connect(timer, &QTimer::timeout, this, &Tab1Widget::updateTime);

    timer->start(100); // 每100毫秒更新一次数据

    // 设置标签的默认文本
    ui->labelAngle->setText("当前倾斜角: 0°");
    ui->labelTorque->setText("当前扭力: 0 Nmm");

    ui->fileFormatComboBox->addItem("TXT");
    ui->fileFormatComboBox->addItem("CSV");

    // 连接按钮点击信号到槽函数
    connect(ui->startButton, &QPushButton::clicked, this, &Tab1Widget::onStartButtonClicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &Tab1Widget::onPauseButtonClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &Tab1Widget::onResetButtonClicked);

    //连接选择设备的点击信号到 Connect_device槽函数
    connect(ui->connect_device,&QPushButton::clicked,this, &Tab1Widget::Connect_device);

    // 连接保存按钮的点击信号到槽函数
    connect(ui->saveButton, &QPushButton::clicked, this, [this, ui]() {
        QString format = ui->fileFormatComboBox->currentText();
        QString fileName = QFileDialog::getSaveFileName(this, "保存文件", "",
                                                        format == "TXT" ? "文本文件 (*.txt)" : "CSV文件 (*.csv)");
        if (!fileName.isEmpty()) {
            saveData(fileName, format);
        }
    });

    // 初始化服务器
    //server = new MyServer(ui->Tcp_Edit, ui->Reminder_Edit, this);

    // 连接信号，当接收到数据时处理UI更新
    //connect(server, &MyServer::bool_data_reciv, this, &Tab1Widget::DataReceived);

    plotTorque->setInteraction(QCP::iRangeDrag, true); // 允许拖动平移
    plotTorque->setInteraction(QCP::iRangeZoom, true); // 允许缩放
    plotAngle->setInteraction(QCP::iRangeDrag, true); // 允许拖动平移
    plotAngle->setInteraction(QCP::iRangeZoom, true); // 允许缩放


    connect(ui->saveTorqueZeroButton, &QPushButton::clicked, this, &Tab1Widget::onSaveTorqueZeroButtonClicked);
   connect(ui->saveAngleZeroButton, &QPushButton::clicked, this, &Tab1Widget::onSaveAngleZeroButtonClicked);

}

Tab1Widget::~Tab1Widget() {
    delete tcpSocket;
}

void Tab1Widget::onSaveTorqueZeroButtonClicked() {
    // 将lastReceivedTorque保存为TORQUE_ZERO
    TORQUE_ZERO = lastReceivedTorque + TORQUE_ZERO;

    // 更新UI显示或执行其他操作
    qDebug() << "已保存的扭力零点:" << TORQUE_ZERO;
    // ui->labelTorqueZero->setText(QString("扭力零点: %1 Nm").arg(TORQUE_ZERO)); // 更新显示
    // 保留两位小数更新显示

}

void Tab1Widget::onSaveAngleZeroButtonClicked() {
    // 将lastReceivedAngle保存为ANGLE_ZERO
    ANGLE_ZERO = lastReceivedAngle + ANGLE_ZERO;

    // 更新UI显示或执行其他操作
    qDebug() << "已保存的倾斜角零点:" << ANGLE_ZERO;
}

// 更新时间的槽函数
void Tab1Widget::updateTime() {
    // 每100毫秒增加0.1秒，表示时间经过100毫秒
    timeElapsed += 0.1;
    timeData.append(timeElapsed); // 将更新后的时间添加到时间数据列表中

    // 更新UI标签显示当前扭力和倾斜角
    QString torqueString = QString::number(torqueData.size() > 0 ? torqueData.last() : 0, 'f', 2);
    QString angleString = QString::number(angleData.size() > 0 ? angleData.last() : 0, 'f', 2);

    ui->labelTorque->setText("当前扭力: " + torqueString); // 更新扭力标签
    ui->labelAngle->setText("当前倾斜角: " + angleString); // 更新倾斜角标签


    ui->labelMaxTorque->setText("最大扭力: " + QString::number(maxTorque, 'f', 2));
    ui->labelMinTorque->setText("最小扭力: " + QString::number(minTorque, 'f', 2));
    ui->labelMaxAngle->setText("最大倾斜角: " + QString::number(maxAngle, 'f', 2));
    ui->labelMinAngle->setText("最小倾斜角: " + QString::number(minAngle, 'f', 2));

    // 调用更新绘图函数，刷新图表
    updatePlots(dataReceived); // 更新扭力和角度的绘图
}

void Tab1Widget::DataReceived(QString str) {

    if (!isReceivingData) {
        return; // 如果不允许接收数据，直接返回
    }

    qDebug() << "接收到原始数据: " << str;

    // 将 QString 按空格分割，处理每个字节
    QStringList byteStrings = str.split(" ");
    if (byteStrings.size() % 10 != 0) {
        qWarning() << "数据格式错误: " << str;
        return;
    }
    bool dataReceived = false; // 标记是否接收到新数据
    for (int i = 0; i < byteStrings.size(); i += 10) {
        if (i + 9 >= byteStrings.size()) break;

        // 解析角度数据
        uint8_t angleDataArray[5];
        for (int j = 0; j < 5; ++j) {
            angleDataArray[j] = static_cast<uint8_t>(byteStrings[i + j].toInt(nullptr, 16));
        }

        // 计算角度值
        uint16_t angleValue = (angleDataArray[3] << 8) | angleDataArray[4]; // 合并最后两个字节
        float angle = static_cast<float>(angleValue) * 360.0f / 32768.0f; // 0x8000对应360°

        // if (angle < 0) {
        //     angle += 360; // 确保角度在0°到360°之间
        // }


        // 保留两位小数
        // angle = static_cast<int>(angle * 100 + 0.5) / 100.0;

        // 解析扭力数据
        uint8_t torqueDataArray[5];
        for (int j = 0; j < 5; ++j) {
            torqueDataArray[j] = static_cast<uint8_t>(byteStrings[i + 5 + j].toInt(nullptr, 16));
        }

        // 计算扭力值
        uint16_t torqueValue = (torqueDataArray[3] << 8) | torqueDataArray[4]; // 合并最后两个字节
        float torque = 0.0f;

        // 检查最高位（符号位）以确定扭力值是否为负
        if (torqueValue & 0x8000) { // 如果最高位为1，表示为负数
            torqueValue = ~torqueValue + 1; // 计算补码的负数值
            torque = -static_cast<float>(torqueValue); // 将扭力值转为负
        }
        else {
            torque = static_cast<float>(torqueValue); // 正数情况
        }


        // 保留两位小数
        // torque = static_cast<int>(torque * 100 + 0.5) / 100.0;

        // 将扭力值减去零点
        torque -= TORQUE_ZERO;
        angle -= ANGLE_ZERO; // 将205°作为零度

        // 保存当前数据的时间戳
        timestampData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));

        // 保存数据
        angleData.append(angle);
        torqueData.append(torque);


        // 更新最后接收到的数据
        lastReceivedAngle = angle;
        lastReceivedTorque = torque;

        dataReceived = true; // 标记为接收到新数据
    }


    // 更新最大值和最小值
    for (int i = 0; i < torqueData.size(); ++i) {
        float torque = torqueData[i];
        if (torque > maxTorque) {
            maxTorque = torque;
        }
        if (torque < minTorque) {
            minTorque = torque;
        }
    }

    for (int i = 0; i < angleData.size(); ++i) {
        float angle = angleData[i];
        if (angle > maxAngle) {
            maxAngle = angle;
        }
        if (angle < minAngle) {
            minAngle = angle;
        }
    }

    // 更新显示
    QString torqueString = QString::number(torqueData.size() > 0 ? torqueData.last() : 0, 'f', 2);
    QString angleString = QString::number(angleData.size() > 0 ? angleData.last() : 0, 'f', 2);

    ui->labelTorque->setText("当前扭力: " + torqueString);
    ui->labelAngle->setText("当前倾斜角: " + angleString);


    // 调用更新绘图函数
    updatePlots(dataReceived);
}

void Tab1Widget::updatePlots(bool newDataReceived) {

    // 获取当前时间
    double currentTime = timeElapsed;

    // 更新扭矩图
    if (newDataReceived) {
        // 如果接收到新数据，则添加到数据列表中
        plotTorque->graph(0)->addData(currentTime, lastReceivedTorque);
    } else {
        // 如果没有新数据，使用最后接收到的扭矩值进行更新
        plotTorque->graph(0)->addData(currentTime, lastReceivedTorque);
    }


    // 更新扭力图的X轴范围和Y轴范围
    plotTorque->xAxis->setRange(currentTime > 30 ? currentTime - 30 : 0, currentTime);
    plotTorque->yAxis->setRange(*std::min_element(torqueData.begin(), torqueData.end()) - 1,
                                *std::max_element(torqueData.begin(), torqueData.end()) + 1);
    plotTorque->replot();

    // 设置Y轴标签格式，保留两位小数
    plotTorque->yAxis->setNumberFormat("f");
    plotTorque->yAxis->setNumberPrecision(2);


    plotTorque->replot();

    // 更新角度图
    if (newDataReceived) {
        // 如果接收到新数据，则添加到数据列表中
        plotAngle->graph(0)->addData(currentTime, lastReceivedAngle);
    } else {
        // 如果没有新数据，使用最后接收到的角度值进行更新
        plotAngle->graph(0)->addData(currentTime, lastReceivedAngle);
    }

    // 更新角度图的X轴范围和Y轴范围
    plotAngle->xAxis->setRange(currentTime > 30 ? currentTime - 30 : 0, currentTime);
    plotAngle->yAxis->setRange(*std::min_element(angleData.begin(), angleData.end()) - 1,
                               *std::max_element(angleData.begin(), angleData.end()) + 1);


    // 设置Y轴标签格式，保留两位小数
    plotAngle->yAxis->setNumberFormat("f");
    plotAngle->yAxis->setNumberPrecision(2);


    plotAngle->replot();
}



void Tab1Widget::setupPlots() {
    // 设置扭力绘图
    plotTorque->addGraph();
    plotTorque->graph(0)->setPen(QPen(Qt::blue));
    plotTorque->xAxis->setLabel("时间 (秒)");
    plotTorque->yAxis->setLabel("扭力 (Nmm)");

    // 设置角度绘图
    plotAngle->addGraph();
    plotAngle->graph(0)->setPen(QPen(Qt::red));
    plotAngle->xAxis->setLabel("时间 (秒)");
    plotAngle->yAxis->setLabel("倾斜角 (°)");
}

void Tab1Widget::updateSampleData() {
    timeElapsed += 1.0; // 时间增加1秒
    double torqueValue = qSin(timeElapsed * 0.5) * 10; // 示例扭力数据
    double angleValue = qCos(timeElapsed * 0.5) * 30;   // 示例角度数据

    // 更新数据
    timeData.append(timeElapsed);
    torqueData.append(torqueValue);
    angleData.append(angleValue);

    // 更新标签
    ui->labelTorque->setText("当前扭力: " + QString::number(torqueValue));
    ui->labelAngle->setText("当前倾斜角: " + QString::number(angleValue));

    // 更新绘图
    updatePlots(dataReceived);
}

// 保存数据的函数
void Tab1Widget::saveData(const QString &fileName, const QString &format) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "文件错误", "无法打开文件进行写入");
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");  // 确保使用UTF-8编码

    if (format == "TXT") {
        for (int i = 0; i < torqueData.size(); ++i) {
            out << "Timestamp: " << timestampData[i] << " - Torque: "
                << QString::number(torqueData[i], 'f', 2)  // 保留两位小数
                << ", Angle: " << QString::number(angleData[i], 'f', 2) << "\n"; // 保留两位小数
        }
    } else if (format == "CSV") {
        out << "Timestamp,Torque,Angle\n";  // 写入CSV表头
        for (int i = 0; i < torqueData.size(); ++i) {
            out << timestampData[i] << ","
                << QString::number(torqueData[i], 'f', 2) << ","  // 保留两位小数
                << QString::number(angleData[i], 'f', 2) << "\n"; // 保留两位小数
        }
    }

    file.close();
    QMessageBox::information(this,"保存成功", "数据已成功保存");
}




// 点击开始按钮后
void Tab1Widget::onStartButtonClicked() {
    isReceivingData = true;
    isPlottingEnabled = true;  // 启用绘图


    timeData.clear();
    torqueData.clear();
    timestampData.clear();
    timestampData.append(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    angleData.clear();
    angleData.append(0);
    torqueData.append(0);
    lastReceivedAngle = 0.0;
    lastReceivedTorque = 0.0;
    maxTorque = 0.0;
    minTorque = 0.0;
    maxAngle = 0.0;
    minAngle = 0.0;

    qDebug() << "数据接收已开始";
    isPaused = true;
    // 更新UI状态
    ui->startButton->setEnabled(false);  // 禁用开始按钮
    ui->pauseButton->setEnabled(true);    // 启用暂停按钮
    ui->pauseButton->setText("暂停");    // 设置按钮为“暂停”
}

// 点击暂停按钮后
void Tab1Widget::onPauseButtonClicked() {
    //  isReceivingData = false;
    //  isPlottingEnabled = false; // 暂停绘图
    //  // timer.stop();              // 停止定时器
    //  qDebug() << "数据接收已暂停";
    // // 更新UI状态
    //  ui->startButton->setEnabled(true);   // 启用开始按钮
    //  ui->pauseButton->setEnabled(true);   // 禁用暂停按钮
    if (isPaused) {
        // 当前是启动状态，点击后变为暂停状态
        isReceivingData = false;
        isPlottingEnabled = false;  // 暂停绘图
        timer.stop();             // 暂停定时器
        qDebug() << "数据接收已暂停";

        // 更新UI状态
        ui->startButton->setEnabled(true);  // 开始按钮
        ui->pauseButton->setText("启动");    // 设置按钮为“启动”
    } else {
        // 当前是暂停状态，点击后变为启动状态
        isReceivingData = true;
        isPlottingEnabled = true; // 启动绘图
        timer.start();              // 开始定时器
        qDebug() << "数据接收已启动";

        // 更新UI状态
        ui->startButton->setEnabled(true);   // 启用开始按钮
        ui->pauseButton->setText("暂停");    // 设置按钮为“暂停”
    }

    // 切换状态
    isPaused = !isPaused;
}

// 归零按钮的槽函数
void Tab1Widget::onResetButtonClicked() {
    // 停止并重置计时器
    isReceivingData = false;
    isPlottingEnabled = false;
    timer.stop();
    timeElapsed = 0.0;

    // 清空数据
    timeData.clear();
    torqueData.clear();
    angleData.clear();

    qDebug() << "timeData:" << timeData;
    qDebug() << "torqueData:" << torqueData;
    qDebug() << "angleData:" << angleData;

    angleData.append(0);
    torqueData.append(0);

    qDebug() << "torqueData:" << torqueData;
    qDebug() << "angleData:" << angleData;

    // 重置图表数据
    plotTorque->graph(0)->setData(QVector<double>(), QVector<double>());
    plotAngle->graph(0)->setData(QVector<double>(), QVector<double>());

    // 重置最后接收到的角度和扭力值
    lastReceivedAngle = 0.0;
    lastReceivedTorque = 0.0;

    qDebug() << "lastReceivedAngle:" << lastReceivedAngle;
    qDebug() << "lastReceivedTorque:" << lastReceivedTorque;

    // 重置最大最小值
    maxTorque = 0.0;
    minTorque = 0.0;
    maxAngle = 0.0;
    minAngle = 0.0;

    // 重新设置Y轴范围为合理的初始值
    plotTorque->yAxis->setRange(minTorque, maxTorque); // 使用初始最大最小值
    plotAngle->yAxis->setRange(minAngle, maxAngle); // 使用初始最大最小值

    // 重新绘制图表以反映初始状态
    plotTorque->replot();
    plotAngle->replot();

    setupPlots();

    // 更新UI显示，显示初始状态
    ui->labelTorque->setText("当前扭力: 0 Nmm");
    ui->labelAngle->setText("当前倾斜角: 0°");
    ui->labelMaxTorque->setText("最大扭力: 0 Nmm");
    ui->labelMinTorque->setText("最小扭力: 0 Nmm");
    ui->labelMaxAngle->setText("最大倾斜角: 0°");
    ui->labelMinAngle->setText("最小倾斜角: 0°");

    // 使按钮可用，允许重新开始测量
    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);

    // 输出调试信息
    qDebug() << "数据和计时器已归零";
}



//显示设备连接界面
void Tab1Widget::Connect_device(){
    emit device_connect_Window();
}
