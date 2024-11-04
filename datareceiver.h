#ifndef DATARECEIVER_H
#define DATARECEIVER_H
#include <QObject>
#include <QSerialPort>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTimer>
#include <vector>

//区分用网络连接的不同设备名称
enum DeviceType{
    unknown,
    pressure,
    torque,
};


//用于接收不同设备（压力标定，扭矩仪）不同接口（串口，网络）发送的原始数据
class DataReceiver : public QObject {
    Q_OBJECT
public:
    explicit DataReceiver(QObject *parent = nullptr);

signals:
    // 信号用于发送接收到的原始数据
    //void received_raw_data(const QByteArray &data);

public slots:
    // 虚函数，用于不同方式接收数据
    virtual void startreceiving() = 0;
};

// 串口接收数据（分布式压力传感器的数据通过串口接收）
class SerialReceiver : public DataReceiver {
    Q_OBJECT
public:
    explicit SerialReceiver(QObject *parent = nullptr);
    //实例化串口对象
    void startreceiving() override ;
private slots:
    //将数据发送给数据解析模块
    void readData();
    void handletimeout();//处理定时器时刻到来
//指示串口连接成功或失败
signals:
    int serial_state(int state);

    //将接收到的传感器参数发送出去
    void matrixReady(const std::vector<std::vector<uint16_t>> &matrix);
public slots:
    // 槽函数，用于接收串口号并尝试打开串口
    void openSerialPort(const QString &portName);
    // 槽函数，用于接收用户断开串口请求
    void closeSerialPort();
    void processdata(const QByteArray &data);
private:
    QSerialPort *serialPort;
    QByteArray  buffer;
    //数据量过大，改用定时器判断的形式来处理数据
    QTimer *timer;
};

// Device类 Device类包含了一个Device所具备的socket信息和type信息

class Device {
public:
    Device(QTcpSocket *socket) : socket(socket), type(unknown) {}

    QTcpSocket* getSocket() const { return socket; }
    DeviceType getType() const { return type; }
    void setType(DeviceType newType) { type = newType; }

private:
    QTcpSocket *socket;
    DeviceType type;
};

//NetWork类
class NetWork : public QObject {
    Q_OBJECT

public:
    NetWork(QObject *parent = nullptr);

public slots:
    void newConnection();
    void readData();
    //向所有类型为pressure的设备发送消息
    void sendToAllPressureDevices(const QString &message);
signals:
    //Pressure设备连接
    void pressure_connect();
    //torque设备连接
    void torque_connect();
    //接收到Pressure设备消息
    void get_pressure_message(QString message);

    //接收到torque设备消息
    void get_torque_message(QString message);
private:
    QTcpServer *server;
    QList<Device*> devices;
};

#endif
