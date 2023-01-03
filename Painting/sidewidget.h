#ifndef SIDEWIDGET_H
#define SIDEWIDGET_H
#include "draw.h"

#include <QWidget>

class QPushButton;
class QLineEdit;
class QSlider;
class QLabel;
class QGridLayout;
class SideWidget :public QWidget
{
public:
    SideWidget(QWidget * parent = nullptr,int tmpCustomW=0,int h=0);
    ~SideWidget();

    void reSize(int tmpCustomW,int h);
    //为了方便外部访问就暂时不加private写函数了
    //画笔的三个widget
    //三个组件设计
    QWidget * topWidget;
    QWidget * centerWidget;
    QWidget * bottomWidget;
    //2D的两个组件
    QWidget * lineCurveWidget;
    QWidget * shapeWidget;
    //贴纸页面
    QWidget * sSelectWidget;
    QWidget * sContentWidget;
    //编辑页面
    QWidget * sEditWidget;
    //侧边框标签
    QLabel *side_label;
    int s_height ;
    int s_width  ;
    //侧边滑块的事件
    QSlider *s_slider1;
    QSlider *s_slider2;
    //设置两个lineEdit显示值
    QLineEdit *s_pixel1;
    QLineEdit *s_pixel2;
    //普通笔选择
    QPushButton * s_b1,* s_b2,* s_b3,* s_b4,
                * s_b5,* s_b6,* s_b7,* s_b8;
    //颜色类需要的控件
    //颜色组
    QPushButton *cb1,*cb2,*cb3,*cb4,*cb5,*cb6,
            *cb7,*cb8,*cb9,*cb10,*cb11,*cb12,
            *cb13,*cb14,*cb15,*cb16;
    //颜色提取以及颜色选择
    QPushButton *extract,*var_color;
    //2D图形直线的类选择
    QPushButton *lc1,*lc2,*lc3,*lc4;
    //2D图形形状的类选择
    QPushButton *shape1,* shape2,* shape3,* shape4,* shape5,
                *shape6,* shape7,* shape8,* shape9,* shape10;
    //贴纸类型选择
    QPushButton *texture1,*texture2,*texture3;
    //自带贴纸类型
    QPushButton *cs_btn1,*cs_btn2,*cs_btn3,*cs_btn4,*cs_btn5,
                *cs_btn6,*cs_btn7,*cs_btn8,*cs_btn9,*cs_btn10;

    //------------------------------------------------------
    //自定义贴纸标签
    QScrollArea * scrollArea;
    QLabel *userLabel;
    QPushButton *userAdd_btn;
    //贴纸临时widget组件
    QWidget *tmpCustomW;
    QWidget *tmpUserW;
    //布局设置
    QGridLayout *glayout;
    //用户添加的按钮移动高度设置
    int userSMove = 0;
    //------------------------------------------------------
    //编辑模式
    QPushButton *select_btn;
    QPushButton *draw_btn;
public:
    void init();
    void createCentralWidget();
    //画笔颜色框清除
    void clearSideSubWidget();
    void clearSideWidget();
    void clearStickerWidget();
    //-----------------------------------------
    //初始化画笔选择框
    void paintingWidget();
    //顶部选择框更换
    void topPenWidget();
    //底部边框颜色更换
    void bottomColorWidget();
    //相似的类都可以选择这个 暂时没想到很好的办法
    void penWidget();
    //橡皮特殊选择
    void rubberWidget();
    //铅笔类
    void pencilWidget();
    //----------------------------------------
    void twoDWidget();
    //直线和曲线类
    void lineWidget();
    void twoDShapeWidget();
    //----------------------------------------
    //贴纸类
    void stickerWidget();
    void stickerSelectWidget();
    void customSticker();
    void userSticker();
    //----------------------------------------
    //编辑类
    void editWidget();
};

#endif // SIDEWIDGET_H
