/********************************************************************************
** Form generated from reading UI file 'TorqueWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TORQUEWIDGET_H
#define UI_TORQUEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_TorqueWidget
{
public:
    QHBoxLayout *horizontalLayout;
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

    void setupUi(QWidget *TorqueWidget)
    {
        if (TorqueWidget->objectName().isEmpty())
            TorqueWidget->setObjectName(QString::fromUtf8("TorqueWidget"));
        TorqueWidget->resize(1112, 785);
        horizontalLayout = new QHBoxLayout(TorqueWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        torque = new QWidget(TorqueWidget);
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


        horizontalLayout->addWidget(torque);


        retranslateUi(TorqueWidget);

        fileFormatComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TorqueWidget);
    } // setupUi

    void retranslateUi(QWidget *TorqueWidget)
    {
        TorqueWidget->setWindowTitle(QCoreApplication::translate("TorqueWidget", "Form", nullptr));
        labelTorque->setText(QCoreApplication::translate("TorqueWidget", "\346\211\255\345\212\233", nullptr));
        labelMaxTorque->setText(QCoreApplication::translate("TorqueWidget", "TextLabel", nullptr));
        labelMinTorque->setText(QCoreApplication::translate("TorqueWidget", "TextLabel", nullptr));
        labelAngle->setText(QCoreApplication::translate("TorqueWidget", "\345\200\276\346\226\234\350\247\222", nullptr));
        labelMaxAngle->setText(QCoreApplication::translate("TorqueWidget", "TextLabel", nullptr));
        labelMinAngle->setText(QCoreApplication::translate("TorqueWidget", "TextLabel", nullptr));
        fileFormatComboBox->setCurrentText(QString());
        fileFormatComboBox->setPlaceholderText(QString());
        saveButton->setText(QCoreApplication::translate("TorqueWidget", "\345\257\274\345\207\272", nullptr));
        connect_device->setText(QCoreApplication::translate("TorqueWidget", "\350\277\236\346\216\245\350\256\276\345\244\207\351\205\215\347\275\256", nullptr));
        saveTorqueZeroButton->setText(QCoreApplication::translate("TorqueWidget", "\346\211\255\345\212\233\347\275\256\351\233\266", nullptr));
        saveAngleZeroButton->setText(QCoreApplication::translate("TorqueWidget", "\350\247\222\345\272\246\347\275\256\351\233\266", nullptr));
        startButton->setText(QCoreApplication::translate("TorqueWidget", "\345\274\200\345\247\213", nullptr));
        pauseButton->setText(QCoreApplication::translate("TorqueWidget", "\346\232\202\345\201\234", nullptr));
        resetButton->setText(QCoreApplication::translate("TorqueWidget", "\347\273\210\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TorqueWidget: public Ui_TorqueWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TORQUEWIDGET_H
