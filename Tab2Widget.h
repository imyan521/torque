#ifndef TAB2WIDGET_H
#define TAB2WIDGET_H

#include <QWidget>
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QPainter>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <vector>
#include <QtGlobal>
#include <QThread>
#include"cartesianwidget.h"
#include"serialporthelper.h"
#include "tcpsocket.h"
#include "configdialog.h"

class Tab2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2Widget(Ui::MainWindow *ui, QWidget *parent = nullptr);
    ~Tab2Widget();
    void generateGrid(int rows, int columns);
    void get_torque_message(QString message);
private:
    Ui::MainWindow *ui;
    CartesianWidget *cartesianWidget;
    MyServer*server;
    std::vector<std::vector<QPushButton*>> gridButtons;
signals:
    void toggle_device_connect_Window();  // 用于通知显示设备管理界面
    void pressure_send_setting_message(const QString &message);          // 发送配置信息
private slots:
    void onChooseSizeChanged(int index);
    void Start_Button_clicked();
    void Stop_Button_clicked();
    void handleConfigConfirmed(const QString &vertical,
    const QString &horizontal, const QString &maxPressure, const QString &minPressure);

    //更新连接到的客户端
    void updateClientComboBox(const QStringList &clientList);
    void Connect_device();
    //选择当前通信的客户端
    void onComboBoxIndexChanged(int index);
    void ui_process();
public slots:
    //更新传感器表格
    void updateMatrixTable(const std::vector<std::vector<uint16_t>> &matrix);
    void get_pressure_message(QString message);
};

#endif // TAB2WIDGET_H
