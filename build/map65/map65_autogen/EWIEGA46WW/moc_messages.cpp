/****************************************************************************
** Meta object code from reading C++ file 'messages.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../map65/messages.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Messages_t {
    QByteArrayData data[27];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Messages_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Messages_t qt_meta_stringdata_Messages = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Messages"
QT_MOC_LITERAL(1, 9, 16), // "click2OnCallsign"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "t2"
QT_MOC_LITERAL(4, 30, 4), // "ctrl"
QT_MOC_LITERAL(5, 35, 13), // "isDoubleClick"
QT_MOC_LITERAL(6, 49, 13), // "errorOccurred"
QT_MOC_LITERAL(7, 63, 5), // "error"
QT_MOC_LITERAL(8, 69, 20), // "sendLocalStationData"
QT_MOC_LITERAL(9, 90, 4), // "call"
QT_MOC_LITERAL(10, 95, 4), // "grid"
QT_MOC_LITERAL(11, 100, 7), // "antenna"
QT_MOC_LITERAL(12, 108, 14), // "rigInformation"
QT_MOC_LITERAL(13, 123, 21), // "sendRemoteStationData"
QT_MOC_LITERAL(14, 145, 4), // "freq"
QT_MOC_LITERAL(15, 150, 4), // "mode"
QT_MOC_LITERAL(16, 155, 3), // "snr"
QT_MOC_LITERAL(17, 159, 9), // "qSpotTime"
QT_MOC_LITERAL(18, 169, 21), // "sendLocalStationData2"
QT_MOC_LITERAL(19, 191, 6), // "theUrl"
QT_MOC_LITERAL(20, 198, 15), // "selectCallsign2"
QT_MOC_LITERAL(21, 214, 15), // "on_cbCQ_toggled"
QT_MOC_LITERAL(22, 230, 7), // "checked"
QT_MOC_LITERAL(23, 238, 19), // "on_cbCQstar_toggled"
QT_MOC_LITERAL(24, 258, 10), // "onFinished"
QT_MOC_LITERAL(25, 269, 14), // "QNetworkReply*"
QT_MOC_LITERAL(26, 284, 5) // "reply"

    },
    "Messages\0click2OnCallsign\0\0t2\0ctrl\0"
    "isDoubleClick\0errorOccurred\0error\0"
    "sendLocalStationData\0call\0grid\0antenna\0"
    "rigInformation\0sendRemoteStationData\0"
    "freq\0mode\0snr\0qSpotTime\0sendLocalStationData2\0"
    "theUrl\0selectCallsign2\0on_cbCQ_toggled\0"
    "checked\0on_cbCQstar_toggled\0onFinished\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Messages[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    1,   66,    2, 0x06 /* Public */,
       8,    4,   69,    2, 0x06 /* Public */,
      13,    6,   78,    2, 0x06 /* Public */,
      18,    3,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    2,   98,    2, 0x08 /* Private */,
      21,    1,  103,    2, 0x08 /* Private */,
      23,    1,  106,    2, 0x08 /* Private */,
      24,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::ULongLong, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime,    9,   10,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, 0x80000000 | 25,   26,

       0        // eod
};

void Messages::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Messages *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->click2OnCallsign((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->errorOccurred((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sendLocalStationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 3: _t->sendRemoteStationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6]))); break;
        case 4: _t->sendLocalStationData2((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->selectCallsign2((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->on_cbCQ_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_cbCQstar_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Messages::*)(QString , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Messages::click2OnCallsign)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Messages::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Messages::errorOccurred)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Messages::*)(QString const & , QString const & , QString const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Messages::sendLocalStationData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Messages::*)(QString const & , QString const & , quint64 , QString const & , int , QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Messages::sendRemoteStationData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Messages::*)(QString const & , QString const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Messages::sendLocalStationData2)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Messages::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Messages.data,
    qt_meta_data_Messages,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Messages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Messages::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Messages.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Messages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Messages::click2OnCallsign(QString _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Messages::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Messages::sendLocalStationData(QString const & _t1, QString const & _t2, QString const & _t3, QString const & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Messages::sendRemoteStationData(QString const & _t1, QString const & _t2, quint64 _t3, QString const & _t4, int _t5, QDateTime _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Messages::sendLocalStationData2(QString const & _t1, QString const & _t2, QString const & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
