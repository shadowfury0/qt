#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    //串行执行
    QPushButton button("Animated Button");
    button.show();
    QPropertyAnimation * animation1 = new QPropertyAnimation(&button,"geometry");
    animation1->setDuration(2000);
    animation1->setStartValue(QRect(250,0,120,30));
    animation1->setEndValue(QRect(250,300,120,30));
    animation1->setEasingCurve(QEasingCurve::OutBounce);

    QPropertyAnimation * animation2 = new QPropertyAnimation(&button,"geomtry");
    animation2->setDuration(1000);
    animation2->setStartValue(QRect(250,300,120,30));
    animation2->setEndValue(QRect(250,300,200,60));
    QSequentialAnimationGroup group;
    group.addAnimation(animation1);
    group.addAnimation(animation2);
    group.start();
    //并行执行
//    QPushButton button1("Animated Button");
//    button1.show();
//    QPushButton button2("Ainmated Button2");
//    button2.show();
//    QPropertyAnimation * animation1 = new QPropertyAnimation(&button1,"geometry");
//    animation1->setDuration(2000);
//    animation1->setStartValue(QRect(250,0,120,30));
//    animation1->setEndValue(QRect(250,300,120,30));
//    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //
//    QPropertyAnimation * animation2 = new QPropertyAnimation(&button2,"geometry");
//    animation2->setDuration(2000);
//    animation2->setStartValue(QRect(400,300,120,30));
//    animation2->setEndValue(QRect(400,300,200,60));
//    QParallelAnimationGroup group;
//    group.addAnimation(animation1);
//    group.addAnimation(animation2);
//    group.start();
    return app.exec();
}
