#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void timeEvent(QTimerEvent* event);
private:
    Ui::Widget *ui;
    int id1,id2,id3;
private slots:
    void timerUpdate();
};
#endif // WIDGET_H
