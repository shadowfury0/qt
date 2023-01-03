#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

QWizardPage *Widget::createPage1()
{
    QWizardPage* page =new QWizardPage;
    page->setTitle("介绍");
    return page;
}

QWizardPage *Widget::createPage2()
{
    QWizardPage* page =new QWizardPage;
    page->setTitle("用户选择信息");
    return page;
}

QWizardPage *Widget::createPage3()
{
    QWizardPage* page =new QWizardPage;
    page->setTitle("结束");
    return page;
}


void Widget::on_ColorButton_clicked()
{
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);//显示alpha选项;
    dialog.exec();
    QColor color=dialog.currentColor();
    qDebug()<<"color:"<<color;

}

void Widget::on_pushButton_clicked()
{
    bool ok;
    QFont font= QFontDialog::getFont(&ok,this);
    //如果单击按钮 ,那么让字体对话框 按钮使用新字体
    //如果单击Cancel按钮,那么输出信息
    if(ok) {
       ui->pushButton->setFont(font);
       qDebug()<<"字体为"<<font;
    }
    else qDebug()<<"没有选择字体"<<font;
}


void Widget::on_StringButton_clicked()
{
    bool ok;
    //获取字符串
    QString string= QInputDialog::getText(this,tr("输入字符串对话框"),tr("请输入用户名称"),QLineEdit::Normal
                                          ,tr("admin"),&ok);
    if (ok) qDebug() << "string" <<string;
    int value1=QInputDialog::getInt(this,tr("请输入整数对话框"),tr("请输入 -1000 到 1000之间的数值"),
                                    100,-1000,1000,2,&ok);
    if(ok) qDebug()<< "value1 :" <<value1;
    double value2 =QInputDialog::getDouble(this,tr("请输入浮点数对话框"),
                                           tr("请输入 -1000到1000之间的数值"),
                                           100,-1000,1000,2,&ok);
    if(ok) qDebug()<<"value2 : "<<value2;
    QStringList items;
    items << tr("条目1")<<tr("条目2");
    //获取条目
    QString item=QInputDialog::getItem(this,tr("条目对话框"),tr("请选择一个条目"),items,0,true,&ok);
    if(ok) qDebug()<<"item" <<item;
}

void Widget::on_Message_clicked()
{
    int ret1 = QMessageBox::question(this,tr("问题对话框"),tr("你了解qt吗"),QMessageBox::Yes,QMessageBox::No);
    if (ret1 == QMessageBox::Yes) qDebug()<< tr("问题!");
    int ret2 = QMessageBox::information(this,tr("提示对话框"),tr("这是QT书籍"),QMessageBox::Ok);
    if (ret2 = QMessageBox::Ok) qDebug() << tr("提示!");
    int ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("不能提前结束"),QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort) qDebug() << tr("警告!");
    int ret4 = QMessageBox::critical(this,tr("严重错误对话框"),tr("发现一个严重的错误"),QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll) qDebug() << tr("错误");
    QMessageBox::about(this,tr("关于对话框"),tr("yafeilinux致力于QT及QT Creator的普及工作"));
}

void Widget::on_ProcessButton_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"),0,500000,this);
    dialog.setWindowTitle(tr("进度条对话框"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.resize(400,100);
    dialog.show();
    for(int i=0;i<500000;i++){
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled())break;
    }
    dialog.setValue(500000);
    qDebug()<<tr("复制结束");
}

void Widget::on_errorButton_clicked()
{
    errordlg = new QErrorMessage(this);
    errordlg->setWindowTitle("错误信息对话框");
    errordlg->resize(300,300);
    errordlg->showMessage("这里是错误信息");
}



void Widget::on_WizardButton_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle("向导对话框");
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}

void Widget::on_label_linkActivated(const QString &link)
{
    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);
}


void Widget::on_pushButton_2_clicked(bool checked)
{
    qDebug()<<"按钮状态"<<checked;
}

void Widget::on_lineEdit_returnPressed()
{

}

void Widget::on_lineEdit_2_returnPressed()
{
    ui->lineEdit->setFocus();
    qDebug()<< ui->lineEdit_2->text();
    qDebug()<< ui->lineEdit_2->displayText();
}

void Widget::on_timeEdit_userTimeChanged(const QTime &time)
{
    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
}

void Widget::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->dateEdit->setDate(QDate::currentDate());
}

void Widget::on_verticalScrollBar_sliderMoved(int position)
{
    int a=ui->verticalScrollBar->sliderPosition();
    ui->spinBox->setValue(a);
}

void Widget::on_pushButton_3_pressed()
{
     ui->calendarWidget->setVisible(false);
}
