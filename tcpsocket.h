#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QLineEdit>
#include <QObject>
#include <QByteArray>
#include <QList>
#include <QMap>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
struct Data{
  int x;
  int y;
  int stdsensor;
  int sensor;
};

class MyServer:public QObject{
    Q_OBJECT
public:
    MyServer(QLineEdit*textEdit,QLineEdit*ReminderEdit,QObject *parent=nullptr);

private slots:
    void onNewConnection();
    void readClientData();
    void onClientDisconnected(); // 新增的槽函数

private:
    QTcpServer *server;
    QLineEdit  *textEdit;
    QLineEdit  *ReminderEdit;
    QList<QTcpSocket*> clients;

public:
    QList<struct Data*>sensor_data;
    struct Data* _data;
    QMap<QTcpSocket*, QString> clientMessages; // 存储每个客户端的消息
    //bool parseMessage(const QString &message,struct );
    int  processdata(QString *message,struct Data* data);
    //当前通信的客户端
    int  currentclientindex=-1;
    void sendMessageToClient(const QString &message);

private:
    void updateClientList();
signals:
    void bool_data_reciv();
    void clientListUpdated(const QStringList &clientList);

};

#endif // TCPSOCKET_H
