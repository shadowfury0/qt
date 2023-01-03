#include "sidewidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QSlider>
#include <QScrollArea>
#include <QGridLayout>
#include <QFile>
SideWidget::SideWidget(QWidget *parent,int w,int h):QWidget(parent)
{
    this->setObjectName("sidewidget");
    this->setStyleSheet("#sidewidget{background-color:gray}");
    this->reSize(w,h);

//    paintingWidget();
    //初始化部件方法
    init();
}

SideWidget::~SideWidget()
{
    /**
      安全起见都进行回收
      **/
    delete topWidget;
    delete centerWidget;
    delete bottomWidget;
    delete side_label;
    //颜色相关的删除有点冗余
    delete cb1;delete cb2; delete cb3 ;delete cb4; delete cb5; delete cb6;
    delete cb7;delete cb8; delete cb9 ;delete cb10;delete cb11;delete cb12;
    delete cb13;delete cb14;delete cb15;delete cb16;
    delete extract;delete var_color;
    //画笔选择
    delete s_b1;delete s_b2;delete s_b3;delete s_b4;
    delete s_b5;delete s_b6;delete s_b7;delete s_b8;
    //2D
    delete lineCurveWidget;
    delete shapeWidget;
    delete lc1;delete lc2;delete lc3;delete lc4;
    delete shape1;delete shape2;delete shape3;delete shape4;delete shape5;
    delete shape6;delete shape7;delete shape8;delete shape9;delete shape10;
    //贴纸
    delete sSelectWidget;
    delete sContentWidget;
    delete texture1;delete texture2;delete texture3;

    delete cs_btn1;delete cs_btn2;delete cs_btn3;delete cs_btn4;delete cs_btn5;
    delete cs_btn6;delete cs_btn7;delete cs_btn8;delete cs_btn9;delete cs_btn10;

    delete scrollArea;
    delete userLabel;
    delete userAdd_btn;
    delete tmpCustomW; delete tmpUserW;
    delete glayout;
    //编辑
    delete sEditWidget;
    delete select_btn;delete draw_btn;
}

void SideWidget::init()
{

}

void SideWidget::createCentralWidget()
{
    centerWidget = new QWidget(this);
    centerWidget->setStyleSheet("background-color: rgb(250,60, 105);");
    centerWidget->setVisible(true);
    centerWidget->move(0,s_height*3/10);
    centerWidget->resize(s_width,s_height*4/10);
}

void SideWidget::clearSideSubWidget()
{

    //这个方法才是可以删除所有的子控件
    QList<QWidget*> qobj = this->centerWidget->findChildren<QWidget*>();
    foreach (QWidget* i, qobj) {
        i->deleteLater();
    }
}

void SideWidget::clearSideWidget()
{

    QList<QWidget*> qobj = this->findChildren<QWidget*>();
    foreach (QWidget* i, qobj) {
        i->deleteLater();
    }
}

void SideWidget::clearStickerWidget()
{
    QList<QWidget*> qobj = this->sContentWidget->findChildren<QWidget*>();
    foreach (QWidget* i, qobj) {
        i->deleteLater();
    }
}

void SideWidget::paintingWidget()
{

    //初始化画笔界面

    topWidget = new QWidget(this);
    topWidget->setStyleSheet("background-color: rgb(71, 240, 255);");
    topWidget->setVisible(true);
    topWidget->move(0,0);
    topWidget->resize(s_width,s_height*3/10);

    //构建笔的中间框架
    createCentralWidget();

    bottomWidget = new QWidget(this);
    bottomWidget->setStyleSheet("background-color: rgb(240 ,71, 255);");
    bottomWidget->setVisible(true);
    bottomWidget->move(0,s_height*7/10);
    bottomWidget->resize(s_width,s_height*3/10);
    side_label = new QLabel(this);
    //稍后更改
    side_label->resize(200,40);
    side_label->move(30,30);
    side_label->setText(tr("画图"));
    side_label->setVisible(true);
    QFont sl_f;
    sl_f.setPointSize(18);
    side_label->setFont(sl_f);
//    side_label->setStyleSheet("background-color: rgb(71, 240, 255);");
    side_label->setStyleSheet(topWidget->styleSheet());

    topPenWidget();
    bottomColorWidget();
    //删除
}

void SideWidget::topPenWidget()
{
    //按钮统一标准
    int s_btn_size = 62;
    QFont fontsize("宋体",18);
    int move_width = s_width/8;
    int move_height= s_height/10;
    //给侧边框加按钮
    //第一个画笔按钮
    s_b1 = new QPushButton(topWidget);
    s_b1->resize(s_btn_size,s_btn_size);
    s_b1->move(move_width,move_height);
    s_b1->setText(tr("笔"));
    //设置字体大小*******
    s_b1->setFont(fontsize);
    s_b1->setVisible(true);

    //第二个笔刷按钮
    s_b2 = new QPushButton(topWidget);
    s_b2->resize(s_btn_size,s_btn_size);
    s_b2->move(move_width+s_btn_size,move_height);
    s_b2->setText(tr("刷"));
    s_b2->setFont(fontsize);
    s_b2->setVisible(true);

    //第三个铅笔
    s_b3 = new QPushButton(topWidget);
    s_b3->resize(s_btn_size,s_btn_size);
    s_b3->move(move_width+s_btn_size*2,move_height);
    s_b3->setText(tr("铅"));
    s_b3->setFont(fontsize);
    s_b3->setVisible(true);

    //第四个书写笔(待定)
    s_b4 = new QPushButton(topWidget);
    s_b4->resize(s_btn_size,s_btn_size);
    s_b4->move(move_width+s_btn_size*3,move_height);
    s_b4->setText(tr("书写"));
    s_b4->setFont(fontsize);
    s_b4->setVisible(true);

    //第五个橡皮
    s_b5 = new QPushButton(topWidget);
    s_b5->resize(s_btn_size,s_btn_size);
    s_b5->move(move_width,move_height+s_btn_size);
    s_b5->setText(tr("橡皮"));
    s_b5->setFont(fontsize);
    s_b5->setVisible(true);

    //第六个蜡笔
    s_b6 = new QPushButton(topWidget);
    s_b6->resize(s_btn_size,s_btn_size);
    s_b6->move(move_width+s_btn_size,move_height+s_btn_size);
    s_b6->setText(tr("蜡"));
    s_b6->setFont(fontsize);
    s_b6->setVisible(true);

    //第七个喷漆(待定)
    s_b7 = new QPushButton(topWidget);
    s_b7->resize(s_btn_size,s_btn_size);
    s_b7->move(move_width+s_btn_size*2,move_height+s_btn_size);
    s_b7->setText(tr("喷"));
    s_b7->setFont(fontsize);
    s_b7->setVisible(true);

    //第八个填充
    s_b8 = new QPushButton(topWidget);
    s_b8->resize(s_btn_size,s_btn_size);
    s_b8->move(move_width+s_btn_size*3,move_height+s_btn_size);
    s_b8->setText(tr("填"));
    s_b8->setFont(fontsize);
    s_b8->setVisible(true);
}

void SideWidget::bottomColorWidget()
{
    int height = s_height;
    int width  = s_width;
    //同一颜色按钮的大小尺寸
    int c_height = height/10;
    int c_width  = width/8;
    int c_size = 40;
    //s_width,s_height*3/10
    //多样的颜色类选择
    var_color = new QPushButton(bottomWidget);
    var_color->setText(tr("选择颜色"));
    var_color->setStyleSheet("background-color: white;");
    var_color->resize(c_size*3.9,c_size);
    var_color->move(c_width,c_height-c_size*1.2);
    var_color->setVisible(true);

    //彩色器按钮
    extract = new QPushButton(bottomWidget);
    extract->setText(tr("取色器"));
    extract->setStyleSheet("background-color: white;");
    extract->resize(c_size*2,c_size);
    extract->move(c_width+c_size*4,c_height-c_size*1.2);
    extract->setVisible(true);

    cb1 = new QPushButton(bottomWidget);
    cb1->resize(c_size,c_size);
    cb1->move(c_width,c_height);
    cb1->setStyleSheet("background-color: white;");
    cb1->setVisible(true);

    //gray
    cb2 = new QPushButton(bottomWidget);
    cb2->resize(c_size,c_size);
    cb2->move(c_width+c_size,c_height);
    cb2->setStyleSheet("background-color: gray;");
    cb2->setVisible(true);

    //dark gray
    cb3 = new QPushButton(bottomWidget);
    cb3->resize(c_size,c_size);
    cb3->move(c_width+c_size*2,c_height);
    cb3->setStyleSheet("background-color: rgb(100, 100, 100);");
    cb3->setVisible(true);

    //black
    cb4 = new QPushButton(bottomWidget);
    cb4->resize(c_size,c_size);
    cb4->move(c_width+c_size*3,c_height);
    cb4->setStyleSheet("background-color: black;");
    cb4->setVisible(true);

    //darkRed
    cb5 = new QPushButton(bottomWidget);
    cb5->resize(c_size,c_size);
    cb5->move(c_width+c_size*4,c_height);
    cb5->setStyleSheet("background-color: darkRed;");
    cb5->setVisible(true);

    //red
    cb6 = new QPushButton(bottomWidget);
    cb6->resize(c_size,c_size);
    cb6->move(c_width+c_size*5,c_height);
    cb6->setStyleSheet("background-color: rgb(255, 55, 55);");
    cb6->setVisible(true);

    //darkyellow
    cb7 = new QPushButton(bottomWidget);
    cb7->resize(c_size,c_size);
    cb7->move(c_width,c_height+c_size);
    cb7->setStyleSheet("background-color: rgb(200, 200, 43);");
    cb7->setVisible(true);

    //yellow
    cb8 = new QPushButton(bottomWidget);
    cb8->resize(c_size,c_size);
    cb8->move(c_width+c_size,c_height+c_size);
    cb8->setStyleSheet("background: yellow;");
    cb8->setVisible(true);

    //darkGreen
    cb9 = new QPushButton(bottomWidget);
    cb9->resize(c_size,c_size);
    cb9->move(c_width+c_size*2,c_height+c_size);
    cb9->setStyleSheet("background: darkGreen;");
    cb9->setVisible(true);

    //green
    cb10 = new QPushButton(bottomWidget);
    cb10->resize(c_size,c_size);
    cb10->move(c_width+c_size*3,c_height+c_size);
    cb10->setStyleSheet("background: green;");
    cb10->setVisible(true);

    //darkCyan
    cb11 = new QPushButton(bottomWidget);
    cb11->resize(c_size,c_size);
    cb11->move(c_width+c_size*4,c_height+c_size);
    cb11->setStyleSheet("background: darkcyan;");
    cb11->setVisible(true);

    //cyan
    cb12 = new QPushButton(bottomWidget);
    cb12->resize(c_size,c_size);
    cb12->move(c_width+c_size*5,c_height+c_size);
    cb12->setStyleSheet("background: cyan;");
    cb12->setVisible(true);

    //darkBlue
    cb13 = new QPushButton(bottomWidget);
    cb13->resize(c_size,c_size);
    cb13->move(c_width,c_height+c_size*2);
    cb13->setStyleSheet("background: darkBlue;");
    cb13->setVisible(true);

    //blue
    cb14 = new QPushButton(bottomWidget);
    cb14->resize(c_size,c_size);
    cb14->move(c_width+c_size,c_height+c_size*2);
    cb14->setStyleSheet("background: blue;");
    cb14->setVisible(true);

    //darkMagenta
    cb15 = new QPushButton(bottomWidget);
    cb15->resize(c_size,c_size);
    cb15->move(c_width+c_size*2,c_height+c_size*2);
    cb15->setStyleSheet("background: darkMagenta;");
    cb15->setVisible(true);

    //magenta
    cb16 = new QPushButton(bottomWidget);
    cb16->resize(c_size,c_size);
    cb16->move(c_width+c_size*3,c_height+c_size*2);
    cb16->setStyleSheet("background: magenta;");
    cb16->setVisible(true);
}

void SideWidget::penWidget()
{
//    clearSideSubWidget();

    //给笔设置标题
    side_label->setText(tr("书写笔"));

    int pen_height = s_height/16;
    //设置大小label
    QLabel *s_label1 = new QLabel(centerWidget);
    s_label1->resize(100,30);
    s_label1->move(s_width/10,pen_height);
    s_label1->setText(tr("粗细"));
    s_label1->setVisible(true);
    //label统一字体大小
    QFont s_l;
    s_l.setPointSize(15);
    s_label1->setFont(s_l);
    //设置大小滑动条  水平!
    s_slider1 = new QSlider(Qt::Horizontal,centerWidget);
    s_slider1->resize(260,30);
    s_slider1->move(s_width/10,pen_height*2);
    s_slider1->setMaximum(30);
    s_slider1->setMinimum(1);
    //应该是继承父类的false导致不设置的话默认看不到
    s_slider1->setVisible(true);

    //设置显示像素大小
    s_pixel1 = new QLineEdit(centerWidget);
    s_pixel1->resize(100,30);
    s_pixel1->move(s_width*2/3,pen_height);
    s_pixel1->setText(tr("1像素"));
    s_pixel1->setAlignment(Qt::AlignRight);
    s_pixel1->setVisible(true);

    //设置透明度标签
    QLabel *s_label2 = new QLabel(centerWidget);
    s_label2->resize(100,30);
    s_label2->move(s_width/10,pen_height*3);
    s_label2->setText(tr("透明度"));
    s_label2->setVisible(true);
    s_label2->setFont(s_l);
    //设置透明度滑块
    s_slider2 = new QSlider(Qt::Horizontal,centerWidget);
    s_slider2->resize(260,30);
    s_slider2->move(s_width/10,pen_height*4);
    s_slider2->setVisible(true);
    //反转后设置滑块位置
    s_slider2->setInvertedAppearance(true);
    s_slider2->setMaximum(255);
    s_slider2->setMinimum(0);
    s_slider2->setSliderPosition(255);

    //透明度
    s_pixel2 = new QLineEdit(centerWidget);
    s_pixel2->resize(100,30);
    s_pixel2->move(s_width*2/3,pen_height*3);
    s_pixel2->setText(tr("255 alpha"));
    s_pixel2->setAlignment(Qt::AlignRight);
    s_pixel2->setVisible(true);
}

void SideWidget::rubberWidget()
{
    side_label->setText(tr("橡皮擦"));
    int pen_height = s_height/16;
    //设置大小label
    QLabel *s_label1 = new QLabel(centerWidget);
    s_label1->resize(100,30);
    s_label1->move(s_width/10,pen_height);
    s_label1->setText(tr("粗细"));
    s_label1->setVisible(true);
    //label统一字体大小
    QFont s_l;
    s_l.setPointSize(15);
    s_label1->setFont(s_l);
    //设置大小滑动条  水平!
    s_slider1 = new QSlider(Qt::Horizontal,centerWidget);
    s_slider1->resize(260,30);
    s_slider1->move(s_width/10,pen_height*2);
    s_slider1->setMaximum(100);
    s_slider1->setMinimum(20);
    //应该是继承父类的false导致不设置的话默认看不到
    s_slider1->setVisible(true);

    //设置显示像素大小
    s_pixel1 = new QLineEdit(centerWidget);
    s_pixel1->resize(100,30);
    s_pixel1->move(s_width*2/3,pen_height);
    s_pixel1->setText(tr("20像素"));
    s_pixel1->setAlignment(Qt::AlignRight);
    s_pixel1->setVisible(true);
}

void SideWidget::pencilWidget()
{
    side_label->setText(tr("铅笔"));
    int pen_height = s_height/16;
    //设置大小label
    QLabel *s_label1 = new QLabel(centerWidget);
    s_label1->resize(100,30);
    s_label1->move(s_width/10,pen_height);
    s_label1->setText(tr("粗细"));
    s_label1->setVisible(true);
    //label统一字体大小
    QFont s_l;
    s_l.setPointSize(15);
    s_label1->setFont(s_l);
    //设置大小滑动条  水平!
    s_slider1 = new QSlider(Qt::Horizontal,centerWidget);
    s_slider1->resize(260,30);
    s_slider1->move(s_width/10,pen_height*2);
    s_slider1->setMaximum(10);
    s_slider1->setMinimum(1);
    //应该是继承父类的false导致不设置的话默认看不到
    s_slider1->setVisible(true);

    //设置显示像素大小
    s_pixel1 = new QLineEdit(centerWidget);
    s_pixel1->resize(100,30);
    s_pixel1->move(s_width*2/3,pen_height);
    s_pixel1->setText(tr("1像素"));
    s_pixel1->setAlignment(Qt::AlignRight);
    s_pixel1->setVisible(true);
}

void SideWidget::twoDWidget()
{
    lineCurveWidget = new QWidget(this);
    lineCurveWidget->setVisible(true);
    lineCurveWidget->move(0,0);
    lineCurveWidget->resize(s_width,s_height/5);
    lineCurveWidget->setStyleSheet("background-color: rgb(240 ,71, 255);");

    shapeWidget = new QWidget(this);
    shapeWidget->setVisible(true);
    shapeWidget->move(0,s_height/5);
    shapeWidget->resize(s_width,s_height*2/5);
    shapeWidget->setStyleSheet("background-color: rgb(71, 240, 255);");


    //稍后更改
    side_label = new QLabel(this);
    side_label->resize(200,40);
    side_label->move(30,30);
    side_label->setText(tr("直线和曲线"));
    side_label->setVisible(true);
    QFont sl_f;
    sl_f.setPointSize(18);
    side_label->setFont(sl_f);
    side_label->setStyleSheet(lineCurveWidget->styleSheet());

    //直线
    lineWidget();
    //图形
    twoDShapeWidget();
}

void SideWidget::lineWidget()
{
    //按钮统一标准
    int s_btn_size = 42;

    QFont fontsize("宋体",15);
    int move_width = s_width/15;
    int move_height= s_height/7;

    //设置大小label
    QLabel *s_label1 = new QLabel(lineCurveWidget);
    s_label1->resize(150,30);
    s_label1->move(s_width/20,s_height/10);
    s_label1->setText(tr("直线或曲线"));
    s_label1->setFont(QFont("宋体",15));
    s_label1->setVisible(true);

    lc1 = new QPushButton(lineCurveWidget);
    lc1->resize(s_btn_size,s_btn_size);
    lc1->move(move_width,move_height);
    lc1->setIcon(QIcon(":/twoD/icon/1.ico"));
    lc1->setIconSize(QSize(s_btn_size,s_btn_size));
    lc1->setVisible(true);

    lc2 = new QPushButton(lineCurveWidget);
    lc2->resize(s_btn_size,s_btn_size);
    lc2->move(move_width+s_btn_size,move_height);
    lc2->setIcon(QIcon(":/twoD/icon/2.ico"));
    lc2->setIconSize(QSize(s_btn_size,s_btn_size));
    lc2->setVisible(true);

    lc3 = new QPushButton(lineCurveWidget);
    lc3->resize(s_btn_size,s_btn_size);
    lc3->move(move_width+s_btn_size*2,move_height);
    lc3->setIcon(QIcon(":/twoD/icon/3.ico"));
    lc3->setIconSize(QSize(s_btn_size,s_btn_size));
    lc3->setVisible(true);

    lc4 = new QPushButton(lineCurveWidget);
    lc4->resize(s_btn_size,s_btn_size);
    lc4->move(move_width+s_btn_size*3,move_height);
    lc4->setText(tr("B"));
    lc4->setVisible(true);
}

void SideWidget::twoDShapeWidget()
{
    //按钮统一标准
    int s_btn_size = 42;
    QFont fontsize("宋体",15);
    int move_width = s_width/15;
    int move_height= s_height/7;
    //offset设置间隔距离
    int offset = 10;
    QLabel *s_label1 = new QLabel(shapeWidget);
    s_label1->resize(100,30);
    s_label1->move(s_width/20,s_height/20);
    s_label1->setText(tr("2D形状"));
    s_label1->setFont(fontsize);
    s_label1->setVisible(true);

    shape1 = new QPushButton(shapeWidget);
    shape1->resize(s_btn_size,s_btn_size);
    shape1->move(move_width,move_height);
    shape1->setIcon(QIcon(":/twoD/icon/5.ico"));
    shape1->setIconSize(QSize(s_btn_size,s_btn_size));
    shape1->setVisible(true);

    shape2 = new QPushButton(shapeWidget);
    shape2->resize(s_btn_size,s_btn_size);
    shape2->move(move_width+s_btn_size+offset,move_height);
    shape2->setIcon(QIcon(":/twoD/icon/6.ico"));
    shape2->setIconSize(QSize(s_btn_size,s_btn_size));
    shape2->setVisible(true);

    shape3 = new QPushButton(shapeWidget);
    shape3->resize(s_btn_size,s_btn_size);
    shape3->move(move_width+(s_btn_size+offset)*2,move_height);
    shape3->setIcon(QIcon(":/twoD/icon/7.ico"));
    shape3->setIconSize(QSize(s_btn_size,s_btn_size));
    shape3->setVisible(true);

    shape4 = new QPushButton(shapeWidget);
    shape4->resize(s_btn_size,s_btn_size);
    shape4->move(move_width+(s_btn_size+offset)*3,move_height);
    shape4->setIcon(QIcon(":/twoD/icon/8.ico"));
    shape4->setIconSize(QSize(s_btn_size,s_btn_size));
    shape4->setVisible(true);

    shape5 = new QPushButton(shapeWidget);
    shape5->resize(s_btn_size,s_btn_size);
    shape5->move(move_width+(s_btn_size+offset)*4,move_height);
    shape5->setIcon(QIcon(":/twoD/icon/9.ico"));
    shape5->setIconSize(QSize(s_btn_size,s_btn_size));
    shape5->setVisible(true);

    shape6 = new QPushButton(shapeWidget);
    shape6->resize(s_btn_size,s_btn_size);
    shape6->move(move_width,move_height+s_btn_size+offset);
    shape6->setIcon(QIcon(":/twoD/icon/10.ico"));
    shape6->setIconSize(QSize(s_btn_size,s_btn_size));
    shape6->setVisible(true);

    shape7 = new QPushButton(shapeWidget);
    shape7->resize(s_btn_size,s_btn_size);
    shape7->move(move_width+s_btn_size+offset,move_height+s_btn_size+offset);
    shape7->setIcon(QIcon(":/twoD/icon/11.ico"));
    shape7->setIconSize(QSize(s_btn_size,s_btn_size));
    shape7->setVisible(true);

    shape8 = new QPushButton(shapeWidget);
    shape8->resize(s_btn_size,s_btn_size);
    shape8->move(move_width+(s_btn_size+offset)*2,move_height+s_btn_size+offset);
    shape8->setIcon(QIcon(":/twoD/icon/12.ico"));
    shape8->setIconSize(QSize(s_btn_size,s_btn_size));
    shape8->setVisible(true);

    shape9 = new QPushButton(shapeWidget);
    shape9->resize(s_btn_size,s_btn_size);
    shape9->move(move_width+(s_btn_size+offset)*3,move_height+s_btn_size+offset);
    shape9->setIcon(QIcon(":/twoD/icon/13.ico"));
    shape9->setIconSize(QSize(s_btn_size,s_btn_size));
    shape9->setVisible(true);

    shape10 = new QPushButton(shapeWidget);
    shape10->resize(s_btn_size,s_btn_size);
    shape10->move(move_width+(s_btn_size+offset)*4,move_height+s_btn_size+offset);
    shape10->setIcon(QIcon(":/twoD/icon/14.ico"));
    shape10->setIconSize(QSize(s_btn_size,s_btn_size));
    shape10->setVisible(true);

}

void SideWidget::stickerWidget()
{
    sSelectWidget = new QWidget(this);
    sSelectWidget->setVisible(true);
    sSelectWidget->move(0,0);
    sSelectWidget->resize(s_width,s_height/5);
    sSelectWidget->setStyleSheet("background-color: rgb(240 ,240, 71);");


    sContentWidget = new QWidget(this);
    sContentWidget->setVisible(true);
    sContentWidget->move(0,s_height/5);
    sContentWidget->resize(s_width,s_height*4/5);
    sContentWidget->setStyleSheet("background-color: rgb(50 ,51,100);");

    side_label = new QLabel(this);
    side_label->resize(s_width,50);
    side_label->move(0,0);
    side_label->setText(tr("贴纸"));
    side_label->setVisible(true);
    side_label->setFont(QFont("宋体",18));
    side_label->setStyleSheet("background-color:gray;");

    stickerSelectWidget();
//    customSticker();
}

void SideWidget::stickerSelectWidget()
{
    //按钮统一标准
    int btn_h = 60;
    int btn_w = 80;

    int move_width = s_width/8;
    int move_height= sSelectWidget->height()-btn_h;

    texture1 = new QPushButton(sSelectWidget);
    texture1->resize(btn_w,btn_h);
    texture1->move(move_width,move_height);
    texture1->setVisible(true);
    texture1->setText(tr("贴纸"));

    texture2 = new QPushButton(sSelectWidget);
    texture2->resize(btn_w,btn_h);
    texture2->move(move_width+btn_w,move_height);
    texture2->setVisible(true);
    texture2->setText(tr("纹理"));

    texture3 = new QPushButton(sSelectWidget);
    texture3->resize(btn_w,btn_h);
    texture3->move(move_width+btn_w*2,move_height);
    texture3->setVisible(true);
    texture3->setText(tr("自定义"));
}

void SideWidget::customSticker()
{
    //按钮统一标准
    int btn_h = 65;
    int btn_w = sContentWidget->width()*4/5;

    int move_w = sContentWidget->width()/10;
    int move_h = sContentWidget->height()/20;
    //按钮间距
    int offset = btn_h*1.1;


    //设置滑动块
    scrollArea = new QScrollArea(sContentWidget);
//    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollArea->setWidgetResizable( true );
    scrollArea->setGeometry(0,0,sContentWidget->width(),sContentWidget->height());
    scrollArea->setAlignment(Qt::AlignTop);
    //一定要设置可见
    scrollArea->setVisible(true);

    tmpCustomW = new QWidget(sContentWidget);
    scrollArea->setWidget(tmpCustomW);
    //设置布局
    glayout = new QGridLayout(sContentWidget);
    tmpCustomW->setLayout(glayout);
    tmpCustomW->setVisible(true);
    cs_btn1 = new QPushButton(sContentWidget);
    cs_btn1->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn1);
//    cs_btn1->move(move_w,move_h);
    cs_btn1->setText(tr("1"));
    cs_btn1->setStyleSheet("background-color:white;");
    cs_btn1->setVisible(true);

    cs_btn2 = new QPushButton(sContentWidget);
    cs_btn2->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn2);
//    cs_btn2->move(move_w,move_h+offset);
    cs_btn2->setText(tr("2"));
    cs_btn2->setStyleSheet("background-color:white;");
    cs_btn2->setVisible(true);

    cs_btn3 = new QPushButton(sContentWidget);
    cs_btn3->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn3);
//    cs_btn3->move(move_w,move_h+offset*2);
    cs_btn3->setText(tr("3"));
    cs_btn3->setStyleSheet("background-color:white;");
    cs_btn3->setVisible(true);

    cs_btn4 = new QPushButton(sContentWidget);
    cs_btn4->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn4);
//    cs_btn4->move(move_w,move_h+offset*3);
    cs_btn4->setText(tr("4"));
    cs_btn4->setStyleSheet("background-color:white;");
    cs_btn4->setVisible(true);


    cs_btn5 = new QPushButton(sContentWidget);
    cs_btn5->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn5);
//    cs_btn5->move(move_w,move_h+offset*4);
    cs_btn5->setText(tr("5"));
    cs_btn5->setStyleSheet("background-color:white;");
    cs_btn5->setVisible(true);

    cs_btn6 = new QPushButton(sContentWidget);
    cs_btn6->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn6);
    cs_btn6->setText(tr("6"));
//    cs_btn6->move(move_w,move_h+offset*5);
    cs_btn6->setStyleSheet("background-color:white;");
    cs_btn6->setVisible(true);

    cs_btn7 = new QPushButton(sContentWidget);
    cs_btn7->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn7);
    cs_btn7->setText(tr("7"));
//    cs_btn7->move(move_w,move_h+offset*6);
    cs_btn7->setStyleSheet("background-color:white;");
    cs_btn7->setVisible(true);

    cs_btn8 = new QPushButton(sContentWidget);
    cs_btn8->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn8);
    cs_btn8->setText(tr("8"));
//    cs_btn8->move(move_w,move_h+offset*7);
    cs_btn8->setStyleSheet("background-color:white;");
    cs_btn8->setVisible(true);

    cs_btn9 = new QPushButton(sContentWidget);
    cs_btn9->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn9);
    cs_btn9->setText(tr("9"));
//    cs_btn9->move(move_w,move_h+offset*8);
    cs_btn9->setStyleSheet("background-color:white;");
    cs_btn9->setVisible(true);

    cs_btn10 = new QPushButton(sContentWidget);
    cs_btn10->setMinimumSize(btn_w,btn_h);
    glayout->addWidget(cs_btn10);
    cs_btn10->setText(tr("10"));
//    cs_btn10->move(move_w,move_h+offset*9);
    cs_btn10->setStyleSheet("background-color:white;");
    cs_btn10->setVisible(true);

}

void SideWidget::userSticker()
{
    //统一标准
    int u_label_h = 25;
    int u_label_w = 120;

    //用户标签大小
    userLabel = new QLabel(sContentWidget);
    userLabel->resize(u_label_w,u_label_h);
    userLabel->move(10,20);
    userLabel->setText(tr("选择自己的贴纸"));
    userLabel->setStyleSheet("background-color:white;");
    userLabel->setVisible(true);

    //用户添加按钮大小
    int u_add_h = sContentWidget->height()/11;
    int u_add_w = sContentWidget->width()*4/5;
    int move_h = sContentWidget->height()/10;
    int move_w = sContentWidget->width()/10;

    userAdd_btn = new QPushButton(sContentWidget);
    userAdd_btn->resize(u_add_w,u_add_h);
    userAdd_btn->move(move_w,move_h);
    userAdd_btn->setText(tr("+          请选择添加的贴纸"));
    userAdd_btn->setStyleSheet("background-color:white;");
    userAdd_btn->setVisible(true);

    //设置滑动块
    scrollArea = new QScrollArea(sContentWidget);
//    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollArea->setWidgetResizable(true);
    scrollArea->setGeometry(0,move_h+u_add_h,sContentWidget->width(),sContentWidget->height()-move_h-u_add_h);
    //一定要设置可见
    scrollArea->setVisible(true);
    //作为临时的页面框
    tmpUserW = new QWidget(sContentWidget);
//    tmpUserW->setStyleSheet("background-color:white;");
    scrollArea->setWidget(tmpUserW);
    //设置布局
    glayout = new QGridLayout(sContentWidget);
//    flayout->setMargin(50);
    glayout->setSpacing(30);
    tmpUserW->setLayout(glayout);
    tmpUserW->setVisible(true);
}


void SideWidget::editWidget()
{
    //距离顶部偏移量
    int e_offset = 50;
    sEditWidget = new QWidget(this);
    sEditWidget->setVisible(true);
    sEditWidget->move(0,e_offset);
    sEditWidget->resize(s_width,s_height-e_offset);
    sEditWidget->setStyleSheet("background-color : rgb(181, 255, 184);");

    side_label = new QLabel(this);
    side_label->resize(s_width,50);
    side_label->move(0,0);
    side_label->setText(tr("编辑"));
    side_label->setVisible(true);
    side_label->setFont(QFont("宋体",18));
    side_label->setStyleSheet("background-color:gray;");

    select_btn = new QPushButton(sEditWidget);
    select_btn->resize(100,60);
    select_btn->setVisible(true);
    select_btn->move(10,10);
    select_btn->setText(tr("选择区域"));

    draw_btn = new QPushButton(sEditWidget);
    draw_btn->resize(100,60);
    draw_btn->setVisible(true);
    draw_btn->move(110,10);
    draw_btn->setText(tr("绘图"));
}

void SideWidget::reSize(int w, int h)
{
    this->resize(w,h);
    s_width = w;
    s_height = h;
}
