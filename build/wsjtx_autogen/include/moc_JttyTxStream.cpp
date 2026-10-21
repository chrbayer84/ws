/****************************************************************************
** Meta object code from reading C++ file 'JttyTxStream.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Modulator/JttyTxStream.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JttyTxStream.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JttyTxStream_t {
    QByteArrayData data[15];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JttyTxStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JttyTxStream_t qt_meta_stringdata_JttyTxStream = {
    {
QT_MOC_LITERAL(0, 0, 12), // "JttyTxStream"
QT_MOC_LITERAL(1, 13, 7), // "drained"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 22), // "TxAudioQueueDrainState"
QT_MOC_LITERAL(4, 45, 5), // "drain"
QT_MOC_LITERAL(5, 51, 17), // "txSourceCommitted"
QT_MOC_LITERAL(6, 69, 27), // "TxEvidence::TxStartSnapshot"
QT_MOC_LITERAL(7, 97, 8), // "snapshot"
QT_MOC_LITERAL(8, 106, 5), // "start"
QT_MOC_LITERAL(9, 112, 21), // "TxEvidence::TxRequest"
QT_MOC_LITERAL(10, 134, 7), // "request"
QT_MOC_LITERAL(11, 142, 12), // "SoundOutput*"
QT_MOC_LITERAL(12, 155, 6), // "stream"
QT_MOC_LITERAL(13, 162, 4), // "stop"
QT_MOC_LITERAL(14, 167, 9) // "pollDrain"

    },
    "JttyTxStream\0drained\0\0TxAudioQueueDrainState\0"
    "drain\0txSourceCommitted\0"
    "TxEvidence::TxStartSnapshot\0snapshot\0"
    "start\0TxEvidence::TxRequest\0request\0"
    "SoundOutput*\0stream\0stop\0pollDrain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JttyTxStream[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   45,    2, 0x0a /* Public */,
      13,    0,   50,    2, 0x0a /* Public */,
      14,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void JttyTxStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JttyTxStream *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->drained((*reinterpret_cast< TxAudioQueueDrainState(*)>(_a[1]))); break;
        case 1: _t->txSourceCommitted((*reinterpret_cast< TxEvidence::TxStartSnapshot(*)>(_a[1]))); break;
        case 2: _t->start((*reinterpret_cast< TxEvidence::TxRequest(*)>(_a[1])),(*reinterpret_cast< SoundOutput*(*)>(_a[2]))); break;
        case 3: _t->stop(); break;
        case 4: _t->pollDrain(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueDrainState >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxEvidence::TxStartSnapshot >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxEvidence::TxRequest >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JttyTxStream::*)(TxAudioQueueDrainState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JttyTxStream::drained)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JttyTxStream::*)(TxEvidence::TxStartSnapshot );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JttyTxStream::txSourceCommitted)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JttyTxStream::staticMetaObject = { {
    QMetaObject::SuperData::link<AudioDevice::staticMetaObject>(),
    qt_meta_stringdata_JttyTxStream.data,
    qt_meta_data_JttyTxStream,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JttyTxStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JttyTxStream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JttyTxStream.stringdata0))
        return static_cast<void*>(this);
    return AudioDevice::qt_metacast(_clname);
}

int JttyTxStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void JttyTxStream::drained(TxAudioQueueDrainState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JttyTxStream::txSourceCommitted(TxEvidence::TxStartSnapshot _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
