#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tab2Widget.h"
#include "Tab1Widget.h"
#include "TorqueWidget.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("歌尔上位机");

    // 创建连接设备窗口实例
    Connect_Window = new connect_device_window(this);
    Connect_Window->hide(); // 确保初始状态是隐藏的

    // 创建 Tab2Widget 和 Tab1Widget 实例
    Tab2Widget *tab2Widget = new Tab2Widget(ui, ui->tab_2);
    Tab1Widget *tab1Widget = new Tab1Widget(ui, ui->torque);

    // // 安装事件过滤器
    // this->installEventFilter(this);

    // // 连接信号
    // connect(Connect_Window, &connect_device_window::clickedOutside, this, &MainWindow::onConnectWindowClickedOutside);

     connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onButton1Clicked);


    // 连接信号和槽
    connect(tab2Widget, &Tab2Widget::toggle_device_connect_Window, this, &MainWindow::onToggleSecondaryWindow);
    connect(tab1Widget, &Tab1Widget::device_connect_Window, this, &MainWindow::onToggleSecondaryWindow);

    connect(Connect_Window->serial_receiver,&SerialReceiver::matrixReady,tab2Widget,&Tab2Widget::updateMatrixTable);
    connect(Connect_Window->net_work,&NetWork::get_pressure_message,tab2Widget,&Tab2Widget::get_pressure_message);
    //connect(Connect_Window->net_work,&NetWork::get_torque_message,tab2Widget,&Tab2Widget::get_torque_message);
    connect(Connect_Window->net_work,&NetWork::get_torque_message,tab1Widget,&Tab1Widget::DataReceived);
    connect(tab2Widget,&Tab2Widget::pressure_send_setting_message,Connect_Window->net_work,&NetWork::sendToAllPressureDevices);

}

// 槽函数：控制设备连接界面的显示和隐藏
void MainWindow::onToggleSecondaryWindow() {
    if (Connect_Window->isVisible()) {
        Connect_Window->close();
    } else {
        Connect_Window->show();
    }
}


void MainWindow::onButton1Clicked()
{
    TorqueWidget *configWindow = new TorqueWidget;
    configWindow->show();

    // tab1Widget->show();  // 或使用tabWindow1->exec()以模态方式打开
}

// bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
//     if (event->type() == QEvent::MouseButtonPress) {
//         // 检查点击是否在 Connect_Window 外部
//         if (Connect_Window->isVisible() && !Connect_Window->geometry().contains(static_cast<QMouseEvent *>(event)->globalPos())) {
//             Connect_Window->close();  // 点击外部时关闭窗口
//             return true;  // 事件被处理
//         }
//     }
//     return QMainWindow::eventFilter(obj, event);  // 继续处理其他事件
// }

// void MainWindow::onConnectWindowClickedOutside() {
//     if (Connect_Window->isVisible()) {
//         Connect_Window->close();  // 点击外部时关闭窗口
//     }
// }

MainWindow::~MainWindow()
{
    delete ui;
}
