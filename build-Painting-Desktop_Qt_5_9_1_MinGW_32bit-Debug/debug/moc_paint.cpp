/****************************************************************************
** Meta object code from reading C++ file 'paint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Painting/paint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Paint_t {
    QByteArrayData data[65];
    char stringdata0[1180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Paint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Paint_t qt_meta_stringdata_Paint = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Paint"
QT_MOC_LITERAL(1, 6, 19), // "on_menu_btn_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 23), // "on_painting_btn_clicked"
QT_MOC_LITERAL(4, 51, 17), // "on_2D_btn_clicked"
QT_MOC_LITERAL(5, 69, 22), // "on_sticker_btn_clicked"
QT_MOC_LITERAL(6, 92, 19), // "on_edit_btn_clicked"
QT_MOC_LITERAL(7, 112, 15), // "on_test_clicked"
QT_MOC_LITERAL(8, 128, 15), // "mousePressEvent"
QT_MOC_LITERAL(9, 144, 12), // "QMouseEvent*"
QT_MOC_LITERAL(10, 157, 5), // "event"
QT_MOC_LITERAL(11, 163, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(12, 181, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(13, 196, 12), // "extractColor"
QT_MOC_LITERAL(14, 209, 21), // "on_pen_button_clicked"
QT_MOC_LITERAL(15, 231, 24), // "on_rubber_button_clicked"
QT_MOC_LITERAL(16, 256, 24), // "on_pencil_button_clicked"
QT_MOC_LITERAL(17, 281, 18), // "pen_slider_changed"
QT_MOC_LITERAL(18, 300, 5), // "value"
QT_MOC_LITERAL(19, 306, 11), // "color_alpha"
QT_MOC_LITERAL(20, 318, 17), // "pen_pixel_changed"
QT_MOC_LITERAL(21, 336, 17), // "pen_alpha_changed"
QT_MOC_LITERAL(22, 354, 1), // "a"
QT_MOC_LITERAL(23, 356, 12), // "white_button"
QT_MOC_LITERAL(24, 369, 11), // "gray_button"
QT_MOC_LITERAL(25, 381, 15), // "darkGray_button"
QT_MOC_LITERAL(26, 397, 12), // "black_button"
QT_MOC_LITERAL(27, 410, 14), // "darkRed_button"
QT_MOC_LITERAL(28, 425, 10), // "red_button"
QT_MOC_LITERAL(29, 436, 17), // "darkYellow_button"
QT_MOC_LITERAL(30, 454, 13), // "yellow_button"
QT_MOC_LITERAL(31, 468, 16), // "darkGreen_button"
QT_MOC_LITERAL(32, 485, 12), // "green_button"
QT_MOC_LITERAL(33, 498, 15), // "darkCyan_button"
QT_MOC_LITERAL(34, 514, 11), // "cyan_button"
QT_MOC_LITERAL(35, 526, 15), // "darkBlue_button"
QT_MOC_LITERAL(36, 542, 11), // "blue_button"
QT_MOC_LITERAL(37, 554, 18), // "darkMagenta_button"
QT_MOC_LITERAL(38, 573, 14), // "magenta_button"
QT_MOC_LITERAL(39, 588, 18), // "multi_color_button"
QT_MOC_LITERAL(40, 607, 23), // "on_drawLine_btn_clicked"
QT_MOC_LITERAL(41, 631, 24), // "on_drawUpArc_btn_clicked"
QT_MOC_LITERAL(42, 656, 26), // "on_drawDownArc_btn_clicked"
QT_MOC_LITERAL(43, 683, 21), // "on_circle_btn_clicked"
QT_MOC_LITERAL(44, 705, 20), // "on_chord_btn_clicked"
QT_MOC_LITERAL(45, 726, 19), // "on_rect_btn_clicked"
QT_MOC_LITERAL(46, 746, 24), // "on_rectRound_btn_clicked"
QT_MOC_LITERAL(47, 771, 23), // "on_triangle_btn_clicked"
QT_MOC_LITERAL(48, 795, 23), // "on_pentagle_btn_clicked"
QT_MOC_LITERAL(49, 819, 22), // "on_hexagon_btn_clicked"
QT_MOC_LITERAL(50, 842, 23), // "on_heptagon_btn_clicked"
QT_MOC_LITERAL(51, 866, 22), // "on_diamond_btn_clicked"
QT_MOC_LITERAL(52, 889, 20), // "on_arrow_btn_clicked"
QT_MOC_LITERAL(53, 910, 29), // "on_custom_sticker_btn_clicked"
QT_MOC_LITERAL(54, 940, 13), // "stickerSelect"
QT_MOC_LITERAL(55, 954, 19), // "on_sticker1_clicked"
QT_MOC_LITERAL(56, 974, 19), // "on_sticker2_clicked"
QT_MOC_LITERAL(57, 994, 19), // "on_sticker3_clicked"
QT_MOC_LITERAL(58, 1014, 19), // "on_sticker4_clicked"
QT_MOC_LITERAL(59, 1034, 27), // "on_user_sticker_btn_clicked"
QT_MOC_LITERAL(60, 1062, 27), // "on_sticker_selected_clicked"
QT_MOC_LITERAL(61, 1090, 20), // "setDrawCustomSticker"
QT_MOC_LITERAL(62, 1111, 18), // "setDrawUserSticker"
QT_MOC_LITERAL(63, 1130, 25), // "on_editSelect_btn_clicked"
QT_MOC_LITERAL(64, 1156, 23) // "on_editDraw_btn_clicked"

    },
    "Paint\0on_menu_btn_clicked\0\0"
    "on_painting_btn_clicked\0on_2D_btn_clicked\0"
    "on_sticker_btn_clicked\0on_edit_btn_clicked\0"
    "on_test_clicked\0mousePressEvent\0"
    "QMouseEvent*\0event\0mouseReleaseEvent\0"
    "mouseMoveEvent\0extractColor\0"
    "on_pen_button_clicked\0on_rubber_button_clicked\0"
    "on_pencil_button_clicked\0pen_slider_changed\0"
    "value\0color_alpha\0pen_pixel_changed\0"
    "pen_alpha_changed\0a\0white_button\0"
    "gray_button\0darkGray_button\0black_button\0"
    "darkRed_button\0red_button\0darkYellow_button\0"
    "yellow_button\0darkGreen_button\0"
    "green_button\0darkCyan_button\0cyan_button\0"
    "darkBlue_button\0blue_button\0"
    "darkMagenta_button\0magenta_button\0"
    "multi_color_button\0on_drawLine_btn_clicked\0"
    "on_drawUpArc_btn_clicked\0"
    "on_drawDownArc_btn_clicked\0"
    "on_circle_btn_clicked\0on_chord_btn_clicked\0"
    "on_rect_btn_clicked\0on_rectRound_btn_clicked\0"
    "on_triangle_btn_clicked\0on_pentagle_btn_clicked\0"
    "on_hexagon_btn_clicked\0on_heptagon_btn_clicked\0"
    "on_diamond_btn_clicked\0on_arrow_btn_clicked\0"
    "on_custom_sticker_btn_clicked\0"
    "stickerSelect\0on_sticker1_clicked\0"
    "on_sticker2_clicked\0on_sticker3_clicked\0"
    "on_sticker4_clicked\0on_user_sticker_btn_clicked\0"
    "on_sticker_selected_clicked\0"
    "setDrawCustomSticker\0setDrawUserSticker\0"
    "on_editSelect_btn_clicked\0"
    "on_editDraw_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Paint[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      59,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  309,    2, 0x08 /* Private */,
       3,    0,  310,    2, 0x08 /* Private */,
       4,    0,  311,    2, 0x08 /* Private */,
       5,    0,  312,    2, 0x08 /* Private */,
       6,    0,  313,    2, 0x08 /* Private */,
       7,    0,  314,    2, 0x08 /* Private */,
       8,    1,  315,    2, 0x08 /* Private */,
      11,    1,  318,    2, 0x08 /* Private */,
      12,    1,  321,    2, 0x08 /* Private */,
      13,    0,  324,    2, 0x08 /* Private */,
      14,    0,  325,    2, 0x08 /* Private */,
      15,    0,  326,    2, 0x08 /* Private */,
      16,    0,  327,    2, 0x08 /* Private */,
      17,    1,  328,    2, 0x08 /* Private */,
      19,    1,  331,    2, 0x08 /* Private */,
      20,    1,  334,    2, 0x08 /* Private */,
      21,    1,  337,    2, 0x08 /* Private */,
      23,    0,  340,    2, 0x08 /* Private */,
      24,    0,  341,    2, 0x08 /* Private */,
      25,    0,  342,    2, 0x08 /* Private */,
      26,    0,  343,    2, 0x08 /* Private */,
      27,    0,  344,    2, 0x08 /* Private */,
      28,    0,  345,    2, 0x08 /* Private */,
      29,    0,  346,    2, 0x08 /* Private */,
      30,    0,  347,    2, 0x08 /* Private */,
      31,    0,  348,    2, 0x08 /* Private */,
      32,    0,  349,    2, 0x08 /* Private */,
      33,    0,  350,    2, 0x08 /* Private */,
      34,    0,  351,    2, 0x08 /* Private */,
      35,    0,  352,    2, 0x08 /* Private */,
      36,    0,  353,    2, 0x08 /* Private */,
      37,    0,  354,    2, 0x08 /* Private */,
      38,    0,  355,    2, 0x08 /* Private */,
      39,    0,  356,    2, 0x08 /* Private */,
      40,    0,  357,    2, 0x08 /* Private */,
      41,    0,  358,    2, 0x08 /* Private */,
      42,    0,  359,    2, 0x08 /* Private */,
      43,    0,  360,    2, 0x08 /* Private */,
      44,    0,  361,    2, 0x08 /* Private */,
      45,    0,  362,    2, 0x08 /* Private */,
      46,    0,  363,    2, 0x08 /* Private */,
      47,    0,  364,    2, 0x08 /* Private */,
      48,    0,  365,    2, 0x08 /* Private */,
      49,    0,  366,    2, 0x08 /* Private */,
      50,    0,  367,    2, 0x08 /* Private */,
      51,    0,  368,    2, 0x08 /* Private */,
      52,    0,  369,    2, 0x08 /* Private */,
      53,    0,  370,    2, 0x08 /* Private */,
      54,    0,  371,    2, 0x08 /* Private */,
      55,    0,  372,    2, 0x08 /* Private */,
      56,    0,  373,    2, 0x08 /* Private */,
      57,    0,  374,    2, 0x08 /* Private */,
      58,    0,  375,    2, 0x08 /* Private */,
      59,    0,  376,    2, 0x08 /* Private */,
      60,    0,  377,    2, 0x08 /* Private */,
      61,    0,  378,    2, 0x08 /* Private */,
      62,    0,  379,    2, 0x08 /* Private */,
      63,    0,  380,    2, 0x08 /* Private */,
      64,    0,  381,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QReal,   18,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Paint *_t = static_cast<Paint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_menu_btn_clicked(); break;
        case 1: _t->on_painting_btn_clicked(); break;
        case 2: _t->on_2D_btn_clicked(); break;
        case 3: _t->on_sticker_btn_clicked(); break;
        case 4: _t->on_edit_btn_clicked(); break;
        case 5: _t->on_test_clicked(); break;
        case 6: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->extractColor(); break;
        case 10: _t->on_pen_button_clicked(); break;
        case 11: _t->on_rubber_button_clicked(); break;
        case 12: _t->on_pencil_button_clicked(); break;
        case 13: _t->pen_slider_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->color_alpha((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 15: _t->pen_pixel_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->pen_alpha_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->white_button(); break;
        case 18: _t->gray_button(); break;
        case 19: _t->darkGray_button(); break;
        case 20: _t->black_button(); break;
        case 21: _t->darkRed_button(); break;
        case 22: _t->red_button(); break;
        case 23: _t->darkYellow_button(); break;
        case 24: _t->yellow_button(); break;
        case 25: _t->darkGreen_button(); break;
        case 26: _t->green_button(); break;
        case 27: _t->darkCyan_button(); break;
        case 28: _t->cyan_button(); break;
        case 29: _t->darkBlue_button(); break;
        case 30: _t->blue_button(); break;
        case 31: _t->darkMagenta_button(); break;
        case 32: _t->magenta_button(); break;
        case 33: _t->multi_color_button(); break;
        case 34: _t->on_drawLine_btn_clicked(); break;
        case 35: _t->on_drawUpArc_btn_clicked(); break;
        case 36: _t->on_drawDownArc_btn_clicked(); break;
        case 37: _t->on_circle_btn_clicked(); break;
        case 38: _t->on_chord_btn_clicked(); break;
        case 39: _t->on_rect_btn_clicked(); break;
        case 40: _t->on_rectRound_btn_clicked(); break;
        case 41: _t->on_triangle_btn_clicked(); break;
        case 42: _t->on_pentagle_btn_clicked(); break;
        case 43: _t->on_hexagon_btn_clicked(); break;
        case 44: _t->on_heptagon_btn_clicked(); break;
        case 45: _t->on_diamond_btn_clicked(); break;
        case 46: _t->on_arrow_btn_clicked(); break;
        case 47: _t->on_custom_sticker_btn_clicked(); break;
        case 48: _t->stickerSelect(); break;
        case 49: _t->on_sticker1_clicked(); break;
        case 50: _t->on_sticker2_clicked(); break;
        case 51: _t->on_sticker3_clicked(); break;
        case 52: _t->on_sticker4_clicked(); break;
        case 53: _t->on_user_sticker_btn_clicked(); break;
        case 54: _t->on_sticker_selected_clicked(); break;
        case 55: _t->setDrawCustomSticker(); break;
        case 56: _t->setDrawUserSticker(); break;
        case 57: _t->on_editSelect_btn_clicked(); break;
        case 58: _t->on_editDraw_btn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Paint::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Paint.data,
      qt_meta_data_Paint,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Paint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Paint.stringdata0))
        return static_cast<void*>(const_cast< Paint*>(this));
    return QWidget::qt_metacast(_clname);
}

int Paint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 59)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 59;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 59)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 59;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
