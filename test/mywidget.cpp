#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QCursor>
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    pix = QPixmap(800,600);
    pix.fill(Qt::white);
    temp = pix;
    lastTemp = temp;
    lastP = temp;
    isSelect = false;
    isDragging = false;
    isPicking = true;
    isDrawing = false;
}

MyWidget::~MyWidget()
{
    delete ui;
}
//QCursor cursor;
//cursor.setShape(Qt::CrossCursor);
//QApplication::setOverrideCursor(cursor);
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    if(isDragging){
        if(event->button() == Qt::LeftButton){
            //要判断start和end大小
            //默认左上右下
            start = event->pos();
            isDrawing = true;
            pix = lastTemp;
        }
    }else{
        if(isSelect){
            if(event->button() == Qt::LeftButton){
                //判断条件
                if(false){
                    isDragging = true;
                }else{
                    isDragging = false;
                }
            }
        }else{
            if(event->button() == Qt::LeftButton){
                pix = lastP;
                start = event->pos();
                isDrawing = true;
            }
        }
//        if(isDragging){
//            if(event->button() == Qt::LeftButton){
//            //要判断start和end大小
//            //默认左上右下
//            start = event->pos();
//            isDrawing = true;
//            pix = lastTemp;
//        }else{
//            pix = lastP;
//            start = event->pos();
//            isDrawing = true;
//        }

//        }
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        end = event->pos();
        temp = pix;
        update();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        end = event->pos();
        isDrawing = false;
        update();
    }
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    if(isDragging){
        int w = end1.x() - start1.x();
        int h = end1.y() - start1.y();
        QPainter painter;
        painter.begin(&temp);
        painter.drawRect(end.x(),end.y(),w,h);
        painter.end();

        painter.begin(this);
        painter.drawPixmap(0,0,temp);
        painter.end();
        if(!isDrawing){
            pix = temp;
            lastP = pix;
        }
    }else{

        int x = start.x();
        int y = start.y();
        int w = end.x() - x;
        int h = end.y() - y;

        QPainter painter;
        painter.begin(&temp);
        painter.drawRect(x,y,w,h);
        painter.end();

        painter.begin(this);
        painter.drawPixmap(0,0,temp);
        if(!isDrawing){
            pix = temp;
            lastTemp = lastP;
            start1 = start;
            end1 = end;
            //结束

        }
    }
}

void MyWidget::on_pushButton_clicked()
{
    isDragging = true;
}

void MyWidget::on_pushButton_2_clicked()
{
    isDragging = false;
}
