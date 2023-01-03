#include "mywidget.h"
#include <QApplication>
#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget w;
    w.resize(1000,800);
    w.show();
//   QApplication app( argc, argv );

//   QDialog * dlg = new QDialog();
//   dlg->setGeometry( 100, 100, 260, 260);

//   QScrollArea *scrollArea = new QScrollArea( dlg );
//   scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
//   scrollArea->setWidgetResizable( true );
//   scrollArea->setGeometry( 10, 10, 200, 200 );

//   QWidget *widget = new QWidget();
//   scrollArea->setWidget( widget );

//   QVBoxLayout *layout = new QVBoxLayout(dlg);
//   widget->setLayout( layout );

//   for (int i = 0; i < 10; i++)
//   {
//       QPushButton *button = new QPushButton( QString( "%1" ).arg( i ) );
//       layout->addWidget( button );
//   }

//   dlg->show();
   return app.exec();
}
