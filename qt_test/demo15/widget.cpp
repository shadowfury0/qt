#include "widget.h"
#include "ui_widget.h"
#include <QAbstractSlider>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QWindow window;
//    QPixmap grab = window.screen()->grabWindow(QApplication::desktop()->winId());
//    QLabel *label = new QLabel(this);
//    label->resize(400,200);
//    QPixmap pix = grab.scaled(label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
//    label->setPixmap(pix);
//    label->move(0,100);
    pix = QPixmap(800,600);
    pix.fill(Qt::gray);
    tempPix = pix;
    isDrawing = false;


}
void Widget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        startPoint =event->pos();
        isDrawing = true;
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        endPoint = event->pos();
        tempPix = pix;
        update();
    }
}

void Widget::setValue(double value)
{
    q_width = value;
}
void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        endPoint = event->pos();
        isDrawing = false;
        update();
    }
}
void Widget::paintEvent(QPaintEvent *event){
    //复合模式案例
//    QPainter painter;
//    QImage image(400,300,QImage::Format_ARGB32_Premultiplied);
//    painter.begin(&image);
//    painter.setBrush(Qt::green);
//    painter.drawRect(100,50,200,200);
//    painter.setBrush(QColor(0,0,255,150));
//    painter.drawRect(50,0,100,100);
//    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//    painter.drawRect(250,0,100,100);
//    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
//    painter.drawRect(50,200,100,100);
//    painter.setCompositionMode(QPainter::CompositionMode_Xor);
//    painter.drawRect(250,200,100,100);
//    painter.end();
//    painter.begin(this);
//    painter.drawImage(0,0,image);
    int x = startPoint.x();
    int y = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
//    int width = endPoint.x() - x;
//    int height = endPoint.y() - y;

    //很奇怪brush放进去不管用
//    QBrush brush;
//    brush.setColor(Qt::red);
    QPainter painter;
    QPixmap pi;
    pi.load(":/1491-2020-08-28021821-1598595501727.jpg");
    QPen pen(Qt::red,q_width);
    pen.setCapStyle(Qt::RoundCap);
    painter.begin(&tempPix);
    painter.setPen(pen);
//    painter.drawRect(x,y,width,height);
    pi=pi.scaled(width,height,Qt::IgnoreAspectRatio);
    painter.drawPixmap(x,y,width,height,pi);
//    painter.setPen(Qt::red);
//    painter.drawLine(x,y,x2,y2);
    painter.end();
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    if(!isDrawing){
        pix = tempPix;
    }
//    startPoint=endPoint;
}
Widget::~Widget()
{
    delete ui;
}
