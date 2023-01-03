#include "client.h"
#include "ui_client.h"
#include <QtNetwork>
#include <QFileDialog>
Client::Client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    payloadSize = 64*1024; //64kb
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    tcpClient = new QTcpSocket(this);
    //连接服务器成功时,会发出connected信号,开始传送文件
    connect(tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    connect(tcpClient,SIGNAL(byteWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    ui->pushButton_2->setEnabled(false);
}

Client::~Client()
{
    delete ui;
}

void Client::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        ui->pushButton_2->setEnabled(true);
        ui->label_3->setText(tr("打开文件 %1 成功！").arg(fileName));
    }
}

void Client::send()
{
    ui->pushButton_2->setEnabled(false);
    bytesWritten = 0;
    ui->label_3->setText(tr("连接中"));
    tcpClient->connectToHost(ui->label->text(),ui->label_2->text().toInt());
}

void Client::startTransfer()
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly)){
        qDebug() << "client : open file error!";
        return;
    }
    totalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_0);
    QString currentFileName = fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
    //保留总大小信息空间。文件名大小信息空间，然后输入文件名
    sendOut << qint64(0) << qint64(0) << currentFileName;
    //这里的总大小是总大小信息，文件名大小信息、文件名实际文件大小的总和
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    //返回outBlock的开始，用实际的大小信息替代两个qint64(0)空间
    sendOut << totalBytes << qint64(outBlock.size()-sizeof (qint64)*2);
    //发送完成文件结构后剩余数据的大小
    bytesToWrite = totalBytes -tcpClient->write(outBlock);
    ui->label_3->setText(tr("已连接"));
    outBlock.resize(0);
}

void Client::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    //如果已经发送了数据
    if(bytesToWrite>0){
        //每次发送payloadSize大小的数据，这里设置为64KB，如果剩余的数据不足64KB
        //就发送剩余数据的大小
        outBlock = localFile->read(qMin(bytesToWrite,payloadSize));
        //发送完一次数据后还剩余数据的大小
        bytesToWrite -= (int)tcpClient->write(outBlock);
        //清空发送缓冲区
        outBlock.resize(0);
    }else{
        localFile->close();
    }
    //更新进度条
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesWritten);
    //如果发送完毕
    if(bytesWritten == totalBytes){
        ui->label_3->setText(tr("传送文件 %1 成功").arg(fileName));
        localFile->close();
        tcpClient->close();
    }
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpClient->errorString();
    tcpClient->close();
    ui->progressBar->reset();
    ui->label_3->setText(tr("客户端准备就绪"));
    ui->pushButton_2->setEnabled(true);
}


void Client::on_pushButton_clicked()
{
    ui->progressBar->reset();
    ui->label_3->setText(tr("状态：等待打开文件"));
    openFile();
}

void Client::on_pushButton_2_clicked()
{
    send();
}
