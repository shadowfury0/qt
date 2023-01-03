#ifndef MYSWITCHBUTTON_H
#define MYSWITCHBUTTON_H

#include <QWidget>
class MySwitchButton : public QWidget
{
    Q_OBJECT
public:
    MySwitchButton(QWidget * parent = nullptr);
    ~MySwitchButton();
    virtual void paintEvent(QPaintEvent *event) override;
private:
    bool isCheck;
};

#endif // MYSWITCHBUTTON_H
