#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDataStream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //写入文件
//    QFile file("C:\\Users\\51341\\Desktop\\file.bbb");
//    file.open(QIODevice::WriteOnly);
//    QDataStream out(&file);
//    out << (quint32)0xA0B0C0D0;
//    out << (qint32)123;
//    out.setVersion(QDataStream::Qt_4_0);
//    out << "asdasdqwd";
//    file.close();
    //读出魔术文件
//    QFile file("C:\\Users\\51341\\Desktop\\file.bbb");
//    file.open(QIODevice::ReadOnly);
//    QDataStream in(&file);
//    quint32 magic;
//    in >> magic;
//    if(magic != 0xA0B0C0D0){
//        qDebug() << QObject::tr("文件格式不正确");
//        return 0;
//    }
//    qint32 version;
//    in >> version;
//    qDebug() << version;
//    file.close();
    return a.exec();
}
