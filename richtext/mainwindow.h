#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private slots:
    void showTextFrame();            // 遍历文档框架
    void showTextBlock();            // 遍历所有文本块
    void setTextFont(bool checked);  // 设置字体格式
};
#endif // MAINWINDOW_H
