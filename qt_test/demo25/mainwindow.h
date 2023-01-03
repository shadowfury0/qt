#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer * player;
private slots:
    void updatePosition(qint64 position);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_horizontalSlider_sliderMoved(int position);
    void stateChanged(QMediaPlayer::State state);
    void mediaStatusChaged(QMediaPlayer::MediaStatus status);
    void showError(QMediaPlayer::Error error);
};
#endif // MAINWINDOW_H
