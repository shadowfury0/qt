#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent * event);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MyWidget *ui;

    QPixmap pix;
    QPixmap temp;
    QPixmap lastTemp;
    QPixmap lastP;
    QPoint start;
    QPoint end;
    //保存上一次位置
    QPoint start1 = QPoint(0,0);
    QPoint end1 = QPoint(0,0);
    bool isDrawing;
    bool isSelect;
    bool isPicking;
    bool isDragging;

    int size ;
    bool isPressed = false;
};

#endif // MYWIDGET_H
