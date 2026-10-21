/****************************************************************************
** Meta object code from reading C++ file 'Transceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Transceiver/Transceiver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Transceiver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Transceiver_t {
    QByteArrayData data[49];
    char stringdata0[499];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Transceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Transceiver_t qt_meta_stringdata_Transceiver = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Transceiver"
QT_MOC_LITERAL(1, 12, 10), // "resolution"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "tciframeswritten"
QT_MOC_LITERAL(4, 41, 14), // "tci_mod_active"
QT_MOC_LITERAL(5, 56, 6), // "update"
QT_MOC_LITERAL(6, 63, 29), // "Transceiver::TransceiverState"
QT_MOC_LITERAL(7, 93, 15), // "sequence_number"
QT_MOC_LITERAL(8, 109, 7), // "failure"
QT_MOC_LITERAL(9, 117, 6), // "reason"
QT_MOC_LITERAL(10, 124, 18), // "tx_inhibit_changed"
QT_MOC_LITERAL(11, 143, 9), // "inhibited"
QT_MOC_LITERAL(12, 153, 6), // "source"
QT_MOC_LITERAL(13, 160, 7), // "hold_rx"
QT_MOC_LITERAL(14, 168, 10), // "release_rx"
QT_MOC_LITERAL(15, 179, 8), // "expiries"
QT_MOC_LITERAL(16, 188, 7), // "invalid"
QT_MOC_LITERAL(17, 196, 21), // "tx_inhibit_port_bound"
QT_MOC_LITERAL(18, 218, 4), // "port"
QT_MOC_LITERAL(19, 223, 12), // "jtty_drained"
QT_MOC_LITERAL(20, 236, 22), // "TxAudioQueueDrainState"
QT_MOC_LITERAL(21, 259, 5), // "drain"
QT_MOC_LITERAL(22, 265, 21), // "jtty_enqueue_accepted"
QT_MOC_LITERAL(23, 287, 9), // "enqueueId"
QT_MOC_LITERAL(24, 297, 11), // "sampleCount"
QT_MOC_LITERAL(25, 309, 20), // "TxAudioQueueProgress"
QT_MOC_LITERAL(26, 330, 8), // "progress"
QT_MOC_LITERAL(27, 339, 19), // "jtty_enqueue_failed"
QT_MOC_LITERAL(28, 359, 17), // "TxAudioQueueEpoch"
QT_MOC_LITERAL(29, 377, 5), // "epoch"
QT_MOC_LITERAL(30, 383, 8), // "finished"
QT_MOC_LITERAL(31, 392, 3), // "set"
QT_MOC_LITERAL(32, 396, 5), // "start"
QT_MOC_LITERAL(33, 402, 4), // "stop"
QT_MOC_LITERAL(34, 407, 16), // "enqueue_jtty_pcm"
QT_MOC_LITERAL(35, 424, 14), // "clear_jtty_pcm"
QT_MOC_LITERAL(36, 439, 4), // "MODE"
QT_MOC_LITERAL(37, 444, 3), // "UNK"
QT_MOC_LITERAL(38, 448, 2), // "CW"
QT_MOC_LITERAL(39, 451, 4), // "CW_R"
QT_MOC_LITERAL(40, 456, 3), // "USB"
QT_MOC_LITERAL(41, 460, 3), // "LSB"
QT_MOC_LITERAL(42, 464, 3), // "FSK"
QT_MOC_LITERAL(43, 468, 5), // "FSK_R"
QT_MOC_LITERAL(44, 474, 5), // "DIG_U"
QT_MOC_LITERAL(45, 480, 5), // "DIG_L"
QT_MOC_LITERAL(46, 486, 2), // "AM"
QT_MOC_LITERAL(47, 489, 2), // "FM"
QT_MOC_LITERAL(48, 492, 6) // "DIG_FM"

    },
    "Transceiver\0resolution\0\0tciframeswritten\0"
    "tci_mod_active\0update\0"
    "Transceiver::TransceiverState\0"
    "sequence_number\0failure\0reason\0"
    "tx_inhibit_changed\0inhibited\0source\0"
    "hold_rx\0release_rx\0expiries\0invalid\0"
    "tx_inhibit_port_bound\0port\0jtty_drained\0"
    "TxAudioQueueDrainState\0drain\0"
    "jtty_enqueue_accepted\0enqueueId\0"
    "sampleCount\0TxAudioQueueProgress\0"
    "progress\0jtty_enqueue_failed\0"
    "TxAudioQueueEpoch\0epoch\0finished\0set\0"
    "start\0stop\0enqueue_jtty_pcm\0clear_jtty_pcm\0"
    "MODE\0UNK\0CW\0CW_R\0USB\0LSB\0FSK\0FSK_R\0"
    "DIG_U\0DIG_L\0AM\0FM\0DIG_FM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Transceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       1,  162, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,
       4,    1,  100,    2, 0x06 /* Public */,
       5,    2,  103,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,
      10,    6,  111,    2, 0x06 /* Public */,
      17,    1,  124,    2, 0x06 /* Public */,
      19,    1,  127,    2, 0x06 /* Public */,
      22,    3,  130,    2, 0x06 /* Public */,
      27,    2,  137,    2, 0x06 /* Public */,
      30,    0,  142,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      31,    2,  143,    2, 0x0a /* Public */,
      32,    1,  148,    2, 0x0a /* Public */,
      33,    0,  151,    2, 0x0a /* Public */,
      34,    3,  152,    2, 0x0a /* Public */,
      35,    1,  159,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt,    2,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   11,   12,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::UShort,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, 0x80000000 | 25,   23,   24,   26,
    QMetaType::Void, 0x80000000 | 28, QMetaType::LongLong,   29,   23,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt,    2,    7,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 28, QMetaType::LongLong,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 28,    2,

 // enums: name, alias, flags, count, data
      36,   36, 0x0,   12,  167,

 // enum data: key, value
      37, uint(Transceiver::UNK),
      38, uint(Transceiver::CW),
      39, uint(Transceiver::CW_R),
      40, uint(Transceiver::USB),
      41, uint(Transceiver::LSB),
      42, uint(Transceiver::FSK),
      43, uint(Transceiver::FSK_R),
      44, uint(Transceiver::DIG_U),
      45, uint(Transceiver::DIG_L),
      46, uint(Transceiver::AM),
      47, uint(Transceiver::FM),
      48, uint(Transceiver::DIG_FM),

       0        // eod
};

void Transceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Transceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->tciframeswritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->tci_mod_active((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->update((*reinterpret_cast< const Transceiver::TransceiverState(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 4: _t->failure((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->tx_inhibit_changed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6]))); break;
        case 6: _t->tx_inhibit_port_bound((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 7: _t->jtty_drained((*reinterpret_cast< TxAudioQueueDrainState(*)>(_a[1]))); break;
        case 8: _t->jtty_enqueue_accepted((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< TxAudioQueueProgress(*)>(_a[3]))); break;
        case 9: _t->jtty_enqueue_failed((*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 10: _t->finished(); break;
        case 11: _t->set((*reinterpret_cast< const Transceiver::TransceiverState(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 12: _t->start((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: _t->stop(); break;
        case 14: _t->enqueue_jtty_pcm((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 15: _t->clear_jtty_pcm((*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Transceiver::TransceiverState >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueDrainState >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueProgress >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueEpoch >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Transceiver::TransceiverState >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueEpoch >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueEpoch >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Transceiver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::resolution)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::tciframeswritten)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::tci_mod_active)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(Transceiver::TransceiverState const & , unsigned  ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::update)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::failure)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(bool , QString const & , quint32 , quint32 , quint32 , quint32 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::tx_inhibit_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(quint16 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::tx_inhibit_port_bound)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(TxAudioQueueDrainState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::jtty_drained)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(qint64 , qint64 , TxAudioQueueProgress );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::jtty_enqueue_accepted)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)(TxAudioQueueEpoch , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::jtty_enqueue_failed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Transceiver::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Transceiver::finished)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Transceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Transceiver.data,
    qt_meta_data_Transceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Transceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Transceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Transceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Transceiver::resolution(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Transceiver::tciframeswritten(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Transceiver::tci_mod_active(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Transceiver::update(Transceiver::TransceiverState const & _t1, unsigned  _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Transceiver::failure(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Transceiver::tx_inhibit_changed(bool _t1, QString const & _t2, quint32 _t3, quint32 _t4, quint32 _t5, quint32 _t6)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Transceiver::tx_inhibit_port_bound(quint16 _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Transceiver::jtty_drained(TxAudioQueueDrainState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Transceiver::jtty_enqueue_accepted(qint64 _t1, qint64 _t2, TxAudioQueueProgress _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Transceiver::jtty_enqueue_failed(TxAudioQueueEpoch _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Transceiver::finished()const
{
    QMetaObject::activate(const_cast< Transceiver *>(this), &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
