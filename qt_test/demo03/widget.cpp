#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::dragEnterEvent(QDragEnterEvent *event){
    if(event->mimeData()->hasUrls()){
        event->acceptProposedAction();
    }else{
        event->ignore();
    }
}
void Widget::dropEvent(QDropEvent *event){
    const QMimeData * mimeData = event->mimeData();
    if(mimeData->hasUrls()){
        QList<QUrl> urlList = mimeData->urls();
        QString filename = urlList.at(0).toLocalFile();
        if(!filename.isEmpty()){
            QFile file(filename);
            if(!file.open(QIODevice::ReadOnly)) return;
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    }
}
