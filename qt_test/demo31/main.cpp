#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QStandardItemModel>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
//    //创建文件系统模型
//    QFileSystemModel model;
//    //指定要监视iide目录
//    model.setRootPath(QDir::currentPath());
//    //创建树型视图
//    QTreeView tree;
//    //为视图指定模型
//    tree.setModel(&model);
//    //指定根索引
//    tree.setRootIndex(model.index(QDir::currentPath()));
//    //创建列表视图
//    QListView list;
//    list.setModel(&model);
//    list.setRootIndex(model.index(QDir::currentPath()));
//    tree.show();
//    list.show();
    QStandardItemModel model;
    QStandardItem * parentItem = model.invisibleRootItem();
    QStandardItem * item0 = new QStandardItem;
    item0->setText("A");
    QPixmap pixmap0(50,50);
    pixmap0.fill("red");
    item0->setIcon(QIcon(pixmap0));
    item0->setToolTip("indexA");
    parentItem->appendRow(item0);
    parentItem = item0;
    QStandardItem * item1 = new QStandardItem;
    item1->setText("B");
    QPixmap pixmap1(50,50);
    pixmap1.fill("blue");
    item1->setIcon(QIcon(pixmap1));
    parentItem->appendRow(item1);
    QStandardItem * item2 = new QStandardItem;
    QPixmap pixmap2(50,50);
    pixmap2.fill("green");
    item2->setData("C",Qt::EditRole);
    item2->setData("indexC",Qt::ToolTipRole);
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);
    parentItem->appendRow(item2);
    QTreeView view;
    view.setModel(&model);
    view.show();
    QModelIndex indexA = model.index(0,0,QModelIndex());
    qDebug() << "indexA row count:" << model.rowCount(indexA);
    QModelIndex indexB = model.index(0,0,indexA);
    qDebug() << "indexB text:" << model.data(indexB,Qt::EditRole).toString();
    qDebug() << "indexB toolTip:"
             << model.data(indexB,Qt::ToolTipRole).toString();
    return app.exec();
}
