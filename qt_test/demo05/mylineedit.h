#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>
#include <QLineEdit>
class MyLineEdit : public QLineEdit
{
public:
    explicit MyLineEdit(QWidget *parent = 0) :
        QLineEdit(parent)
    {

    }
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYLINEEDIT_H
