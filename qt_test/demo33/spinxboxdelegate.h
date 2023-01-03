#ifndef SPINXBOXDELEGATE_H
#define SPINXBOXDELEGATE_H
#include <QSpinBox>
#include <QItemDelegate>
class SpinxBoxDelegate:public QItemDelegate
{
    Q_OBJECT
public:
    explicit SpinxBoxDelegate(QObject *parent=0);
    QWidget * createEditor(QWidget * parent,const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;
    void setEditorData(QWidget *editor,const QModelIndex &index) const;
    void setModelData(QWidget *editor,QAbstractItemModel * model,
                      const QModelIndex &index);
    void updateEditorGeometry(QWidget * ediotr,const QStyleOptionViewItem &option,
                              const QModelIndex &index);
};

#endif // SPINXBOXDELEGATE_H
