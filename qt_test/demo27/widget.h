#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudioRecorder>
#include <QDebug>
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget;class QAudioRecorder;}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void udateProgress(qint64 duration);
private:
    Ui::Widget *ui;
    QAudioRecorder * audioRecorder;
};
#endif // WIDGET_H
