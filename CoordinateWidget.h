#ifndef COORDINAATE_H
#define COORDINAATE_H
class CoordinateWidget : public QWidget
{
public:
    CoordinateWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        QPoint pos = event->pos(); // 鼠标点击位置相对于 CoordinateWidget 的坐标

        // 转换为UI坐标系中的坐标
        QPoint uiPos = mapToGlobal(pos);
        uiPos = mapFromGlobal(uiPos);

        qDebug() << "UI坐标系中的坐标：" << uiPos;
    }
};

#endif // COORDINAATE_H
