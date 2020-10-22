#include "usart.h"
#include <QDebug>
#include <QDialog>

Usart::Usart()
{
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    if (list.empty())
    {
        qDebug() << "no serial!";
    }
    else
    {
        serial = new QSerialPort(list[0]);
        if (serial->isOpen())
        {
            serial->clear();
            serial->close();
        }
        if (serial->open(QIODevice::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
            serial->setDataBits(QSerialPort::Data8);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
        }
        else
        {
            qDebug() << "fail to open!";
        }
    }
}

Usart::~Usart()
{
    if (serial->isOpen())
    {
        serial->close();
    }
    delete serial;
}

void Usart::sendStartADC()
{
    char info[1] = { 0x01 };
    serial->write(info, 1);
}

int Usart::receiveInfo(int i)
{
    int len = serial->read(data, i);
    if (len == 2)
    {
        int receive;
        receive = data[0];
        receive = (receive << 8) + data[1];
        qDebug() << "the data is" << receive;
        return receive;
    }
    qDebug() << "error";
    return -1;

}
