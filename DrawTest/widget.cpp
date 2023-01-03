#include "widget.h"
#include "ui_widget.h"
#include "scroll.h"
#include "mstyle.h"
#include <QPainter>
#include <QDebug>
#include <QStyleFactory>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QMouseEvent>
#include <QPoint>
#include <QColorDialog>
#include <QtMath>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ScrollButton *button = new ScrollButton(this);
//    button->reSize(50,50);
//    button->move(50,50);
//    button->setVisible(true);
//    qDebug() << " height : " << button->getHeight() << " width : " << button->getWidth()<< endl;

//    ScrollLine *line = new ScrollLine(this);
//    line->reSize(50,2);
//    line->move(100,100);
//    line->setVisible(true);

//    connect(this->ui->pushButton,&QPushButton::clicked,line,&ScrollLine::reverse);

    Scroll *scroll = new Scroll(this);
    scroll->reSize(200,30);
    scroll->move(200,50);

//    testProgressBar * test = new testProgressBar(this);
//    test->resize(60,10);
//    test->move(50,200);
    MStyle *m = new MStyle;
    this->ui->pushButton->setStyle(m);
    this->ui->pushButton->setPalette(m->standardPalette());
    this->ui->pushButton->setText(tr("asdd"));
    //这样子设置
//    this->ui->pushButton->setPalette(m->standardPalette());
//    this->ui->pushButton->setPalette(QPalette(Qt::red));
//    QPalette p;
//    p.setBrush(QPalette::Active,QPalette::ButtonText,QBrush(Qt::green));

//    p.setBrush(QPalette::Active,QPalette::Base,QBrush(Qt::red));

//    this->ui->applyStyleButton->setPalette(p);
//    this->ui->horizontalSlider->setStyle(m);
//    this->ui->horizontalSlider->setPalette(m->standardPalette());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

//    painter.setPen(QPen(Qt::DashLine));
//    painter.setPen(QPen(Qt::black,5,Qt::DashLine));
//    painter.drawRect(100,100,200,200);

//    QPixmap pix;
//    pix.load(":/picture/1491-2020-08-28021821-1598595501727.jpg");
//    pix=pix.scaled(this->size(),Qt::IgnoreAspectRatio);
//    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
//    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
//    painter.setBrush(QColor(255,255,255,100));
//    painter.drawRect(0,0,pix.width(),pix.height());
//    painter.drawPixmap(100,0,pix.width(),pix.height(),pix);
//    painter.setBrush(QColor(0,0,255,100));
//    painter.drawRect(100,0,pix.width(),pix.height());

//    int midx = 100;
//    int midy = 100;
//    int r= 50;

//    QPointF points[5]={QPointF(10,20),QPointF(20,30),QPointF(30,40),QPointF(20,40),QPointF(10,30)} ;
//    points[0] = QPointF(0,50);
//    points[1] = QPointF(25,0);
//    points[2] = QPointF(75,0);
//    points[3] = QPointF(100,50);
//    points[4] = QPointF(75,100);
//    points[5] = QPointF(25,100);
//    int n=5;
//    QPointF points[n];
//    for(int i=0; i < n;i++){
//        //设置各个顶点的值
//        points[i] = QPointF(midx+r*qCos(2*M_PI*i/n),midy+r*qSin(2*M_PI*i/n));
//    }
//    painter.drawConvexPolygon(points,5);
//    painter.setPen(QPen(Qt::black,6));
//    painter.drawLine(0,0,100,100);
}


void Widget::on_pushButton_2_clicked()
{
    QColor c = QColorDialog::getColor(Qt::white,this,tr("颜色对话框"));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){

        QPoint point = event->pos();
        QPixmap pix = QPixmap::grabWidget(this,point.x(),point.y(),1,1);
        QColor c = pix.toImage().pixel(0,0);
        qDebug() << "red : " << c.red() << "green : " << c.green() << "blue : " << c.blue();
    }
}


