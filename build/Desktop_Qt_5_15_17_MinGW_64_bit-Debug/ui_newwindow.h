/********************************************************************************
** Form generated from reading UI file 'newwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINDOW_H
#define UI_NEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *newWindow)
    {
        if (newWindow->objectName().isEmpty())
            newWindow->setObjectName(QString::fromUtf8("newWindow"));
        newWindow->resize(550, 408);
        pushButton = new QPushButton(newWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 190, 75, 24));

        retranslateUi(newWindow);

        QMetaObject::connectSlotsByName(newWindow);
    } // setupUi

    void retranslateUi(QWidget *newWindow)
    {
        newWindow->setWindowTitle(QCoreApplication::translate("newWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("newWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newWindow: public Ui_newWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINDOW_H
