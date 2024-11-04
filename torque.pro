#-------------------------------------------------
#
# Project created by QtCreator 2023-11-14T21:00:11
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += network
QT       += charts
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Tab1Widget.cpp \
    Tab2Widget.cpp \
    TorqueWidget.cpp \
    connect_device_window.cpp \
    dataparser.cpp \
    datareceiver.cpp \
        main.cpp \
        mainwindow.cpp \
    cartesianwidget.cpp \
    serialporthelper.cpp \
    tcpsocket.cpp \
    configdialog.cpp\
    qcustomplot.cpp

HEADERS += \
    Tab1Widget.h \
    Tab2Widget.h \
    TorqueWidget.h \
    connect_device_window.h \
    dataparser.h \
    datareceiver.h \
    mainwindow.h \
    cartesianwidget.h \
    delay.h \
    file.h \
    serialporthelper.h \
    tcpsocket.h \
    configdialog.h\
    qcustomplot.h

FORMS += \
        TorqueWidget.ui \
        connect_device_window.ui \
        mainwindow.ui

DISTFILES +=
