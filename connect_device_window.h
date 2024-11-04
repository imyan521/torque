#ifndef CONNECT_DEVICE_WINDOW_H
#define CONNECT_DEVICE_WINDOW_H

#include <QWidget>
#include <QSerialPortInfo>
#include "datareceiver.h"
#include <QString>
namespace Ui {
class connect_device_window;

}

class connect_device_window : public QWidget
{
    Q_OBJECT

public:
    explicit connect_device_window(QWidget *parent = nullptr);
    ~connect_device_window();

    //显示当前可用的串口号
    void refreshAvailablePorts();

private slots:
        //点击传感器连接按钮时，触发连接请求信号
        void on_senserconnect_button_clicked();

        //请求断开串口连接
        void on_senserclose_button_clicked();

        //串口打开状态 1：成功 2：失败 3：断开
        void serial_open_state(int state);

        //刷新当前串口
        void on_sensor_refresh_clicked();

        //有传感器连接时
        void on_preesure_connect();

        void on_torque_connect();

signals:
        //将用户选择的串口号信息发送给serial_receiver
        void current_serialport_info(QString serailport_info);
        //关闭串口
        void close_serialport();

       // void clickedOutside();
private:
        Ui::connect_device_window *ui;
        //处理与传感器连接相关事件
        void sensor_related();
        //处理与网络连接相关事件
        void network_related();


        // void mousePressEvent(QMouseEvent *event) override; // 事件处理

public:
        //用于处理串口连接
        SerialReceiver* serial_receiver;

        //用于处理网络连接
        NetWork* net_work;
};

#endif // CONNECT_DEVICE_WINDOW_H
