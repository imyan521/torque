#include "cartesianwidget.h"

CartesianWidget::CartesianWidget(QWidget *parent) : QWidget(parent), xAxisScale(30) {
    // 构造函数，初始化x轴缩放比例
}

void CartesianWidget::setAxisScale(int scale) {
    xAxisScale = scale; // 设置新的x轴缩放比例
    update(); // 请求重绘
}

void CartesianWidget::drawPoint(QPainter &painter, int x, int y) {
    // 计算实际的 x 坐标
    int actualX = calculateActualX(x);

    // 计算实际的 y 坐标
    int actualY = calculateActualY(y);

    // 绘制点
    painter.setRenderHint(QPainter::Antialiasing, true); // 开启抗锯齿
    painter.setPen(Qt::red); // 设置画笔颜色为红色
    painter.drawEllipse(QPoint(actualX, actualY), 1, 1); // 绘制点
}

void CartesianWidget::drawstdPoint(QPainter &painter, int x, int y) {
    // 计算实际的 x 坐标
    int actualX = calculateActualX(x);

    // 计算实际的 y 坐标
    int actualY = calculateActualY(y);

    // 绘制点
    painter.setRenderHint(QPainter::Antialiasing, true); // 开启抗锯齿
    painter.setPen(Qt::blue); // 设置画笔颜色为蓝色
    painter.drawEllipse(QPoint(actualX, actualY), 1, 1); // 绘制点
}

void CartesianWidget::showSpecificPoint(int x, int y) {
    // 显示特定点
    specificPoint = QPoint(x, y);
    hasSpecificPoint = true; // 设置标志位
    update(); // 请求重绘
}

int CartesianWidget::calculateActualX(int x) const {
    int xMax = 750; // x轴最大值
    int xMin = 250; // x轴最小值
    int xRange = xAxisScale; // x轴范围
    return (xMax - xMin) / (xRange) * x + xMin; // 计算实际x坐标
}

int CartesianWidget::calculateActualY(int y) const {
    int yMax = 250; // y轴最大值
    int yMin = 750; // y轴最小值
    int yRange = 500; // y轴范围
    return (yMax - yMin) / yRange * y + yMin; // 计算实际y坐标
}

void CartesianWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event); // 调用父类的事件处理

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 开启抗锯齿

    int width = this->width();
    int height = this->height();

    // 计算坐标系的位置和大小
    int x = width / 4;
    int y = height * 3 / 4;
    int w = width / 2;
    int h = height / 2;

    // 绘制 x 轴
    painter.drawLine(x, y, x + w, y);

    // 绘制 x 轴箭头
    int arrowSize = 10;
    QPolygon arrowPolygon;
    arrowPolygon << QPoint(x + w, y) << QPoint(x + w - arrowSize, y - arrowSize / 2) << QPoint(x + w - arrowSize, y + arrowSize / 2);
    painter.drawPolygon(arrowPolygon);

    // 绘制 y 轴
    painter.drawLine(x, y, x, y - h);

    // 绘制 y 轴箭头
    QPolygon arrowPolygon2;
    arrowPolygon2 << QPoint(x, y - h) << QPoint(x - arrowSize / 2, y - h + arrowSize) << QPoint(x + arrowSize / 2, y - h + arrowSize);
    painter.drawPolygon(arrowPolygon2);

    // 绘制 x 轴刻度和标签
    int numTicks = 11; // 显示 11 个刻度
    int tickSpacing = w / (numTicks - 1); // 根据需要显示的刻度数量动态计算刻度间隔
    for (int i = 0; i < numTicks; ++i) {
        int xPos = x + i * tickSpacing;
        painter.drawLine(xPos, y - 5, xPos, y + 5); // 绘制刻度线
        painter.drawText(xPos - 10, y + 20, QString::number(i * xAxisScale / 10)); // 根据 xAxisScale 动态计算刻度的数值
    }

    // 绘制 y 轴刻度和标签
    int step = h / 10; // 刻度间隔
    int halfStep = step / 2;
    for (int i = y - step; i > y - h; i -= step) {
        painter.drawLine(x - 5, i, x + 5, i); // 调整刻度线的长度
        painter.drawText(x - halfStep - 40, i, QString::number(y - i)); // 标签
    }

    // 绘制点
    if (!pointList.empty()) {
        for (auto point : pointList) {
            drawPoint(painter, point.x(), point.y()); // 绘制自定义点
        }
    }

    // 绘制标准点
    if (!stdpointList.empty()) {
        for (auto point : stdpointList) {
            drawstdPoint(painter, point.x(), point.y()); // 绘制标准点
        }
    }
}

void CartesianWidget::mousePressEvent(QMouseEvent *event) {
    // 处理鼠标点击事件
    if (event->button() == Qt::LeftButton) {
        QPoint clickedPos = event->pos();
        qDebug() << "Clicked at: (" << clickedPos.x() << ", " << clickedPos.y() << ")"; // 打印点击位置
    }
}

void CartesianWidget::clearandresizePointlist() {
    pointList.clear(); // 清空点列表
    pointList.reserve(xAxisScale); // 预留空间
    update(); // 请求重绘
}

void CartesianWidget::clearandresizestdPointlist() {
    stdpointList.clear(); // 清空标准点列表
    stdpointList.reserve(xAxisScale); // 预留空间
    update(); // 请求重绘
}
