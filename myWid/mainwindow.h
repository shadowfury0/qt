#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MdiChild;
class QMdiSubWindow;
class QSignalMapper;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void updateMenus();
    MdiChild * createMdiChild();
    void setActiveSubWindow(QWidget *window);
    void on_actionOpen_triggered();
    void updateWindowMenu();
    void on_actionSave_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionClose_triggered();

    void on_actionCloseAll_triggered();

    void on_actionExit_triggered();

    void showTextRowAndCol();

private:
    Ui::MainWindow *ui;
    QAction * actionSeparator;
    MdiChild * activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);
    QSignalMapper * windowMapper;

    void readSettings();
    void writeSettings();
    void intWindow();
protected:
    void closeEvent(QCloseEvent * event);
};
#endif // MAINWINDOW_H
