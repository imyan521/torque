/********************************************************************************
** Form generated from reading UI file 'connect_device_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_DEVICE_WINDOW_H
#define UI_CONNECT_DEVICE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connect_device_window
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *torque;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLineEdit *torqueEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *biaoding;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *pressureEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sensor;
    QVBoxLayout *verticalLayout_4;
    QPushButton *sensor_connect;
    QPushButton *sensor_close;
    QLineEdit *sensorEdit;
    QVBoxLayout *verticalLayout_5;
    QComboBox *serial_comboBox;
    QPushButton *serial_refresh;
    QPushButton *pushButton;

    void setupUi(QWidget *connect_device_window)
    {
        if (connect_device_window->objectName().isEmpty())
            connect_device_window->setObjectName(QString::fromUtf8("connect_device_window"));
        connect_device_window->resize(857, 638);
        connect_device_window->setMinimumSize(QSize(700, 450));
        connect_device_window->setMouseTracking(false);
        horizontalLayout_5 = new QHBoxLayout(connect_device_window);
        horizontalLayout_5->setSpacing(4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 6);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        torque = new QPushButton(connect_device_window);
        torque->setObjectName(QString::fromUtf8("torque"));
        torque->setMinimumSize(QSize(200, 100));
        torque->setIconSize(QSize(100, 100));

        horizontalLayout_2->addWidget(torque);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_5 = new QPushButton(connect_device_window);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setIconSize(QSize(50, 50));

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(connect_device_window);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setIconSize(QSize(50, 50));

        verticalLayout_2->addWidget(pushButton_6);


        horizontalLayout_2->addLayout(verticalLayout_2);

        torqueEdit = new QLineEdit(connect_device_window);
        torqueEdit->setObjectName(QString::fromUtf8("torqueEdit"));
        torqueEdit->setMaxLength(32780);

        horizontalLayout_2->addWidget(torqueEdit);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        biaoding = new QPushButton(connect_device_window);
        biaoding->setObjectName(QString::fromUtf8("biaoding"));
        biaoding->setMinimumSize(QSize(200, 100));
        biaoding->setIconSize(QSize(100, 100));

        horizontalLayout_3->addWidget(biaoding);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_3 = new QPushButton(connect_device_window);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIconSize(QSize(50, 50));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(connect_device_window);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setIconSize(QSize(50, 50));

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout_3->addLayout(verticalLayout_3);

        pressureEdit = new QLineEdit(connect_device_window);
        pressureEdit->setObjectName(QString::fromUtf8("pressureEdit"));
        pressureEdit->setMaxLength(32780);

        horizontalLayout_3->addWidget(pressureEdit);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sensor = new QPushButton(connect_device_window);
        sensor->setObjectName(QString::fromUtf8("sensor"));
        sensor->setMinimumSize(QSize(200, 100));
        sensor->setIconSize(QSize(100, 100));

        horizontalLayout_4->addWidget(sensor);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        sensor_connect = new QPushButton(connect_device_window);
        sensor_connect->setObjectName(QString::fromUtf8("sensor_connect"));
        sensor_connect->setIconSize(QSize(40, 40));

        verticalLayout_4->addWidget(sensor_connect);

        sensor_close = new QPushButton(connect_device_window);
        sensor_close->setObjectName(QString::fromUtf8("sensor_close"));
        sensor_close->setIconSize(QSize(40, 40));

        verticalLayout_4->addWidget(sensor_close);


        horizontalLayout_4->addLayout(verticalLayout_4);

        sensorEdit = new QLineEdit(connect_device_window);
        sensorEdit->setObjectName(QString::fromUtf8("sensorEdit"));
        sensorEdit->setMaxLength(32780);

        horizontalLayout_4->addWidget(sensorEdit);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        serial_comboBox = new QComboBox(connect_device_window);
        serial_comboBox->addItem(QString());
        serial_comboBox->setObjectName(QString::fromUtf8("serial_comboBox"));
        serial_comboBox->setIconSize(QSize(80, 16));

        verticalLayout_5->addWidget(serial_comboBox);

        serial_refresh = new QPushButton(connect_device_window);
        serial_refresh->setObjectName(QString::fromUtf8("serial_refresh"));
        serial_refresh->setIconSize(QSize(40, 40));

        verticalLayout_5->addWidget(serial_refresh);

        pushButton = new QPushButton(connect_device_window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_5->addWidget(pushButton);


        horizontalLayout_5->addLayout(verticalLayout_5);


        retranslateUi(connect_device_window);

        QMetaObject::connectSlotsByName(connect_device_window);
    } // setupUi

    void retranslateUi(QWidget *connect_device_window)
    {
        connect_device_window->setWindowTitle(QCoreApplication::translate("connect_device_window", "Form", nullptr));
        torque->setText(QCoreApplication::translate("connect_device_window", "\346\211\255\347\237\251\344\273\252", nullptr));
        pushButton_5->setText(QCoreApplication::translate("connect_device_window", "\350\277\236\346\216\245", nullptr));
        pushButton_6->setText(QCoreApplication::translate("connect_device_window", "\346\226\255\345\274\200", nullptr));
        torqueEdit->setText(QCoreApplication::translate("connect_device_window", "\350\256\276\345\244\207\346\234\252\350\277\236\346\216\245", nullptr));
        biaoding->setText(QCoreApplication::translate("connect_device_window", "\345\216\213\345\212\233\346\240\207\345\256\232\350\256\276\345\244\207", nullptr));
        pushButton_3->setText(QCoreApplication::translate("connect_device_window", "\350\277\236\346\216\245", nullptr));
        pushButton_4->setText(QCoreApplication::translate("connect_device_window", "\346\226\255\345\274\200", nullptr));
        pressureEdit->setText(QCoreApplication::translate("connect_device_window", "\350\256\276\345\244\207\346\234\252\350\277\236\346\216\245", nullptr));
        sensor->setText(QCoreApplication::translate("connect_device_window", "\345\210\206\345\270\203\345\274\217\344\274\240\346\204\237\345\231\250", nullptr));
        sensor_connect->setText(QCoreApplication::translate("connect_device_window", "\350\277\236\346\216\245", nullptr));
        sensor_close->setText(QCoreApplication::translate("connect_device_window", "\346\226\255\345\274\200", nullptr));
        sensorEdit->setText(QCoreApplication::translate("connect_device_window", "\350\256\276\345\244\207\346\234\252\350\277\236\346\216\245", nullptr));
        serial_comboBox->setItemText(0, QCoreApplication::translate("connect_device_window", "\344\270\262\345\217\243\345\217\267", nullptr));

        serial_refresh->setText(QCoreApplication::translate("connect_device_window", "\345\210\267\346\226\260", nullptr));
        pushButton->setText(QCoreApplication::translate("connect_device_window", "\351\205\215\347\275\256\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connect_device_window: public Ui_connect_device_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_DEVICE_WINDOW_H
