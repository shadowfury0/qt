#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction * action_textFind = new QAction(tr("查找"),this);
    connect(action_textFind,&QAction::triggered,this,&MainWindow::textFind);
    ui->menubar->addAction(action_textFind);

    findDialog = new QDialog(this);
    lineEdit = new QLineEdit(this);
    QPushButton * btn= new QPushButton(findDialog);
    btn->setText(tr("查找下一个"));
    connect(btn,&QPushButton::clicked,this,&MainWindow::findNext);
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    findDialog->setLayout(layout);

    highlighter = new syntaxhighlighter(ui->textEdit->document());
    //ui->textEdit->append(tr("<h1><font color=red>使用HTML</font></h1>"));
}
void MainWindow::textFind(){
    findDialog->show();
}
void MainWindow::findNext(){
    QString string = lineEdit->text();
    bool isfind = ui->textEdit->find(string,QTextDocument::FindBackward);
    if(isfind){
        qDebug()<<tr("行号：%1 列号 %2").arg(ui->textEdit->textCursor().blockNumber())
                  .arg(ui->textEdit->textCursor().columnNumber());
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

