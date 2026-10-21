/****************************************************************************
** Meta object code from reading C++ file 'TxInhibitGate.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TxInhibit/TxInhibitGate.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TxInhibitGate.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TxInhibitGate_t {
    QByteArrayData data[23];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TxInhibitGate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TxInhibitGate_t qt_meta_stringdata_TxInhibitGate = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TxInhibitGate"
QT_MOC_LITERAL(1, 14, 11), // "physicalPtt"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "radiate"
QT_MOC_LITERAL(4, 35, 14), // "inhibitChanged"
QT_MOC_LITERAL(5, 50, 9), // "inhibited"
QT_MOC_LITERAL(6, 60, 6), // "source"
QT_MOC_LITERAL(7, 67, 7), // "hold_rx"
QT_MOC_LITERAL(8, 75, 10), // "release_rx"
QT_MOC_LITERAL(9, 86, 8), // "expiries"
QT_MOC_LITERAL(10, 95, 7), // "invalid"
QT_MOC_LITERAL(11, 103, 9), // "portBound"
QT_MOC_LITERAL(12, 113, 4), // "port"
QT_MOC_LITERAL(13, 118, 9), // "lineError"
QT_MOC_LITERAL(14, 128, 7), // "message"
QT_MOC_LITERAL(15, 136, 14), // "pttApplyFailed"
QT_MOC_LITERAL(16, 151, 15), // "start_listening"
QT_MOC_LITERAL(17, 167, 10), // "set_intent"
QT_MOC_LITERAL(18, 178, 2), // "on"
QT_MOC_LITERAL(19, 181, 8), // "shutdown"
QT_MOC_LITERAL(20, 190, 8), // "emit_pin"
QT_MOC_LITERAL(21, 199, 12), // "on_udp_ready"
QT_MOC_LITERAL(22, 212, 4) // "tick"

    },
    "TxInhibitGate\0physicalPtt\0\0radiate\0"
    "inhibitChanged\0inhibited\0source\0hold_rx\0"
    "release_rx\0expiries\0invalid\0portBound\0"
    "port\0lineError\0message\0pttApplyFailed\0"
    "start_listening\0set_intent\0on\0shutdown\0"
    "emit_pin\0on_udp_ready\0tick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TxInhibitGate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    6,   72,    2, 0x06 /* Public */,
      11,    1,   85,    2, 0x06 /* Public */,
      13,    1,   88,    2, 0x06 /* Public */,
      15,    1,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    0,   94,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,
      19,    1,   98,    2, 0x0a /* Public */,
      19,    0,  101,    2, 0x2a /* Public | MethodCloned */,
      21,    0,  102,    2, 0x08 /* Private */,
      22,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    5,    6,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::UShort,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TxInhibitGate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TxInhibitGate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->physicalPtt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->inhibitChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6]))); break;
        case 2: _t->portBound((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->lineError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->pttApplyFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->start_listening(); break;
        case 6: _t->set_intent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->shutdown((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->shutdown(); break;
        case 9: _t->on_udp_ready(); break;
        case 10: _t->tick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TxInhibitGate::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TxInhibitGate::physicalPtt)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TxInhibitGate::*)(bool , QString const & , quint32 , quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TxInhibitGate::inhibitChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TxInhibitGate::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TxInhibitGate::portBound)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TxInhibitGate::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TxInhibitGate::lineError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TxInhibitGate::*)(QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TxInhibitGate::pttApplyFailed)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TxInhibitGate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TxInhibitGate.data,
    qt_meta_data_TxInhibitGate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TxInhibitGate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TxInhibitGate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TxInhibitGate.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TxInhibitGate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void TxInhibitGate::physicalPtt(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TxInhibitGate::inhibitChanged(bool _t1, QString const & _t2, quint32 _t3, quint32 _t4, quint32 _t5, quint32 _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TxInhibitGate::portBound(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TxInhibitGate::lineError(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TxInhibitGate::pttApplyFailed(QString const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
