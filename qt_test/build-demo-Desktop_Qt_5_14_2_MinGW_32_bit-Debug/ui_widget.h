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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *ColorButton;
    QPushButton *pushButton;
    QPushButton *StringButton;
    QPushButton *Message;
    QPushButton *ProcessButton;
    QPushButton *errorButton;
    QPushButton *WizardButton;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QScrollBar *verticalScrollBar;
    QSpinBox *spinBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFontComboBox *fontComboBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_3;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1291, 741);
        ColorButton = new QPushButton(Widget);
        ColorButton->setObjectName(QString::fromUtf8("ColorButton"));
        ColorButton->setGeometry(QRect(100, 60, 93, 28));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 60, 93, 28));
        StringButton = new QPushButton(Widget);
        StringButton->setObjectName(QString::fromUtf8("StringButton"));
        StringButton->setGeometry(QRect(100, 120, 93, 28));
        Message = new QPushButton(Widget);
        Message->setObjectName(QString::fromUtf8("Message"));
        Message->setGeometry(QRect(240, 120, 93, 28));
        ProcessButton = new QPushButton(Widget);
        ProcessButton->setObjectName(QString::fromUtf8("ProcessButton"));
        ProcessButton->setGeometry(QRect(100, 180, 93, 28));
        errorButton = new QPushButton(Widget);
        errorButton->setObjectName(QString::fromUtf8("errorButton"));
        errorButton->setGeometry(QRect(240, 180, 93, 28));
        WizardButton = new QPushButton(Widget);
        WizardButton->setObjectName(QString::fromUtf8("WizardButton"));
        WizardButton->setGeometry(QRect(170, 250, 93, 28));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(450, 60, 120, 80));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(5);
        frame->setMidLineWidth(10);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 250, 91, 21));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 390, 151, 151));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/51341/Pictures/1491-2020-08-28021821-1598595501727.jpg")));
        label_2->setScaledContents(true);
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(410, 400, 64, 23));
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setProperty("value", QVariant(456.120000000000005));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 310, 93, 28));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(450, 330, 191, 21));
        lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(450, 290, 191, 21));
        lineEdit_2->setEchoMode(QLineEdit::Normal);
        verticalScrollBar = new QScrollBar(Widget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(740, 50, 16, 160));
        verticalScrollBar->setMaximum(200);
        verticalScrollBar->setSingleStep(1);
        verticalScrollBar->setPageStep(1);
        verticalScrollBar->setOrientation(Qt::Vertical);
        verticalScrollBar->setInvertedAppearance(true);
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(680, 110, 41, 71));
        spinBox->setMaximum(200);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(830, 430, 281, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        fontComboBox = new QFontComboBox(verticalLayoutWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        verticalLayout->addWidget(fontComboBox);

        verticalLayoutWidget_2 = new QWidget(Widget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(440, 450, 301, 261));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 9, -1, -1);

        verticalLayout_2->addLayout(verticalLayout_3);

        timeEdit = new QTimeEdit(verticalLayoutWidget_2);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setWrapping(false);
        timeEdit->setCalendarPopup(true);

        verticalLayout_2->addWidget(timeEdit);

        dateEdit = new QDateEdit(verticalLayoutWidget_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        verticalLayout_2->addWidget(dateEdit);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        verticalLayout_2->addLayout(verticalLayout_4);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(910, 110, 93, 28));
        calendarWidget = new QCalendarWidget(Widget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(820, 150, 296, 218));

        retranslateUi(Widget);
        QObject::connect(pushButton, SIGNAL(pressed()), Widget, SLOT(show()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        ColorButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\233\264\346\224\271\345\255\227\344\275\223", nullptr));
        StringButton->setText(QCoreApplication::translate("Widget", "\350\276\223\345\205\245\345\255\227\347\254\246\344\270\262", nullptr));
        Message->setText(QCoreApplication::translate("Widget", "\346\266\210\346\201\257\346\217\220\347\244\272", nullptr));
        ProcessButton->setText(QCoreApplication::translate("Widget", "\350\277\233\345\272\246\346\235\241\345\257\271\350\257\235\346\241\206", nullptr));
        errorButton->setText(QCoreApplication::translate("Widget", "\351\224\231\350\257\257", nullptr));
        WizardButton->setText(QCoreApplication::translate("Widget", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206", nullptr));
        label->setText(QCoreApplication::translate("Widget", "kkkkkkkkkkkkkkkkkkkkkkkkkkllllllllll", nullptr));
        label_2->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\214\211\351\222\256", nullptr));
        lineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\345\217\257\346\211\251\345\261\225\347\252\227\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
