#include "mstyle.h"

#include <QStyleOptionButton>
#include <QPainter>
#include <QStyleFactory>

//这个东西一定要设置
//要注册到QStyleFactory类中才能进行风格的使用
MStyle::MStyle():QProxyStyle(QStyleFactory::create("windows"))
{
    //这个名称不是很重要
    setObjectName("MyStyle");
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
        QProxyStyle::drawControl(element, &myButtonOption, painter, widget);
        break;
    }
    default:
        QProxyStyle::drawControl(element,option,painter,widget);
    }
}

void MStyle::drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    switch (element) {
    case PE_PanelButtonCommand:
        {
            //这里颜色可以不用该设置阴影效果比较好
            int delta = (option->state & State_MouseOver) ? 64 : 0;
            QColor slightlyOpaqueBlack(0, 0, 0, 63);
            QColor semiTransparentWhite(255, 255, 255, 127 + delta);
            QColor semiTransparentBlack(0, 0, 0, 127 - delta);

            int x, y, width, height;
            option->rect.getRect(&x, &y, &width, &height);

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
        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
}

QColor MStyle::colorSelect(Shape::color c) const
{
    switch (c) {
    case Shape::black:
        return Qt::black;
        break;
    case Shape::white:
        return Qt::white;
        break;
    case Shape::red:
        return Qt::red;
        break;
    case Shape::darkRed:
        return Qt::darkRed;
        break;
    case Shape::blue:
        return Qt::blue;
        break;
    case Shape::darkBlue:
        return Qt::darkBlue;
        break;
    case Shape::green:
        return Qt::green;
        break;
    case Shape::darkGreen:
        return Qt::darkGreen;
        break;
    case Shape::cyan:
        return Qt::cyan;
        break;
    case Shape::darkCyan:
        return Qt::darkCyan;
        break;
    case Shape::gray:
        return Qt::gray;
        break;
    case Shape::darkGray:
        return Qt::darkGray;
        break;
    case Shape::magenta:
        return Qt::magenta;
        break;
    case Shape::darkMagenta:
        return Qt::darkMagenta;
        break;
    case Shape::yellow:
        return Qt::yellow;
        break;
    case Shape::darkYellow:
        return Qt::darkYellow;
        break;
    }
}

void MStyle::setBasicColor(Shape::color c)
{
    s_color = c;
}

QPalette MStyle::standardPalette() const
{

    QColor color(colorSelect(s_color));
    QPalette palette(color);
    QBrush brush;
    brush.setColor(Qt::blue);
    palette.setColor(QPalette::ButtonText,Qt::blue);

    m_standardPalette = palette;


    return m_standardPalette;
}
//button按钮外观设置已经做好了
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


