#ifndef CARTESIANWIDGET_H
#define CARTESIANWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QDebug>
#include <QMouseEvent>
#include <vector>


class CartesianWidget : public QWidget
{
    Q_OBJECT

public:
    void showSpecificPoint(int x,int y);

    explicit CartesianWidget(QWidget *parent = nullptr);

    void setAxisScale(int scale);

    void drawPoint(QPainter &painter, int x, int y);

    void drawstdPoint(QPainter &painter, int x, int y);

    void mousePressEvent(QMouseEvent *event) override;

    void clearandresizePointlist();

    void clearandresizestdPointlist();

protected:
     int calculateActualX(int x) const;

      int calculateActualY(int y) const;

      void paintEvent(QPaintEvent *event) override;

public:
    int xAxisScale;
    bool hasSpecificPoint=false;
    QPoint specificPoint;
    std::vector<QPoint> pointList;
    std::vector<QPoint> stdpointList;
};

#endif // CARTESIANWIDGET_H
