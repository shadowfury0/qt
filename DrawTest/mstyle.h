#ifndef MSTYLE_H
#define MSTYLE_H
#include <QCommonStyle>
#include <QProxyStyle>
class MStyle: public QProxyStyle
{
    Q_OBJECT
public:
    MStyle();
    void drawControl(ControlElement element, const QStyleOption *option,
                     QPainter *painter, const QWidget *widget = nullptr) const override;
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget = nullptr) const override;
    void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                            QPainter *painter, const QWidget *widget = nullptr) const override;
    QPalette standardPalette() const override;
//    SubControl hitTestComplexControl(ComplexControl cc,
//                                     const QStyleOptionComplex *opt, const QPoint &pt
//                                     , const QWidget *w = nullptr) const override;

private:
    static QPainterPath roundRectPath(const QRect &rect);

    mutable QPalette m_standardPalette;
};

#endif // MSTYLE_H
