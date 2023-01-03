#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractSocket>
#include <QTcpServer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class QTcpServer;
class QFile;
class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private:
    Ui::Widget *ui;
    QTcpServer tcpServer;
    QTcpSocket * tcpServerConnection;
    qint64 totalBytes;//存放总大小信息
    qint64 bytesReceived;//已收到数据的大小
    qint64 fileNameSize;//文件名大小信息
    QString fileName;//存放本地文件
    QFile * localFile;//本地文件
    QByteArray inBlock;//数据缓冲区
private slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);
    void on_pushButton_clicked();
};
#endif // WIDGET_H
