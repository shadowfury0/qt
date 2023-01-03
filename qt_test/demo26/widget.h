#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QDebug>
#include <QMediaRecorder>
#include <QAudioEncoderSettings>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; class QCamera; class QCameraViewfinder;class QCameraImageCapture;}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QCamera * camera;
    QCameraViewfinder * viewfinder;
    QCameraImageCapture * imageCaputre;
    QMediaRecorder * recorder;
};
#endif // WIDGET_H
