#include "topwidget.h"
#include <QPushButton>
TopWidget::TopWidget(QWidget *parent, int w, int h):QWidget(parent)
{
    h_width = w;h_height = h;
    this->resize(w,h);
    this->setObjectName("topWidget");
    this->setStyleSheet("#topWidget{background-color:gray}");

    init();
}

TopWidget::~TopWidget()
{
    delete menu_btn;
    delete pen_btn;
    delete twD_btn;
    delete sticker_btn;
    delete edit_btn;
    delete test;
}

void TopWidget::init()
{

    int m_height = h_height;
    int m_width  = h_width/13;
    //菜单
    this->menu_btn = new QPushButton(this);
    this->menu_btn ->resize(m_width,m_height);
    this->menu_btn ->setText(tr("菜单栏按钮"));
    //画笔
    this->pen_btn = new QPushButton(this);
    this->pen_btn->resize(m_width,m_height);
    this->pen_btn ->move(m_width*2,0);
    this->pen_btn ->setText(tr("画笔"));

    //2D图形
    this->twD_btn = new QPushButton(this);
    this->twD_btn ->resize(m_width,m_height);
    this->twD_btn ->move(m_width*3,0);
    this->twD_btn ->setText(tr("2D图形"));

    //贴纸
    this->sticker_btn = new QPushButton(this);
    this->sticker_btn->resize(m_width,m_height);
    this->sticker_btn->move(m_width*4,0);
    this->sticker_btn->setText(tr("贴纸"));

    //编辑
    this->edit_btn = new QPushButton(this);
    this->edit_btn->resize(m_width,m_height);
    this->edit_btn->move(m_width*5,0);
    this->edit_btn->setText(tr("编辑"));
    //测试
    this->test = new QPushButton(this);
    this->test ->resize(m_width,m_height);
    this->test ->move(this->width()-m_width,0);
}
