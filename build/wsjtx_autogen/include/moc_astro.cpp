/****************************************************************************
** Meta object code from reading C++ file 'astro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/astro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'astro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Astro_t {
    QByteArrayData data[17];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Astro_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Astro_t qt_meta_stringdata_Astro = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Astro"
QT_MOC_LITERAL(1, 6, 15), // "tracking_update"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "skedFreq"
QT_MOC_LITERAL(4, 32, 7), // "freqMHz"
QT_MOC_LITERAL(5, 40, 17), // "nominal_frequency"
QT_MOC_LITERAL(6, 58, 9), // "Frequency"
QT_MOC_LITERAL(7, 68, 2), // "rx"
QT_MOC_LITERAL(8, 71, 2), // "tx"
QT_MOC_LITERAL(9, 74, 28), // "on_rbConstFreqOnMoon_clicked"
QT_MOC_LITERAL(10, 103, 22), // "on_rbFullTrack_clicked"
QT_MOC_LITERAL(11, 126, 22), // "on_rbNoDoppler_clicked"
QT_MOC_LITERAL(12, 149, 20), // "on_rbOwnEcho_clicked"
QT_MOC_LITERAL(13, 170, 21), // "on_rbOnDxEcho_clicked"
QT_MOC_LITERAL(14, 192, 19), // "on_rbCallDx_clicked"
QT_MOC_LITERAL(15, 212, 28), // "on_cbDopplerTracking_toggled"
QT_MOC_LITERAL(16, 241, 16) // "on_pbSet_clicked"

    },
    "Astro\0tracking_update\0\0skedFreq\0freqMHz\0"
    "nominal_frequency\0Frequency\0rx\0tx\0"
    "on_rbConstFreqOnMoon_clicked\0"
    "on_rbFullTrack_clicked\0on_rbNoDoppler_clicked\0"
    "on_rbOwnEcho_clicked\0on_rbOnDxEcho_clicked\0"
    "on_rbCallDx_clicked\0on_cbDopplerTracking_toggled\0"
    "on_pbSet_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Astro[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   73,    2, 0x0a /* Public */,
       9,    1,   78,    2, 0x08 /* Private */,
      10,    1,   81,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      15,    1,   96,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void Astro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Astro *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tracking_update(); break;
        case 1: _t->skedFreq((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->nominal_frequency((*reinterpret_cast< Frequency(*)>(_a[1])),(*reinterpret_cast< Frequency(*)>(_a[2]))); break;
        case 3: _t->on_rbConstFreqOnMoon_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_rbFullTrack_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_rbNoDoppler_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_rbOwnEcho_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_rbOnDxEcho_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_rbCallDx_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_cbDopplerTracking_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_pbSet_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Astro::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Astro::tracking_update)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Astro::*)(double ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Astro::skedFreq)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Astro::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Astro.data,
    qt_meta_data_Astro,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Astro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Astro::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Astro.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Astro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Astro::tracking_update()const
{
    QMetaObject::activate(const_cast< Astro *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Astro::skedFreq(double _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Astro *>(this), &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
