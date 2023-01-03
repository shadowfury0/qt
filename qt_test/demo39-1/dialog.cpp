#include "dialog.h"
#include "ui_dialog.h"
#include <QtNetwork>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    receiver = new QUdpSocket(this);
    receiver->bind(45454,QUdpSocket::ShareAddress);
    connect(receiver,&QUdpSocket::readyRead,this,&Dialog::processPendingDatagram);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::processPendingDatagram()
{
    while (receiver->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(),datagram.size());
        ui->label->setText(datagram);
    }
}

