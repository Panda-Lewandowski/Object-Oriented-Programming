#include "delay.h"

void delay(int sec)
{
    QTime dieTime= QTime::currentTime().addMSecs(sec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);


}
