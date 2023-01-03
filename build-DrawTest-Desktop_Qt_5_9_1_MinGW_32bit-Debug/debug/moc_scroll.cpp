/****************************************************************************
** Meta object code from reading C++ file 'scroll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawTest/scroll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scroll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scroll_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scroll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scroll_t qt_meta_stringdata_Scroll = {
    {
QT_MOC_LITERAL(0, 0, 6) // "Scroll"

    },
    "Scroll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scroll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Scroll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Scroll::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Scroll.data,
      qt_meta_data_Scroll,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Scroll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scroll::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scroll.stringdata0))
        return static_cast<void*>(const_cast< Scroll*>(this));
    return QWidget::qt_metacast(_clname);
}

int Scroll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_ScrollButton_t {
    QByteArrayData data[9];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScrollButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScrollButton_t qt_meta_stringdata_ScrollButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScrollButton"
QT_MOC_LITERAL(1, 13, 15), // "mousePressEvent"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 43, 5), // "event"
QT_MOC_LITERAL(5, 49, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(6, 64, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(7, 82, 12), // "valueChanged"
QT_MOC_LITERAL(8, 95, 5) // "value"

    },
    "ScrollButton\0mousePressEvent\0\0"
    "QMouseEvent*\0event\0mouseMoveEvent\0"
    "mouseReleaseEvent\0valueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScrollButton[] = {

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
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       7,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ScrollButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScrollButton *_t = static_cast<ScrollButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ScrollButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScrollButton.data,
      qt_meta_data_ScrollButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScrollButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrollButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScrollButton.stringdata0))
        return static_cast<void*>(const_cast< ScrollButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScrollButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_ScrollLine_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScrollLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScrollLine_t qt_meta_stringdata_ScrollLine = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ScrollLine"
QT_MOC_LITERAL(1, 11, 7), // "reverse"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "ScrollLine\0reverse\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScrollLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ScrollLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScrollLine *_t = static_cast<ScrollLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reverse(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ScrollLine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScrollLine.data,
      qt_meta_data_ScrollLine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScrollLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrollLine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScrollLine.stringdata0))
        return static_cast<void*>(const_cast< ScrollLine*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScrollLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
