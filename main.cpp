#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "test.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    qDebug()<<"From main thread: "<<QThread::currentThreadId();



    return a.exec();
}


