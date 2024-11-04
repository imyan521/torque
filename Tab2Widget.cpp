#include "Tab2Widget.h"
#include <QDebug>
#include <QTabWidget>
Tab2Widget::Tab2Widget(Ui::MainWindow *ui, QWidget *parent) :
    QWidget(parent),
    ui(ui) // 使用传入的 UI
{
    ui->tabWidget_2->setTabToolTip(0,"压力实时分布");
    ui->tabWidget_2->setTabToolTip(1,"标定曲线图");
    // 连接启动按钮的点击信号到 Start_Button_clicked 槽函数
    connect(ui->startbutton,
            &QPushButton::clicked, this, &Tab2Widget::Start_Button_clicked);

    // 连接停止按钮的点击信号到 Stop_Button_clicked 槽函数
    connect(ui->StopButton, &QPushButton::clicked, this, &Tab2Widget::Stop_Button_clicked);

    //连接选择设备的点击信号到 Connect_device槽函数
    connect(ui->connectdevice,&QPushButton::clicked,this, &Tab2Widget::Connect_device);
    // 连接配置按钮的点击信号，使用 lambda 表达式处理
    connect(ui->configbotton, &QPushButton::clicked, [this]() {
        ConfigDialog dialog(this); // 创建配置对话框
        // 连接对话框的配置确认信号到 handleConfigConfirmed 槽函数
        connect(&dialog,
                &ConfigDialog::configConfirmed, this, &Tab2Widget::handleConfigConfirmed);
        dialog.exec(); // 以模态方式显示对话框
    });

    // 创建 CartesianWidget 实例并设置其几何属性
    // cartesianWidget = new CartesianWidget(this);
    // cartesianWidget->setGeometry(650, -200, 1000, 1000); // 设置位置和大小
    // cartesianWidget->show(); // 显示 CartesianWidget

    // 创建 MyServer 实例，将 UI 控件传递给它
    server = new MyServer(ui->TcpEdit, ui->ReminderEdit, this);

    // 连接服务器信号与相应槽
    connect(server, &MyServer::bool_data_reciv, this, &Tab2Widget::ui_process);
    connect(server, &MyServer::clientListUpdated, this, &Tab2Widget::updateClientComboBox);
    connect(ui->Clientcombox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Tab2Widget::onComboBoxIndexChanged);

}

Tab2Widget::~Tab2Widget() {} // 析构函数，默认实现

// 处理选择大小改变的信号
void Tab2Widget::onChooseSizeChanged(int _index) {
    // 打印当前索引，便于调试
    qDebug() << "Current index:" << _index;
    // 其他逻辑...
}

// 启动按钮点击处理函数
void Tab2Widget::Start_Button_clicked() {
    server->sendMessageToClient("166"); // 发送信号给客户端
    qDebug() << "166" << endl;
}

// 更新客户端组合框
void Tab2Widget::updateClientComboBox(const QStringList &clientList) {
    ui->Clientcombox->clear(); // 清空组合框
    if (clientList.isEmpty()) {
        ui->Clientcombox->addItem("无客户端连接"); // 添加提示信息
        ui->Clientcombox->setEnabled(false);
    } else {
        ui->Clientcombox->addItems(clientList); // 添加客户端列表
        ui->Clientcombox->setEnabled(true);
    }
}

// 处理组合框索引变化
void Tab2Widget::onComboBoxIndexChanged(int index) {
    if (ui->Clientcombox->currentText() == "无客户端连接") {
        server->currentclientindex = -1; // 设置当前客户端索引为无效
    } else {
        server->currentclientindex = index; // 更新当前客户端索引
    }
    qDebug() << "更新客户端" << endl;
}

// 停止按钮点击处理函数
void Tab2Widget::Stop_Button_clicked() {
    server->sendMessageToClient("Stop"); // 发送停止信号
    qDebug() << "Stop" << endl;
}

// 配置确认处理函数
void Tab2Widget::handleConfigConfirmed(const QString &vertical,
                                       const QString &horizontal, const QString &maxPressure, const QString &minPressure) {
    // 在此实现配置确认后的处理逻辑

    // 将vertical和horizontal格式化为两位数字
    QString formattedVertical = QString("%1").arg(vertical.toInt(), 2, 10, QChar('0'));
    QString formattedHorizontal = QString("%1").arg(horizontal.toInt(), 2, 10, QChar('0'));

    QString message = QString("1%1%2")
                          .arg(formattedVertical)
                          .arg(formattedHorizontal);

    //打印需要发送的字符串
    qDebug()<<message<<Qt::endl;
    pressure_send_setting_message(message);
    //server->sendMessageToClient(message);

    // 如果需要，将字符串转换为数字，并调用 GenerateGrid
    bool verticalOk, horizontalOk;
    int verticalInt = vertical.toInt(&verticalOk);
    int horizontalInt = horizontal.toInt(&horizontalOk);
    //generateGrid(verticalInt, horizontalInt);
    //qDebug() << "发送配置信息成功";
}

// 处理接收的数据
void Tab2Widget::ui_process() {
    // qDebug() << "接受到信号" << endl;
    // qDebug() << "x:" << this->server->_data->x;
    // qDebug() << "y:" << this->server->_data->y;
    // setButtonColor(this->server->_data->x, this->server->_data->y, Qt::black); // 设置按钮颜色
    // cartesianWidget->pointList.push_back(QPoint(server->_data->x, this->server->_data->stdsensor)); // 更新点列表
    // cartesianWidget->stdpointList.push_back(QPoint(server->_data->x, this->server->_data->sensor));
    // cartesianWidget->update(); // 更新绘图
    // sensorvalue.push_back(this->server->_data->sensor); // 更新传感器值
    // stdsensorvalue.push_back(this->server->_data->stdsensor);
    // ui->ValueEdit->setText(QString("y: %1\ny1: %2").arg(this->server->_data->sensor).arg(this->server->_data->stdsensor)); // 显示当前值
    // ui->ErrorEdit->setText(QString("%1").arg(this->server->_data->sensor - this->server->_data->stdsensor)); // 显示误差
}


//显示设备连接界面
void Tab2Widget::Connect_device(){
    emit toggle_device_connect_Window();
}

void Tab2Widget::updateMatrixTable(const std::vector<std::vector<uint16_t>> &matrix){
    // 确保表格大小是 16x16
    if (ui->tableWidget->rowCount() != 16 || ui->tableWidget->columnCount() != 16) {
        qWarning() << "表格大小不符合 16x16 的要求";
        return;
    }

    // 设置 QTableWidget 中的单元格内容
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrix[i][j]));
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void Tab2Widget::get_pressure_message(QString message){
    ui->pressure_edit->setText(message);
}

void Tab2Widget::get_torque_message(QString message){
    ui->torque_edit->setText(message);
}

void Tab2Widget::generateGrid(int rows, int columns){

}
