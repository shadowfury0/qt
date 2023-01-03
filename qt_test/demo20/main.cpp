#include <QApplication>
#include <QPushButton>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>
#include <QFinalState>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QPushButton button("State Machine");
    QPushButton quitButton("Quit");
    QStateMachine machine;
    QState * s1 = new QState(&machine);
    QState * s11 = new QState(s1);
    QState * s12 = new QState(s1);
    QState * s13 = new QState(s1);
    s1->setInitialState(s11);

//    QState * s2 = new QState(&machine);

//    QState * s3 = new QState(&machine);
    s11->assignProperty(&button,"geometry",QRect(100,100,120,50));
    s12->assignProperty(&button,"geometry",QRect(300,100,120,50));
    s13->assignProperty(&button,"geometry",QRect(200,200,120,50));
    machine.setInitialState(s1);
    machine.start();
    button.show();
    QSignalTransition *transition1 = s11->addTransition(&button,SIGNAL(clicked()),s12);
    QSignalTransition *transition2 = s12->addTransition(&button,SIGNAL(clicked()),s13);
    QSignalTransition *transition3 = s13->addTransition(&button,SIGNAL(clicked()),s11);

    QPropertyAnimation * animation = new QPropertyAnimation(&button,"geometry");
//    transition1->addAnimation(animation);
//    transition2->addAnimation(animation);
//    transition3->addAnimation(animation);
    machine.addDefaultAnimation(animation);
    QObject::connect(s13,&QState::entered,&button,&QPushButton::showMinimized);
    QFinalState * s2 = new QFinalState(&machine);
    s1->addTransition(&quitButton,&QPushButton::clicked,s2);
    QObject::connect(&machine,&QStateMachine::finished,qApp,&QApplication::quit);
    machine.setInitialState(s1);
    machine.start();
    button.show();
    quitButton.show();
    return app.exec();
}
