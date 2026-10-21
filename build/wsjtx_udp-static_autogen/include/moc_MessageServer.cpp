/****************************************************************************
** Meta object code from reading C++ file 'MessageServer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UDPExamples/MessageServer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSet>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageServer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MessageServer_t {
    QByteArrayData data[93];
    char stringdata0[945];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageServer_t qt_meta_stringdata_MessageServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MessageServer"
QT_MOC_LITERAL(1, 14, 13), // "client_opened"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "ClientKey"
QT_MOC_LITERAL(4, 39, 7), // "version"
QT_MOC_LITERAL(5, 47, 8), // "revision"
QT_MOC_LITERAL(6, 56, 13), // "status_update"
QT_MOC_LITERAL(7, 70, 9), // "Frequency"
QT_MOC_LITERAL(8, 80, 4), // "mode"
QT_MOC_LITERAL(9, 85, 7), // "dx_call"
QT_MOC_LITERAL(10, 93, 6), // "report"
QT_MOC_LITERAL(11, 100, 7), // "tx_mode"
QT_MOC_LITERAL(12, 108, 10), // "tx_enabled"
QT_MOC_LITERAL(13, 119, 12), // "transmitting"
QT_MOC_LITERAL(14, 132, 8), // "decoding"
QT_MOC_LITERAL(15, 141, 5), // "rx_df"
QT_MOC_LITERAL(16, 147, 5), // "tx_df"
QT_MOC_LITERAL(17, 153, 7), // "de_call"
QT_MOC_LITERAL(18, 161, 7), // "de_grid"
QT_MOC_LITERAL(19, 169, 7), // "dx_grid"
QT_MOC_LITERAL(20, 177, 16), // "watchdog_timeout"
QT_MOC_LITERAL(21, 194, 8), // "sub_mode"
QT_MOC_LITERAL(22, 203, 9), // "fast_mode"
QT_MOC_LITERAL(23, 213, 15), // "special_op_mode"
QT_MOC_LITERAL(24, 229, 19), // "frequency_tolerance"
QT_MOC_LITERAL(25, 249, 9), // "tr_period"
QT_MOC_LITERAL(26, 259, 18), // "configuration_name"
QT_MOC_LITERAL(27, 278, 10), // "tx_message"
QT_MOC_LITERAL(28, 289, 10), // "tx_symbols"
QT_MOC_LITERAL(29, 300, 13), // "client_closed"
QT_MOC_LITERAL(30, 314, 6), // "decode"
QT_MOC_LITERAL(31, 321, 6), // "is_new"
QT_MOC_LITERAL(32, 328, 4), // "time"
QT_MOC_LITERAL(33, 333, 3), // "snr"
QT_MOC_LITERAL(34, 337, 10), // "delta_time"
QT_MOC_LITERAL(35, 348, 15), // "delta_frequency"
QT_MOC_LITERAL(36, 364, 7), // "message"
QT_MOC_LITERAL(37, 372, 14), // "low_confidence"
QT_MOC_LITERAL(38, 387, 7), // "off_air"
QT_MOC_LITERAL(39, 395, 11), // "WSPR_decode"
QT_MOC_LITERAL(40, 407, 5), // "drift"
QT_MOC_LITERAL(41, 413, 8), // "callsign"
QT_MOC_LITERAL(42, 422, 4), // "grid"
QT_MOC_LITERAL(43, 427, 5), // "power"
QT_MOC_LITERAL(44, 433, 10), // "qso_logged"
QT_MOC_LITERAL(45, 444, 8), // "time_off"
QT_MOC_LITERAL(46, 453, 14), // "dial_frequency"
QT_MOC_LITERAL(47, 468, 11), // "report_sent"
QT_MOC_LITERAL(48, 480, 15), // "report_received"
QT_MOC_LITERAL(49, 496, 8), // "tx_power"
QT_MOC_LITERAL(50, 505, 8), // "comments"
QT_MOC_LITERAL(51, 514, 4), // "name"
QT_MOC_LITERAL(52, 519, 7), // "time_on"
QT_MOC_LITERAL(53, 527, 13), // "operator_call"
QT_MOC_LITERAL(54, 541, 7), // "my_call"
QT_MOC_LITERAL(55, 549, 7), // "my_grid"
QT_MOC_LITERAL(56, 557, 13), // "exchange_sent"
QT_MOC_LITERAL(57, 571, 13), // "exchange_rcvd"
QT_MOC_LITERAL(58, 585, 9), // "prop_mode"
QT_MOC_LITERAL(59, 595, 9), // "satellite"
QT_MOC_LITERAL(60, 605, 8), // "sat_mode"
QT_MOC_LITERAL(61, 614, 6), // "freqRx"
QT_MOC_LITERAL(62, 621, 15), // "decodes_cleared"
QT_MOC_LITERAL(63, 637, 11), // "logged_ADIF"
QT_MOC_LITERAL(64, 649, 4), // "ADIF"
QT_MOC_LITERAL(65, 654, 5), // "error"
QT_MOC_LITERAL(66, 660, 5), // "start"
QT_MOC_LITERAL(67, 666, 9), // "port_type"
QT_MOC_LITERAL(68, 676, 4), // "port"
QT_MOC_LITERAL(69, 681, 12), // "QHostAddress"
QT_MOC_LITERAL(70, 694, 23), // "multicast_group_address"
QT_MOC_LITERAL(71, 718, 13), // "QSet<QString>"
QT_MOC_LITERAL(72, 732, 23), // "network_interface_names"
QT_MOC_LITERAL(73, 756, 13), // "clear_decodes"
QT_MOC_LITERAL(74, 770, 6), // "window"
QT_MOC_LITERAL(75, 777, 5), // "reply"
QT_MOC_LITERAL(76, 783, 9), // "modifiers"
QT_MOC_LITERAL(77, 793, 5), // "close"
QT_MOC_LITERAL(78, 799, 6), // "replay"
QT_MOC_LITERAL(79, 806, 7), // "halt_tx"
QT_MOC_LITERAL(80, 814, 9), // "auto_only"
QT_MOC_LITERAL(81, 824, 9), // "free_text"
QT_MOC_LITERAL(82, 834, 4), // "text"
QT_MOC_LITERAL(83, 839, 4), // "send"
QT_MOC_LITERAL(84, 844, 8), // "location"
QT_MOC_LITERAL(85, 853, 18), // "highlight_callsign"
QT_MOC_LITERAL(86, 872, 2), // "bg"
QT_MOC_LITERAL(87, 875, 2), // "fg"
QT_MOC_LITERAL(88, 878, 9), // "last_only"
QT_MOC_LITERAL(89, 888, 20), // "switch_configuration"
QT_MOC_LITERAL(90, 909, 9), // "configure"
QT_MOC_LITERAL(91, 919, 7), // "submode"
QT_MOC_LITERAL(92, 927, 17) // "generate_messages"

    },
    "MessageServer\0client_opened\0\0ClientKey\0"
    "version\0revision\0status_update\0Frequency\0"
    "mode\0dx_call\0report\0tx_mode\0tx_enabled\0"
    "transmitting\0decoding\0rx_df\0tx_df\0"
    "de_call\0de_grid\0dx_grid\0watchdog_timeout\0"
    "sub_mode\0fast_mode\0special_op_mode\0"
    "frequency_tolerance\0tr_period\0"
    "configuration_name\0tx_message\0tx_symbols\0"
    "client_closed\0decode\0is_new\0time\0snr\0"
    "delta_time\0delta_frequency\0message\0"
    "low_confidence\0off_air\0WSPR_decode\0"
    "drift\0callsign\0grid\0power\0qso_logged\0"
    "time_off\0dial_frequency\0report_sent\0"
    "report_received\0tx_power\0comments\0"
    "name\0time_on\0operator_call\0my_call\0"
    "my_grid\0exchange_sent\0exchange_rcvd\0"
    "prop_mode\0satellite\0sat_mode\0freqRx\0"
    "decodes_cleared\0logged_ADIF\0ADIF\0error\0"
    "start\0port_type\0port\0QHostAddress\0"
    "multicast_group_address\0QSet<QString>\0"
    "network_interface_names\0clear_decodes\0"
    "window\0reply\0modifiers\0close\0replay\0"
    "halt_tx\0auto_only\0free_text\0text\0send\0"
    "location\0highlight_callsign\0bg\0fg\0"
    "last_only\0switch_configuration\0configure\0"
    "submode\0generate_messages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  144,    2, 0x06 /* Public */,
       6,   23,  151,    2, 0x06 /* Public */,
      29,    1,  198,    2, 0x06 /* Public */,
      30,   10,  201,    2, 0x06 /* Public */,
      39,   11,  222,    2, 0x06 /* Public */,
      44,   21,  245,    2, 0x06 /* Public */,
      62,    1,  288,    2, 0x06 /* Public */,
      63,    2,  291,    2, 0x06 /* Public */,
      65,    1,  296,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      66,    3,  299,    2, 0x0a /* Public */,
      66,    2,  306,    2, 0x2a /* Public | MethodCloned */,
      66,    1,  311,    2, 0x2a /* Public | MethodCloned */,
      73,    2,  314,    2, 0x0a /* Public */,
      73,    1,  319,    2, 0x2a /* Public | MethodCloned */,
      75,    9,  322,    2, 0x0a /* Public */,
      77,    1,  341,    2, 0x0a /* Public */,
      78,    1,  344,    2, 0x0a /* Public */,
      79,    2,  347,    2, 0x0a /* Public */,
      81,    3,  352,    2, 0x0a /* Public */,
      84,    2,  359,    2, 0x0a /* Public */,
      85,    5,  364,    2, 0x0a /* Public */,
      85,    4,  375,    2, 0x2a /* Public | MethodCloned */,
      85,    3,  384,    2, 0x2a /* Public | MethodCloned */,
      85,    2,  391,    2, 0x2a /* Public | MethodCloned */,
      89,    2,  396,    2, 0x0a /* Public */,
      90,   10,  401,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    2,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::UChar, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::Bool,   31,    2,   32,   33,   34,   35,    8,   36,   37,   38,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, 0x80000000 | 7, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Bool,   31,    2,   32,   33,   34,    2,   40,   41,   42,   43,   38,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, 0x80000000 | 7, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,   45,    9,   19,   46,    8,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,   64,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 67, 0x80000000 | 69, 0x80000000 | 71,   68,   70,   72,
    QMetaType::Void, 0x80000000 | 67, 0x80000000 | 69,   68,   70,
    QMetaType::Void, 0x80000000 | 67,   68,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UChar,    2,   74,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QTime, QMetaType::Int, QMetaType::Float, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::UChar,    2,   32,   33,   34,   35,    8,   36,   37,   76,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    2,   80,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Bool,    2,   82,   83,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,   84,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QColor, QMetaType::QColor, QMetaType::Bool,    2,   41,   86,   87,   88,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QColor, QMetaType::QColor,    2,   41,   86,   87,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QColor,    2,   41,   86,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,   41,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,   26,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::Bool, QMetaType::UInt, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    2,    8,   24,   91,   22,   25,   15,    9,   19,   92,

       0        // eod
};

void MessageServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MessageServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->client_opened((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->status_update((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< Frequency(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< quint32(*)>(_a[10])),(*reinterpret_cast< quint32(*)>(_a[11])),(*reinterpret_cast< const QString(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< bool(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< bool(*)>(_a[17])),(*reinterpret_cast< quint8(*)>(_a[18])),(*reinterpret_cast< quint32(*)>(_a[19])),(*reinterpret_cast< quint32(*)>(_a[20])),(*reinterpret_cast< const QString(*)>(_a[21])),(*reinterpret_cast< const QString(*)>(_a[22])),(*reinterpret_cast< const QString(*)>(_a[23]))); break;
        case 2: _t->client_closed((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 3: _t->decode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const ClientKey(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10]))); break;
        case 4: _t->WSPR_decode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const ClientKey(*)>(_a[2])),(*reinterpret_cast< QTime(*)>(_a[3])),(*reinterpret_cast< qint32(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< Frequency(*)>(_a[6])),(*reinterpret_cast< qint32(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< qint32(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11]))); break;
        case 5: _t->qso_logged((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< Frequency(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< QDateTime(*)>(_a[12])),(*reinterpret_cast< const QString(*)>(_a[13])),(*reinterpret_cast< const QString(*)>(_a[14])),(*reinterpret_cast< const QString(*)>(_a[15])),(*reinterpret_cast< const QString(*)>(_a[16])),(*reinterpret_cast< const QString(*)>(_a[17])),(*reinterpret_cast< const QString(*)>(_a[18])),(*reinterpret_cast< const QString(*)>(_a[19])),(*reinterpret_cast< const QString(*)>(_a[20])),(*reinterpret_cast< const QString(*)>(_a[21]))); break;
        case 6: _t->decodes_cleared((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 7: _t->logged_ADIF((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 8: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->start((*reinterpret_cast< port_type(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2])),(*reinterpret_cast< QSet<QString>(*)>(_a[3]))); break;
        case 10: _t->start((*reinterpret_cast< port_type(*)>(_a[1])),(*reinterpret_cast< const QHostAddress(*)>(_a[2]))); break;
        case 11: _t->start((*reinterpret_cast< port_type(*)>(_a[1]))); break;
        case 12: _t->clear_decodes((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 13: _t->clear_decodes((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 14: _t->reply((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< QTime(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< quint8(*)>(_a[9]))); break;
        case 15: _t->close((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 16: _t->replay((*reinterpret_cast< const ClientKey(*)>(_a[1]))); break;
        case 17: _t->halt_tx((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->free_text((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 19: _t->location((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 20: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 21: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3])),(*reinterpret_cast< const QColor(*)>(_a[4]))); break;
        case 22: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QColor(*)>(_a[3]))); break;
        case 23: _t->highlight_callsign((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 24: _t->switch_configuration((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 25: _t->configure((*reinterpret_cast< const ClientKey(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6])),(*reinterpret_cast< quint32(*)>(_a[7])),(*reinterpret_cast< const QString(*)>(_a[8])),(*reinterpret_cast< const QString(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSet<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MessageServer::*)(ClientKey const & , QString const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::client_opened)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(ClientKey const & , Frequency , QString const & , QString const & , QString const & , QString const & , bool , bool , bool , quint32 , quint32 , QString const & , QString const & , QString const & , bool , QString const & , bool , quint8 , quint32 , quint32 , QString const & , QString const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::status_update)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(ClientKey const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::client_closed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(bool , ClientKey const & , QTime , qint32 , float , quint32 , QString const & , QString const & , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::decode)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(bool , ClientKey const & , QTime , qint32 , float , Frequency , qint32 , QString const & , QString const & , qint32 , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::WSPR_decode)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(ClientKey const & , QDateTime , QString const & , QString const & , Frequency , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QDateTime , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & , QString const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::qso_logged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(ClientKey const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::decodes_cleared)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(ClientKey const & , QByteArray const & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::logged_ADIF)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MessageServer::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageServer::error)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MessageServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MessageServer.data,
    qt_meta_data_MessageServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MessageServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MessageServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MessageServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MessageServer::client_opened(ClientKey const & _t1, QString const & _t2, QString const & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MessageServer::status_update(ClientKey const & _t1, Frequency _t2, QString const & _t3, QString const & _t4, QString const & _t5, QString const & _t6, bool _t7, bool _t8, bool _t9, quint32 _t10, quint32 _t11, QString const & _t12, QString const & _t13, QString const & _t14, bool _t15, QString const & _t16, bool _t17, quint8 _t18, quint32 _t19, quint32 _t20, QString const & _t21, QString const & _t22, QString const & _t23)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t22))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t23))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MessageServer::client_closed(ClientKey const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MessageServer::decode(bool _t1, ClientKey const & _t2, QTime _t3, qint32 _t4, float _t5, quint32 _t6, QString const & _t7, QString const & _t8, bool _t9, bool _t10)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MessageServer::WSPR_decode(bool _t1, ClientKey const & _t2, QTime _t3, qint32 _t4, float _t5, Frequency _t6, qint32 _t7, QString const & _t8, QString const & _t9, qint32 _t10, bool _t11)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MessageServer::qso_logged(ClientKey const & _t1, QDateTime _t2, QString const & _t3, QString const & _t4, Frequency _t5, QString const & _t6, QString const & _t7, QString const & _t8, QString const & _t9, QString const & _t10, QString const & _t11, QDateTime _t12, QString const & _t13, QString const & _t14, QString const & _t15, QString const & _t16, QString const & _t17, QString const & _t18, QString const & _t19, QString const & _t20, QString const & _t21)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t14))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t15))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t16))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t17))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t18))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t19))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t20))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t21))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MessageServer::decodes_cleared(ClientKey const & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MessageServer::logged_ADIF(ClientKey const & _t1, QByteArray const & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MessageServer::error(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< MessageServer *>(this), &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
