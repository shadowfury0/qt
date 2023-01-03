
#include <QTime>
#include "myitem.h"
#include "myview.h"
#include <QApplication>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QOpenGLWidget>
int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);
    QApplication app(argc,argv);
//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene;
    scene.setSceneRect(-200,-150,400,300);

    QTimer timer;
    QObject::connect(&timer,&QTimer::timeout,&scene,&QGraphicsScene::advance);
    timer.start(300);

    for(int i=0;i<5;++i){
        MyItem *item = new MyItem;
        item->setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
        item->setPos(i*50-90,-50);
        scene.addItem(item);
    }

    MyItem * item1 = new MyItem;
    item1->setColor(Qt::blue);
    MyItem * item2 = new MyItem;
    item2->setColor(Qt::green);
    QGraphicsItemGroup * group = scene.createItemGroup(scene.selectedItems());
    group->addToGroup(item1);
    group->addToGroup(item2);
    group->setFlag(QGraphicsItem::ItemIsMovable);
    group->setPos(30,0);
    scene.addItem(group);

    MyView view;
    view.setScene(&scene);
//    QBrush * brush=new QBrush;
//    brush->setColor(QColor(Qt::blue));
//    view.setBackgroundBrush(*brush);
    view.show();

    QPixmap pixmap(400,300);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    view.render(&painter);
    painter.end();
    pixmap.save("view.png");
    view.setViewport(new QOpenGLWidget());
    return app.exec();
}
