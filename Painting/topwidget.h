#ifndef TOPWIDGET_H
#define TOPWIDGET_H

class QPushButton;
#include <QWidget>
class TopWidget:public QWidget
{
public:
    TopWidget(QWidget * parent = nullptr,int w = 0,int h = 0);
    ~TopWidget();
    void init();


    QPushButton *menu_btn,*pen_btn,*twD_btn,*sticker_btn,*edit_btn,*test;
private:
    int h_height = 0;int h_width = 0;

};

#endif // TOPWIDGET_H
