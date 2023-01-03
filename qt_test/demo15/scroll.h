#ifndef SCROLL_H
#define SCROLL_H
#include <QAbstractScrollArea>

class ScrollArea;
class Scroll:public QAbstractScrollArea
{
    Q_OBJECT
public:
    Scroll(QWidget * parent = nullptr);
    ~Scroll();

    void paintEvent(QPaintEvent *) override;
    void dragMoveEvent(QDragMoveEvent *) override;
private:
    ScrollArea *scrollArea;
};

class ScrollArea:public QWidget
{
    Q_OBJECT
public:
    ScrollArea(QWidget * parent = nullptr);
    ~ScrollArea();

    void paintEvent(QPaintEvent *event) override;
};

#endif // SCROLL_H
