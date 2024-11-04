#ifndef DELAY_H
#define DELAY_H
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>

void delay(int millisecondsToWait)
{
    QEventLoop loop;
    QTimer::singleShot(millisecondsToWait, &loop, &QEventLoop::quit);
    loop.exec();
}
#endif // DELAY_H
