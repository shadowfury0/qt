#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "syntaxhighlighter.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDialog>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;class QLindEdit;class QDialog;class syntaxhighlighter; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit * lineEdit;
    QDialog * findDialog;
    syntaxhighlighter * highlighter;
private slots:
    void textFind();
    void findNext();
};
#endif // MAINWINDOW_H
