/****************************************************************************
** Meta object code from reading C++ file 'plotter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qmap/plotter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPlotter_t {
    QByteArrayData data[17];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPlotter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPlotter_t qt_meta_stringdata_CPlotter = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CPlotter"
QT_MOC_LITERAL(1, 9, 13), // "freezeDecode0"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 1), // "n"
QT_MOC_LITERAL(4, 26, 13), // "freezeDecode1"
QT_MOC_LITERAL(5, 40, 15), // "callsignClicked"
QT_MOC_LITERAL(6, 56, 4), // "call"
QT_MOC_LITERAL(7, 61, 8), // "freq_khz"
QT_MOC_LITERAL(8, 70, 4), // "grid"
QT_MOC_LITERAL(9, 75, 4), // "mode"
QT_MOC_LITERAL(10, 80, 11), // "even_period"
QT_MOC_LITERAL(11, 92, 9), // "fsked_khz"
QT_MOC_LITERAL(12, 102, 9), // "start_qso"
QT_MOC_LITERAL(13, 112, 15), // "mousePressEvent"
QT_MOC_LITERAL(14, 128, 12), // "QMouseEvent*"
QT_MOC_LITERAL(15, 141, 5), // "event"
QT_MOC_LITERAL(16, 147, 21) // "mouseDoubleClickEvent"

    },
    "CPlotter\0freezeDecode0\0\0n\0freezeDecode1\0"
    "callsignClicked\0call\0freq_khz\0grid\0"
    "mode\0even_period\0fsked_khz\0start_qso\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseDoubleClickEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPlotter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    7,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   60,    2, 0x08 /* Private */,
      16,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Bool,    6,    7,    8,    9,   10,   11,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void CPlotter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CPlotter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->freezeDecode0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->freezeDecode1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->callsignClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CPlotter::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPlotter::freezeDecode0)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CPlotter::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPlotter::freezeDecode1)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CPlotter::*)(const QString & , double , const QString & , const QString & , int , double , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CPlotter::callsignClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CPlotter::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_CPlotter.data,
    qt_meta_data_CPlotter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CPlotter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPlotter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CPlotter.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int CPlotter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CPlotter::freezeDecode0(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CPlotter::freezeDecode1(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CPlotter::callsignClicked(const QString & _t1, double _t2, const QString & _t3, const QString & _t4, int _t5, double _t6, bool _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
