#include "configdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDoubleValidator>
#include <QMessageBox>

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this); // 主布局

    // 创建并添加纵向框件数量标签和输入框
    QLabel *labelVertical = new QLabel("纵向框件数量:", this);
    lineEditVertical = new QLineEdit(this);
    lineEditVertical->setValidator(new QDoubleValidator(0, 100, 2, this)); // 允许输入两位小数的浮点数
    mainLayout->addWidget(labelVertical);
    mainLayout->addWidget(lineEditVertical);

    // 创建并添加横向框件数量标签和输入框
    QLabel *labelHorizontal = new QLabel("横向框件数量:", this);
    lineEditHorizontal = new QLineEdit(this);
    lineEditHorizontal->setValidator(new QDoubleValidator(0, 100, 2, this)); // 允许输入两位小数的浮点数
    mainLayout->addWidget(labelHorizontal);
    mainLayout->addWidget(lineEditHorizontal);

    // 创建并添加最大压力范围标签和输入框
    QLabel *labelMaxPressure = new QLabel("最大压力范围:", this);
    lineEditMaxPressure = new QLineEdit(this);
    lineEditMaxPressure->setValidator(new QDoubleValidator(0, 1000, 2, this)); // 允许输入两位小数的浮点数

    QHBoxLayout *maxPressureLayout = new QHBoxLayout(); // 最大压力布局
    QPushButton *maxPressureMinusButton = new QPushButton("-", this); // 减小按钮
    QPushButton *maxPressurePlusButton = new QPushButton("+", this); // 增加按钮

    // 连接减小按钮信号与槽
    connect(maxPressureMinusButton, &QPushButton::clicked, [this]() {
        adjustPressure(lineEditMaxPressure, -10); // 调整压力
    });

    // 连接增加按钮信号与槽
    connect(maxPressurePlusButton, &QPushButton::clicked, [this]() {
        adjustPressure(lineEditMaxPressure, 10); // 调整压力
    });

    maxPressureLayout->addWidget(maxPressureMinusButton);
    maxPressureLayout->addWidget(lineEditMaxPressure);
    maxPressureLayout->addWidget(maxPressurePlusButton);

    mainLayout->addWidget(labelMaxPressure);
    mainLayout->addLayout(maxPressureLayout); // 添加最大压力布局

    // 创建并添加最小压力范围标签和输入框
    QLabel *labelMinPressure = new QLabel("最小压力范围:", this);
    lineEditMinPressure = new QLineEdit(this);
    lineEditMinPressure->setValidator(new QDoubleValidator(0, 1000, 2, this)); // 允许输入两位小数的浮点数

    QHBoxLayout *minPressureLayout = new QHBoxLayout(); // 最小压力布局
    QPushButton *minPressureMinusButton = new QPushButton("-", this); // 减小按钮
    QPushButton *minPressurePlusButton = new QPushButton("+", this); // 增加按钮

    // 连接减小按钮信号与槽
    connect(minPressureMinusButton, &QPushButton::clicked, [this]() {
        adjustPressure(lineEditMinPressure, -10); // 调整压力
    });

    // 连接增加按钮信号与槽
    connect(minPressurePlusButton, &QPushButton::clicked, [this]() {
        adjustPressure(lineEditMinPressure, 10); // 调整压力
    });

    minPressureLayout->addWidget(minPressureMinusButton);
    minPressureLayout->addWidget(lineEditMinPressure);
    minPressureLayout->addWidget(minPressurePlusButton);

    mainLayout->addWidget(labelMinPressure);
    mainLayout->addLayout(minPressureLayout); // 添加最小压力布局

    // 添加确定和取消按钮
    QPushButton *okButton = new QPushButton("确定", this);
    QPushButton *cancelButton = new QPushButton("取消", this);

    // 连接确定按钮信号与槽
    connect(okButton, &QPushButton::clicked, this, &ConfigDialog::onOkButtonClicked);
    // 连接取消按钮信号与槽
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    mainLayout->addWidget(okButton);
    mainLayout->addWidget(cancelButton); // 添加按钮到布局
}

void ConfigDialog::onOkButtonClicked() {
    // 检查所有输入框是否填写
    if (lineEditVertical->text().isEmpty() ||
        lineEditHorizontal->text().isEmpty() ||
        lineEditMaxPressure->text().isEmpty() ||
        lineEditMinPressure->text().isEmpty()) {
        QMessageBox::warning(this, "输入错误", "所有字段都是必填的，请输入所有值。"); // 弹出警告框
        return;
    }

    // 发送配置确认信号
    emit configConfirmed(lineEditVertical->text(), lineEditHorizontal->text(), lineEditMaxPressure->text(), lineEditMinPressure->text());

    accept(); // 关闭对话框并返回接受状态
}

void ConfigDialog::adjustPressure(QLineEdit *lineEdit, double change) {
    double currentValue = lineEdit->text().toDouble(); // 获取当前值
    lineEdit->setText(QString::number(currentValue + change)); // 调整并设置新的值
}
