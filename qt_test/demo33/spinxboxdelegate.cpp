#include "spinxboxdelegate.h"

SpinxBoxDelegate::SpinxBoxDelegate(QObject *parent) :QItemDelegate(parent)
{

}

QWidget *SpinxBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void SpinxBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();
    QSpinBox * spinxBox = static_cast<QSpinBox*>(editor);
    spinxBox->setValue(value);
}

void SpinxBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index)
{
    QSpinBox * spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index,value,Qt::EditRole);
}

void SpinxBoxDelegate::updateEditorGeometry(QWidget *ediotr, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    ediotr->setGeometry(option.rect);
}
