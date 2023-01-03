#ifndef PAINT_H
#define PAINT_H
#include "Shape.h"
#include "sidewidget.h"
#include "topwidget.h"
#include "Sticker/emojidialog.h"
#include <QWidget>

class Draw;
class QLabel;
class QPushButton;
class QGraphicsView;
class QSlider;
class QLineEdit;
class QColorDialog;
class Paint : public QWidget
{
    Q_OBJECT
public:
    //全局变量
    //全局参数
    int global_height = 0;
    int global_width = 0;
    //侧边框全局变量
    int s_width = 0;
    int s_height = 0;
public:
    Paint(QWidget *parent = nullptr);
    ~Paint();
    //void paintEvent(QPaintEvent *event) override;
    //比较重要的一个东西
private:
    //function
    void init();
    //绑定侧边框所用到的子类
    void bindingSideWidget();
    //绑定相关的所有槽与信号
    void bindingBasePen_SingalAndSlot();
    void bindingPen();
    void bindingRubber();
    void bingdingPencil();

    void binding2D_SignalAndSlot();

    void bindingSticker_SignalAndSolt();
    void bindingStickerCustom();
    void bindingStickerUser();

    void bindingEdit_SignalAndSlot();

    //绑定系统自带的所有贴纸类
    void bindingMEmoji1();
    void bindingAEmoji2();
    //顶部框初始化
    void topWidgetInit();
    //侧边框初始化
    void sideWidgetInit();


    //清楚所有
    void clearSideWidget();
    //清除边框类
    void clearSideSubWidget();
    //清除贴纸类
    void clearStickerWidget();

    //保存用户贴纸
    void saveUserSticker(const qint32 height,const QString fileName);
    void addSaveUserSticker();
    //设置用户贴纸移动高度
    void setUserSMove(int h);
    qint32 getUserSMove();

    //弄一个编辑页面对图像进行伸缩
private:
//    QWidget * side_widget;
    TopWidget *topwidget;
    SideWidget *sideWidget;
    //侧边滑块的事件
    QSlider *s_slider1;
    QSlider *s_slider2;

    QPoint  offset;
    Draw * draw;
    //侧边框标签


    //设置两个lineEdit显示值
    QLineEdit *s_pixel1;
    QLineEdit *s_pixel2;

    //贴纸选择对话框
//   额外窗口手动清除
    EmojiDialog *emojiDialog1;
    EmojiDialog *emojiDialog2;

    struct userSticker{
        int height;
        QString fileName;
    };
    //设置list保存多个按钮
    QList<userSticker> uSticker;

private slots:
    void on_menu_btn_clicked();
    void on_painting_btn_clicked();
    void on_2D_btn_clicked();
    void on_sticker_btn_clicked();
    void on_edit_btn_clicked();
    void on_test_clicked();

    //下面三个暂时没啥用
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
//    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) override;
//    bool eventFilter(QObject *obj, QEvent *event);
    //取色器函数
    void extractColor();
    //画笔pen按钮
    void on_pen_button_clicked();
    //橡皮选中
    void on_rubber_button_clicked();
    //铅笔响应事件
    void on_pencil_button_clicked();
    //笔区域响应事件
    //滑块事件
    void pen_slider_changed(int value);
    //颜色透明度设置
    void color_alpha(qreal value);
    //设置lineEdit值
    void pen_pixel_changed(int value);
    void pen_alpha_changed(int a);
    //颜色设置槽
    void white_button();
    void gray_button();
    void darkGray_button();
    void black_button();
    void darkRed_button();
    void red_button();
    void darkYellow_button();
    void yellow_button();
    void darkGreen_button();
    void green_button();
    void darkCyan_button();
    void cyan_button();
    void darkBlue_button();
    void blue_button();
    void darkMagenta_button();
    void magenta_button();
    void multi_color_button();

    //绑定2d类型
    //Line
    void on_drawLine_btn_clicked();
    void on_drawUpArc_btn_clicked();
    void on_drawDownArc_btn_clicked();
    //2D shape
    void on_circle_btn_clicked();
    void on_chord_btn_clicked();
    void on_rect_btn_clicked();
    void on_rectRound_btn_clicked();
    void on_triangle_btn_clicked();
    void on_pentagle_btn_clicked();
    void on_hexagon_btn_clicked();
    void on_heptagon_btn_clicked();
    void on_diamond_btn_clicked();
    void on_arrow_btn_clicked();

    //贴纸按钮
    void on_custom_sticker_btn_clicked();
    //设置类型
    void stickerSelect();
    void on_sticker1_clicked();
    void on_sticker2_clicked();
    void on_sticker3_clicked();
    void on_sticker4_clicked();
    //添加用户自定义贴纸
    void on_user_sticker_btn_clicked();
    void on_sticker_selected_clicked();
    //emoji设置
    void setDrawCustomSticker();
    //自定义设置
    void setDrawUserSticker();

    //编辑按钮
    void on_editSelect_btn_clicked();
    void on_editDraw_btn_clicked();

};

#endif // PAINT_H
