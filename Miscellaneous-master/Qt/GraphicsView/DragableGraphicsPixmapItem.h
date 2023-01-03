#ifndef GRAPHICSPIXMAPITEM_H
#define GRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QCursor>
#include <QDebug>

class DragableGraphicsPixmapItem : public QGraphicsPixmapItem
{
public:
    DragableGraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = Q_NULLPTR)
        : QGraphicsPixmapItem(pixmap, parent)
        , m_pressed(false)
    {
        setCursor(QCursor(Qt::PointingHandCursor));
        setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        setAcceptDrops(false);
    }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool    m_pressed;
};

#endif // GRAPHICSPIXMAPITEM_H
