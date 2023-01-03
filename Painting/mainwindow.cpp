#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include "paint.h"
#include "draw.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //画板类
//    p = new Paint();
//    p->show();
//    QPushButton *button=new QPushButton(tr("这是一个按钮"),this);
//    button->resize(100,100);
//    button->move(500,500);
//    connect(button,&QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);
    //画图类
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->setVisible(false);
    p->setVisible(true);
}
