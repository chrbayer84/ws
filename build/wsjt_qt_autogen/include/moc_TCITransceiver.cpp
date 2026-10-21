/****************************************************************************
** Meta object code from reading C++ file 'TCITransceiver.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Transceiver/TCITransceiver.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCITransceiver.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCITransceiver_t {
    QByteArrayData data[94];
    char stringdata0[1118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCITransceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCITransceiver_t qt_meta_stringdata_TCITransceiver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TCITransceiver"
QT_MOC_LITERAL(1, 15, 10), // "sendIqData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "float*"
QT_MOC_LITERAL(4, 34, 13), // "sendAudioData"
QT_MOC_LITERAL(5, 48, 9), // "receiveIQ"
QT_MOC_LITERAL(6, 58, 13), // "txAudioChrono"
QT_MOC_LITERAL(7, 72, 9), // "tci_done1"
QT_MOC_LITERAL(8, 82, 9), // "tci_done2"
QT_MOC_LITERAL(9, 92, 9), // "tci_done3"
QT_MOC_LITERAL(10, 102, 9), // "tci_done4"
QT_MOC_LITERAL(11, 112, 9), // "tci_done5"
QT_MOC_LITERAL(12, 122, 9), // "tci_done6"
QT_MOC_LITERAL(13, 132, 9), // "tci_done7"
QT_MOC_LITERAL(14, 142, 9), // "tci_done8"
QT_MOC_LITERAL(15, 152, 15), // "sendTextMessage"
QT_MOC_LITERAL(16, 168, 7), // "message"
QT_MOC_LITERAL(17, 176, 11), // "txAudioData"
QT_MOC_LITERAL(18, 188, 3), // "len"
QT_MOC_LITERAL(19, 192, 4), // "data"
QT_MOC_LITERAL(20, 197, 16), // "enqueue_jtty_pcm"
QT_MOC_LITERAL(21, 214, 7), // "samples"
QT_MOC_LITERAL(22, 222, 17), // "TxAudioQueueEpoch"
QT_MOC_LITERAL(23, 240, 5), // "epoch"
QT_MOC_LITERAL(24, 246, 9), // "enqueueId"
QT_MOC_LITERAL(25, 256, 14), // "clear_jtty_pcm"
QT_MOC_LITERAL(26, 271, 15), // "poll_jtty_drain"
QT_MOC_LITERAL(27, 287, 16), // "onBinaryReceived"
QT_MOC_LITERAL(28, 304, 17), // "onMessageReceived"
QT_MOC_LITERAL(29, 322, 3), // "str"
QT_MOC_LITERAL(30, 326, 7), // "onError"
QT_MOC_LITERAL(31, 334, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(32, 363, 3), // "err"
QT_MOC_LITERAL(33, 367, 11), // "onConnected"
QT_MOC_LITERAL(34, 379, 14), // "onDisconnected"
QT_MOC_LITERAL(35, 394, 7), // "Tci_Cmd"
QT_MOC_LITERAL(36, 402, 11), // "Cmd_Unknown"
QT_MOC_LITERAL(37, 414, 10), // "Cmd_Device"
QT_MOC_LITERAL(38, 425, 15), // "Cmd_ReceiveOnly"
QT_MOC_LITERAL(39, 441, 12), // "Cmd_TrxCount"
QT_MOC_LITERAL(40, 454, 16), // "Cmd_ChannelCount"
QT_MOC_LITERAL(41, 471, 13), // "Cmd_VfoLimits"
QT_MOC_LITERAL(42, 485, 12), // "Cmd_IfLimits"
QT_MOC_LITERAL(43, 498, 12), // "Cmd_ModeList"
QT_MOC_LITERAL(44, 511, 8), // "Cmd_Mode"
QT_MOC_LITERAL(45, 520, 9), // "Cmd_Ready"
QT_MOC_LITERAL(46, 530, 8), // "Cmd_Stop"
QT_MOC_LITERAL(47, 539, 9), // "Cmd_Start"
QT_MOC_LITERAL(48, 549, 10), // "Cmd_Preamp"
QT_MOC_LITERAL(49, 560, 7), // "Cmd_Dds"
QT_MOC_LITERAL(50, 568, 6), // "Cmd_If"
QT_MOC_LITERAL(51, 575, 7), // "Cmd_Trx"
QT_MOC_LITERAL(52, 583, 12), // "Cmd_RxEnable"
QT_MOC_LITERAL(53, 596, 12), // "Cmd_TxEnable"
QT_MOC_LITERAL(54, 609, 19), // "Cmd_RxChannelEnable"
QT_MOC_LITERAL(55, 629, 13), // "Cmd_RitEnable"
QT_MOC_LITERAL(56, 643, 13), // "Cmd_RitOffset"
QT_MOC_LITERAL(57, 657, 13), // "Cmd_XitEnable"
QT_MOC_LITERAL(58, 671, 13), // "Cmd_XitOffset"
QT_MOC_LITERAL(59, 685, 15), // "Cmd_SplitEnable"
QT_MOC_LITERAL(60, 701, 8), // "Cmd_IqSR"
QT_MOC_LITERAL(61, 710, 11), // "Cmd_IqStart"
QT_MOC_LITERAL(62, 722, 10), // "Cmd_IqStop"
QT_MOC_LITERAL(63, 733, 11), // "Cmd_CWSpeed"
QT_MOC_LITERAL(64, 745, 11), // "Cmd_CWDelay"
QT_MOC_LITERAL(65, 757, 8), // "Cmd_Spot"
QT_MOC_LITERAL(66, 766, 14), // "Cmd_SpotDelete"
QT_MOC_LITERAL(67, 781, 14), // "Cmd_FilterBand"
QT_MOC_LITERAL(68, 796, 7), // "Cmd_VFO"
QT_MOC_LITERAL(69, 804, 11), // "Cmd_Version"
QT_MOC_LITERAL(70, 816, 8), // "Cmd_Tune"
QT_MOC_LITERAL(71, 825, 10), // "Cmd_RxMute"
QT_MOC_LITERAL(72, 836, 10), // "Cmd_Smeter"
QT_MOC_LITERAL(73, 847, 9), // "Cmd_Power"
QT_MOC_LITERAL(74, 857, 7), // "Cmd_SWR"
QT_MOC_LITERAL(75, 865, 12), // "Cmd_ECoderRX"
QT_MOC_LITERAL(76, 878, 13), // "Cmd_ECoderVFO"
QT_MOC_LITERAL(77, 892, 11), // "Cmd_AudioSR"
QT_MOC_LITERAL(78, 904, 14), // "Cmd_AudioStart"
QT_MOC_LITERAL(79, 919, 13), // "Cmd_AudioStop"
QT_MOC_LITERAL(80, 933, 12), // "Cmd_AppFocus"
QT_MOC_LITERAL(81, 946, 10), // "Cmd_Volume"
QT_MOC_LITERAL(82, 957, 13), // "Cmd_SqlEnable"
QT_MOC_LITERAL(83, 971, 12), // "Cmd_SqlLevel"
QT_MOC_LITERAL(84, 984, 9), // "Cmd_Drive"
QT_MOC_LITERAL(85, 994, 13), // "Cmd_TuneDrive"
QT_MOC_LITERAL(86, 1008, 8), // "Cmd_Mute"
QT_MOC_LITERAL(87, 1017, 19), // "Cmd_RxSensorsEnable"
QT_MOC_LITERAL(88, 1037, 19), // "Cmd_TxSensorsEnable"
QT_MOC_LITERAL(89, 1057, 13), // "Cmd_RxSensors"
QT_MOC_LITERAL(90, 1071, 13), // "Cmd_TxSensors"
QT_MOC_LITERAL(91, 1085, 11), // "Cmd_AgcMode"
QT_MOC_LITERAL(92, 1097, 11), // "Cmd_AgcGain"
QT_MOC_LITERAL(93, 1109, 8) // "Cmd_Lock"

    },
    "TCITransceiver\0sendIqData\0\0float*\0"
    "sendAudioData\0receiveIQ\0txAudioChrono\0"
    "tci_done1\0tci_done2\0tci_done3\0tci_done4\0"
    "tci_done5\0tci_done6\0tci_done7\0tci_done8\0"
    "sendTextMessage\0message\0txAudioData\0"
    "len\0data\0enqueue_jtty_pcm\0samples\0"
    "TxAudioQueueEpoch\0epoch\0enqueueId\0"
    "clear_jtty_pcm\0poll_jtty_drain\0"
    "onBinaryReceived\0onMessageReceived\0"
    "str\0onError\0QAbstractSocket::SocketError\0"
    "err\0onConnected\0onDisconnected\0Tci_Cmd\0"
    "Cmd_Unknown\0Cmd_Device\0Cmd_ReceiveOnly\0"
    "Cmd_TrxCount\0Cmd_ChannelCount\0"
    "Cmd_VfoLimits\0Cmd_IfLimits\0Cmd_ModeList\0"
    "Cmd_Mode\0Cmd_Ready\0Cmd_Stop\0Cmd_Start\0"
    "Cmd_Preamp\0Cmd_Dds\0Cmd_If\0Cmd_Trx\0"
    "Cmd_RxEnable\0Cmd_TxEnable\0Cmd_RxChannelEnable\0"
    "Cmd_RitEnable\0Cmd_RitOffset\0Cmd_XitEnable\0"
    "Cmd_XitOffset\0Cmd_SplitEnable\0Cmd_IqSR\0"
    "Cmd_IqStart\0Cmd_IqStop\0Cmd_CWSpeed\0"
    "Cmd_CWDelay\0Cmd_Spot\0Cmd_SpotDelete\0"
    "Cmd_FilterBand\0Cmd_VFO\0Cmd_Version\0"
    "Cmd_Tune\0Cmd_RxMute\0Cmd_Smeter\0Cmd_Power\0"
    "Cmd_SWR\0Cmd_ECoderRX\0Cmd_ECoderVFO\0"
    "Cmd_AudioSR\0Cmd_AudioStart\0Cmd_AudioStop\0"
    "Cmd_AppFocus\0Cmd_Volume\0Cmd_SqlEnable\0"
    "Cmd_SqlLevel\0Cmd_Drive\0Cmd_TuneDrive\0"
    "Cmd_Mute\0Cmd_RxSensorsEnable\0"
    "Cmd_TxSensorsEnable\0Cmd_RxSensors\0"
    "Cmd_TxSensors\0Cmd_AgcMode\0Cmd_AgcGain\0"
    "Cmd_Lock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCITransceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       1,  186, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  124,    2, 0x06 /* Public */,
       4,    3,  133,    2, 0x06 /* Public */,
       5,    2,  140,    2, 0x06 /* Public */,
       6,    1,  145,    2, 0x06 /* Public */,
       7,    0,  148,    2, 0x06 /* Public */,
       8,    0,  149,    2, 0x06 /* Public */,
       9,    0,  150,    2, 0x06 /* Public */,
      10,    0,  151,    2, 0x06 /* Public */,
      11,    0,  152,    2, 0x06 /* Public */,
      12,    0,  153,    2, 0x06 /* Public */,
      13,    0,  154,    2, 0x06 /* Public */,
      14,    0,  155,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  156,    2, 0x0a /* Public */,
      17,    2,  159,    2, 0x0a /* Public */,
      20,    3,  164,    2, 0x0a /* Public */,
      25,    1,  171,    2, 0x0a /* Public */,
      26,    0,  174,    2, 0x08 /* Private */,
      27,    1,  175,    2, 0x08 /* Private */,
      28,    1,  178,    2, 0x08 /* Private */,
      30,    1,  181,    2, 0x08 /* Private */,
      33,    0,  184,    2, 0x08 /* Private */,
      34,    0,  185,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, 0x80000000 | 3, QMetaType::Bool,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::UInt, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3,   18,   19,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 22, QMetaType::LongLong,   21,   23,   24,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      35,   35, 0x0,   58,  191,

 // enum data: key, value
      36, uint(TCITransceiver::Cmd_Unknown),
      37, uint(TCITransceiver::Cmd_Device),
      38, uint(TCITransceiver::Cmd_ReceiveOnly),
      39, uint(TCITransceiver::Cmd_TrxCount),
      40, uint(TCITransceiver::Cmd_ChannelCount),
      41, uint(TCITransceiver::Cmd_VfoLimits),
      42, uint(TCITransceiver::Cmd_IfLimits),
      43, uint(TCITransceiver::Cmd_ModeList),
      44, uint(TCITransceiver::Cmd_Mode),
      45, uint(TCITransceiver::Cmd_Ready),
      46, uint(TCITransceiver::Cmd_Stop),
      47, uint(TCITransceiver::Cmd_Start),
      48, uint(TCITransceiver::Cmd_Preamp),
      49, uint(TCITransceiver::Cmd_Dds),
      50, uint(TCITransceiver::Cmd_If),
      51, uint(TCITransceiver::Cmd_Trx),
      52, uint(TCITransceiver::Cmd_RxEnable),
      53, uint(TCITransceiver::Cmd_TxEnable),
      54, uint(TCITransceiver::Cmd_RxChannelEnable),
      55, uint(TCITransceiver::Cmd_RitEnable),
      56, uint(TCITransceiver::Cmd_RitOffset),
      57, uint(TCITransceiver::Cmd_XitEnable),
      58, uint(TCITransceiver::Cmd_XitOffset),
      59, uint(TCITransceiver::Cmd_SplitEnable),
      60, uint(TCITransceiver::Cmd_IqSR),
      61, uint(TCITransceiver::Cmd_IqStart),
      62, uint(TCITransceiver::Cmd_IqStop),
      63, uint(TCITransceiver::Cmd_CWSpeed),
      64, uint(TCITransceiver::Cmd_CWDelay),
      65, uint(TCITransceiver::Cmd_Spot),
      66, uint(TCITransceiver::Cmd_SpotDelete),
      67, uint(TCITransceiver::Cmd_FilterBand),
      68, uint(TCITransceiver::Cmd_VFO),
      69, uint(TCITransceiver::Cmd_Version),
      70, uint(TCITransceiver::Cmd_Tune),
      71, uint(TCITransceiver::Cmd_RxMute),
      72, uint(TCITransceiver::Cmd_Smeter),
      73, uint(TCITransceiver::Cmd_Power),
      74, uint(TCITransceiver::Cmd_SWR),
      75, uint(TCITransceiver::Cmd_ECoderRX),
      76, uint(TCITransceiver::Cmd_ECoderVFO),
      77, uint(TCITransceiver::Cmd_AudioSR),
      78, uint(TCITransceiver::Cmd_AudioStart),
      79, uint(TCITransceiver::Cmd_AudioStop),
      80, uint(TCITransceiver::Cmd_AppFocus),
      81, uint(TCITransceiver::Cmd_Volume),
      82, uint(TCITransceiver::Cmd_SqlEnable),
      83, uint(TCITransceiver::Cmd_SqlLevel),
      84, uint(TCITransceiver::Cmd_Drive),
      85, uint(TCITransceiver::Cmd_TuneDrive),
      86, uint(TCITransceiver::Cmd_Mute),
      87, uint(TCITransceiver::Cmd_RxSensorsEnable),
      88, uint(TCITransceiver::Cmd_TxSensorsEnable),
      89, uint(TCITransceiver::Cmd_RxSensors),
      90, uint(TCITransceiver::Cmd_TxSensors),
      91, uint(TCITransceiver::Cmd_AgcMode),
      92, uint(TCITransceiver::Cmd_AgcGain),
      93, uint(TCITransceiver::Cmd_Lock),

       0        // eod
};

void TCITransceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCITransceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendIqData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->sendAudioData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
        case 2: _t->receiveIQ((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->txAudioChrono((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->tci_done1(); break;
        case 5: _t->tci_done2(); break;
        case 6: _t->tci_done3(); break;
        case 7: _t->tci_done4(); break;
        case 8: _t->tci_done5(); break;
        case 9: _t->tci_done6(); break;
        case 10: _t->tci_done7(); break;
        case 11: _t->tci_done8(); break;
        case 12: _t->sendTextMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->txAudioData((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< float*(*)>(_a[2]))); break;
        case 14: _t->enqueue_jtty_pcm((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 15: _t->clear_jtty_pcm((*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[1]))); break;
        case 16: _t->poll_jtty_drain(); break;
        case 17: _t->onBinaryReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 18: _t->onMessageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 20: _t->onConnected(); break;
        case 21: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        case 19:
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
            using _t = void (TCITransceiver::*)(int , quint32 , float * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::sendIqData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)(int , quint32 , float * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::sendAudioData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::receiveIQ)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::txAudioChrono)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done1)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done2)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done3)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done4)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done5)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done6)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done7)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (TCITransceiver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCITransceiver::tci_done8)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TCITransceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<PollingTransceiver::staticMetaObject>(),
    qt_meta_stringdata_TCITransceiver.data,
    qt_meta_data_TCITransceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TCITransceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCITransceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCITransceiver.stringdata0))
        return static_cast<void*>(this);
    return PollingTransceiver::qt_metacast(_clname);
}

int TCITransceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PollingTransceiver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void TCITransceiver::sendIqData(int _t1, quint32 _t2, float * _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCITransceiver::sendAudioData(int _t1, quint32 _t2, float * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TCITransceiver::receiveIQ(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TCITransceiver::txAudioChrono(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TCITransceiver::tci_done1()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TCITransceiver::tci_done2()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TCITransceiver::tci_done3()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TCITransceiver::tci_done4()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void TCITransceiver::tci_done5()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void TCITransceiver::tci_done6()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TCITransceiver::tci_done7()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void TCITransceiver::tci_done8()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
