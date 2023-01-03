#ifndef MYDESIGNERPLUGIN_H
#define MYDESIGNERPLUGIN_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
class MyDesignerPlugin : public QWidget
{
    Q_OBJECT

public:
    MyDesignerPlugin(QWidget *parent = 0);
};

#endif // MYDESIGNERPLUGIN_H
