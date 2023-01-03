#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;class QMovie; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_toggled(bool checked);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QMovie * movie;
};
#endif // MAINWINDOW_H
