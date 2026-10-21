/****************************************************************************
** Meta object code from reading C++ file 'soundin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qmap/soundin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoundInThread_t {
    QByteArrayData data[12];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoundInThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoundInThread_t qt_meta_stringdata_SoundInThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SoundInThread"
QT_MOC_LITERAL(1, 14, 15), // "bufferAvailable"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "std::valarray<qint16>"
QT_MOC_LITERAL(4, 53, 7), // "samples"
QT_MOC_LITERAL(5, 61, 4), // "rate"
QT_MOC_LITERAL(6, 66, 11), // "readyForFFT"
QT_MOC_LITERAL(7, 78, 1), // "k"
QT_MOC_LITERAL(8, 80, 5), // "error"
QT_MOC_LITERAL(9, 86, 7), // "message"
QT_MOC_LITERAL(10, 94, 6), // "status"
QT_MOC_LITERAL(11, 101, 4) // "quit"

    },
    "SoundInThread\0bufferAvailable\0\0"
    "std::valarray<qint16>\0samples\0rate\0"
    "readyForFFT\0k\0error\0message\0status\0"
    "quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoundInThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,
       8,    1,   47,    2, 0x06 /* Public */,
      10,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void SoundInThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SoundInThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bufferAvailable((*reinterpret_cast< std::valarray<qint16>(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->readyForFFT((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->status((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SoundInThread::*)(std::valarray<qint16> , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundInThread::bufferAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SoundInThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundInThread::readyForFFT)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SoundInThread::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundInThread::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SoundInThread::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SoundInThread::status)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SoundInThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_SoundInThread.data,
    qt_meta_data_SoundInThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SoundInThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundInThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SoundInThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SoundInThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void SoundInThread::bufferAvailable(std::valarray<qint16> _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SoundInThread::readyForFFT(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SoundInThread::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SoundInThread::status(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
