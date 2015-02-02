#ifndef TEST_H
#define TEST_H

#include <QThread>
#include <QDebug>
#include <QTimer>
#include "mainwindow.h"

class Worker : public QObject
{
public:


private:
    int counter = 0;
    Q_OBJECT
private slots:
    void onTimeout()
    {
        qDebug()<<counter;

        if(counter == 3)
        {
            iAmFinished();
        }else{

        qDebug()<<"Worker::onTimeout get called from?: "<<QThread::currentThreadId();


        this->newImageAvaliable();

        counter++;
        }
    }

signals:
    void newImageAvaliable();
    void iAmFinished();

};

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread(MainWindow *parent);

    Worker* pToWorker;

private:

    int counter=0;
    MainWindow *itsParent;

    void run()
    {

        Worker worker;
        pToWorker = &worker;
        QTimer timer;


        qDebug()<<"From work thread: "<<currentThreadId();

        connect(&timer,SIGNAL(timeout()),&worker,SLOT(onTimeout()));
        connect(&timer,SIGNAL(timeout()),this,SLOT(aPrivateSlot()));
        connect(&worker,SIGNAL(iAmFinished()),this,SLOT(quit()));
        connect(&worker,SIGNAL(newImageAvaliable()),itsParent,SLOT(slotOfMainWindow()));

        timer.start(1000);

        this->exec();
    }

private slots:
    void aPrivateSlot();


};



#endif
