#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "usart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void addSum();
private:
    Ui::Widget *ui;
    Usart serial;
    double I;
    QTimer *timer;
    int addTimes;
    void timerInit();
    double sum;
};
#endif // WIDGET_H
