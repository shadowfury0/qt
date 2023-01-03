#include "scroll.h"
#include <QtDebug>
#include <QPen>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
Scroll::Scroll(QWidget *parent) : QWidget(parent)
{
    s_height = 0;
    s_width  = 0;

    scrollLine = new ScrollLine(this);
    scrollButton = new ScrollButton(this);
}

Scroll::~Scroll()
{
    delete scrollLine;
    delete scrollButton;
}

void Scroll::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawRect(0,0,s_width,s_height);
    painter.setPen(QPen(Qt::gray));
    painter.setBrush(Qt::gray);
}

void Scroll::reSize(int w, int h)
{
    s_height = h;
    s_width  = w;
    this->resize(w,h);
    scrollLine->reSize(s_width,s_height/2);
    scrollLine->move(0,s_height/4);
    scrollButton->reSize(s_height,s_height);
}

void Scroll::setHeight(int h)
{
    s_height = h;
}

int Scroll::getHeight()
{
    return s_height;
}

void Scroll::setWidth(int w)
{
    s_width = w;
}

int Scroll::getWidth()
{
    return s_width;
}

ScrollButton::ScrollButton(QWidget *parent):QWidget(parent)
{
    b_height = 0;
    b_width  = 0;
}

ScrollButton::~ScrollButton()
{

}

void ScrollButton::paintEvent(QPaintEvent *)
{
//    QPen pen(Qt::green,4);
//    QBrush brush(Qt::green);
    QPainter painter(this);
    QPainterPath path;
    path.addEllipse(0,0,b_width,b_height);
    painter.setBrush(Qt::green);
    painter.setPen(Qt::green);
//    painter.setBrush(brush);
//    painter.setPen(pen);
    painter.drawPath(path);
}

void ScrollButton::reSize(int w,int h)
{
    b_width  = w;
    b_height = h;
    //只能通过这一种方式进行切换大小否则会画图不全
    this->resize(b_height,b_width);
}

void ScrollButton::setHeight(int h)
{
    b_height = h;
}

int ScrollButton::getHeight()
{
    return b_height;
}

void ScrollButton::setWidth(int w)
{
    b_width = w;
}

int ScrollButton::getWidth()
{
    return b_width;
}

void ScrollButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        offset = event->pos();
        qDebug()<< "parent  x:  " << offset.x() << "y: " <<offset.y();
        qDebug()<< "x : "<< this->x() << "y :" << this->y();
    }
}

void ScrollButton::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        move(offset.x(),offset.y());
        offset = event->pos();
    }
}

void ScrollButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}


void ScrollButton::valueChanged(int value)
{

}

ScrollLine::ScrollLine(QWidget *parent):QWidget(parent)
{
    l_width = 0;
    l_height = 0;
}

ScrollLine::~ScrollLine()
{

}

void ScrollLine::reSize(int w, int h)
{
    l_width  = w;
    l_height = h;
    this->resize(w,h);
}

void ScrollLine::setHeight(int h)
{
    l_height = h;
}

int ScrollLine::getHeight()
{
    return l_height;
}

void ScrollLine::setWidth(int w)
{
    l_width = w;
}

int ScrollLine::getWidth()
{
    return l_width;
}

void ScrollLine::reverse()
{
    int temp = l_height;
    setHeight(l_width);
    setWidth(temp);
    this->resize(l_width,l_height);
}

void ScrollLine::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPainterPath path;
    path.addRect(0,0,l_width,l_height);
    painter.setBrush(Qt::gray);
    painter.setPen(Qt::gray);
    painter.drawPath(path);
}
