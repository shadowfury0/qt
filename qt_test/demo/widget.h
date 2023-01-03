#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>
#include <QWizard>
#include <QPixmap>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QErrorMessage* errordlg;
    Ui::Widget* ui;
    QWizardPage* createPage1();
    QWizardPage* createPage2();
    QWizardPage* createPage3();
private slots:
    void on_ColorButton_clicked();

    void on_pushButton_clicked();


    void on_StringButton_clicked();


    void on_Message_clicked();

    void on_ProcessButton_clicked();

    void on_errorButton_clicked();

    void on_WizardButton_clicked();

    void on_label_linkActivated(const QString &link);
    void on_pushButton_2_clicked(bool checked);
    void on_lineEdit_returnPressed();
    void on_lineEdit_2_returnPressed();
    void on_timeEdit_userTimeChanged(const QTime &time);
    void on_dateEdit_userDateChanged(const QDate &date);
    void on_verticalScrollBar_sliderMoved(int position);
    void on_pushButton_3_pressed();
};
#endif // WIDGET_H
