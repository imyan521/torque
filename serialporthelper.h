#ifndef SERIALPORTHELPER_H
#define SERIALPORTHELPER_H

#include<QObject>
#include<QSerialPort>
#include<QTimer>
#include <QElapsedTimer>


class SerialPortHelper:public QObject
{
    Q_OBJECT
public:
    explicit SerialPortHelper(QObject*parent=nullptr);
    ~SerialPortHelper();
    bool openSerialPort(const QString &portName, int baudRate);

    void closeSerialPort();

    void sendData(const QByteArray &data);

    bool waitForResponse();

    void processData(const QByteArray &data);

    bool Isworking=false;
signals:

    void dataRecieved(const QByteArray &data);

    void newDataParsed(char num,char sensor,char stdsensor);
private slots:

    void readData();

private:
    QSerialPort *serialPort;
    QTimer *timer;
};

#endif // SERIALPORTHELPER_H
