/****************************************************************************
** Meta object code from reading C++ file 'graph_view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../GraphBuilder-main/graph_view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph_view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_viewLog_t {
    QByteArrayData data[1];
    char stringdata0[8];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_viewLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_viewLog_t qt_meta_stringdata_viewLog = {
    {
QT_MOC_LITERAL(0, 0, 7) // "viewLog"

    },
    "viewLog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_viewLog[] = {

 // content:
       8,       // revision
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

void viewLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject viewLog::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_viewLog.data,
    qt_meta_data_viewLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *viewLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *viewLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_viewLog.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int viewLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MyGraphicsView_t {
    QByteArrayData data[37];
    char stringdata0[350];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGraphicsView_t qt_meta_stringdata_MyGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyGraphicsView"
QT_MOC_LITERAL(1, 15, 10), // "mouseMoved"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "position"
QT_MOC_LITERAL(4, 36, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(5, 53, 17), // "mouseRightClicked"
QT_MOC_LITERAL(6, 71, 13), // "mouseReleased"
QT_MOC_LITERAL(7, 85, 8), // "vexAdded"
QT_MOC_LITERAL(8, 94, 18), // "MyGraphicsVexItem*"
QT_MOC_LITERAL(9, 113, 3), // "vex"
QT_MOC_LITERAL(10, 117, 8), // "arcAdded"
QT_MOC_LITERAL(11, 126, 19), // "MyGraphicsLineItem*"
QT_MOC_LITERAL(12, 146, 3), // "arc"
QT_MOC_LITERAL(13, 150, 8), // "logAdded"
QT_MOC_LITERAL(14, 159, 8), // "viewLog*"
QT_MOC_LITERAL(15, 168, 3), // "log"
QT_MOC_LITERAL(16, 172, 8), // "selected"
QT_MOC_LITERAL(17, 181, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(18, 196, 4), // "item"
QT_MOC_LITERAL(19, 201, 10), // "unselected"
QT_MOC_LITERAL(20, 212, 10), // "visitClear"
QT_MOC_LITERAL(21, 223, 8), // "setHover"
QT_MOC_LITERAL(22, 232, 2), // "in"
QT_MOC_LITERAL(23, 235, 6), // "setSel"
QT_MOC_LITERAL(24, 242, 3), // "sel"
QT_MOC_LITERAL(25, 246, 9), // "startLine"
QT_MOC_LITERAL(26, 256, 8), // "startVex"
QT_MOC_LITERAL(27, 265, 7), // "setMenu"
QT_MOC_LITERAL(28, 273, 6), // "target"
QT_MOC_LITERAL(29, 280, 7), // "display"
QT_MOC_LITERAL(30, 288, 6), // "addLog"
QT_MOC_LITERAL(31, 295, 10), // "vexRemoved"
QT_MOC_LITERAL(32, 306, 10), // "arcRemoved"
QT_MOC_LITERAL(33, 317, 4), // "line"
QT_MOC_LITERAL(34, 322, 12), // "addAnimation"
QT_MOC_LITERAL(35, 335, 10), // "QTimeLine*"
QT_MOC_LITERAL(36, 346, 3) // "ani"

    },
    "MyGraphicsView\0mouseMoved\0\0position\0"
    "mouseLeftClicked\0mouseRightClicked\0"
    "mouseReleased\0vexAdded\0MyGraphicsVexItem*\0"
    "vex\0arcAdded\0MyGraphicsLineItem*\0arc\0"
    "logAdded\0viewLog*\0log\0selected\0"
    "QGraphicsItem*\0item\0unselected\0"
    "visitClear\0setHover\0in\0setSel\0sel\0"
    "startLine\0startVex\0setMenu\0target\0"
    "display\0addLog\0vexRemoved\0arcRemoved\0"
    "line\0addAnimation\0QTimeLine*\0ani"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,
       5,    1,  120,    2, 0x06 /* Public */,
       6,    0,  123,    2, 0x06 /* Public */,
       7,    1,  124,    2, 0x06 /* Public */,
      10,    1,  127,    2, 0x06 /* Public */,
      13,    1,  130,    2, 0x06 /* Public */,
      16,    1,  133,    2, 0x06 /* Public */,
      19,    0,  136,    2, 0x06 /* Public */,
      20,    0,  137,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  138,    2, 0x0a /* Public */,
      21,    0,  141,    2, 0x2a /* Public | MethodCloned */,
      23,    1,  142,    2, 0x0a /* Public */,
      25,    1,  145,    2, 0x0a /* Public */,
      27,    2,  148,    2, 0x0a /* Public */,
      27,    1,  153,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  156,    2, 0x0a /* Public */,
      31,    1,  159,    2, 0x0a /* Public */,
      32,    1,  162,    2, 0x0a /* Public */,
      34,    1,  165,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   24,
    QMetaType::Void, 0x80000000 | 8,   26,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Bool,   28,   29,
    QMetaType::Void, 0x80000000 | 17,   28,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   33,
    QMetaType::Void, 0x80000000 | 35,   36,

       0        // eod
};

void MyGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMoved((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->mouseLeftClicked((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->mouseRightClicked((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: _t->mouseReleased(); break;
        case 4: _t->vexAdded((*reinterpret_cast< MyGraphicsVexItem*(*)>(_a[1]))); break;
        case 5: _t->arcAdded((*reinterpret_cast< MyGraphicsLineItem*(*)>(_a[1]))); break;
        case 6: _t->logAdded((*reinterpret_cast< viewLog*(*)>(_a[1]))); break;
        case 7: _t->selected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 8: _t->unselected(); break;
        case 9: _t->visitClear(); break;
        case 10: _t->setHover((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setHover(); break;
        case 12: _t->setSel((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 13: _t->startLine((*reinterpret_cast< MyGraphicsVexItem*(*)>(_a[1]))); break;
        case 14: _t->setMenu((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 15: _t->setMenu((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 16: _t->addLog((*reinterpret_cast< viewLog*(*)>(_a[1]))); break;
        case 17: _t->vexRemoved((*reinterpret_cast< MyGraphicsVexItem*(*)>(_a[1]))); break;
        case 18: _t->arcRemoved((*reinterpret_cast< MyGraphicsLineItem*(*)>(_a[1]))); break;
        case 19: _t->addAnimation((*reinterpret_cast< QTimeLine*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsVexItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsLineItem* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< viewLog* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsVexItem* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< viewLog* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsVexItem* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsLineItem* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTimeLine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGraphicsView::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::mouseMoved)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::mouseLeftClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::mouseRightClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::mouseReleased)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(MyGraphicsVexItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::vexAdded)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(MyGraphicsLineItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::arcAdded)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(viewLog * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::logAdded)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::selected)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::unselected)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::visitClear)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGraphicsView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_MyGraphicsView.data,
    qt_meta_data_MyGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MyGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MyGraphicsView::mouseMoved(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGraphicsView::mouseLeftClicked(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGraphicsView::mouseRightClicked(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGraphicsView::mouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyGraphicsView::vexAdded(MyGraphicsVexItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGraphicsView::arcAdded(MyGraphicsLineItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGraphicsView::logAdded(viewLog * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGraphicsView::selected(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGraphicsView::unselected()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MyGraphicsView::visitClear()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
struct qt_meta_stringdata_MyGraphicsVexItem_t {
    QByteArrayData data[26];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGraphicsVexItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGraphicsVexItem_t qt_meta_stringdata_MyGraphicsVexItem = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MyGraphicsVexItem"
QT_MOC_LITERAL(1, 18, 8), // "setHover"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "in"
QT_MOC_LITERAL(4, 31, 8), // "selected"
QT_MOC_LITERAL(5, 40, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(6, 55, 3), // "sel"
QT_MOC_LITERAL(7, 59, 8), // "lineFrom"
QT_MOC_LITERAL(8, 68, 18), // "MyGraphicsVexItem*"
QT_MOC_LITERAL(9, 87, 5), // "start"
QT_MOC_LITERAL(10, 93, 16), // "menuStateChanged"
QT_MOC_LITERAL(11, 110, 4), // "item"
QT_MOC_LITERAL(12, 115, 7), // "display"
QT_MOC_LITERAL(13, 123, 8), // "logAdded"
QT_MOC_LITERAL(14, 132, 8), // "viewLog*"
QT_MOC_LITERAL(15, 141, 3), // "log"
QT_MOC_LITERAL(16, 145, 7), // "removed"
QT_MOC_LITERAL(17, 153, 3), // "vex"
QT_MOC_LITERAL(18, 157, 12), // "addAnimation"
QT_MOC_LITERAL(19, 170, 10), // "QTimeLine*"
QT_MOC_LITERAL(20, 181, 3), // "ani"
QT_MOC_LITERAL(21, 185, 11), // "onMouseMove"
QT_MOC_LITERAL(22, 197, 8), // "position"
QT_MOC_LITERAL(23, 206, 11), // "onLeftClick"
QT_MOC_LITERAL(24, 218, 12), // "onRightClick"
QT_MOC_LITERAL(25, 231, 14) // "onMouseRelease"

    },
    "MyGraphicsVexItem\0setHover\0\0in\0selected\0"
    "QGraphicsItem*\0sel\0lineFrom\0"
    "MyGraphicsVexItem*\0start\0menuStateChanged\0"
    "item\0display\0logAdded\0viewLog*\0log\0"
    "removed\0vex\0addAnimation\0QTimeLine*\0"
    "ani\0onMouseMove\0position\0onLeftClick\0"
    "onRightClick\0onMouseRelease"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraphicsVexItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       1,    0,   82,    2, 0x26 /* Public | MethodCloned */,
       4,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
      10,    2,   89,    2, 0x06 /* Public */,
      10,    1,   94,    2, 0x26 /* Public | MethodCloned */,
      13,    1,   97,    2, 0x06 /* Public */,
      16,    1,  100,    2, 0x06 /* Public */,
      18,    1,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      21,    1,  106,    2, 0x0a /* Public */,
      23,    1,  109,    2, 0x0a /* Public */,
      24,    1,  112,    2, 0x0a /* Public */,
      25,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Bool,   11,   12,
    QMetaType::Void, 0x80000000 | 5,   11,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 8,   17,
    QMetaType::Void, 0x80000000 | 19,   20,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   22,
    QMetaType::Void, QMetaType::QPointF,   22,
    QMetaType::Void, QMetaType::QPointF,   22,
    QMetaType::Void,

       0        // eod
};

void MyGraphicsVexItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGraphicsVexItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHover((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setHover(); break;
        case 2: _t->selected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->lineFrom((*reinterpret_cast< MyGraphicsVexItem*(*)>(_a[1]))); break;
        case 4: _t->menuStateChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->menuStateChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 6: _t->logAdded((*reinterpret_cast< viewLog*(*)>(_a[1]))); break;
        case 7: _t->removed((*reinterpret_cast< MyGraphicsVexItem*(*)>(_a[1]))); break;
        case 8: _t->addAnimation((*reinterpret_cast< QTimeLine*(*)>(_a[1]))); break;
        case 9: _t->onMouseMove((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 10: _t->onLeftClick((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 11: _t->onRightClick((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 12: _t->onMouseRelease(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsVexItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< viewLog* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsVexItem* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTimeLine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGraphicsVexItem::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::setHover)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGraphicsVexItem::*)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::selected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGraphicsVexItem::*)(MyGraphicsVexItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::lineFrom)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyGraphicsVexItem::*)(QGraphicsItem * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::menuStateChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyGraphicsVexItem::*)(viewLog * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::logAdded)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyGraphicsVexItem::*)(MyGraphicsVexItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::removed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MyGraphicsVexItem::*)(QTimeLine * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsVexItem::addAnimation)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGraphicsVexItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyGraphicsVexItem.data,
    qt_meta_data_MyGraphicsVexItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGraphicsVexItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsVexItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsVexItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsEllipseItem"))
        return static_cast< QGraphicsEllipseItem*>(this);
    return QObject::qt_metacast(_clname);
}

int MyGraphicsVexItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MyGraphicsVexItem::setHover(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void MyGraphicsVexItem::selected(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGraphicsVexItem::lineFrom(MyGraphicsVexItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGraphicsVexItem::menuStateChanged(QGraphicsItem * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void MyGraphicsVexItem::logAdded(viewLog * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGraphicsVexItem::removed(MyGraphicsVexItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGraphicsVexItem::addAnimation(QTimeLine * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
struct qt_meta_stringdata_MyGraphicsLineItem_t {
    QByteArrayData data[24];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGraphicsLineItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGraphicsLineItem_t qt_meta_stringdata_MyGraphicsLineItem = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MyGraphicsLineItem"
QT_MOC_LITERAL(1, 19, 8), // "setHover"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "in"
QT_MOC_LITERAL(4, 32, 8), // "selected"
QT_MOC_LITERAL(5, 41, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(6, 56, 3), // "sel"
QT_MOC_LITERAL(7, 60, 16), // "menuStateChanged"
QT_MOC_LITERAL(8, 77, 4), // "item"
QT_MOC_LITERAL(9, 82, 7), // "display"
QT_MOC_LITERAL(10, 90, 8), // "logAdded"
QT_MOC_LITERAL(11, 99, 8), // "viewLog*"
QT_MOC_LITERAL(12, 108, 3), // "log"
QT_MOC_LITERAL(13, 112, 7), // "removed"
QT_MOC_LITERAL(14, 120, 19), // "MyGraphicsLineItem*"
QT_MOC_LITERAL(15, 140, 4), // "line"
QT_MOC_LITERAL(16, 145, 12), // "addAnimation"
QT_MOC_LITERAL(17, 158, 10), // "QTimeLine*"
QT_MOC_LITERAL(18, 169, 3), // "ani"
QT_MOC_LITERAL(19, 173, 11), // "onMouseMove"
QT_MOC_LITERAL(20, 185, 8), // "position"
QT_MOC_LITERAL(21, 194, 11), // "onLeftClick"
QT_MOC_LITERAL(22, 206, 12), // "onRightClick"
QT_MOC_LITERAL(23, 219, 14) // "onMouseRelease"

    },
    "MyGraphicsLineItem\0setHover\0\0in\0"
    "selected\0QGraphicsItem*\0sel\0"
    "menuStateChanged\0item\0display\0logAdded\0"
    "viewLog*\0log\0removed\0MyGraphicsLineItem*\0"
    "line\0addAnimation\0QTimeLine*\0ani\0"
    "onMouseMove\0position\0onLeftClick\0"
    "onRightClick\0onMouseRelease"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraphicsLineItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       1,    0,   77,    2, 0x26 /* Public | MethodCloned */,
       4,    1,   78,    2, 0x06 /* Public */,
       7,    2,   81,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x26 /* Public | MethodCloned */,
      10,    1,   89,    2, 0x06 /* Public */,
      13,    1,   92,    2, 0x06 /* Public */,
      16,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,   98,    2, 0x08 /* Private */,
      21,    1,  101,    2, 0x08 /* Private */,
      22,    1,  104,    2, 0x08 /* Private */,
      23,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Bool,    8,    9,
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   20,
    QMetaType::Void, QMetaType::QPointF,   20,
    QMetaType::Void, QMetaType::QPointF,   20,
    QMetaType::Void,

       0        // eod
};

void MyGraphicsLineItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGraphicsLineItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHover((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setHover(); break;
        case 2: _t->selected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->menuStateChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->menuStateChanged((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 5: _t->logAdded((*reinterpret_cast< viewLog*(*)>(_a[1]))); break;
        case 6: _t->removed((*reinterpret_cast< MyGraphicsLineItem*(*)>(_a[1]))); break;
        case 7: _t->addAnimation((*reinterpret_cast< QTimeLine*(*)>(_a[1]))); break;
        case 8: _t->onMouseMove((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 9: _t->onLeftClick((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 10: _t->onRightClick((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 11: _t->onMouseRelease(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< viewLog* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyGraphicsLineItem* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTimeLine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGraphicsLineItem::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsLineItem::setHover)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGraphicsLineItem::*)(QGraphicsItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsLineItem::selected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyGraphicsLineItem::*)(QGraphicsItem * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsLineItem::menuStateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyGraphicsLineItem::*)(viewLog * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsLineItem::logAdded)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MyGraphicsLineItem::*)(MyGraphicsLineItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsLineItem::removed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MyGraphicsLineItem::*)(QTimeLine * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsLineItem::addAnimation)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGraphicsLineItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyGraphicsLineItem.data,
    qt_meta_data_MyGraphicsLineItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGraphicsLineItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsLineItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsLineItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsLineItem"))
        return static_cast< QGraphicsLineItem*>(this);
    return QObject::qt_metacast(_clname);
}

int MyGraphicsLineItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MyGraphicsLineItem::setHover(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void MyGraphicsLineItem::selected(QGraphicsItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGraphicsLineItem::menuStateChanged(QGraphicsItem * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void MyGraphicsLineItem::logAdded(viewLog * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGraphicsLineItem::removed(MyGraphicsLineItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGraphicsLineItem::addAnimation(QTimeLine * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
