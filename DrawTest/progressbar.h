#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QWidget>
#include <QCommonStyle>
#include <QProgressBar>
class progressBar :public QProgressBar
{
    Q_OBJECT
public:
    progressBar(QWidget * parent = nullptr);
    ~progressBar();
    void paintEvent(QPaintEvent *) override;
//    void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w = nullptr) const override;
//    void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w = nullptr) const override;
};

#endif // PROGRESSBAR_H
