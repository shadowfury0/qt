#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QGraphicsView>
#include "myview.h"
#include "myitem.h"
int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

//    QApplication app(argc,argv);

//    QGraphicsScene scene;
//    MyItem * item =new MyItem;
//    QGraphicsRectItem * item = new QGraphicsRectItem(0,0,100,100);
//    scene.addItem(item);
//    qDebug() << scene.itemAt(50,50,QTransform());


//    QGraphicsScene scene2;
//    QGraphicsRectItem * item2 = new QGraphicsRectItem(0,0,200,200);
//    scene2.addItem(item2);

    //创造视图
//    QGraphicsView view(&scene);
//    view.setForegroundBrush(QColor(255,255,0,100));
//    view.resize(400,300);
//    view.show();

//    QGraphicsView view2(&scene2);
//    view2.resize(400,300);
//    view2.show();

    //
    QApplication app(argc,argv);
    QGraphicsScene scene;
    MyItem * item = new MyItem;
    scene.addItem(item);
    item->setPos(10,10);
    QGraphicsItem * rectItem = scene.addRect(QRect(0,0,100,100),QPen(Qt::blue),QBrush(Qt::green));
    rectItem->setPos(20,20);
    MyView view;
    view.setScene(&scene);
    view.setForegroundBrush(QColor(255,255,0,100));
    view.resize(400,400);
    view.show();
    return app.exec();
}
