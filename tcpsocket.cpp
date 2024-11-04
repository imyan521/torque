#include "tcpsocket.h"
// MyServer 构造函数
MyServer::MyServer(QLineEdit* textEdit, QLineEdit* ReminderEdit, QObject *parent) : QObject(parent) {
    server = new QTcpServer(this); // 创建新的 TCP 服务器
    this->textEdit = textEdit; // 存储用于显示消息的文本编辑框引用
    this->ReminderEdit = ReminderEdit; // 存储用于状态更新的文本编辑框引用
    this->_data = new Data; // 初始化数据对象，用于存储接收到的数据
    ReminderEdit->setText("等待数据"); // 设置初始状态文本为“等待数据”
    // 连接 newConnection 信号到 onNewConnection 槽
    connect(server, &QTcpServer::newConnection, this, &MyServer::onNewConnection);
    // 开始监听端口 1234
    server->listen(QHostAddress::Any, 1234);
}

// 新客户端连接的处理函数
void MyServer::onNewConnection() {
    QTcpSocket *clientSocket = server->nextPendingConnection(); // 获取下一个待处理的连接
    clients.append(clientSocket); // 将新客户端添加到客户端列表中

    // 构建并显示客户端连接信息
    QString clientInfo = QString("下位机连接成功，地址：%1，端口：%2")
                             .arg(clientSocket->peerAddress().toString()).arg(clientSocket->peerPort());
    textEdit->setText(clientInfo);

    // 连接信号到相应的槽函数
    connect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::readClientData);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::onClientDisconnected); // 连接断开信号

    updateClientList(); // 更新客户端列表
}

// 客户端断开连接的处理函数
void MyServer::onClientDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender()); // 获取断开连接的客户端套接字
    if (clientSocket) {
        clients.removeAll(clientSocket); // 从列表中移除已断开的客户端
        textEdit->setText("连接已断开"); // 更新显示文本
        clientSocket->deleteLater(); // 清理已断开的 QTcpSocket 对象

        updateClientList(); // 更新客户端列表
    }
}

// 读取客户端数据的处理函数
void MyServer::readClientData() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender()); // 获取发送数据的客户端套接字
    if (clientSocket) {
        QByteArray clientData = clientSocket->readAll(); // 读取客户端发送的所有数据
        QString message = QString::fromUtf8(clientData); // 将字节数组转换为 QString
        qDebug() << message; // 打印接收到的消息

        int res = processdata(&message, this->_data); // 处理接收到的数据
        if (res == 1) {
            // 向客户端发送有效数据的响应消息
            QString response = "有效数据!";
            clientSocket->write(response.toUtf8()); // 发送响应
            clientSocket->flush(); // 立即发送数据
            this->ReminderEdit->setText("有效数据"); // 更新状态文本
            emit bool_data_reciv(); // 发送数据接收信号
        } else {
            this->ReminderEdit->setText("无效数据"); // 更新状态文本为“无效数据”
        }
        textEdit->setText(QString("下位机发送：%1").arg(message)); // 显示发送的消息
    }
}

// 处理数据的函数
int MyServer::processdata(QString* str, Data* data) {
    bool numMatched = false; // 标记是否成功解析数值
    bool dataMatched = false; // 标记是否成功解析数据

    // 解析 #NUM
    QRegularExpression numRegex("#NUM(\\d+) (\\d+)");
    QRegularExpressionMatch numMatch = numRegex.match(*str);
    if (numMatch.hasMatch()) {
        QString xStr = numMatch.captured(1);
        QString yStr = numMatch.captured(2);

        bool xOk, yOk;
        int x = xStr.toInt(&xOk); // 将字符串转换为整数
        int y = yStr.toInt(&yOk);

        if (xOk && yOk) {
            data->x = x; // 存储 x 值
            data->y = y; // 存储 y 值
            qDebug() << "data->x:" << x << endl;
            qDebug() << "data->y:" << y << endl;
            numMatched = true; // 标记为成功匹配
        } else {
            qWarning() << "Invalid x or y value in #NUM"; // 警告无效的数值
            return -1; // 返回失败标志
        }
    }

    // 解析 #DATA
    QRegularExpression dataRegex("#DATA(\\d+) (\\d+)");
    QRegularExpressionMatch dataMatch = dataRegex.match(*str);
    if (dataMatch.hasMatch()) {
        QString stdSensorStr = dataMatch.captured(1);
        QString sensorStr = dataMatch.captured(2);

        bool stdSensorOk, sensorOk;
        int stdSensor = stdSensorStr.toInt(&stdSensorOk);
        int sensor = sensorStr.toInt(&sensorOk);

        if (stdSensorOk && sensorOk) {
            data->stdsensor = stdSensor; // 存储标准传感器值
            data->sensor = sensor; // 存储传感器值
            qDebug() << "data_stdsensor" << stdSensor << endl;
            qDebug() << "data_sensor" << sensor << endl;
            dataMatched = true; // 标记为成功匹配
        } else {
            qWarning() << "Invalid stdsensor or sensor value in #DATA"; // 警告无效的传感器值
            return -1; // 返回失败标志
        }
    }

    // 检查是否满足所有要求
    if (numMatched && dataMatched) {
        return 1; // 返回成功标志
    } else {
        qWarning() << "String does not satisfy all requirements"; // 警告不满足要求
        return -1; // 返回失败标志
    }
}

// 更新客户端列表的函数
void MyServer::updateClientList() {
    QStringList clientList;
    for (int i = 0; i < clients.size(); ++i) {
        clientList.append(QString("Client %1").arg(i)); // 添加客户端索引到列表
    }
    emit clientListUpdated(clientList); // 发射客户端列表更新信号
}

// 向指定客户端发送消息的函数
void MyServer::sendMessageToClient(const QString &message) {
    if (currentclientindex >= 0 && currentclientindex < clients.size()) {
        QTcpSocket *clientSocket = clients[currentclientindex]; // 获取当前客户端套接字
        if (clientSocket && clientSocket->isOpen()) { // 检查套接字是否有效
            clientSocket->write(message.toUtf8()); // 发送消息
            clientSocket->flush(); // 立即发送数据
        }
    }
    // 处理当前客户端索引无效的情况（可根据需求添加逻辑）
}
