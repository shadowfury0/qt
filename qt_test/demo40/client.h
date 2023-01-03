#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QAbstractSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE
class QTcpSocket;
class QFile;
class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
private slots:
    void openFile();
    void send();
    void startTransfer();
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Client *ui;
    QTcpSocket * tcpClient;
    QFile * localFile;
    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 payloadSize;
    QString fileName;
    QByteArray outBlock;
};
#endif // CLIENT_H
