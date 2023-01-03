#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(100,100);

    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);
    //设置鼠标跟踪
    setMouseTracking(true);
}
void Widget::keyPressEvent(QKeyEvent *event){
    qDebug()<<tr("键盘按下事件");
}
void Widget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        QPoint temp;
        temp = event->globalPos() - offset;
        move(temp);
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *event){
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}
void Widget::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        if(windowState() !=Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);
    }
}
void Widget::wheelEvent(QWheelEvent *event){
    if(event->delta() > 0){
        ui->textEdit->zoomIn();
    }else {
        ui->textEdit->zoomOut();
    }
}
Widget::~Widget()
{
    delete ui;
}

