#include "serialporthelper.h"

SerialPortHelper::SerialPortHelper(QObject *parent) : QObject(parent)
{
    serialPort = new QSerialPort(this); // 创建串口对象
    // 当串口接收到数据时，触发 readyRead 信号，调用 readData
    connect(serialPort, &QSerialPort::readyRead, this, &SerialPortHelper::readData);

    timer = new QTimer(this); // 创建定时器
    connect(timer, &QTimer::timeout, this, &SerialPortHelper::readData); // 定时器超时时调用 readData
}

SerialPortHelper::~SerialPortHelper()
{
    delete serialPort; // 删除串口对象
    delete timer; // 删除定时器
}

bool SerialPortHelper::openSerialPort(const QString &portName, int baudRate)
{
    serialPort->setPortName(portName); // 设置串口名
    serialPort->setBaudRate(baudRate); // 设置波特率
    serialPort->setDataBits(QSerialPort::Data8); // 设置数据位
    serialPort->setStopBits(QSerialPort::OneStop); // 设置停止位
    serialPort->setParity(QSerialPort::NoParity); // 设置校验位

    // 尝试打开串口，成功返回 true，否则返回 false
    return serialPort->open(QIODevice::ReadWrite);
}

void SerialPortHelper::closeSerialPort()
{
    // 如果串口已打开，则关闭
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}

void SerialPortHelper::sendData(const QByteArray &data)
{
    serialPort->write(data); // 向串口发送数据
}

void SerialPortHelper::readData()
{
    // 如果串口正在工作，读取串口数据并处理
    if (Isworking) {
        QByteArray receivedData = serialPort->readAll(); // 读取所有可用数据
        processData(receivedData); // 处理接收到的数据
    }
}

bool SerialPortHelper::waitForResponse()
{
    QByteArray responseData; // 响应数据缓存
    QElapsedTimer timer; // 定时器
    timer.start(); // 开始计时

    // 等待响应，最多 10 秒
    while (timer.elapsed() < 10000) {
        // 等待数据到达
        if (serialPort->waitForReadyRead(100)) {
            responseData += serialPort->readAll(); // 读取全部可用数据
            // 检查是否包含 "OK"
            if (responseData.contains("OK")) {
                sendData("recv"); // 发送确认接收
                Isworking = false; // 标记工作状态
                return true; // 返回成功
            }
        }
        Isworking = true; // 更新工作状态
    }
    sendData("Wait For Response failed"); // 发送失败信息
    return false; // 返回失败
}

void SerialPortHelper::processData(const QByteArray &data)
{
    static QByteArray buffer; // 用于缓存未完整的数据包
    buffer += data; // 将接收到的数据添加到缓存中

    // 循环处理缓存中的数据
    while (buffer.size() >= 4) {
        // 判断数据包的开始字节是否为 0x13
        if (buffer.at(0) == '\x13') {
            // 发射信号通知外部，传递编号和传感器数值
            emit newDataParsed(buffer[1], buffer[2], buffer[3]);
        }
        // 从缓冲区中移除已处理的数据
        buffer = buffer.mid(4);
    }
}
