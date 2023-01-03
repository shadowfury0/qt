#include "server.h"
#include "ui_server.h"
#include <QtNetwork>
Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));

}

Server::~Server()
{
    delete ui;
}

void Server::start()
{
    if(!tcpServer.listen(QHostAddress::LocalHost,6666)){
        qDebug() << tcpServer.errorString();
        close();
        return;
    }
    ui->pushButton->setEnabled(false);
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    ui->label->setText(tr("监听"));
    ui->progressBar->reset();
}

void Server::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(error(QAbstactSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    ui->label->setText(tr("接受连接"));
    //关闭服务器，不再进行监听
    tcpServer.close();
}

void Server::updateServerProgress()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_0);
    //如果接受到的数据小于16个字节保存到来的文件头结构
    if(bytesReceived <= sizeof (qint64)*2){
        if(tcpServerConnection->bytesAvailable()>= sizeof (qint64)*2&&(fileNameSize==0)){
            in >> totalBytes >>fileNameSize;
            bytesReceived += sizeof(qint64) *2;
        }
        if((tcpServerConnection->bytesAvailable()>=fileNameSize)&&(fileNameSize!=0)){
            //接受文件名，并建立文件
            in >> fileName;
            ui->label->setText(tr("接受文件 %1 .。。").arg(fileName));
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly)){
                qDebug() << "server: open file error!";
                return;
            }
        }else{
            return;
        }
    }
    if(bytesReceived < totalBytes){
        bytesReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesReceived);
    if(bytesReceived == totalBytes){
        tcpServerConnection->close();
        localFile->close();
        ui->pushButton->setEnabled(true);
        ui->label->setText(tr("接受文件 %1 成功").arg(fileName));
    }
}

void Server::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->progressBar->reset();
    ui->label->setText(tr("服务器就绪"));
}


void Server::on_pushButton_clicked()
{
    start();
}
