#ifndef DRAW_H
#define DRAW_H
#include <QWidget>
#include <QGraphicsView>
#include "Shape.h"
/**
 * @brief The Draw class
 * 很奇怪不知道为什么设置画笔型状的时候如果画图甩出去的画那么还是会存在
 * 正方型在末尾,实在不行等opengl再进行观察再改进
 * 单独设置的话问题解决了
 * 之后用opengl再进行设置吧
 */
class Draw: public QWidget
{
    Q_OBJECT
public:
    Draw(QWidget *parent = nullptr,int height = 0,int width = 0);
    ~Draw();
private:
    QPixmap pix;
    QPixmap tempPix;
    QPoint startPoint;
    QPoint endPoint;
    QPoint lastStart;
    QPoint lastEnd;
    bool isDrawing;
    bool isExtract;
    bool isSticker;
    //判断选中的类型
    Shape::type type_selected = Shape::type::normal_pen;
    //初始类型
    Shape::pen pen_selected = Shape::pen::n_pen;
    Shape::td two_D = Shape::Line;
    QColor color = Qt::black;

    //简单判断画笔的类型
    Qt::PenStyle penStyle = Qt::SolidLine;
    Qt::PenCapStyle penCapStyle = Qt::FlatCap;
    Qt::PenJoinStyle penJoinStyle = Qt::BevelJoin;

    int pen_size = 0;
    int d_alpha = 255;
    //贴纸文件路径
    QString stickerPath = nullptr;
    //编辑
    bool isSelect;
    //临时存储选中的区域
    QPixmap selectPix;
    Shape::editMode edit_selected;
private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event) ;
//函数
public:
    void setType(Shape::type t);
    void setShape(Shape::td s);
    void setIsDrawing(bool value);
    void setColor(Shape::color c);
    void setColor(QColor c);

    QColor getColor();
    void setIsExtract(bool value);
    //暂时搁置
    void setIsSticker(bool s);
    //画笔类方法
    void setPen(Shape::pen p);
    void setPenSize(int size);
    //设置贴纸路径
    void setStickerPath(const QString &path);
    //透明度
    void set_Alpha(qreal value);
    int get_Alpha();
    //普通颜色类判断方法
    QColor which_color(Shape::color c);
    //画笔类型简单判断 (不一定会用到)
    //返回是哪一个类型
//    void setPenStyle(Shape::penStyle style);
//    auto findPenStyle(Shape::penStyle style);
    Qt::PenStyle which_penStyle(Shape::penStyle style);
    Qt::PenCapStyle which_penCapStyle(Shape::penStyle style);
    Qt::PenJoinStyle which_penJoinStyle(Shape::penStyle style);
    //设置编辑选择类型
    void setEditMode(Shape::editMode edit);
private:
    //测试函数
    void draw_test();
    //选择什么东西去画
    void selectPen_drawing();
    void selectRubber_drawing();
    void selectPencil_drawing();
    //2D类
    void draw_line();
    void draw_upArc();
    void draw_downArc();
    void draw_ellipse();
    void draw_chord();
    void draw_rect();
    void draw_roundRect();
    void draw_triangle();
    void draw_pentagon();
    void draw_hexagon();
    void draw_heptagon();
    void draw_diamond();
    void draw_arrow();
    //贴纸
    void draw_default_sticker(const QString &filename);
    //编辑模式
    void draw_editSelect_mode();
    void draw_editDraw_mode();
};

#endif // DRAW_H
