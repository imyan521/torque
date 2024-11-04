#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "connect_device_window.h"
#include "TorqueWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //用于管理连接设备的界面
    connect_device_window *Connect_Window;

    TorqueWidget * torque_widget;

    // bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
     //控制设备连接界面的显示与关闭
     void onToggleSecondaryWindow();


     void onButton1Clicked();

     // void onConnectWindowClickedOutside();
};
#endif // MAINWINDOW_H
