/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../demo/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[22];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 22), // "on_ColorButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 53, 23), // "on_StringButton_clicked"
QT_MOC_LITERAL(5, 77, 18), // "on_Message_clicked"
QT_MOC_LITERAL(6, 96, 24), // "on_ProcessButton_clicked"
QT_MOC_LITERAL(7, 121, 22), // "on_errorButton_clicked"
QT_MOC_LITERAL(8, 144, 23), // "on_WizardButton_clicked"
QT_MOC_LITERAL(9, 168, 22), // "on_label_linkActivated"
QT_MOC_LITERAL(10, 191, 4), // "link"
QT_MOC_LITERAL(11, 196, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(12, 220, 7), // "checked"
QT_MOC_LITERAL(13, 228, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(14, 254, 27), // "on_lineEdit_2_returnPressed"
QT_MOC_LITERAL(15, 282, 27), // "on_timeEdit_userTimeChanged"
QT_MOC_LITERAL(16, 310, 4), // "time"
QT_MOC_LITERAL(17, 315, 27), // "on_dateEdit_userDateChanged"
QT_MOC_LITERAL(18, 343, 4), // "date"
QT_MOC_LITERAL(19, 348, 32), // "on_verticalScrollBar_sliderMoved"
QT_MOC_LITERAL(20, 381, 8), // "position"
QT_MOC_LITERAL(21, 390, 23) // "on_pushButton_3_pressed"

    },
    "Widget\0on_ColorButton_clicked\0\0"
    "on_pushButton_clicked\0on_StringButton_clicked\0"
    "on_Message_clicked\0on_ProcessButton_clicked\0"
    "on_errorButton_clicked\0on_WizardButton_clicked\0"
    "on_label_linkActivated\0link\0"
    "on_pushButton_2_clicked\0checked\0"
    "on_lineEdit_returnPressed\0"
    "on_lineEdit_2_returnPressed\0"
    "on_timeEdit_userTimeChanged\0time\0"
    "on_dateEdit_userDateChanged\0date\0"
    "on_verticalScrollBar_sliderMoved\0"
    "position\0on_pushButton_3_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      11,    1,   99,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    1,  104,    2, 0x08 /* Private */,
      17,    1,  107,    2, 0x08 /* Private */,
      19,    1,  110,    2, 0x08 /* Private */,
      21,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   16,
    QMetaType::Void, QMetaType::QDate,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ColorButton_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_StringButton_clicked(); break;
        case 3: _t->on_Message_clicked(); break;
        case 4: _t->on_ProcessButton_clicked(); break;
        case 5: _t->on_errorButton_clicked(); break;
        case 6: _t->on_WizardButton_clicked(); break;
        case 7: _t->on_label_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_returnPressed(); break;
        case 10: _t->on_lineEdit_2_returnPressed(); break;
        case 11: _t->on_timeEdit_userTimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 12: _t->on_dateEdit_userDateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 13: _t->on_verticalScrollBar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_3_pressed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
