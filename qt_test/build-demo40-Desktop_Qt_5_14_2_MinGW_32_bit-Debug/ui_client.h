/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QProgressBar *progressBar;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(800, 600);
        QFont font;
        font.setPointSize(15);
        Client->setFont(font);
        lineEdit = new QLineEdit(Client);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 50, 231, 31));
        lineEdit_2 = new QLineEdit(Client);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 140, 231, 31));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 270, 131, 31));
        pushButton_2 = new QPushButton(Client);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 270, 121, 31));
        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 81, 21));
        QFont font1;
        font1.setPointSize(13);
        label->setFont(font1);
        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 140, 81, 21));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_3 = new QLabel(Client);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 230, 231, 31));
        label_3->setFont(font1);
        progressBar = new QProgressBar(Client);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 190, 471, 23));
        progressBar->setValue(0);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        pushButton->setText(QCoreApplication::translate("Client", "\346\211\223\345\274\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Client", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("Client", "\344\270\273\346\234\272\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Client", "\347\253\257\345\217\243\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Client", "\347\212\266\346\200\201\357\274\232\347\255\211\345\276\205\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
