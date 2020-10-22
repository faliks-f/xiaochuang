#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    sum = 0;
    I = 0;
    addTimes = 0;
    timerInit();
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addSum()
{
    if (addTimes == 900)
    {
        timer->stop();
    }
    serial.sendStartADC();
    int returnValue;
    int sign = 0;
    do
    {
        ++sign;
        returnValue = serial.receiveInfo(2);
    } while (!returnValue && sign < 10);
    if (returnValue != 0)
        I = (double)returnValue / 10000;
    sum += I * 2;
    ++addTimes;
}

void Widget::timerInit()
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::addSum);
    timer->start(2000);
}

