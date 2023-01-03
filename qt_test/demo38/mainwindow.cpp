#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "localHostName: " << localHostName << endl
             << "IP Address: " << info.addresses();
    foreach(QHostAddress address,info.addresses()){
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            qDebug() << address.toString();
    }
    qDebug() << "-----------------------" << endl;
//    QHostInfo::lookupHost("www.baidu.com",this,SLOT(lookedUp(QHostInfo)));

    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    //遍历每一个网络接口
    foreach(QNetworkInterface interface,list)
    {
        qDebug() << "Name: " << interface.name();
        qDebug() << "HardwareAddress: " << interface.hardwareAddress();
        QList <QNetworkAddressEntry> entryList = interface.addressEntries();
        foreach(QNetworkAddressEntry entry,entryList){
            qDebug() << "IP Address: " << entry.ip().toString();
            qDebug() << "Netmask: " << entry.netmask().toString();
            qDebug() << "Broadcast: " << entry.broadcast().toString();
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lookedUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError){
        qDebug() << "Lookup fialed: " << host.errorString();
    }
    foreach(const QHostAddress &address,host.addresses())
        qDebug() << "Found address: " << address.toString();
}

