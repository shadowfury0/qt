#include "emojidialog.h"

#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
EmojiDialog::EmojiDialog(QWidget *parent):QDialog(parent)
{
    //定死大小
//    this->setFixedSize(300,180);
//    this->resize(250,180);
    this->setWindowTitle("emoji");
    layout = new QGridLayout;
    //设置按钮大小为窗口大小
    layout->setContentsMargins(10,10,10,10);
    //垂直间距
    layout->setVerticalSpacing(2);
    //水平间距
    layout->setHorizontalSpacing(3);
//    layout->setSpacing(0);
    //设置文件路径
//    buttonInit();

    this->setLayout(layout);
    qDebug() << " h :" << this->height() << " w: " << this->width();
}

EmojiDialog::~EmojiDialog()
{
    delete layout;
    //贴纸
    delete em1;delete em2;delete em3;delete em4;delete em5;delete em6;
    delete em7;delete em8;delete em9;delete em10;delete em11;delete em12;
    delete em13;delete em14;delete em15;delete em16;delete em17;delete em18;
    delete em19;delete em20;delete em21;delete em22;delete em23;delete em24;
    delete em25;delete em26;delete em27;delete em28;delete em29;delete em30;
    delete em31;delete em32;delete em33;delete em34;delete em35;delete em36;
    delete em37;delete em38;delete em39;delete em40;
}

EmojiDialog::buttonInit()
{
    //按钮大小统一标准
    int btn_size = 36;
    //按钮统一标准
    em1 = new QPushButton(this);
    em1->setObjectName("em1");

//    qDebug() << em1->objectName();
    em1->setFixedSize(btn_size,btn_size);
    layout->addWidget(em1,0,0);

    em2 = new QPushButton(this);
    em2->setObjectName("em2");

//    qDebug() << em2->objectName();
    em2->setFixedSize(btn_size,btn_size);
    layout->addWidget(em2,0,1);

    em3 = new QPushButton(this);
    em3->setObjectName("em3");

//    qDebug() << em3->objectName();
    em3->setFixedSize(btn_size,btn_size);
    layout->addWidget(em3,0,2);

    em4 = new QPushButton(this);
    em4->setObjectName("em4");

//    qDebug() << em4->objectName();
    em4->setFixedSize(btn_size,btn_size);
    layout->addWidget(em4,0,3);

    em5 = new QPushButton(this);
    em5->setObjectName("em5");

//    qDebug() << em5->objectName();
    em5->setFixedSize(btn_size,btn_size);
    layout->addWidget(em5,0,4);

    em6 = new QPushButton(this);
    em6->setObjectName("em6");

//    qDebug() << em6->objectName();
    em6->setFixedSize(btn_size,btn_size);
    layout->addWidget(em6,0,5);

    em7 = new QPushButton(this);
    em7->setObjectName("em7");

//    qDebug() << em7->objectName();
    em7->setFixedSize(btn_size,btn_size);
    layout->addWidget(em7,0,6);

    em8 = new QPushButton(this);
    em8->setObjectName("em8");

//    qDebug() << em8->objectName();
    em8->setFixedSize(btn_size,btn_size);
    layout->addWidget(em8,0,7);

    em9 = new QPushButton(this);
    em9->setObjectName("em9");

//    qDebug() << em9->objectName();
    em9->setFixedSize(btn_size,btn_size);
    layout->addWidget(em9,1,0);

    em10 = new QPushButton(this);
    em10->setObjectName("em10");

//    qDebug() << em10->objectName();
    em10->setFixedSize(btn_size,btn_size);
    layout->addWidget(em10,1,1);

    em11 = new QPushButton(this);
    em11->setObjectName("em11");

//    qDebug() << em11->objectName();
    em11->setFixedSize(btn_size,btn_size);
    layout->addWidget(em11,1,2);

    em12 = new QPushButton(this);
    em12->setObjectName("em12");

//    qDebug() << em12->objectName();
    em12->setFixedSize(btn_size,btn_size);
    layout->addWidget(em12,1,3);

    em13 = new QPushButton(this);
    em13->setObjectName("em13");

//    qDebug() << em13->objectName();
    em13->setFixedSize(btn_size,btn_size);
    layout->addWidget(em13,1,4);

    em14 = new QPushButton(this);
    em14->setObjectName("em14");

//    qDebug() << em14->objectName();
    em14->setFixedSize(btn_size,btn_size);
    layout->addWidget(em14,1,5);

    em15 = new QPushButton(this);
    em15->setObjectName("em15");

//    qDebug() << em15->objectName();
    em15->setFixedSize(btn_size,btn_size);
    layout->addWidget(em15,1,6);

    em16 = new QPushButton(this);
    em16->setObjectName("em16");

//    qDebug() << em16->objectName();
    em16->setFixedSize(btn_size,btn_size);
    layout->addWidget(em16,1,7);

    em17 = new QPushButton(this);
    em17->setObjectName("em17");

//    qDebug() << em17->objectName();
    em17->setFixedSize(btn_size,btn_size);
    layout->addWidget(em17,2,0);

    em18 = new QPushButton(this);
    em18->setObjectName("em18");

//    qDebug() << em18->objectName();
    em18->setFixedSize(btn_size,btn_size);
    layout->addWidget(em18,2,1);

    em19 = new QPushButton(this);
    em19->setObjectName("em19");

//    qDebug() << em19->objectName();
    em19->setFixedSize(btn_size,btn_size);
    layout->addWidget(em19,2,2);

    em20 = new QPushButton(this);
    em20->setObjectName("em20");

//    qDebug() << em20->objectName();
    em20->setFixedSize(btn_size,btn_size);
    layout->addWidget(em20,2,3);

    em21 = new QPushButton(this);
    em21->setObjectName("em21");

//    qDebug() << em21->objectName();
    em21->setFixedSize(btn_size,btn_size);
    layout->addWidget(em21,2,4);

    em22 = new QPushButton(this);
    em22->setObjectName("em22");

//    qDebug() << em22->objectName();
    em22->setFixedSize(btn_size,btn_size);
    layout->addWidget(em22,2,5);

    em23 = new QPushButton(this);
    em23->setObjectName("em23");

//    qDebug() << em23->objectName();
    em23->setFixedSize(btn_size,btn_size);
    layout->addWidget(em23,2,6);

    em24 = new QPushButton(this);
    em24->setObjectName("em24");

//    qDebug() << em24->objectName();
    em24->setFixedSize(btn_size,btn_size);
    layout->addWidget(em24,2,7);

    em25 = new QPushButton(this);
    em25->setObjectName("em25");

//    qDebug() << em25->objectName();
    em25->setFixedSize(btn_size,btn_size);
    layout->addWidget(em25,3,0);

    em26 = new QPushButton(this);
    em26->setObjectName("em26");

//    qDebug() << em26->objectName();
    em26->setFixedSize(btn_size,btn_size);
    layout->addWidget(em26,3,1);

    em27 = new QPushButton(this);
    em27->setObjectName("em27");

//    qDebug() << em27->objectName();
    em27->setFixedSize(btn_size,btn_size);
    layout->addWidget(em27,3,2);

    em28 = new QPushButton(this);
    em28->setObjectName("em28");

//    qDebug() << em28->objectName();
    em28->setFixedSize(btn_size,btn_size);
    layout->addWidget(em28,3,3);

    em29 = new QPushButton(this);
    em29->setObjectName("em29");

//    qDebug() << em29->objectName();
    em29->setFixedSize(btn_size,btn_size);
    layout->addWidget(em29,3,4);

    em30 = new QPushButton(this);
    em30->setObjectName("em30");

//    qDebug() << em30->objectName();
    em30->setFixedSize(btn_size,btn_size);
    layout->addWidget(em30,3,5);

    em31 = new QPushButton(this);
    em31->setObjectName("em31");

//    qDebug() << em31->objectName();
    em31->setFixedSize(btn_size,btn_size);
    layout->addWidget(em31,3,6);

    em32 = new QPushButton(this);
    em32->setObjectName("em32");

//    qDebug() << em32->objectName();
    em32->setFixedSize(btn_size,btn_size);
    layout->addWidget(em32,3,7);

    em33 = new QPushButton(this);
    em33->setObjectName("em33");

//    qDebug() << em33->objectName();
    em33->setFixedSize(btn_size,btn_size);
    layout->addWidget(em33,4,0);

    em34 = new QPushButton(this);
    em34->setObjectName("em34");

//    qDebug() << em34->objectName();
    em34->setFixedSize(btn_size,btn_size);
    layout->addWidget(em34,4,1);

    em35 = new QPushButton(this);
    em35->setObjectName("em35");

//    qDebug() << em35->objectName();
    em35->setFixedSize(btn_size,btn_size);
    layout->addWidget(em35,4,2);

    em36 = new QPushButton(this);
    em36->setObjectName("em36");

//    qDebug() << em36->objectName();
    em36->setFixedSize(btn_size,btn_size);
    layout->addWidget(em36,4,3);

    em37 = new QPushButton(this);
    em37->setObjectName("em37");

//    qDebug() << em37->objectName();
    em37->setFixedSize(btn_size,btn_size);
    layout->addWidget(em37,4,4);

    em38 = new QPushButton(this);
    em38->setObjectName("em38");

//    qDebug() << em38->objectName();
    em38->setFixedSize(btn_size,btn_size);
    layout->addWidget(em38,4,5);

    em39 = new QPushButton(this);
    em39->setObjectName("em39");

//    qDebug() << em39->objectName();
    em39->setFixedSize(btn_size,btn_size);
    layout->addWidget(em39,4,6);

    em40 = new QPushButton(this);
    em40->setObjectName("em40");

//    qDebug() << em40->objectName();
    em40->setFixedSize(btn_size,btn_size);
    layout->addWidget(em40,4,7);

    //改变按钮形状
    changeButtonIcon();
}

QString EmojiDialog::getDirName()
{
    return dirName;
}

void EmojiDialog::setDirName(const QString name)
{
    dirName = name;
}

void EmojiDialog::changeButtonIcon()
{
    quint8 num = 0;
    QList<QPushButton*> qbtn = this->findChildren<QPushButton*>();
    foreach (QPushButton * i,qbtn) {
        i->setIcon(QIcon(tr(":/sticker/picture/%1/%2.png").arg(dirName).arg(++num)));
    }
}
