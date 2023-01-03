#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
    void setColor(const QColor &color){brushColor=color;}
    void advance(int phase) override;
    QPainterPath shape() const override;
protected:
    void keyPressEvent(QKeyEvent *event) ;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
private:
    QColor brushColor;
};

#endif // MYITEM_H
