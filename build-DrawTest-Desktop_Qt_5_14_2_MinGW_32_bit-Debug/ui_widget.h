/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QScrollBar *horizontalScrollBar;
    QPushButton *pushButton;
    QComboBox *styleComboBox;
    QPushButton *applyStyleButton;
    QCheckBox *enableEditCheckBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setStyleSheet(QString::fromUtf8(""));
        horizontalScrollBar = new QScrollBar(Widget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(580, 240, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 70, 93, 28));
        styleComboBox = new QComboBox(Widget);
        styleComboBox->setObjectName(QString::fromUtf8("styleComboBox"));
        styleComboBox->setGeometry(QRect(580, 350, 87, 22));
        applyStyleButton = new QPushButton(Widget);
        applyStyleButton->setObjectName(QString::fromUtf8("applyStyleButton"));
        applyStyleButton->setGeometry(QRect(580, 400, 93, 28));
        applyStyleButton->setStyleSheet(QString::fromUtf8(""));
        enableEditCheckBox = new QCheckBox(Widget);
        enableEditCheckBox->setObjectName(QString::fromUtf8("enableEditCheckBox"));
        enableEditCheckBox->setGeometry(QRect(700, 350, 91, 19));
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(580, 190, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        applyStyleButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        enableEditCheckBox->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
