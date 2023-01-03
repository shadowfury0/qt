#ifndef EMOJIDIALOG_H
#define EMOJIDIALOG_H

#include <QDialog>

class QPushButton;
class QGridLayout;
class EmojiDialog :public QDialog
{
public:
    EmojiDialog(QWidget *parent = nullptr);
    ~EmojiDialog();


    buttonInit();
    QString getDirName();
    void setDirName(const QString name);

    void changeButtonIcon();

    QPushButton *em1,*em2,*em3,*em4,*em5,*em6,
                *em7,*em8,*em9,*em10,*em11,*em12,
                *em13,*em14,*em15,*em16,*em17,*em18,
                *em19,*em20,*em21,*em22,*em23,*em24,
                *em25,*em26,*em27,*em28,*em29,*em30,
                *em31,*em32,*em33,*em34,*em35,*em36,
                *em37,*em38,*em39,*em40;

private:
    QString dirName="";
    //设置布局
    QGridLayout * layout;
    //设置颜表情按钮
};

#endif // EMOJIDIALOG_H
