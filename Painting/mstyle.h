#ifndef MSTYLE_H
#define MSTYLE_H

#include "Shape.h"

#include <QProxyStyle>
//#include <QCommonStyle>
//这个类目前实验成功
class MStyle: public QProxyStyle
{
    Q_OBJECT
public:
    MStyle();
    //------------------------------------
    //继承方法
    void drawControl(ControlElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget = nullptr) const override;
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget = nullptr) const override;
    QPalette standardPalette() const override;
    //--------------------------------------
    void setBasicColor(Shape::color c);

private:
    static QPainterPath roundRectPath(const QRect &rect);
    QColor colorSelect(Shape::color color) const;


    Shape::color s_color = Shape::color::white;
    mutable QPalette m_standardPalette;
};

#endif // MSTYLE_H
