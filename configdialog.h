#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include <QLineEdit>

class ConfigDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = nullptr);
signals:
    void configConfirmed(const QString &vertical,
    const QString &horizontal, const QString &maxPressure, const QString &minPressure);
private slots:
    void onOkButtonClicked();
    void adjustPressure(QLineEdit *lineEdit, double change);

private:
    QLineEdit *lineEditVertical;
    QLineEdit *lineEditHorizontal;
    QLineEdit *lineEditMaxPressure;
    QLineEdit *lineEditMinPressure;
};

#endif // CONFIGDIALOG_H

