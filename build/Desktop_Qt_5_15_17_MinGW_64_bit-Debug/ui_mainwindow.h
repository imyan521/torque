/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button1;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QHBoxLayout *horizontalLayout_5;
    QWidget *torque;
    QHBoxLayout *horizontalLayout_8;
    QWidget *leftLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QCustomPlot *plotTorque;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelTorque;
    QLabel *labelMaxTorque;
    QLabel *labelMinTorque;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QCustomPlot *plotAngle;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelAngle;
    QLabel *labelMaxAngle;
    QLabel *labelMinAngle;
    QWidget *rigthLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *fileFormatComboBox;
    QPushButton *saveButton;
    QVBoxLayout *verticalLayout;
    QPushButton *connect_device;
    QPushButton *saveTorqueZeroButton;
    QPushButton *saveAngleZeroButton;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QWidget *tab_2;
    QPushButton *StopButton;
    QLineEdit *ReminderEdit;
    QTextEdit *ValueEdit;
    QLineEdit *ErrorLabel;
    QLineEdit *CurrnetValuelabel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QLineEdit *ErrorLabel_2;
    QPushButton *configbotton;
    QTextEdit *MeanErrorEdit;
    QLineEdit *TestEdit;
    QComboBox *Clientcombox;
    QPushButton *ClearButton;
    QTextEdit *ErrorEdit;
    QLineEdit *TcpEdit;
    QPushButton *startbutton;
    QPushButton *connectdevice;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QTableWidget *tableWidget;
    QPushButton *table_button;
    QWidget *tab_3;
    QTextEdit *pressure_edit;
    QTextEdit *torque_edit;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1105, 799);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button1 = new QPushButton(centralwidget);
        button1->setObjectName(QString::fromUtf8("button1"));

        horizontalLayout->addWidget(button1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        horizontalLayout_5 = new QHBoxLayout(tab_1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        torque = new QWidget(tab_1);
        torque->setObjectName(QString::fromUtf8("torque"));
        horizontalLayout_8 = new QHBoxLayout(torque);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        leftLayout = new QWidget(torque);
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        leftLayout->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftLayout->sizePolicy().hasHeightForWidth());
        leftLayout->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(leftLayout);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(leftLayout);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        plotTorque = new QCustomPlot(widget_4);
        plotTorque->setObjectName(QString::fromUtf8("plotTorque"));
        plotTorque->setMinimumSize(QSize(400, 100));

        horizontalLayout_6->addWidget(plotTorque);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelTorque = new QLabel(widget_4);
        labelTorque->setObjectName(QString::fromUtf8("labelTorque"));

        verticalLayout_4->addWidget(labelTorque);

        labelMaxTorque = new QLabel(widget_4);
        labelMaxTorque->setObjectName(QString::fromUtf8("labelMaxTorque"));

        verticalLayout_4->addWidget(labelMaxTorque);

        labelMinTorque = new QLabel(widget_4);
        labelMinTorque->setObjectName(QString::fromUtf8("labelMinTorque"));

        verticalLayout_4->addWidget(labelMinTorque);


        horizontalLayout_6->addLayout(verticalLayout_4);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(leftLayout);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        plotAngle = new QCustomPlot(widget_5);
        plotAngle->setObjectName(QString::fromUtf8("plotAngle"));
        plotAngle->setMinimumSize(QSize(400, 100));

        horizontalLayout_7->addWidget(plotAngle);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelAngle = new QLabel(widget_5);
        labelAngle->setObjectName(QString::fromUtf8("labelAngle"));

        verticalLayout_3->addWidget(labelAngle);

        labelMaxAngle = new QLabel(widget_5);
        labelMaxAngle->setObjectName(QString::fromUtf8("labelMaxAngle"));

        verticalLayout_3->addWidget(labelMaxAngle);

        labelMinAngle = new QLabel(widget_5);
        labelMinAngle->setObjectName(QString::fromUtf8("labelMinAngle"));

        verticalLayout_3->addWidget(labelMinAngle);


        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_2->addWidget(widget_5);


        horizontalLayout_8->addWidget(leftLayout);

        rigthLayout = new QWidget(torque);
        rigthLayout->setObjectName(QString::fromUtf8("rigthLayout"));
        verticalLayout_5 = new QVBoxLayout(rigthLayout);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        fileFormatComboBox = new QComboBox(rigthLayout);
        fileFormatComboBox->setObjectName(QString::fromUtf8("fileFormatComboBox"));
        fileFormatComboBox->setMinimumSize(QSize(0, 0));
        fileFormatComboBox->setEditable(false);
        fileFormatComboBox->setMaxVisibleItems(10);
        fileFormatComboBox->setFrame(true);

        horizontalLayout_4->addWidget(fileFormatComboBox);

        saveButton = new QPushButton(rigthLayout);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setMinimumSize(QSize(0, 0));

        horizontalLayout_4->addWidget(saveButton);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        connect_device = new QPushButton(rigthLayout);
        connect_device->setObjectName(QString::fromUtf8("connect_device"));

        verticalLayout->addWidget(connect_device);

        saveTorqueZeroButton = new QPushButton(rigthLayout);
        saveTorqueZeroButton->setObjectName(QString::fromUtf8("saveTorqueZeroButton"));

        verticalLayout->addWidget(saveTorqueZeroButton);

        saveAngleZeroButton = new QPushButton(rigthLayout);
        saveAngleZeroButton->setObjectName(QString::fromUtf8("saveAngleZeroButton"));

        verticalLayout->addWidget(saveAngleZeroButton);

        startButton = new QPushButton(rigthLayout);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout->addWidget(startButton);

        pauseButton = new QPushButton(rigthLayout);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        verticalLayout->addWidget(pauseButton);

        resetButton = new QPushButton(rigthLayout);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout->addWidget(resetButton);


        verticalLayout_5->addLayout(verticalLayout);


        horizontalLayout_8->addWidget(rigthLayout);


        horizontalLayout_5->addWidget(torque);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        StopButton = new QPushButton(tab_2);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setGeometry(QRect(580, 710, 41, 61));
        ReminderEdit = new QLineEdit(tab_2);
        ReminderEdit->setObjectName(QString::fromUtf8("ReminderEdit"));
        ReminderEdit->setGeometry(QRect(320, 720, 171, 41));
        ValueEdit = new QTextEdit(tab_2);
        ValueEdit->setObjectName(QString::fromUtf8("ValueEdit"));
        ValueEdit->setGeometry(QRect(780, 670, 104, 70));
        ErrorLabel = new QLineEdit(tab_2);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setGeometry(QRect(990, 770, 111, 25));
        CurrnetValuelabel = new QLineEdit(tab_2);
        CurrnetValuelabel->setObjectName(QString::fromUtf8("CurrnetValuelabel"));
        CurrnetValuelabel->setGeometry(QRect(780, 760, 121, 25));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 40, 641, 611));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        ErrorLabel_2 = new QLineEdit(tab_2);
        ErrorLabel_2->setObjectName(QString::fromUtf8("ErrorLabel_2"));
        ErrorLabel_2->setGeometry(QRect(1170, 770, 101, 25));
        configbotton = new QPushButton(tab_2);
        configbotton->setObjectName(QString::fromUtf8("configbotton"));
        configbotton->setGeometry(QRect(10, 670, 151, 81));
        MeanErrorEdit = new QTextEdit(tab_2);
        MeanErrorEdit->setObjectName(QString::fromUtf8("MeanErrorEdit"));
        MeanErrorEdit->setGeometry(QRect(1170, 680, 111, 70));
        TestEdit = new QLineEdit(tab_2);
        TestEdit->setObjectName(QString::fromUtf8("TestEdit"));
        TestEdit->setGeometry(QRect(200, 0, 131, 41));
        Clientcombox = new QComboBox(tab_2);
        Clientcombox->addItem(QString());
        Clientcombox->setObjectName(QString::fromUtf8("Clientcombox"));
        Clientcombox->setGeometry(QRect(170, 670, 121, 31));
        ClearButton = new QPushButton(tab_2);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setGeometry(QRect(650, 710, 41, 61));
        ErrorEdit = new QTextEdit(tab_2);
        ErrorEdit->setObjectName(QString::fromUtf8("ErrorEdit"));
        ErrorEdit->setGeometry(QRect(990, 680, 104, 70));
        TcpEdit = new QLineEdit(tab_2);
        TcpEdit->setObjectName(QString::fromUtf8("TcpEdit"));
        TcpEdit->setGeometry(QRect(320, 670, 441, 41));
        startbutton = new QPushButton(tab_2);
        startbutton->setObjectName(QString::fromUtf8("startbutton"));
        startbutton->setGeometry(QRect(510, 710, 51, 61));
        connectdevice = new QPushButton(tab_2);
        connectdevice->setObjectName(QString::fromUtf8("connectdevice"));
        connectdevice->setGeometry(QRect(170, 720, 121, 71));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(700, 10, 571, 621));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 16)
            tableWidget->setColumnCount(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        if (tableWidget->rowCount() < 16)
            tableWidget->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem31);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 50, 551, 481));
        table_button = new QPushButton(tab);
        table_button->setObjectName(QString::fromUtf8("table_button"));
        table_button->setGeometry(QRect(140, 10, 211, 31));
        tabWidget_2->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        pressure_edit = new QTextEdit(tab_3);
        pressure_edit->setObjectName(QString::fromUtf8("pressure_edit"));
        pressure_edit->setGeometry(QRect(40, 50, 441, 151));
        torque_edit = new QTextEdit(tab_3);
        torque_edit->setObjectName(QString::fromUtf8("torque_edit"));
        torque_edit->setGeometry(QRect(40, 270, 441, 181));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 10, 131, 31));
        lineEdit_2 = new QLineEdit(tab_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 220, 131, 41));
        tabWidget_2->addTab(tab_3, QString());
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1105, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        fileFormatComboBox->setCurrentIndex(-1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "button1", nullptr));
        labelTorque->setText(QCoreApplication::translate("MainWindow", "\346\211\255\345\212\233", nullptr));
        labelMaxTorque->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelMinTorque->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelAngle->setText(QCoreApplication::translate("MainWindow", "\345\200\276\346\226\234\350\247\222", nullptr));
        labelMaxAngle->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelMinAngle->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        fileFormatComboBox->setCurrentText(QString());
        fileFormatComboBox->setPlaceholderText(QString());
        saveButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        connect_device->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207\351\205\215\347\275\256", nullptr));
        saveTorqueZeroButton->setText(QCoreApplication::translate("MainWindow", "\346\211\255\345\212\233\347\275\256\351\233\266", nullptr));
        saveAngleZeroButton->setText(QCoreApplication::translate("MainWindow", "\350\247\222\345\272\246\347\275\256\351\233\266", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "pause", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainWindow", "\346\211\255\347\237\251\344\273\252", nullptr));
        StopButton->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        ErrorLabel->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\257\273\345\217\226\350\257\257\345\267\256", nullptr));
        CurrnetValuelabel->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\257\273\345\217\226\346\225\260\345\200\274", nullptr));
        ErrorLabel_2->setText(QCoreApplication::translate("MainWindow", "\345\235\207\346\226\271\345\267\256", nullptr));
        configbotton->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\350\256\276\345\244\207\351\205\215\347\275\256", nullptr));
        TestEdit->setText(QCoreApplication::translate("MainWindow", "\346\240\207\345\256\232\350\277\233\345\272\246\346\217\220\347\244\272", nullptr));
        Clientcombox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\350\256\276\345\244\207\350\277\236\346\216\245", nullptr));

        ClearButton->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        TcpEdit->setText(QCoreApplication::translate("MainWindow", "\347\255\211\345\276\205\344\270\213\344\275\215\346\234\272\350\277\236\346\216\245\357\274\214\347\253\257\345\217\243\345\217\267\357\274\2321234", nullptr));
        startbutton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        connectdevice->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207\351\205\215\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\210\2271", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\345\210\2272", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\345\210\2273", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\345\210\2274", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\210\2275", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\345\210\2276", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\345\210\2277", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\345\210\2278", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\345\210\2279", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\345\210\22710", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\345\210\22711", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\345\210\22712", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\345\210\22713", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\345\210\22714", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\345\210\22715", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\345\210\22716", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\350\241\2141", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\350\241\2142", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\350\241\2143", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\350\241\2144", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\350\241\2145", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "\350\241\2146", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "\350\241\2147", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "\350\241\2148", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "\350\241\2149", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "\350\241\21410", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "\350\241\21411", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "\350\241\21412", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "\350\241\21413", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "\350\241\21414", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "\350\241\21415", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "\350\241\21416", nullptr));
        table_button->setText(QCoreApplication::translate("MainWindow", "16*16\345\256\236\346\227\266\345\216\213\345\212\233\345\210\206\345\270\203\345\233\276", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\345\215\225\347\202\271\346\240\207\345\256\232\350\256\276\345\244\207", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\346\211\255\347\237\251\344\273\252", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233\346\240\207\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
