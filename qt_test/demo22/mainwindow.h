#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSoundEffect>
#include <QMainWindow>
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class QSoundEffect;class QMediaPlayer;class QVideoWidget;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSoundEffect * effect;
    QMediaPlayer * player;
    QVideoWidget * videoWidget;
};
#endif // MAINWINDOW_H
