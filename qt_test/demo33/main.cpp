#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QListWidget>
#include <QTreeWidget>
#include <QAbstractItemModel>
#include <QTableWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //一种添加项目的便捷方法
    QListWidget listWidget;
    new QListWidgetItem("a",&listWidget);
    //添加项目的另一种方法，这样还可以进行各种设置
    QListWidgetItem * listWidgetItem = new QListWidgetItem;
    listWidgetItem->setText("b");
    //listWidgetItem->setIcon()
    listWidgetItem->setToolTip("this is b!");
    listWidget.insertItem(1,listWidgetItem);
    //设置排序为倒序
    listWidget.sortItems(Qt::DescendingOrder);
    //显示列表部件
    listWidget.show();

    QTreeWidget treeWidget;
    treeWidget.setColumnCount(2);
    QStringList headers;
    headers << "name" << "year";
    treeWidget.setHeaderLabels(headers);
    //添加项目
    QTreeWidgetItem * gradel = new QTreeWidgetItem(&treeWidget);
    gradel->setText(0,"Gradel");
    QTreeWidgetItem * student = new QTreeWidgetItem(gradel);
    student->setText(0,"Tom");
    student->setText(1,"1986");
    QTreeWidgetItem * gradel2 = new QTreeWidgetItem(&treeWidget,gradel);
    gradel2->setText(0,"Grade2");
    treeWidget.show();

    QTableWidget tableWidget(3,2);
    QTableWidgetItem * tableWidgetItem = new QTableWidgetItem("qt");
    tableWidget.setItem(1,1,tableWidgetItem);
    //创建表格项目，并将他们作为标头
    QTableWidgetItem * headerV = new QTableWidgetItem("first");
    tableWidget.setVerticalHeaderItem(0,headerV);
    QTableWidgetItem * headerH = new QTableWidgetItem("ID");
    tableWidget.setHorizontalHeaderItem(0,headerH);
    tableWidget.show();
    listWidget.setSelectionMode(QAbstractItemView::SingleSelection);
    //启用拖动
    listWidget.setDragEnabled(true);
    listWidget.viewport()->setAcceptDrops(true);
    listWidget.setDropIndicatorShown(true);
    listWidget.setDragDropMode(QAbstractItemView::InternalMove);


//    MainWindow w;
//    w.show();
    return a.exec();
}
