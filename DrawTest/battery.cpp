#include "battery.h"
#include <QPainter>
#include <QRect>
Battery::Battery(QWidget *parent)
{

}

Battery::~Battery()
{

}

void Battery::setPowerLevel(int pow)
{
    mPowerLevel = pow;
    emit powerLevelChanged(pow);
    repaint();
}

int Battery::powerLevel()
{
    return mPowerLevel;
}

void Battery::setWarnLevel(int warn)
{
    mWarnLevl = warn;
}

int Battery::warnLevel()
{
    return mWarnLevl;
}

QSize Battery::sizeHint() const
{
    int H = this->height();
    int W = this->width();
    QSize size(W,H);
    return size;
}

void Battery::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QRect rect(0,0,width(),height());
    painter.setViewport(rect);
    painter.setWindow(0,0,140,50);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(mColorBack);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    rect.setRect(1,1,129,48);
    painter.drawRect(rect);
    brush.setColor(mColorBorder);
    painter.setBrush(brush);
    rect.setRect(130,15,10,20);
    painter.drawRect(rect);

    if(mPowerLevel > mWarnLevl){
        brush.setColor(mColorPower);
        pen.setColor(mColorPower);
    }else {
        brush.setColor(mColorWarning);
        pen.setColor(mColorWarning);
    }
    painter.setBrush(brush);
    painter.setPen(pen);
    if(mPowerLevel > 0 ){
        rect.setRect(5,5,mPowerLevel,40);
        painter.drawRect(rect);
    }

    QFontMetrics textSize(this->font());
    QString powStr = QString::asprintf("%d%%",mPowerLevel);
    QRect textRec = textSize.boundingRect(powStr);

    painter.setFont(this->font());
    painter.setPen(pen);
    painter.drawText(55 - textRec.width() / 2 , 23+textRec.height() /2 ,powStr);
}
