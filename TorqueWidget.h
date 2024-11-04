#ifndef TORQUEWIDGET_H
#define TORQUEWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include "qcustomplot.h"
#include <QTimer>
#include "tcpsocket.h"

namespace Ui {
class TorqueWidget;
}

class TorqueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TorqueWidget(QWidget *parent = nullptr);
    ~TorqueWidget();

    void DataReceived(QString str);
    static float TORQUE_ZERO; // 声明静态变量
    static float ANGLE_ZERO; // 声明静态变量

private slots:
    // void onConnectButtonClicked(); // 点击连接按钮的槽函数
    void updateSampleData();
    void onStartButtonClicked();  // 开始按钮槽函数
    void onPauseButtonClicked();  // 暂停按钮槽函数
    void onResetButtonClicked();  // 归零按钮槽函数
    void updatePlots(bool newDataReceived);           // 更新图表
    void Connect_device();

    void onSaveTorqueZeroButtonClicked();
    void onSaveAngleZeroButtonClicked();


signals:
    void device_connect_Window();  // 用于通知显示设备管理界面


private:
    Ui::TorqueWidget *ui;
    QTcpSocket *tcpSocket;
    QCustomPlot *plotTorque;
    QCustomPlot *plotAngle;
    double timeElapsed;          // 记录使用时间
    float lastReceivedTorque;    // 上一次接收到的扭矩
    float lastReceivedAngle;     // 上一次接收到的角度
    bool isReceivingData;        // 数据接收状态
    MyServer*server;
    void setupPlots();            // 初始化图表
    void loadSampleData();         // 加载预设数据
    void updateTime();
    QTimer timer;                 // 定时器，用于动态更新图表
    QTimer *updateTimer; // 定时器

    QVector<double> timeData;     // 时间数据
    QVector<double> torqueData;   // 扭力数据
    QVector<double> angleData;    // 角度数据
    bool isPlottingEnabled;       // 控制是否允许绘图
    bool dataReceived;
    bool isPaused=true;           //初始状态为启动
    QString torqueStr;            // 当前扭力数据
    QString angleStr;             // 当前角度数据

    QVector<double> sampleTorqueData; // 预设的扭力数据
    QVector<double> sampleAngleData;  // 预设的角度数据

    // 保存数据到文件的函数
    void saveData(const QString &fileName, const QString &format);

    float maxTorque;  // 存储最大扭力值
    float minTorque;  // 存储最小扭力值
    float maxAngle;   // 存储最大角度值
    float minAngle;   // 存储最小角度值

    QVector<QString> timestampData;
};

#endif // TORQUEWIDGET_H
