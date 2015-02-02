#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>
#include "test.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t = new Thread(this);
    t->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOfMainWindow()
{
    qDebug()<<"slotOfMainWindow called From Thread";
}
