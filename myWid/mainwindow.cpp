#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdichild.h"
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include <QSettings>
#include <QCloseEvent>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this);
    actionSeparator->setSeparator(true);
    updateMenus();
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow *)),this,SLOT(updateMenus()));
    //创建信号映射器
    windowMapper = new QSignalMapper(this);
    //映射器重新发射信号,根据信号设置活动窗口
    connect(windowMapper,SIGNAL(mapped(QWidget *)),this,SLOT(setActiveSubWindow(QWidget *)));
    updateWindowMenu();
    //更新窗口菜单,并设置当前窗口菜单将要显示的时候更新菜单
    connect(ui->menu_3,SIGNAL(aboutToShow()),this,SLOT(updateWindowMenu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
     MdiChild *child = createMdiChild();
     child->newFile();
     child->show();
}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild()!=0);
    ui->actionSave->setEnabled(hasMdiChild);
    ui->actionSaveAs->setEnabled(hasMdiChild);
    ui->actionPaste->setEnabled(hasMdiChild);
    ui->actionClose->setEnabled(hasMdiChild);
    ui->actionCloseAll->setEnabled(hasMdiChild);
    ui->actionTile->setEnabled(hasMdiChild);
    ui->actionCascade->setEnabled(hasMdiChild);
    ui->actionNext->setEnabled(hasMdiChild);
    ui->actionPrevious->setEnabled(hasMdiChild);
    actionSeparator->setVisible(hasMdiChild);
    bool hasSelection = (activeMdiChild()&&activeMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);
    ui->actionUndo->setEnabled(hasSelection);
    ui->actionRedo->setEnabled(activeMdiChild()&&activeMdiChild()->document()->isRedoAvailable());
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild * child =new MdiChild;
    ui->mdiArea->addSubWindow(child);
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionOpen,SLOT(setEnabled(bool)));
    connect(child,SIGNAL(copyAvailable(bool)),ui->actionCopy,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(undoAvailable(bool)),ui->actionUndo,SLOT(setEnabled(bool)));
    connect(child->document(),SIGNAL(redoAvailable(bool)),ui->actionRedo,SLOT(setEnabled(bool)));
    connect(child,SIGNAL(curosrPositionChanged()),this,SLOT(showTextRowAndCol()));
    return child;
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));
}

MdiChild *MainWindow::activeMdiChild()
{
    if(QMdiSubWindow * activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicakFilePath = QFileInfo(fileName).canonicalFilePath();
    foreach(QMdiSubWindow * window,ui->mdiArea->subWindowList()){
        MdiChild * mdiChild = qobject_cast<MdiChild*>(window->widget());
        if(mdiChild->currentFile() == canonicakFilePath)
            return window;
    }
    return 0;
}

void MainWindow::readSettings()
{
    QSettings settings("yafeilinux","myMdi");
    QPoint pos = settings.value("pos",QPoint(200,200)).toPoint();
    QSize size = settings.value("size",QSize(400,400)).toSize();
    move(pos);
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settings("yafeilinux","myMdi");
    settings.setValue("pos",pos());
    settings.setValue("size",size());
}

void MainWindow::intWindow()
{
    setWindowTitle(tr("多文档编辑器"));

    ui->menubar->setWindowTitle(tr("工具栏"));
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->statusbar->showMessage(tr("欢迎使用多文档编辑器"));
    QLabel * label = new QLabel(this);
    label->setFrameStyle(QFrame::Box|QFrame::Sunken);
    label->setText(tr("<a href=\"https://www.baidu.com/>baidu</a>"));
    label->setTextFormat(Qt::RichText);
    label->setOpenExternalLinks(true);
    ui->statusbar->addPermanentWidget(label);
    ui->actionNew->setStatusTip(tr("创建一个文件"));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow()){
        event->ignore();
    }else{
        writeSettings();
        event->accept();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        QMdiSubWindow * existing = findMdiChild(fileName);
        if(existing){
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        MdiChild * child = createMdiChild();
        if(child->loadFile(fileName)){
            ui->statusbar->showMessage(tr("打开文件成功"),2000);
            child->show();
        }else{
            child->close();
        }
    }
}

void MainWindow::updateWindowMenu()
{
    //先清空菜单，然后再添加各个菜单的动作
    ui->menu_3->clear();
    ui->menu_3->addAction(ui->actionClose);
    ui->menu_3->addAction(ui->actionCloseAll);
    ui->menu_3->addSeparator();
    ui->menu_3->addAction(ui->actionTile);
    ui->menu_3->addAction(ui->actionCascade);
    ui->menu_3->addSeparator();
    ui->menu_3->addAction(ui->actionNext);
    ui->menu_3->addAction(ui->actionPrevious);
    ui->menu_3->addAction(actionSeparator);
    //如果有活动窗口,则显示间隔器
    QList<QMdiSubWindow*> windows = ui->mdiArea->subWindowList();
    actionSeparator->setVisible(!windows.isEmpty());
    for(int i=0;i<windows.size();i++){
        MdiChild * child = qobject_cast<MdiChild*>(windows.at(i)->widget());
        QString text;
        //如果窗口小于9,则设置快捷键
        if(i<9){
            text = tr("&%1 %2").arg(i+1).arg(child->userFriendCurrentFile());
        }else{
            text = tr("%1  %2").arg(i+1).arg(child->userFriendCurrentFile());
        }
        QAction * action = ui->menu_3->addAction(text);
        action->setCheckable(true);
        action->setChecked(child == activeMdiChild());
        connect(action,SIGNAL(triggered()),windowMapper,SLOT(map()));

        windowMapper->setMapping(action,windows.at(i));
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(activeMdiChild() && activeMdiChild()->save()){
        ui->statusbar->showMessage(tr("文件保存成功"),2000);
    }
}

void MainWindow::on_actionUndo_triggered()
{
    if(activeMdiChild()) activeMdiChild()->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    if(activeMdiChild()) activeMdiChild()->redo();
}

void MainWindow::on_actionCut_triggered()
{
    if(activeMdiChild()) activeMdiChild()->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    if(activeMdiChild()) activeMdiChild()->paste();
}

void MainWindow::on_actionCopy_triggered()
{
    if(activeMdiChild()) activeMdiChild()->copy();
}

void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actionCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void MainWindow::showTextRowAndCol()
{
    if(activeMdiChild()){
        int rowNum = activeMdiChild()->textCursor().blockNumber()+1;
        int colNum = activeMdiChild()->textCursor().columnNumber()+1;
        ui->statusbar->showMessage(tr("%1 行 %2 列").arg(rowNum).arg(colNum),2000);
    }
}
