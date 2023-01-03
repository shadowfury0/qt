#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDesktopWidget>
#include <QWindow>
#include <QScreen>
#include <QMouseEvent>
#include <QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setValue(double value);
protected:
    void paintEvent(QPaintEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QPixmap pix;
    QPixmap tempPix;
    QPoint startPoint;
    QPoint endPoint;
    bool isDrawing;

    bool is=false;

    double q_width;
};
#endif // WIDGET_H
