#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QList>
#include <QListIterator>
#include <QMutableListIterator>
#include <QMap>
#include <QMapIterator>
#include <QMultiMap>
#include <QMutableMapIterator>
#include <QCoreApplication>
#include <QVector>
#include <QStringList>
#include <algorithm>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //容器类测试
//    QList <QString> list;
//    list << "aa" << "bb" <<"cc";
//    if(list[1] == "bb") list[1] = "ab";
//    list.replace(2,"bc");
//    qDebug() << "the list is";
//    for(int i=0;i<list.size();i++){
//        qDebug() << list.at(i);
//    }
//    list.append("dd");
//    list.prepend("mm");
//    QString str = list.takeAt(2);
//    qDebug() << "at(2) item is:" <<str;
//    qDebug() << "the list is:";
//    for(int i=0;i<list.size();i++){
//        qDebug() << list.at(i);
//    }
//    list.insert(2,"mm");
//    list.swap(1,3);
//    qDebug()<< "the list is:";
//    for(int i=0;i<list.size();i++){
//        qDebug() << list.at(i);
//    }
//    qDebug()<<"contains 'mm'"<<list.contains("mm");
//    qDebug()<< "the 'mm' count:"<<list.count("mm");
//    qDebug()<< "the first 'mm' index:" << list.indexOf("mm");
//    qDebug()<< "the second 'mm' index:"<<list.indexOf("mm",1);
//    QMap<QString,int> map;
//    map["one"] = 1;
//    map["three"] = 3;
//    map.insert("seven",7);
//    int value1 = map["six"];
//    qDebug() << "value1: "<<value1;
//    qDebug() << "contains six ?"<<map.contains("six");
//    int value2 = map.value("five");
//    qDebug() << "value2 :" << value2;
//    qDebug() << "contains 'five' ?" << map.contains("five");
//    int value3 = map.value("nine",9);
//    qDebug() << "value3 :"<<value3;
//    map.insert("ten",10);
//    map.insert("ten",100);
//    qDebug() << "ten :"<<map.value("ten");
//    map.insertMulti("two",2);
//    map.insertMulti("two",4);
//    QList<int> values = map.values("two");
//    qDebug()<< "two :"<<values;
//    QMultiMap<QString,int> map1,map2,map3;
//    map1.insert("values",1);
//    map2.insert("values",2);
//    map3.insert("values",3);
//    map3 = map2 + map1;
//    QList<int> myValues = map3.values("values");
//    qDebug() << "the values are :";
//    for(int i=0; i<myValues.size();i++){
//        qDebug()<<myValues.at(i);
//    }

//    QList <QString> list;
//    list << "A" << "B" << "C" << "D";
//    QListIterator<QString>i(list);
//    qDebug() << "the forwards: ";
//    while (i.hasNext()) {
//        qDebug() << i.next();
//    }
//    qDebug() << "the backwards :";
//    while (i.hasPrevious()) {
//        qDebug()<<i.previous();
//    }
//    qDebug() << "-----------------------";
//    QMutableListIterator<QString>j(list);
//    j.toBack();
//    while (j.hasPrevious()) {
//        QString str = j.previous();
//        if(str == "B") j.remove();
//    }
//    j.insert("Q");
//    j.toBack();
//    if(j.hasPrevious()) j.previous() = "N";
//    j.previous();
//    j.setValue("M");
//    j.toFront();
//    qDebug() << "the forward is:";
//    while(j.hasNext()) qDebug() << j.next();
//    QMap<QString,QString> map;
//    map.insert("Paris","France");
//    map.insert("Moscow","Russia");
//    map.insert("Mexico City","Mexico");
//    map.insert("Guatemala City","Guatemala");
//    QMapIterator<QString,QString>i(map);
//    while (i.hasNext()) {
//        i.next();
//        qDebug()<<i.key()<<" : "<<i.value();
//    }
//    if(i.findPrevious("Mexico")) qDebug()<<"find Mexico";
//    QMutableMapIterator<QString,QString>j(map);
//    while (j.hasNext()) {
//        if(j.next().key().endsWith("City"))
//            j.remove();
//    }
//    while (j.hasNext()) {
//        j.previous();
//        qDebug() << j.key() << " : " << j.value();
//    }
    QStringList list;
    list << "one" << "two" << "three";
    qDebug() << QObject::tr("std::copy算法");
    QVector<QString> vect(3);
    std::copy(list.begin(),list.end(),vect.begin());
    qDebug() << vect;
    qDebug() << endl << QObject::tr("std::equal算法");
    bool ret1 = std::equal(list.begin(),list.end(),vect.begin());
    qDebug() << "eqaul: "<<ret1;
    qDebug() << endl << QObject::tr("std::find算法");
    QList<QString>::iterator i = std::find(list.begin(),list.end(),"two");
    qDebug() << *i;
    qDebug() << endl <<QObject::tr("std::fill算法");
    std::fill(list.begin(),list.end(),"eleven");
    qDebug() << list;
    QList<int> list1;
    list1 << 3 << 3 << 6 << 6<<6 <<8;
    qDebug() << endl <<QObject::tr("std::count算法");
    int countOf6 = std::count(list1.begin(),list1.end(),6);
    qDebug() <<  "countOf6" <<countOf6;
    qDebug() << endl <<QObject::tr("std::lower_bound算法 :");
    QList<int>::iterator j =std::lower_bound(list1.begin(),list1.end(),5);
    list1.insert(j,5);
    qDebug() <<list1;
    QList<int> list2;
    list2 << 33 << 12 << 68 << 12;
    qDebug() << endl <<QObject::tr("std::sort算法");
    std::sort(list2.begin(),list2.end());
    qDebug() << endl << QObject::tr("std::stable_sort算法");
    //Widget w;
    //w.show();
    return a.exec();
}
