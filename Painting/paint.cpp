#include "paint.h"
#include "draw.h"
#include "Shape.h"
#include "mstyle.h"

#include <QGraphicsView>
#include <QDebug>
#include <QList>
#include <QPushButton>
#include <QPalette>
#include <QGroupBox>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#include <QSlider>
#include <QLineEdit>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>

#include <QFormLayout>
Paint::Paint(QWidget *parent ): QWidget(parent)
{
    //固定窗口
    //this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    //准备设置窗口大小设定
    this->resize(1281,978);
    this->move(300,0);

    //窗口到时候自定义一下
    //颜色设置稍后更改
    this->setStyleSheet("background-color:white;");
    this->setWindowTitle(tr("这是一个画板"));
    this->setMinimumWidth(50);
    //这里可以进行更改一下风格
//    QString mainstyle = "QWidget#"+this->objectName()+"{background-color:QColor(251, 251, 251);"
//                                                      "border-radius:20px;}";
//    this->setStyleSheet(mainstyle);

    global_height = this->height();
    global_width = this->width();
    qDebug() << "全局宽度 : " << global_width << "全局高度 : " << global_height;
//------------------------------------
    int m_height = global_height/14;
    int m_width  = global_width/13;

    //设置按钮工具栏
    topwidget = new TopWidget(this,global_width,m_height);
    topWidgetInit();
    //--------------------------------------------
    //画图框
    //画图类去draw里面添加动作
    int d_height = global_height*4/5+m_height;
    int d_width  = global_width*0.7;

    //draw->installEventFilter(this);
    draw = new Draw(this,d_height,d_width);
    draw->resize(d_width,d_height);
    draw->move(20,m_height*1.5);

    //显示侧边框
    sideWidgetInit();
    //绑定侧边框用的的widget显示
    //绑定基本笔类 暂时放在这里


    //清楚侧边框
//    connect(text_btn,&QPushButton::clicked,this,&Paint::clearSideWidget);
}

Paint::~Paint()
{
    delete draw;
    delete sideWidget;
    delete topwidget;
    delete draw;
    delete emojiDialog1;
}

void Paint::init()
{

}

void Paint::bindingSideWidget()
{
}

void Paint::bindingBasePen_SingalAndSlot()
{
    connect(sideWidget->var_color,&QPushButton::clicked,this,&Paint::multi_color_button);
    connect(sideWidget->extract,&QPushButton::clicked,this,&Paint::extractColor);
    //pen
    connect(sideWidget->s_b1,&QPushButton::clicked,this,&Paint::on_pen_button_clicked);
    //pencil
    connect(sideWidget->s_b3,&QPushButton::clicked,this,&Paint::on_pencil_button_clicked);
    //rubber
    connect(sideWidget->s_b5,&QPushButton::clicked,this,&Paint::on_rubber_button_clicked);

//    connect(sideWidget->s_b4,&QPushButton::clicked,this,&Paint::on_pen_button_clicked);
//    connect(sideWidget->s_b5,&QPushButton::clicked,this,&Paint::on_pen_button_clicked);
//    connect(sideWidget->s_b6,&QPushButton::clicked,this,&Paint::on_pen_button_clicked);
//    connect(sideWidget->s_b7,&QPushButton::clicked,this,&Paint::on_pen_button_clicked);
//    connect(sideWidget->s_b8,&QPushButton::clicked,this,&Paint::on_pen_button_clicked);
//bingdingColor
    connect(sideWidget->cb1,&QPushButton::clicked,this,&Paint::white_button);
    connect(sideWidget->cb2,&QPushButton::clicked,this,&Paint::gray_button);
    connect(sideWidget->cb3,&QPushButton::clicked,this,&Paint::darkGray_button);
    connect(sideWidget->cb4,&QPushButton::clicked,this,&Paint::black_button);
    connect(sideWidget->cb5,&QPushButton::clicked,this,&Paint::darkRed_button);
    connect(sideWidget->cb6,&QPushButton::clicked,this,&Paint::red_button);
    connect(sideWidget->cb7,&QPushButton::clicked,this,&Paint::darkYellow_button);
    connect(sideWidget->cb8,&QPushButton::clicked,this,&Paint::yellow_button);
    connect(sideWidget->cb9,&QPushButton::clicked,this,&Paint::darkGreen_button);
    connect(sideWidget->cb10,&QPushButton::clicked,this,&Paint::green_button);
    connect(sideWidget->cb11,&QPushButton::clicked,this,&Paint::darkCyan_button);
    connect(sideWidget->cb12,&QPushButton::clicked,this,&Paint::cyan_button);
    connect(sideWidget->cb13,&QPushButton::clicked,this,&Paint::darkBlue_button);
    connect(sideWidget->cb14,&QPushButton::clicked,this,&Paint::blue_button);
    connect(sideWidget->cb15,&QPushButton::clicked,this,&Paint::darkMagenta_button);
    connect(sideWidget->cb16,&QPushButton::clicked,this,&Paint::magenta_button);
}

void Paint::bindingPen()
{
//bingdingPen
    //size  transparency
    connect(sideWidget->s_slider1,&QAbstractSlider::valueChanged,this,&Paint::pen_slider_changed);
    connect(sideWidget->s_slider1,&QAbstractSlider::valueChanged,this,&Paint::pen_pixel_changed);
    connect(sideWidget->s_slider2,&QAbstractSlider::valueChanged,this,&Paint::color_alpha);
    connect(sideWidget->s_slider2,&QAbstractSlider::valueChanged,this,&Paint::pen_alpha_changed);
}

void Paint::bindingRubber()
{
    connect(sideWidget->s_slider1,&QAbstractSlider::valueChanged,this,&Paint::pen_slider_changed);
    connect(sideWidget->s_slider1,&QAbstractSlider::valueChanged,this,&Paint::pen_pixel_changed);
}
//same above
void Paint::bingdingPencil()
{
    connect(sideWidget->s_slider1,&QAbstractSlider::valueChanged,this,&Paint::pen_slider_changed);
    connect(sideWidget->s_slider1,&QAbstractSlider::valueChanged,this,&Paint::pen_pixel_changed);
}

void Paint::binding2D_SignalAndSlot()
{
    //line
    connect(sideWidget->lc1,&QPushButton::clicked,this,&Paint::on_drawLine_btn_clicked);
    //arc
    connect(sideWidget->lc2,&QPushButton::clicked,this,&Paint::on_drawUpArc_btn_clicked);
    connect(sideWidget->lc3,&QPushButton::clicked,this,&Paint::on_drawDownArc_btn_clicked);
    //circle
    connect(sideWidget->shape1,&QPushButton::clicked,this,&Paint::on_circle_btn_clicked);
    //chord
    connect(sideWidget->shape2,&QPushButton::clicked,this,&Paint::on_chord_btn_clicked);
    //rectangle
    connect(sideWidget->shape3,&QPushButton::clicked,this,&Paint::on_rect_btn_clicked);
    //roundRectangle
    connect(sideWidget->shape4,&QPushButton::clicked,this,&Paint::on_rectRound_btn_clicked);
    //triangle
    connect(sideWidget->shape5,&QPushButton::clicked,this,&Paint::on_triangle_btn_clicked);
    //pentagnle
    connect(sideWidget->shape6,&QPushButton::clicked,this,&Paint::on_pentagle_btn_clicked);
    //hexagon
    connect(sideWidget->shape7,&QPushButton::clicked,this,&Paint::on_hexagon_btn_clicked);
    //heptagon
    connect(sideWidget->shape8,&QPushButton::clicked,this,&Paint::on_heptagon_btn_clicked);
    //diamond
    connect(sideWidget->shape9,&QPushButton::clicked,this,&Paint::on_diamond_btn_clicked);
    //arrow
    connect(sideWidget->shape10,&QPushButton::clicked,this,&Paint::on_arrow_btn_clicked);
}

void Paint::bindingSticker_SignalAndSolt()
{
    //自带贴纸
    connect(sideWidget->texture1,&QPushButton::clicked,this,&Paint::on_custom_sticker_btn_clicked);
    //添加自定义贴纸
    connect(sideWidget->texture3,&QPushButton::clicked,this,&Paint::on_user_sticker_btn_clicked);
}

void Paint::bindingStickerCustom()
{
    connect(sideWidget->cs_btn1,&QPushButton::clicked,this,&Paint::on_sticker1_clicked);
    connect(sideWidget->cs_btn2,&QPushButton::clicked,this,&Paint::on_sticker2_clicked);
    connect(sideWidget->cs_btn3,&QPushButton::clicked,this,&Paint::on_sticker3_clicked);
    connect(sideWidget->cs_btn4,&QPushButton::clicked,this,&Paint::on_sticker4_clicked);
}

void Paint::bindingStickerUser()
{
    connect(sideWidget->userAdd_btn,&QPushButton::clicked,this,&Paint::on_sticker_selected_clicked);
}

void Paint::bindingEdit_SignalAndSlot()
{
    connect(sideWidget->select_btn,&QPushButton::clicked,this,&Paint::on_editSelect_btn_clicked);
    connect(sideWidget->draw_btn,&QPushButton::clicked,this,&Paint::on_editDraw_btn_clicked);
}

void Paint::bindingMEmoji1()
{
    QList<QPushButton*> qbtn = emojiDialog1->findChildren<QPushButton*>();
    foreach (QPushButton * i,qbtn) {
        connect(i,&QPushButton::clicked,this,&Paint::setDrawCustomSticker);
    }
}

void Paint::bindingAEmoji2()
{
    QList<QPushButton*> qbtn = emojiDialog2->findChildren<QPushButton*>();
    foreach (QPushButton * i,qbtn) {
        connect(i,&QPushButton::clicked,this,&Paint::setDrawCustomSticker);
    }
}

void Paint::topWidgetInit()
{
    connect(topwidget->pen_btn,&QPushButton::clicked,this,&Paint::on_painting_btn_clicked);
    //这里先给直线类暂用触发器
    connect(topwidget->twD_btn,&QPushButton::clicked,this,&Paint::on_2D_btn_clicked);
    connect(topwidget->sticker_btn,&QPushButton::clicked,this,&Paint::on_sticker_btn_clicked);
    connect(topwidget->edit_btn,&QPushButton::clicked,this,&Paint::on_edit_btn_clicked);
}

void Paint::sideWidgetInit()
{
    //侧边框
    sideWidget = new SideWidget(this,global_width/4,global_height*9/10);
    sideWidget->move(global_width*3/4,global_height/10);
}

void Paint::clearSideWidget()
{
    sideWidget->clearSideWidget();
}

void Paint::clearSideSubWidget()
{
   sideWidget->clearSideSubWidget();
}

void Paint::clearStickerWidget()
{
    sideWidget->clearStickerWidget();
}

void Paint::saveUserSticker(const qint32 height, const QString fileName)
{
    userSticker user;
    user.height = height;
    user.fileName = fileName ;
    uSticker.append(user);
}

void Paint::addSaveUserSticker()
{
    if(!uSticker.empty()){
        foreach (userSticker us, uSticker) {
            //添加按钮
            QPushButton *btn = new QPushButton(sideWidget->tmpUserW);
            //这里暂时用很长的路径名作为对象名
            btn->setObjectName(us.fileName);
        //    btn->setText(tr("-----"));
            btn->setMinimumHeight(us.height);
            btn->setStyleSheet("background-color:white;");

            btn->setVisible(true);
            sideWidget->glayout->addWidget(btn);
            //添加图片
            QPixmap pix;
            pix.load(us.fileName);
//            pix=pix.scaled(btn->size(),Qt::KeepAspectRatio);
            btn->setIcon(QIcon(pix));
            btn->setIconSize(btn->size());

            setUserSMove(btn->height()+sideWidget->glayout->spacing()+getUserSMove());
            //设置scrollarea控件大小
            sideWidget->tmpUserW->setFixedHeight(sideWidget->userSMove);
            //设置滚动条控件大小
            sideWidget->scrollArea->verticalScrollBar()->setValue(sideWidget->userSMove);
            connect(btn,&QPushButton::clicked,this,&Paint::setDrawUserSticker);
        }
    }
}

void Paint::setUserSMove(int h)
{
    sideWidget->userSMove = h;
}

qint32 Paint::getUserSMove()
{
    return sideWidget->userSMove;
}

void Paint::on_menu_btn_clicked()
{
    qDebug() << "height : " << this->height() << " width : " << this->width() << endl;
    qDebug() << " window size: " << window()->size() << endl;
}

void Paint::on_painting_btn_clicked()
{
    clearSideWidget();
    sideWidget->paintingWidget();
    bindingBasePen_SingalAndSlot();
}

void Paint::on_2D_btn_clicked()
{
    //这里设置一下默认画笔
    clearSideWidget();
    sideWidget->twoDWidget();
    binding2D_SignalAndSlot();
}

void Paint::on_sticker_btn_clicked()
{
    clearSideWidget();
    sideWidget->stickerWidget();
    bindingSticker_SignalAndSolt();
}

void Paint::on_edit_btn_clicked()
{
    clearSideWidget();
    sideWidget->editWidget();
    bindingEdit_SignalAndSlot();
}

void Paint::on_test_clicked()
{
    draw->setShape(Shape::td::Rectangle);
    draw->setType(Shape::type::two_d);
}

void Paint::on_pen_button_clicked()
{
    clearSideSubWidget();
    //显示笔的页面内容
    sideWidget->penWidget();
    bindingPen();

    draw->setPen(Shape::pen::n_pen);
    draw->setType(Shape::type::normal_pen);
    //默认初始值设定
    draw->setPenSize(1);
    draw->setColor(Qt::black);
}

void Paint::on_rubber_button_clicked()
{
    clearSideSubWidget();
    //显示橡皮的内容
    sideWidget->rubberWidget();
    bindingRubber();

    draw->setPen(Shape::pen::rubber);
    draw->setType(Shape::type::normal_pen);
    //橡皮擦默认白色
    draw->setColor(Qt::white);
    draw->setPenSize(20);
}

void Paint::on_pencil_button_clicked()
{
    clearSideSubWidget();
    //显示笔的页面内容
    sideWidget->pencilWidget();
    bingdingPencil();;

    draw->setPen(Shape::pen::pencil);
    draw->setType(Shape::type::normal_pen);
    //默认初始值设定
    draw->setPenSize(1);
    draw->setColor(Qt::black);
}

void Paint::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){       // 如果是鼠标左键按下
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor); // 使鼠标指针暂时改变形状
        offset = event->globalPos();// 获取指针位置和窗口位置的差值
//        if(offset.x() > 0 && offset.y() > 0){
//            qDebug() << offset.x() << offset.y() << endl;
//        }else {
//            qDebug() << " 在graphic 外边 : " << endl;
//        }
    }
}

void Paint::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();         // 恢复鼠标指针形状
}

void Paint::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){      // 这里必须使用buttons()
        QPoint temp;
        temp = event->globalPos();
//        qDebug() << event->x() << " : " << event->y();
        // 使用鼠标指针当前的位置减去差值，就得到了窗口应该移动的位置
    }
}

//bool Paint::eventFilter(QObject *obj, QEvent *event)
//{
//}

void Paint::extractColor()
{
    draw->setIsExtract(true);
    draw->setIsDrawing(false);
}

void Paint::pen_slider_changed(int value)
{
    draw->setPenSize(value);
}

void Paint::color_alpha(qreal value)
{
    draw->set_Alpha(value);
}

void Paint::pen_pixel_changed(int value)
{
    if(sideWidget->s_pixel1){
        sideWidget->s_pixel1->setText(tr("%1像素").arg(value));
    }
}

void Paint::pen_alpha_changed(int a)
{
    if(sideWidget->s_pixel2){
        sideWidget->s_pixel2->setText(tr("%1 alpha").arg(a));
    }
}

//按钮类设置
void Paint::white_button()
{
    draw->setColor(Shape::white);
}

void Paint::gray_button()
{
    draw->setColor(Shape::gray);
}

void Paint::darkGray_button()
{
    draw->setColor(Shape::darkGray);
}

void Paint::black_button()
{
    draw->setColor(Shape::black);
}

void Paint::darkRed_button()
{
    draw->setColor(Shape::darkRed);
}

void Paint::red_button()
{
    draw->setColor(Shape::red);
}

void Paint::darkYellow_button()
{
    draw->setColor(Shape::darkYellow);
}

void Paint::yellow_button()
{
    draw->setColor(Shape::yellow);
}

void Paint::darkGreen_button()
{
    draw->setColor(Shape::darkGreen);
}

void Paint::green_button()
{
    draw->setColor(Shape::green);
}

void Paint::darkCyan_button()
{
    draw->setColor(Shape::darkCyan);
}

void Paint::cyan_button()
{
    draw->setColor(Shape::cyan);
}

void Paint::darkBlue_button()
{
    draw->setColor(Shape::darkBlue);
}

void Paint::blue_button()
{
    draw->setColor(Shape::blue);
}

void Paint::darkMagenta_button()
{
    draw->setColor(Shape::darkMagenta);
}

void Paint::magenta_button()
{
    draw->setColor(Shape::magenta);
}

void Paint::multi_color_button()
{   //不能选择sidewidget
    QColor color = QColorDialog::getColor(Qt::white,this,tr("选择颜色"));
    draw->setColor(color);
}

void Paint::on_drawLine_btn_clicked()
{
    sideWidget->side_label->setText(tr("直线"));
    draw->setShape(Shape::td::Line);
    draw->setType(Shape::type::two_d);
}

void Paint::on_drawUpArc_btn_clicked()
{
    sideWidget->side_label->setText(tr("上弧形"));
    draw->setShape(Shape::td::UpArc);
    draw->setType(Shape::type::two_d);
}

void Paint::on_drawDownArc_btn_clicked()
{
    sideWidget->side_label->setText(tr("下弧形"));
    draw->setShape(Shape::td::DownArc);
    draw->setType(Shape::type::two_d);
}

void Paint::on_circle_btn_clicked()
{
    sideWidget->side_label->setText(tr("圆"));
    draw->setShape(Shape::td::Ellipse);
    draw->setType(Shape::type::two_d);
}

void Paint::on_chord_btn_clicked()
{
    sideWidget->side_label->setText(tr("弦"));
    draw->setShape(Shape::td::Chord);
    draw->setType(Shape::type::two_d);
}

void Paint::on_rect_btn_clicked()
{
    sideWidget->side_label->setText(tr("矩形"));
    draw->setShape(Shape::td::Rectangle);
    draw->setType(Shape::type::two_d);
}

void Paint::on_rectRound_btn_clicked()
{
    sideWidget->side_label->setText(tr("圆矩形"));
    draw->setShape(Shape::td::RoundRectangle);
    draw->setType(Shape::type::two_d);
}

void Paint::on_triangle_btn_clicked()
{
    sideWidget->side_label->setText(tr("三角形"));
    draw->setShape(Shape::td::Triangle);
    draw->setType(Shape::type::two_d);
}

void Paint::on_pentagle_btn_clicked()
{
    sideWidget->side_label->setText(tr("五边形"));
    draw->setShape(Shape::td::Pentagon);
    draw->setType(Shape::type::two_d);
}

void Paint::on_hexagon_btn_clicked()
{
    sideWidget->side_label->setText(tr("六边形"));
    draw->setShape(Shape::td::Hexagon);
    draw->setType(Shape::type::two_d);
}

void Paint::on_heptagon_btn_clicked()
{
    sideWidget->side_label->setText(tr("七边形"));
    draw->setShape(Shape::td::Heptagon);
    draw->setType(Shape::type::two_d);
}

void Paint::on_diamond_btn_clicked()
{
    sideWidget->side_label->setText(tr("菱形"));
    draw->setShape(Shape::td::Diamond);
    draw->setType(Shape::type::two_d);
}

void Paint::on_arrow_btn_clicked()
{
    sideWidget->side_label->setText(tr("箭头"));
    draw->setShape(Shape::td::Arrow);
    draw->setType(Shape::type::two_d);
}

void Paint::on_custom_sticker_btn_clicked()
{
    clearStickerWidget();
    sideWidget->side_label->setText(tr("贴纸"));
    sideWidget->customSticker();
    stickerSelect();
    bindingStickerCustom();
}

void Paint::stickerSelect()
{
    draw->setType(Shape::type::sticker);
}

void Paint::on_sticker1_clicked()
{
    draw->setIsSticker(false);
    emojiDialog1 = new EmojiDialog(this);
    emojiDialog1->setObjectName(tr("emojiDialog1"));
    emojiDialog1->setWindowTitle(tr("M_emoji"));
//    emojiDialog->setModal(true);
    emojiDialog1->show();
    emojiDialog1->setDirName(tr("M_emoji"));
    emojiDialog1->buttonInit();
    bindingMEmoji1();
}

void Paint::on_sticker2_clicked()
{
    emojiDialog2 = new EmojiDialog(this);
    emojiDialog2->setWindowTitle(tr("animal"));
    emojiDialog2->setObjectName(tr("emojiDialog2"));
//    emojiDialog->setModal(true);
    emojiDialog2->show();
    emojiDialog2->setDirName(tr("Animal"));
    emojiDialog2->buttonInit();
    bindingAEmoji2();
}

void Paint::on_sticker3_clicked()
{
//    draw->setStickerPath(":/sticker/emoji/3.png");
}

void Paint::on_sticker4_clicked()
{
    //    draw->setStickerPath(":/sticker/emoji/4.png");
}

void Paint::on_user_sticker_btn_clicked()
{
    //设置user移动高度为0
    setUserSMove(0);
    clearStickerWidget();
    sideWidget->side_label->setText(tr("用户自定义"));
    sideWidget->userSticker();
    stickerSelect();
    bindingStickerUser();
    //添加原来的按钮
    addSaveUserSticker();
}

void Paint::on_sticker_selected_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("请选择文件"));
//    QMessageBox::information(this,"..",fileName);
    qDebug() << fileName << endl;

    //添加按钮
    QPushButton *btn = new QPushButton(sideWidget->tmpUserW);
    //这里暂时用很长的路径名作为对象名
    btn->setObjectName(fileName);
//    btn->setText(tr("-----"));
    btn->setMinimumHeight(100);
    btn->setStyleSheet("background-color:white;");

    btn->setVisible(true);
    sideWidget->glayout->addWidget(btn);
    //添加图片
    QPixmap pix;
    pix.load(fileName);
//    pix=pix.scaled(btn->size(),Qt::KeepAspectRatio);
    btn->setIcon(QIcon(pix));
    btn->setIconSize(btn->size());

    setUserSMove(btn->height()+sideWidget->glayout->spacing()+getUserSMove());
    //设置scrollarea控件大小
    sideWidget->tmpUserW->setFixedHeight(sideWidget->userSMove);
    //设置滚动条控件大小
    sideWidget->scrollArea->verticalScrollBar()->setValue(sideWidget->userSMove);

    connect(btn,&QPushButton::clicked,this,&Paint::setDrawUserSticker);
    //保存原来的贴纸
    saveUserSticker(btn->height(),fileName);
}

void Paint::setDrawCustomSticker()
{
    draw->setIsExtract(false);
    draw->setIsDrawing(false);
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    qDebug() << " objectname ==" << button->objectName();
    QString tmp = button->objectName().mid(2);
//    QString pathDir = emojiDialog1->getDirName();
    QString parN = button->parent()->objectName();
    QString pathDir = "";
    if(parN == "emojiDialog1"){
        pathDir = emojiDialog1->getDirName();
    }else if(parN == "emojiDialog2"){
        pathDir = emojiDialog2->getDirName();
    }else{
        qDebug()<<"该路径不存在" ;
    }
    draw->setStickerPath(tr(":/sticker/picture/%1/%2.png").arg(pathDir).arg(tmp));
//    emojiDialog->close();
    //    draw->setIsSticker(true);
}

void Paint::setDrawUserSticker()
{
    draw->setStickerPath(sender()->objectName());
}

void Paint::on_editSelect_btn_clicked()
{
    draw->setType(Shape::type::edit);
    draw->setEditMode(Shape::editMode::select);
}

void Paint::on_editDraw_btn_clicked()
{
    draw->setType(Shape::type::edit);
    draw->setEditMode(Shape::editMode::draw);
}
