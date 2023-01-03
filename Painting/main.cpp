#include "mainwindow.h"
#include "paint.h"

#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QtDebug>
int main(int argc, char *argv[])
{
//    qputenv("QT_SCALE_FACTOR", "2.0");
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();
    Paint p;
    p.show();

   /* Draw draw;
    draw.resize(600,600);
    draw.show()*/;
    return a.exec();
}
