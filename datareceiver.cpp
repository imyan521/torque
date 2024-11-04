#include "datareceiver.h"
#include <iostream>
#include <iomanip>
DataReceiver::DataReceiver(QObject *parent) : QObject(parent){

}

/*void DataReceiver::received_raw_data(const QByteArray &data){

}*/

SerialReceiver::SerialReceiver(QObject *parent): DataReceiver(parent){
    //创建串口对象
    serialPort = new QSerialPort(this);
    //创建定时器
    timer = new QTimer(this);
}


void SerialReceiver::startreceiving(){

}

//数据量太庞大了，不适合在中断中直接处理，会出现错误
void SerialReceiver::readData() {
    // 将新读取到的数据追加到缓冲区
    QByteArray newData = serialPort->readAll();
}


//接收到连接请求时，尝试打开对应串口
void SerialReceiver::openSerialPort(const QString &portName) {
    if (serialPort->isOpen()) {
        serialPort->close();  // 如果已经打开，则关闭串口
    }

    // 设置串口号
    serialPort->setPortName(portName);
    // 设置其他串口参数
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // 尝试打开串口
    if (serialPort->open(QIODevice::ReadWrite)) {
        //发送连接成功信号
        qDebug() << "Serial port opened successfully:" << portName;

        connect(timer, &QTimer::timeout, this, &SerialReceiver::handletimeout);
        timer->start(100);  // 每隔 100 毫秒检查一次串口数据
        //如果有可读内容 触发readData 数据量太过于庞大且传输过于频繁 改用定时处理数据
        //connect(serialPort,
        //&QSerialPort::readyRead, this, &SerialReceiver::readData);
        emit serial_state(1);
    } else {
        //发送连接失败信号
        qDebug() << "Failed to open serial port:" << portName;
        emit serial_state(2);
    }
}

//关闭串口
void SerialReceiver::closeSerialPort(){
    serialPort->close();
    emit serial_state(3);
}

void SerialReceiver::processdata(const QByteArray &data){
    // 确保数据大小是 512 个字节
    if (data.size() != 512) {
        std::cerr << "数据大小错误，应为 512 字节，当前为 " << data.size() << " 字节。" << std::endl;
        return;
    }

    // Step 1: 将 512 字节数据转换为 16x32 的矩阵
    std::vector<std::vector<uint8_t>> matrix_16x32(16, std::vector<uint8_t>(32));
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 32; ++j) {
            matrix_16x32[i][j] = static_cast<uint8_t>(data[i * 32 + j]);
        }
    }

    // 打印 16x32 的字节矩阵，以 16 进制形式
    qDebug()<<"16x32 字节矩阵：" << Qt::endl;
    for (const auto &row : matrix_16x32) {
        for (auto byte : row) {
            std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Step 2: 将 16x32 矩阵转换为 16x16 矩阵，每两个字节组合成一个 16 位整数 最终的计算结果
    std::vector<std::vector<uint16_t>> matrix_16x16(16, std::vector<uint16_t>(16));
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            // 将每行的 32 个字节，按两个字节合并成 16 位整数
            uint16_t high_byte = static_cast<uint16_t>(matrix_16x32[i][j * 2]) << 8;     // 高字节
            uint16_t low_byte = static_cast<uint16_t>(matrix_16x32[i][j * 2 + 1]);       // 低字节
            matrix_16x16[i][j] = high_byte + low_byte;
        }
    }
    emit matrixReady(matrix_16x16);
    // 打印 16x16 的矩阵，以 10 进制形式
    qDebug() << "16x16 矩阵（每两个字节的和）：" << Qt::endl;
    for (const auto &row : matrix_16x16) {
        for (auto value : row) {
            std::cout << std::setw(4) << std::setfill('0') << std::dec << value << " ";
        }
        std::cout << std::endl;
    }
}
void SerialReceiver:: handletimeout() {
    // 从串口读取所有可用的数据
    if (serialPort->bytesAvailable() > 0) {
        QByteArray newData = serialPort->readAll();
        buffer.append(newData);
        qDebug() << "Received data:" << newData.toHex(' ').toUpper();
    }

    // 在缓冲区中查找帧头 0xAC，并确保有足够的数据
    int pos = buffer.indexOf('\xAC');
    while (pos != -1 && buffer.size() - pos >= 513) {
        // 提取帧头后的 512 个字节
        QByteArray frameData = buffer.mid(pos + 1, 512);
        qDebug()<<"一帧数据"<<Qt::endl;
        qDebug()<<"一帧数据长度"<<frameData.length()<<Qt::endl;        qDebug()<<frameData<<Qt::endl;

        processdata(frameData);
        // 从缓冲区中移除已处理的数据
        buffer = buffer.mid(pos + 513);

        // 继续查找下一个可能的帧头
        pos = buffer.indexOf('\xAC');
    }
}


//网络相关
NetWork::NetWork(QObject *parent) : QObject(parent) {
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &NetWork::newConnection);
    if (!server->listen(QHostAddress::Any, 1234)) {
        qCritical() << "Unable to start the server";
    } else {
        qDebug() << "Server started...";
    }
}

void NetWork::newConnection() {
    while (server->hasPendingConnections()) {
        QTcpSocket *socket = server->nextPendingConnection();
        Device *device = new Device(socket);
        devices.append(device);
        connect(socket, &QTcpSocket::readyRead, this, &NetWork::readData);
        qDebug() << "New device connected, type is unknown.";
    }
}

// 读取数据，并根据连接类型不同，进行对应处理
void NetWork::readData() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket)
        return;

    Device *device = nullptr;
    for (Device *dev : qAsConst(devices)) {
        if (dev->getSocket() == socket) {
            device = dev;
            break;
        }
    }

    if (!device)
        return;

    QByteArray data = socket->readAll();
    QString message = QString::fromUtf8(data);

    if (device->getType() == unknown) {
        // 设备类型未知时，进行类型识别
        if (message == "pressure") {
            device->setType(pressure);
            emit pressure_connect();
            qDebug() << "Device type set to pressure";
        } else if (message == "torque\r\n") {
            device->setType(torque);
            emit torque_connect();
            qDebug() << "Device type set to torque";
        } else {
            qDebug() << "Received data from unknown device:" << message;
        }
    } else {
        // 设备类型已知，根据不同的类型进行相应的处理
        switch (device->getType()) {
        case pressure:
            emit get_pressure_message(message);
            break;
        case torque:
            emit get_torque_message(message);
            break;
        default:
            qWarning() << "Unknown device type, unable to handle.";
            break;
        }
    }
}

void NetWork::sendToAllPressureDevices(const QString &message){
    QByteArray data = message.toUtf8();

    for (Device *device : qAsConst(devices)) {
        if (device->getType() == pressure) {
            QTcpSocket *socket = device->getSocket();
            if (socket && socket->state() == QAbstractSocket::ConnectedState) {
                socket->write(data);
                socket->flush();  // 确保立即发送
                qDebug() << "Message sent to Pressure device:" << message;
            } else {
                qDebug() << "Pressure device socket is not connected.";
            }
        }
    }
}
