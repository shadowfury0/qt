#include "mstyle.h"
#include <QStyleOptionButton>
#include <QPainter>
#include <QStyleFactory>

//这个东西一定要设置
//要注册到QStyleFactory类中才能进行风格的使用
//:QCommonStyle(QStyleFactory::create("windows"))
MStyle::MStyle()
{
    //这个名称不是很重要
    setObjectName("NorwegianWood");
}

void MStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    switch (element) {
    case CE_PushButtonBevel:
    {
        QStyleOptionButton myButtonOption;
        const QStyleOptionButton *buttonOption =
                qstyleoption_cast<const QStyleOptionButton *>(option);
        if (buttonOption) {
            myButtonOption = *buttonOption;
            if (myButtonOption.palette.currentColorGroup()
                    != QPalette::Disabled) {
                if (myButtonOption.state & (State_Sunken | State_On)) {
                    myButtonOption.palette.setBrush(QPalette::ButtonText,
                            myButtonOption.palette.brightText());
                }
            }
        }
        QCommonStyle::drawControl(element, &myButtonOption, painter, widget);
        break;
    }
    default:
        QCommonStyle::drawControl(element,option,painter,widget);
    }
}

void MStyle::drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    switch (element) {
    case PE_PanelButtonCommand:
        {
        int x, y, width, height;
        option->rect.getRect(&x, &y, &width, &height);

        int delta = (option->state & State_MouseOver) ? 64 : 0;
        QColor slightlyOpaqueBlack(0, 0, 0, 63);
        QColor semiTransparentWhite(255, 255, 255, 127 + delta);
        QColor semiTransparentBlack(0, 0, 0, 127 - delta);



        QPainterPath roundRect = roundRectPath(option->rect);
        int radius = qMin(width, height) / 2;

        QBrush brush;
        bool darker;

        const QStyleOptionButton *buttonOption =
                qstyleoption_cast<const QStyleOptionButton *>(option);
        if (buttonOption
                && (buttonOption->features & QStyleOptionButton::Flat)) {
            brush = option->palette.window();
            darker = (option->state & (State_Sunken | State_On));
        } else {
            if (option->state & (State_Sunken | State_On)) {
                brush = option->palette.mid();
                darker = !(option->state & State_Sunken);
            } else {
                brush = option->palette.button();
                darker = false;
            }
        }
        painter->save();

        painter->setRenderHint(QPainter::Antialiasing, true);

        painter->fillPath(roundRect, brush);

        if (darker)
            painter->fillPath(roundRect, slightlyOpaqueBlack);

        int penWidth;

        if (radius < 10)
            penWidth = 3;
        else if (radius < 20)
            penWidth = 5;
        else
            penWidth = 7;

        QPen topPen(semiTransparentWhite, penWidth);
        QPen bottomPen(semiTransparentBlack, penWidth);

        if (option->state & (State_Sunken | State_On))
            qSwap(topPen, bottomPen);

        int x1 = x;
        int x2 = x + radius;
        int x3 = x + width - radius;
        int x4 = x + width;

        if (option->direction == Qt::RightToLeft) {
            qSwap(x1, x4);
            qSwap(x2, x3);
        }

        QPolygon topHalf;
        topHalf << QPoint(x1, y)
                << QPoint(x4, y)
                << QPoint(x3, y + radius)
                << QPoint(x2, y + height - radius)
                << QPoint(x1, y + height);

        painter->setClipPath(roundRect);
        painter->setClipRegion(topHalf, Qt::IntersectClip);
        painter->setPen(topPen);
        painter->drawPath(roundRect);

        QPolygon bottomHalf = topHalf;
        bottomHalf[0] = QPoint(x4, y + height);

        painter->setClipPath(roundRect);
        painter->setClipRegion(bottomHalf, Qt::IntersectClip);
        painter->setPen(bottomPen);
        painter->drawPath(roundRect);

        painter->setPen(option->palette.windowText().color());
        painter->setClipping(false);
        painter->drawPath(roundRect);


        painter->restore();
        }
        break;
    default:
        QCommonStyle::drawPrimitive(element, option, painter, widget);
    }
}

void MStyle::drawComplexControl(QStyle::ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const
{
    switch (control) {

    default:
        QCommonStyle::drawComplexControl(control,option,painter,widget);
    }
}

QPalette MStyle::standardPalette() const
{
    if (!m_standardPalette.isBrushSet(QPalette::Disabled, QPalette::Mid)) {
        //这里颜色设置到时候更改一下
        QColor color(200, 130, 95);
        QColor beige(236, 182, 120);
        QColor slightlyOpaqueBlack(0, 0, 0, 63);

        //只有这个设置背景才有用
        QPalette palette(color);


        palette.setBrush(QPalette::BrightText, Qt::white);
        //剩下两个不做更改
        palette.setBrush(QPalette::Base, beige);
        palette.setBrush(QPalette::Highlight,Qt::darkGreen);


        QBrush brush = palette.window();
//        brush.setColor(brush.color().darker());
        brush.setColor(Qt::white);
        palette.setBrush(QPalette::ButtonText,brush);
//        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
//        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
//        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
//        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
//        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
//        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);

        m_standardPalette = palette;
    }

    return m_standardPalette;
}

QPainterPath MStyle::roundRectPath(const QRect &rect)
{
    int radius = qMin(rect.width(), rect.height()) / 2;
    int diam = 2 * radius;

    int x1, y1, x2, y2;
    rect.getCoords(&x1, &y1, &x2, &y2);

    QPainterPath path;
    path.moveTo(x2, y1 + radius);
    path.arcTo(QRect(x2 - diam, y1, diam, diam), 0.0, +90.0);
    path.lineTo(x1 + radius, y1);
    path.arcTo(QRect(x1, y1, diam, diam), 90.0, +90.0);
    path.lineTo(x1, y2 - radius);
    path.arcTo(QRect(x1, y2 - diam, diam, diam), 180.0, +90.0);
    path.lineTo(x1 + radius, y2);
    path.arcTo(QRect(x2 - diam, y2 - diam, diam, diam), 270.0, +90.0);
    path.closeSubpath();
    return path;
}







