#ifndef SCROLL_H
#define SCROLL_H

#include <QPushButton>
#include <QAbstractSlider>
class ScrollButton;
class ScrollLine;
class Scroll:public QWidget
{
    Q_OBJECT
public:
    Scroll(QWidget * parent = nullptr);
    ~Scroll();

    void paintEvent(QPaintEvent *) override;

    void reSize(int w,int h);
    void setHeight(int h);
    int  getHeight();
    void setWidth(int w);
    int  getWidth();
private:
    int s_height;
    int s_width;

    ScrollButton *scrollButton;
    ScrollLine * scrollLine;
};

class ScrollButton:public QWidget
{
    Q_OBJECT
public:
    ScrollButton(QWidget * parent = nullptr);
    ~ScrollButton();
private:
    void paintEvent(QPaintEvent *event) override;
public:
    void reSize(int w,int h);
    void setHeight(int h);
    int  getHeight();
    void setWidth(int w);
    int  getWidth();

public slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void valueChanged(int value);
private:
    int b_height;
    int b_width;

    QPoint offset;
};
class ScrollLine:public QWidget
{
    Q_OBJECT
public:
    ScrollLine(QWidget * parent = nullptr);
    ~ScrollLine();
public slots:
    //反转该图形
    void reverse();
public:
    void reSize(int w,int h);
    void setHeight(int h);
    int  getHeight();
    void setWidth(int w);
    int  getWidth();

private:
    void paintEvent(QPaintEvent *event) override;
private:
    int l_height;
    int l_width;
};

#endif // SCROLL_H
