#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&myWatcher,&QFileSystemWatcher::directoryChanged,this,&MainWindow::show);
    connect(&myWatcher,&QFileSystemWatcher::fileChanged,this,&MainWindow::showMessage);
    QDir myDir(QDir::currentPath());
    myDir.setNameFilters(QStringList("*.h"));
    ui->listWidget->addItem(myDir.absolutePath()+tr("目录下的.h所有文件"));
    ui->listWidget->addItems(myDir.entryList());
    myDir.mkdir("mydir");
    myDir.cd("mydir");
    ui->listWidget->addItem(tr("监视的目录：")+myDir.absolutePath());
    myWatcher.addPath(myDir.absolutePath());
    //创建文件,并将其加入的监视器中
    QFile file(myDir.absolutePath()+"/myfile.txt");
    if(file.open(QIODevice::WriteOnly)){
        QFileInfo info(file);
        ui->listWidget->addItem(tr("监视的文件:")+info.absoluteFilePath());
        myWatcher.addPath(info.absolutePath());
        file.close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessage(const QString &path)
{
    QDir dir(QDir::currentPath()+"/mydir");
    if(path == dir.absolutePath()){
        ui->listWidget->addItem(dir.dirName() + tr("目录发生改变:"));
        ui->listWidget->addItems(dir.entryList());
    }else {
        ui->listWidget->addItem(path+tr("文件发生改变!"));
    }
}

