#include "test.h"



Thread::Thread(MainWindow *parent): itsParent(parent)
{
}

void Thread::aPrivateSlot()
{

    qDebug()<<counter;
    if(counter == 3)
    {
        this->quit();
    }
    else
    {
    qDebug()<<"Private Slot of a class that is owned by the main Thread: gets called from?: "<<QThread::currentThreadId();
    }

    counter++;
}


