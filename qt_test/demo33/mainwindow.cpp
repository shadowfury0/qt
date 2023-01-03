#include "mainwindow.h"
#include "spinxboxdelegate.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(7, 4, this);
    for (int row = 0; row < 7; ++row) {
        for (int column = 0; column < 4; ++column) {
            QStandardItem *item = new QStandardItem(QString("%1")
                                                    .arg(row * 4 + column));
            model->setItem(row, column, item);
        }
    }
    tableView = new QTableView;
    tableView->setModel(model);
    setCentralWidget(tableView);

    QItemSelectionModel * selectionModel = tableView->selectionModel();

    QModelIndex topLeft;
    QModelIndex bottomRight;

    topLeft = model->index(1,1,QModelIndex());
    bottomRight = model->index(5,2,QModelIndex());
    QItemSelection selection(topLeft,bottomRight);
    selectionModel->select(selection,QItemSelectionModel::Select);

    ui->menubar->addAction(tr("当前项目"),this,&MainWindow::getCurrentItemData);
    ui->menubar->addAction(tr("切换选择"),this,&MainWindow::toggleSelection);
    connect(selectionModel,&QItemSelectionModel::selectionChanged,this,&MainWindow::updateSelection);
    connect(selectionModel,&QItemSelectionModel::currentChanged,this,&MainWindow::changedCurrent);
    tableView2 = new QTableView;
    tableView2->setWindowTitle("tableView2");
    tableView2->resize(400,300);
    tableView2->setModel(model);
    tableView2->setSelectionModel(selectionModel);
    tableView2->show();
    SpinxBoxDelegate * delegate = new SpinxBoxDelegate(this);
    tableView->setItemDelegate(delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableView2;
}

void MainWindow::getCurrentItemData()
{
    qDebug() <<tr("当前项目内容：") << tableView->selectionModel()->currentIndex().data().toString();
}

void MainWindow::toggleSelection()
{
    QModelIndex topLeft = tableView->model()->index(0,0,QModelIndex());
    QModelIndex bottomRight = tableView->model()->index(tableView->model()->rowCount(QModelIndex())-1,
                                                        tableView->model()->columnCount(QModelIndex())-1,
                                                       QModelIndex());
    QItemSelection curSelection(topLeft,bottomRight);
    tableView->selectionModel()->select(curSelection,QItemSelectionModel::Toggle);
}

void MainWindow::updateSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index;
    QModelIndexList list = selected.indexes();
    foreach(index,list){
        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());
        tableView->model()->setData(index,text);
    }
    list = deselected.indexes();
    foreach(index,list){
        tableView->model()->setData(index,"");
    }
}

void MainWindow::changedCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug() << tr("move(%1,%2) to (%3,%4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}



