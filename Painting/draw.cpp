#include "draw.h"
#include "Shape.h"

#include <QPoint>
#include <QtMath>
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include <QPen>
#include <QPixmap>
Draw::Draw(QWidget *parent,int height,int width):QWidget(parent)
{
    pix = QPixmap(width,height);
    //填充背景颜色
    pix.fill(Qt::gray);
    tempPix = pix;
    isDrawing = false;
    isSticker = false;
    isSelect = false;
}

Draw::~Draw()
{
}
void Draw::mousePressEvent(QMouseEvent *event)
{
    //画图类提取颜色
    if(isExtract){
        if(event->button() == Qt::LeftButton){
            QCursor cursor;
            //自定义鼠标指针
//            QCursor cursor(QPixmap());
            cursor.setShape(Qt::CrossCursor);
            QApplication::setOverrideCursor(cursor);

        }
    }else {
        //正常画图模式
        //这里先暂时统一开始标准
        if(event->button() == Qt::LeftButton){
            startPoint =event->pos();
            isDrawing = true;
        }
    }
    qDebug() << " x : " << event->x() << "y: " << event->y() << endl;
}

void Draw::mouseMoveEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) && !isExtract){
        endPoint = event->pos();
        tempPix = pix;
        update();
    }
}

void Draw::mouseReleaseEvent(QMouseEvent *event)
{
    if(isExtract){
        QPoint point = event->pos();
        QPixmap pix = QPixmap::grabWidget(this,point.x(),point.y(),1,1);
        QColor c = pix.toImage().pixel(0,0);
        qDebug() << "red : " << c.red() << "green : " << c.green() << "blue : " << c.blue();
        setColor(c);
        isExtract = false;
        //恢复鼠标
        QApplication::restoreOverrideCursor();
        //撤销event事件
        Q_UNUSED(event);
    }else{
        if(event->button() == Qt::LeftButton){
            endPoint = event->pos();
            isDrawing = false;
            update();
        }
    }
}
void Draw::paintEvent(QPaintEvent *event)
{
    switch (type_selected) {
    case Shape::type::normal_pen:
        switch (pen_selected) {
        case Shape::pen::n_pen:
            //最初始的pen处理
            selectPen_drawing();
            break;
            //橡皮跟笔情况相同
        case Shape::pen::rubber:
            selectRubber_drawing();
            break;
        case Shape::pen::pencil:
            //其实跟上面一样方便以后更改罢了
            selectPencil_drawing();
            break;
        default:
            //暂时不做处理
            break;
        }
        //这里先默认这么处理
        pix = tempPix;
        break;
    case Shape::type::two_d:
        switch (two_D) {
        case Shape::td::Line:
            draw_line();
            break;
        case Shape::td::UpArc:
            draw_upArc();
            break;
        case Shape::td::DownArc:
            draw_downArc();
            break;
        case Shape::td::Ellipse:
            draw_ellipse();
            break;
        case Shape::td::Rectangle:
            draw_rect();
            break;
        case Shape::td::RoundRectangle:
            draw_roundRect();
            break;
        case Shape::td::Chord:
            draw_chord();
            break;
        case Shape::td::Triangle:
            draw_triangle();
            break;
        case Shape::td::Pentagon:
            draw_pentagon();
            break;
        case Shape::td::Hexagon:
            draw_hexagon();
            break;
        case Shape::td::Heptagon:
            draw_heptagon();
            break;
        case Shape::td::Diamond:
            draw_diamond();
            break;
        case Shape::td::Arrow:
            draw_arrow();
            break;
        default:
            //暂时不做处理
            break;
        }
        //-----------------------
        break;
    case Shape::type::sticker:

        draw_default_sticker(stickerPath);
        break;
    case Shape::type::edit:
        switch(edit_selected){
        case Shape::editMode::select:
            draw_editSelect_mode();
            break;
        case Shape::editMode::draw:
            draw_editDraw_mode();
            break;
        default:
            break;
        }

        break;
    default:
        //暂时不做处理
        break;
    }
}

void Draw::setType(Shape::type t)
{
    type_selected = t;
}

void Draw::setPen(Shape::pen p)
{
    pen_selected = p;
}

void Draw::setPenSize(int size)
{
    pen_size = size;
}

void Draw::setStickerPath(const QString &path)
{
    if(nullptr == path||"" == path){
        qDebug() << "请选择正确的图片" ;
    }else{
        stickerPath = path;
    }
}


void Draw::set_Alpha(qreal value)
{
    d_alpha = value;
}

int Draw::get_Alpha()
{
    return d_alpha;
}

void Draw::setShape(Shape::td s)
{
    two_D = s;
}

void Draw::setIsDrawing(bool value)
{
    isDrawing = value;
}

void Draw::setColor(Shape::color c)
{
    color = which_color(c);
}

void Draw::setColor(QColor c)
{
    color = c;
}


QColor Draw::getColor()
{
    return color;
}

void Draw::setIsExtract(bool value)
{
    isExtract = value;
}

void Draw::setIsSticker(bool s)
{
    isSticker = s;
}

QColor Draw::which_color(Shape::color c)
{
    switch (c) {
    case Shape::black:
        return Qt::black;
    case Shape::white:
        return Qt::white;
    case Shape::red:
        return Qt::red;
    case Shape::darkRed:
        return Qt::darkRed;
    case Shape::blue:
        return Qt::blue;
    case Shape::darkBlue:
        return Qt::darkBlue;
    case Shape::green:
        return Qt::green;
    case Shape::darkGreen:
        return Qt::darkGreen;
    case Shape::cyan:
        return Qt::cyan;
    case Shape::darkCyan:
        return Qt::darkCyan;
    case Shape::gray:
        return Qt::gray;
    case Shape::darkGray:
        return Qt::darkGray;
    case Shape::magenta:
        return Qt::magenta;
    case Shape::darkMagenta:
        return Qt::darkMagenta;
    case Shape::yellow:
        return Qt::yellow;
    case Shape::darkYellow:
        return Qt::darkYellow;
    default:
        //错误处理暂时搁置
        break;
    }
    //条件不满足
    //暂时没想到return什么
}

//penStyle
Qt::PenStyle Draw::which_penStyle(Shape::penStyle style)
{
    switch (style) {
    case Shape::penStyle::solid:
        penStyle = Qt::SolidLine;
        break;
    case Shape::penStyle::dash:
        penStyle = Qt::DashLine;
        break;
    case Shape::penStyle::dot:
        penStyle = Qt::DotLine;
        break;
    case Shape::penStyle::dashdot:
        penStyle = Qt::DashDotLine;
        break;
    case Shape::penStyle::dashdotdot:
        penStyle = Qt::DashDotDotLine;
        break;
    case Shape::penStyle::custom:
        penStyle = Qt::CustomDashLine;
        break;
    default:
        //错误处理
        break;
    }
    return penStyle;
}
//joinstyle
Qt::PenJoinStyle Draw::which_penJoinStyle(Shape::penStyle style)
{
    switch (style) {
    case Shape::bevel:
        penJoinStyle = Qt::BevelJoin;
        break;
    case Shape::miter:
        penJoinStyle = Qt::MiterJoin;
        break;
    case Shape::roundjoin:
        penJoinStyle = Qt::RoundJoin;
        break;
    default:
        //错误处理
        break;
    }
    return penJoinStyle;
}

void Draw::setEditMode(Shape::editMode edit)
{
    edit_selected = edit;
}
//capstyle
Qt::PenCapStyle Draw::which_penCapStyle(Shape::penStyle style)
{
    switch (style) {
    case Shape::penStyle::square:
        penCapStyle = Qt::SquareCap;
        break;
    case Shape::penStyle::flat:
        penCapStyle = Qt::FlatCap;
        break;
    case Shape::penStyle::roundcap:
        penCapStyle = Qt::RoundCap;
        break;
    default:
        //错误处理
        break;
    }
    return penCapStyle;
}
//画画测试
void Draw::draw_test()
{

}

void Draw::selectPen_drawing()
{
    QColor l_color = getColor();
//    if(isRubber){
//        l_color = Qt::white;
//    }
    QPainter painter;
    l_color.setAlpha(d_alpha);
    //画tempix类
    QPen pen(l_color, pen_size);
//    if(isRubber){
//        pen.setCapStyle(which_penCapStyle(Shape::penStyle::roundcap));
//    }

    painter.begin(&tempPix);
    painter.setPen(pen);
    painter.drawLine(startPoint,endPoint);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    //关键
    startPoint=endPoint;
    //2d图形统一的标准
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::selectRubber_drawing()
{
    QPainter painter;
    QPen pen(Qt::white, pen_size);
    pen.setCapStyle(which_penCapStyle(Shape::penStyle::roundcap));
    painter.begin(&tempPix);
    painter.setPen(pen);
    painter.drawLine(startPoint,endPoint);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    //关键
    startPoint=endPoint;

    if(!isDrawing){
        pix = tempPix;
    }
}
//方便临时更改进行重复写操作
void Draw::selectPencil_drawing()
{
    QColor l_color = getColor();
    QPainter painter;
    l_color.setAlpha(d_alpha);
    //画tempix类
    QPen pen(l_color, pen_size);
    pen.setCapStyle(which_penCapStyle(Shape::penStyle::roundcap));
    painter.begin(&tempPix);
    painter.setPen(pen);
    painter.drawLine(startPoint,endPoint);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    //关键
    startPoint=endPoint;
    //2d图形统一的标准
    if(!isDrawing){
        pix = tempPix;
    }
}

//2d图形类暂时默认pensize为3
void Draw::draw_line()
{
    QPainter painter;
    QColor l_color=getColor();
    //画tempix类
    QPen pen(l_color, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    painter.begin(&tempPix);
    painter.setPen(pen);
    painter.drawLine(startPoint,endPoint);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_upArc()
{
    QPainter painter;
    QColor l_color=getColor();
    //画tempix类
    QPen pen(l_color, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    painter.begin(&tempPix);
    painter.setPen(pen);
    //看文档
    painter.drawArc(QRect(startPoint,endPoint),30*16,120*16);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_downArc()
{
    QPainter painter;
    QColor l_color=getColor();
    //画tempix类
    QPen pen(l_color, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);

    painter.begin(&tempPix);
    painter.setPen(pen);
    //看文档
    painter.drawArc(QRect(startPoint,endPoint),-30*16,-120*16);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_ellipse()
{
    //获取坐标
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    QPainter painter;
    QColor l_color=getColor();
    //画tempix类
    QPen pen(l_color, 3);

    painter.begin(&tempPix);
    painter.setPen(pen);
    painter.drawEllipse(x,y,width,height);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_chord()
{
    //获取坐标
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    QPainter painter;
    QColor l_color=getColor();
    //画tempix类
    QPen pen(l_color, 3);

    painter.begin(&tempPix);
    painter.setPen(pen);
    painter.drawChord(x,y,width,height,30*16,120*16);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_rect()
{
    //获取坐标
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    painter.drawRect(x,y,width,height);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_roundRect()
{

    //获取坐标
    int x = startPoint.x();
    int y = startPoint.y();
    int width = endPoint.x() - x;
    int height = endPoint.y() - y;
    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    //这里先设置弧度为5
    painter.drawRoundedRect(x,y,width,height,30,30);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_triangle()
{
    //获取坐标
    int x1 = startPoint.x();
    int y1 = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    //获取顶点集合
    QPointF points[3] = {
          QPointF(x1,y2),
          QPointF((x1+x2)/2,y1),
          QPointF(x2,y2)
   };

    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    //这里先设置弧度为5
    painter.drawConvexPolygon(points,3);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_pentagon()
{
    //获取坐标
    int x1 = startPoint.x();
    int y1 = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    //计算出中心点位置
    int midx = (startPoint.x()+endPoint.x())/2;
    int midy = (startPoint.y()+endPoint.y())/2;
    int r = qMin(x2-x1,y2-y1);

    //正五边形顶点计算规则
    int n=5;
    //获取顶点集合
    QPointF points[n];
    for(int i=0; i < n;i++){
        //设置各个顶点的值
        points[i] = QPointF(midx+r*qSin(2*M_PI*i/n),midy+r*qCos(2*M_PI*i/n));
    }

    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    //这里先设置弧度为5
    painter.drawConvexPolygon(points,n);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_hexagon()
{
    //获取坐标
    int x1 = startPoint.x();
    int y1 = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    //计算出中心点位置
    int midx = (startPoint.x()+endPoint.x())/2;
    int midy = (startPoint.y()+endPoint.y())/2;
    int r = qMin(x2-x1,y2-y1);

    //正五边形顶点计算规则
    int n=6;
    //获取顶点集合
    QPointF points[n];
    for(int i=0; i < n;i++){
        //设置各个顶点的值
        points[i] = QPointF(midx+r*qSin(2*M_PI*i/n),midy+r*qCos(2*M_PI*i/n));
    }

    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    painter.drawConvexPolygon(points,n);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_heptagon()
{
    //获取坐标
    int x1 = startPoint.x();
    int y1 = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    //计算出中心点位置
    int midx = (startPoint.x()+endPoint.x())/2;
    int midy = (startPoint.y()+endPoint.y())/2;
    int r = qMin(x2-x1,y2-y1);

    //正五边形顶点计算规则
    int n=7;
    //获取顶点集合
    QPointF points[n];
    for(int i=0; i < n;i++){
        //设置各个顶点的值
        points[i] = QPointF(midx+r*qSin(2*M_PI*i/n),midy+r*qCos(2*M_PI*i/n));
    }

    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    painter.drawConvexPolygon(points,n);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_diamond()
{
    //获取坐标
    int x1 = startPoint.x();
    int y1 = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    //获取顶点集合
    QPointF points[4] = {
      QPointF((x1+x2)/2,y1),
      QPointF(x2,(y1+y2)/2),
      QPointF((x1+x2)/2,y2),
      QPointF(x1,(y1+y2)/2),
   };

    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    //这里先设置弧度为5
    painter.drawConvexPolygon(points,4);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_arrow()
{
    //获取坐标
    int x1 = startPoint.x();
    int y1 = startPoint.y();
    int x2 = endPoint.x();
    int y2 = endPoint.y();
    //获取顶点集合
    QPointF points[4] = {
      QPointF(x1,y2),
      QPointF((x1+x2)/2,y1),
      QPointF(x2,y2),
      QPointF((x1+x2)/2,(y1+y2)/2),
   };

    //获取painter类
    QPainter painter;
    QColor d_color = getColor();
    //画tempix类
    painter.begin(&tempPix);
    //要在这里进行换颜色
    painter.setPen(QPen(d_color,3));
    //这里先设置弧度为5
    painter.drawConvexPolygon(points,4);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);
    painter.end();
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_default_sticker(const QString &filename)
{

    QPainter painter;
    QPixmap pixmap;
    pixmap.load(filename);

    //对图片的高度进行的调整
    //宽最大600 高最大值1000
    int s_h = pixmap.height();
    int s_w = pixmap.width();

    if(s_h>150 || s_w >250){
        s_h /= 2;
        s_w /=2;
    }else if(s_h>300 || s_w >500){
        s_h/=2.5;
        s_w/=2.5;
    }else if(s_h>450 || s_w > 750){
        s_h/=3;
        s_w/=3;
    }else if(s_h>600 || s_w>750){
        //最大设置
        s_h = 1000;
        s_w = 600;
    }

    //获取坐标
    int midx = endPoint.x()-s_w/2;
    int midy = endPoint.y()-s_h/2;

    painter.begin(&tempPix);
    //画贴纸
    //保证宽高比
    pixmap=pixmap.scaled(s_w,s_h,Qt::KeepAspectRatio);
    painter.drawPixmap(midx,midy,s_w,s_h,pixmap);
    painter.end();
    //交换
    painter.begin(this);
    painter.drawPixmap(0,0,tempPix);

    painter.end();
    //关键
    //拖动的方法暂时没找到先放着
//    startPoint=endPoint;
    if(!isDrawing){
        pix = tempPix;
    }
}

void Draw::draw_editSelect_mode()
{

}

void Draw::draw_editDraw_mode()
{

}

