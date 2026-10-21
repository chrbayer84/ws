/****************************************************************************
** Meta object code from reading C++ file 'MMTTYIF.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widgets/MMTTYIF.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MMTTYIF.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MMTTYIF_t {
    QByteArrayData data[26];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MMTTYIF_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MMTTYIF_t qt_meta_stringdata_MMTTYIF = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MMTTYIF"
QT_MOC_LITERAL(1, 8, 18), // "inactivity_timeout"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "app_is_quitting"
QT_MOC_LITERAL(4, 44, 13), // "app_tx_string"
QT_MOC_LITERAL(5, 58, 3), // "str"
QT_MOC_LITERAL(6, 62, 12), // "app_start_tx"
QT_MOC_LITERAL(7, 75, 11), // "app_stop_tx"
QT_MOC_LITERAL(8, 87, 12), // "app_abort_tx"
QT_MOC_LITERAL(9, 100, 16), // "message_received"
QT_MOC_LITERAL(10, 117, 11), // "log_message"
QT_MOC_LITERAL(11, 129, 3), // "msg"
QT_MOC_LITERAL(12, 133, 17), // "connection_failed"
QT_MOC_LITERAL(13, 151, 20), // "echo_message_to_n1mm"
QT_MOC_LITERAL(14, 172, 7), // "message"
QT_MOC_LITERAL(15, 180, 22), // "report_output_complete"
QT_MOC_LITERAL(16, 203, 16), // "report_ptt_state"
QT_MOC_LITERAL(17, 220, 5), // "is_on"
QT_MOC_LITERAL(18, 226, 8), // "shutdown"
QT_MOC_LITERAL(19, 235, 11), // "onConnected"
QT_MOC_LITERAL(20, 247, 14), // "onDisconnected"
QT_MOC_LITERAL(21, 262, 7), // "onError"
QT_MOC_LITERAL(22, 270, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(23, 299, 11), // "socketError"
QT_MOC_LITERAL(24, 311, 14), // "onRetryTimeout"
QT_MOC_LITERAL(25, 326, 11) // "onReadyRead"

    },
    "MMTTYIF\0inactivity_timeout\0\0app_is_quitting\0"
    "app_tx_string\0str\0app_start_tx\0"
    "app_stop_tx\0app_abort_tx\0message_received\0"
    "log_message\0msg\0connection_failed\0"
    "echo_message_to_n1mm\0message\0"
    "report_output_complete\0report_ptt_state\0"
    "is_on\0shutdown\0onConnected\0onDisconnected\0"
    "onError\0QAbstractSocket::SocketError\0"
    "socketError\0onRetryTimeout\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MMTTYIF[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    1,  106,    2, 0x06 /* Public */,
       6,    0,  109,    2, 0x06 /* Public */,
       7,    0,  110,    2, 0x06 /* Public */,
       8,    0,  111,    2, 0x06 /* Public */,
       9,    0,  112,    2, 0x06 /* Public */,
      10,    1,  113,    2, 0x06 /* Public */,
      12,    0,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  117,    2, 0x0a /* Public */,
      15,    0,  120,    2, 0x0a /* Public */,
      16,    1,  121,    2, 0x0a /* Public */,
      18,    0,  124,    2, 0x0a /* Public */,
      19,    0,  125,    2, 0x08 /* Private */,
      20,    0,  126,    2, 0x08 /* Private */,
      21,    1,  127,    2, 0x08 /* Private */,
      24,    0,  130,    2, 0x08 /* Private */,
      25,    0,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MMTTYIF::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MMTTYIF *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inactivity_timeout(); break;
        case 1: _t->app_is_quitting(); break;
        case 2: _t->app_tx_string((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->app_start_tx(); break;
        case 4: _t->app_stop_tx(); break;
        case 5: _t->app_abort_tx(); break;
        case 6: _t->message_received(); break;
        case 7: _t->log_message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->connection_failed(); break;
        case 9: _t->echo_message_to_n1mm((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->report_output_complete(); break;
        case 11: _t->report_ptt_state((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->shutdown(); break;
        case 13: _t->onConnected(); break;
        case 14: _t->onDisconnected(); break;
        case 15: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 16: _t->onRetryTimeout(); break;
        case 17: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::inactivity_timeout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::app_is_quitting)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::app_tx_string)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::app_start_tx)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::app_stop_tx)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::app_abort_tx)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::message_received)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::log_message)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MMTTYIF::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MMTTYIF::connection_failed)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MMTTYIF::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MMTTYIF.data,
    qt_meta_data_MMTTYIF,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MMTTYIF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MMTTYIF::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MMTTYIF.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MMTTYIF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MMTTYIF::inactivity_timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MMTTYIF::app_is_quitting()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MMTTYIF::app_tx_string(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MMTTYIF::app_start_tx()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MMTTYIF::app_stop_tx()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MMTTYIF::app_abort_tx()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MMTTYIF::message_received()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MMTTYIF::log_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MMTTYIF::connection_failed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
