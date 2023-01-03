#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QGraphicsScene scene;
    QTextEdit * edit = new QTextEdit;
    QPushButton * button = new QPushButton("clear");
    QObject::connect(button,SIGNAL(clicked()),edit,SLOT(clear()));
    QGraphicsWidget * textEdit = scene.addWidget(edit);
    QGraphicsWidget * pushButton = scene.addWidget(button);
    QGraphicsLinearLayout * layout = new QGraphicsLinearLayout;
    layout->addItem(textEdit);
    layout->addItem(pushButton);
    QGraphicsWidget * from = new QGraphicsWidget;
    from->setLayout(layout);
    from->setWindowTitle("Widget Ttem");
    from->setWindowFlags(Qt::Window);
    //将图形部件进行扭曲
    from->setTransform(QTransform().shear(2,-0.5),true);
    scene.addItem(from);
    QGraphicsView view(&scene);
    view.show();
    return app.exec();
}
