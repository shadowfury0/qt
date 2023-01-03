#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count()>0){
        foreach (const QCameraInfo &camerainfo, cameras) {
            qDebug() << camerainfo.description();
        }
        camera = new QCamera(cameras.at(0));
    }
    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(600,350);
    imageCaputre = new QCameraImageCapture(camera);
    camera->start();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage);
    QString fileName = QFileDialog::getSaveFileName();
    camera->searchAndLock();
    imageCaputre->capture(fileName);
    camera->unlock();
}
