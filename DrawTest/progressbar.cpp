#include "progressbar.h"
#include <QStylePainter>
#include <QStyleOptionProgressBar>
progressBar::progressBar(QWidget *parent)
{

}

progressBar::~progressBar()
{

}

void progressBar::paintEvent(QPaintEvent *)
{
    QStylePainter paint(this);
    QStyleOptionProgressBar opt;
    initStyleOption(&opt);
    paint.drawControl(QStyle::CE_ProgressBar,opt);
}

