#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_2_clicked();
    void mousePressEvent(QMouseEvent *event);


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
