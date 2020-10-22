#ifndef USART_H
#define USART_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Usart
{   
public:
    Usart();
    ~Usart();
    void sendStartADC();
    int receiveInfo(int i);

private:
    QSerialPort *serial;
    char data[64];
};

#endif // USART_H
