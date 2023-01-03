#include "widget.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QVariant v1(15);
//    qDebug() << v1.toInt();
//    QVariant v2(12.3);
//    qDebug() << v2.toFloat();
//    QVariant v3("nihao");
//    qDebug() << v3.toString();
//    QColor color = QColor(Qt::red);
//    QVariant v4 = color;
//    qDebug() << v4.type();
//    qDebug() << v4.value<QColor>();
//    QString str = "hello";
//    QVariant v5 = str;
//    qDebug() << v5.canConvert(QVariant::Int);
//    qDebug() << v5.toString();
//    qDebug() << v5.convert(QVariant::Int);
//    qDebug() << v5.toString();
//    QRegExp rx("^\\d\\d?$");
//    qDebug() << rx.indexIn("a1");
//    qDebug() << rx.indexIn("5");
//    qDebug() << rx.indexIn("5b");
//    qDebug() << rx.indexIn("12");
//    qDebug() << rx.indexIn("123");
//    qDebug() << "********************";
//    rx.setPattern("\\b(mail|letter)\\b");
//    qDebug() << rx.indexIn("emailletter");
//    qDebug() << rx.indexIn("my mail");
//    qDebug() << rx.indexIn("my email letter");
//    qDebug() << "**************************";
//    rx.setPattern("M(?!ail)");
//    QString str1 = "this is M";
//    str1.replace(rx,"Mail");
//    qDebug() << "str1 : "<<str1;
//    QString str2 = "my M ,your M his Mail";
//    str2.replace(rx,"Mail");
//    qDebug() << "str2 : " << str2;
//    QString str3 = "One Eric another Eirik,and anEricsson";
//    "How many Eiriks ,Eric?";
//    QRegExp rx2("\\bEi? ri[ck]\\b");
//    int pos = 0;
//    int count = 0;
//    while (pos >= 0) {
//        pos = rx2.indexIn(str3,pos);
//        if(pos>=0){
//            ++pos;
//            ++count;
//        }
//    }
//    qDebug() << "count: " << count;
    QRegExp rx5("\\b(\\w+)\\W+\\1\\b");
    rx5.setCaseSensitivity(Qt::CaseInsensitive);
    qDebug() << rx5.indexIn("Hello--hello");
    qDebug() << rx5.cap(0);
    qDebug() << rx5.cap(1);
    qDebug() << "********************";
    QRegExp rx6("(\\w+)@\\1");
    qDebug() << rx6.indexIn("asdf@");
    qDebug() << rx6.indexIn("asdf@asdf");
    //Widget w;
    //w.show();
    //return a.exec();
    return 0;
}
