/****************************************************************************
** Meta object code from reading C++ file 'draw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Painting/draw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'draw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Draw_t {
    QByteArrayData data[9];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Draw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Draw_t qt_meta_stringdata_Draw = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Draw"
QT_MOC_LITERAL(1, 5, 15), // "mousePressEvent"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 35, 5), // "event"
QT_MOC_LITERAL(5, 41, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(6, 56, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(7, 74, 10), // "paintEvent"
QT_MOC_LITERAL(8, 85, 12) // "QPaintEvent*"

    },
    "Draw\0mousePressEvent\0\0QMouseEvent*\0"
    "event\0mouseMoveEvent\0mouseReleaseEvent\0"
    "paintEvent\0QPaintEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Draw[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 8,    4,

       0        // eod
};

void Draw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Draw *_t = static_cast<Draw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Draw::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Draw.data,
      qt_meta_data_Draw,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Draw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Draw::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Draw.stringdata0))
        return static_cast<void*>(const_cast< Draw*>(this));
    return QWidget::qt_metacast(_clname);
}

int Draw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
