#include "connect_device_window.h"
#include <QDebug>
#include <QScreen>
#include "ui_connect_device_window.h"


connect_device_window::connect_device_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::connect_device_window)
{
    ui->setupUi(this);

    // 设置窗口的外观和行为
    this->setWindowTitle("Connect Device");
    this->resize(600, 300);
    this->setAttribute(Qt::WA_StyledBackground, true);
    // this->setStyleSheet("background-color: #f0f0f0; border: 1px solid #cccccc; border-radius: 10px;"); // 设置背景颜色和圆角
    this->setStyleSheet("background-color:#f0f0f0");  // 设置背景颜色为白色
    qDebug()<<"hello"<<Qt::endl;

    //将窗口移动到屏幕中央
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    serial_receiver=new SerialReceiver(this);
    net_work=new NetWork(this);
    refreshAvailablePorts();
    int x = (screenGeometry.width() - this->width()) / 5;
    int y = (screenGeometry.height() - this->height()) / 5;
    this->move(x, y);

    //处理串口连接事件
    sensor_related();

    //处理网络连接事件
    network_related();
}

// void connect_device_window::mousePressEvent(QMouseEvent *event) {
//     QWidget::mousePressEvent(event);  // 调用基类的事件处理
// }

void connect_device_window::network_related(){
    connect(net_work,&NetWork::pressure_connect,this,&connect_device_window::on_preesure_connect);
    connect(net_work,&NetWork::torque_connect,this,&connect_device_window::on_torque_connect);
}


void connect_device_window::sensor_related(){
    //连接传感器连接按钮到对应的槽函数
    connect(ui->sensor_connect,&QPushButton::clicked,this, &connect_device_window::on_senserconnect_button_clicked);

    //发送当前串口号给SerialReveiver类并要求进行连接
    connect(this, &connect_device_window::current_serialport_info,
            serial_receiver, &SerialReceiver::openSerialPort);

    //断开串口连接
    connect(ui->sensor_close,&QPushButton::clicked,this,&connect_device_window::on_senserclose_button_clicked);
    connect(this,&connect_device_window::close_serialport,serial_receiver,&SerialReceiver::closeSerialPort);

    //接收当前串口连接状态
    connect(serial_receiver,&SerialReceiver::serial_state,this,&connect_device_window::serial_open_state);

    //刷新可用串口号
    connect(ui->serial_refresh,&QPushButton::clicked,this,&connect_device_window::on_sensor_refresh_clicked);
}
connect_device_window::~connect_device_window()
{
    delete ui;
}

void connect_device_window::refreshAvailablePorts(){
    ui->serial_comboBox->clear();  // 清空之前的串口列表

    // 获取所有可用的串口
    const QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : availablePorts) {
        ui->serial_comboBox->addItem(portInfo.portName());
    }
}

//点击串口连接按钮触发
void connect_device_window::on_senserconnect_button_clicked(){
    qDebug()<<ui->serial_comboBox->currentText();
    //发送当前串口号
    emit current_serialport_info(ui->serial_comboBox->currentText());
}

//指示串口连接状态
void connect_device_window::serial_open_state(int state){
    qDebug()<<state<<Qt::endl;
    if(state==1) ui->sensorEdit->setText("设备连接成功");

    else if(state==2) ui->sensorEdit->setText("设备连接失败");


    else if(state==3) ui->sensorEdit->setText("设备已断开");
}

//关闭串口连接
void connect_device_window::on_senserclose_button_clicked(){
    qDebug()<<"关闭串口"<<Qt::endl;
    emit close_serialport();
}

void connect_device_window::on_sensor_refresh_clicked(){
    ui->serial_comboBox->clear();  // 清空之前的串口列表

    // 获取所有可用的串口
    const QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : availablePorts) {
        ui->serial_comboBox->addItem(portInfo.portName());
    }
}

void connect_device_window::on_preesure_connect(){
    ui->pressureEdit->setText("设备已连接");
}

void connect_device_window::on_torque_connect(){
    ui->torqueEdit->setText("设备已连接");
}

