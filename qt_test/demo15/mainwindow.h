#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include "widget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_verticalScrollBar_valueChanged(int value);

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    Widget *w ;
    QScrollBar *q;

};

#endif // MAINWINDOW_H
