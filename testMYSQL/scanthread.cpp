#include "scanthread.h"
#include<QDebug>


ScanThread::ScanThread(QObject *parent): QThread(parent)
{
    stop=false;
}

void ScanThread::run()
{
    while(!stop)
    {
        emit updateTable();
        msleep(2000);
    }
    quit();
}
