#include "scroll.h"
#include <QPen>
#include <QPainter>
Scroll::Scroll(QWidget *parent) : QAbstractScrollArea(parent)
{

}

Scroll::~Scroll()
{

}

void Scroll::paintEvent(QPaintEvent *)
{

}

void Scroll::dragMoveEvent(QDragMoveEvent *)
{

}

ScrollArea::ScrollArea(QWidget *parent):QWidget(parent)
{

}

ScrollArea::~ScrollArea()
{

}

void ScrollArea::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setColor(Qt::red);
    QBrush brush;
    brush.setColor(Qt::green);
    QPainter painter;
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawPoint(900,700);
}
