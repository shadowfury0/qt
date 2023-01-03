#ifndef WIDGET_H
#define WIDGET_H

#include "mylineedit.h"

#include <QWidget>
#include "QDebug"
#include "QKeyEvent"
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget;class MyLineEdit; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent *event) ;

    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
    Ui::Widget *ui;
    MyLineEdit * lineEdit;

    QPoint  offset;
};
#endif // WIDGET_H
