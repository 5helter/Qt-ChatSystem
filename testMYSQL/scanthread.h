#ifndef SCANTHREAD_H
#define SCANTHREAD_H

#include <QThread>
#include <QObject>

class ScanThread : public QThread
{
    Q_OBJECT
public:
     explicit ScanThread(QObject *parent = nullptr);
       bool stop;
protected:
    void run() override;
signals:
    void updateTable();
};

#endif // SCANTHREAD_H
