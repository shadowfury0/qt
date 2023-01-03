#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction * action_textTable = new QAction(tr("表格"),this);
    QAction * action_textList = new QAction(tr("列表"),this);

    connect(action_textTable,&QAction::triggered,this,&MainWindow::insertTable);
    connect(action_textList,&QAction::triggered,this,&MainWindow::insertList);

    ui->menubar->addAction(action_textTable);
    ui->menubar->addAction(action_textList);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::insertTable(){
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);
    format.setCellPadding(10);
    cursor.insertTable(2,2,format);
}
void MainWindow::insertList(){
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);
    ui->textEdit->textCursor().insertList(format);
}
void MainWindow::insertImage(){
    QTextImageFormat format;
    format.setName("");
    ui->textEdit->textCursor().insertImage(format);
}
