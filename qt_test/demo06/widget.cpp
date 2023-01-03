#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),keyUp(false),keyLeft(false),move(false)
{
    ui->setupUi(this);
    setFocus();
}
void Widget::keyPressEvent(QKeyEvent *event){
//    if(event->modifiers() == Qt::ControlModifier){
//        if(event->key() == Qt::Key_M){//是否按下M键
//            setWindowState(Qt::WindowMaximized);
//        }else{
//            QWidget::keyPressEvent(event);
//        }
//    }
//    if(event->key() == Qt::Key_Up){
//        qDebug()<<"press"<<event->isAutoRepeat();
//    }
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat()) return;
        keyUp=true;
    }else if(event->key() == Qt::Key_Left){
        if (event->isAutoRepeat()) return;
        keyLeft=true;
    }
}
void Widget::keyReleaseEvent(QKeyEvent *event){
    //setWindowState(Qt::WindowMinimized);
//    if(event->key() == Qt::Key_Up){
//        qDebug()<<"release" <<event->isAutoRepeat();
//        qDebug()<<"up";
//    }
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat()) return;
        keyUp=false;
        if(move){
            move = false;
            return;
        }
        if(keyLeft){
            ui->pushButton->move(30,80);
            move=true;
        }else{
            ui->pushButton->move(120,80);
        }
    }else if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat()) return;
        keyLeft = false;
        if(move){
            move = false;
            return;
        }
        if(keyUp){
            ui->pushButton->move(30,80);
            move=true;
        }else{
            ui->pushButton->move(30,120);
        }
    }
}
Widget::~Widget()
{
    delete ui;
}

