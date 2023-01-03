#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    effect = new QSoundEffect(this);
    effect->setSource(QUrl::fromLocalFile(":/sound.wav"));
    effect->setVolume(0.20f);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    effect->play();
}
void MainWindow::on_pushButton_2_clicked()
{
    effect->stop();
}
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    effect->setLoopCount(arg1);
}


