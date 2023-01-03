#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w = new Widget(this);
    w->resize(800,600);
//    QScrollBar *q = new QScrollBar(Qt::Horizontal,w);
//    q->resize(100,10);
//    q->move(100,100);
    connect(this->ui->pushButton,&QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete w;
}

void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    w->setValue(value);
}

void MainWindow::on_pushButton_clicked()
{
        q = new QScrollBar(Qt::Horizontal,w);
        q->resize(100,10);
        q->move(100,100);
        q->setVisible(true);
}


