#ifndef BATTERY_H
#define BATTERY_H

#include <QWidget>
#include <QColor>

class Battery:public QWidget
{
    Q_OBJECT
private:
    QColor mColorBack = Qt::white;
    QColor mColorBorder = Qt::white;
    QColor mColorPower = Qt::black;
    QColor mColorWarning = Qt::red;
    int mPowerLevel = 60;
    int mWarnLevl = 20;
public:
    Battery(QWidget * parent = 0);
    ~Battery();
    void setPowerLevel(int pow);
    int powerLevel();
    void setWarnLevel(int warn);
    int warnLevel();
    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;
signals:
    void powerLevelChanged(int);
};

#endif // BATTERY_H
