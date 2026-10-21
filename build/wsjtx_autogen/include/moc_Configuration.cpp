/****************************************************************************
** Meta object code from reading C++ file 'Configuration.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Configuration.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Configuration.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Configuration_t {
    QByteArrayData data[79];
    char stringdata0[1403];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Configuration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Configuration_t qt_meta_stringdata_Configuration = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Configuration"
QT_MOC_LITERAL(1, 14, 17), // "text_font_changed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 25), // "decoded_text_font_changed"
QT_MOC_LITERAL(4, 59, 18), // "udp_server_changed"
QT_MOC_LITERAL(5, 78, 8), // "QString&"
QT_MOC_LITERAL(6, 87, 15), // "udp_server_name"
QT_MOC_LITERAL(7, 103, 18), // "network_interfaces"
QT_MOC_LITERAL(8, 122, 23), // "udp_server_port_changed"
QT_MOC_LITERAL(9, 146, 9), // "port_type"
QT_MOC_LITERAL(10, 156, 11), // "server_port"
QT_MOC_LITERAL(11, 168, 15), // "udp_TTL_changed"
QT_MOC_LITERAL(12, 184, 3), // "TTL"
QT_MOC_LITERAL(13, 188, 27), // "accept_udp_requests_changed"
QT_MOC_LITERAL(14, 216, 7), // "checked"
QT_MOC_LITERAL(15, 224, 36), // "udp_wsjtx_compatibility_mode_..."
QT_MOC_LITERAL(16, 261, 27), // "decode_highlighting_changed"
QT_MOC_LITERAL(17, 289, 23), // "DecodeHighlightingModel"
QT_MOC_LITERAL(18, 313, 18), // "transceiver_update"
QT_MOC_LITERAL(19, 332, 29), // "Transceiver::TransceiverState"
QT_MOC_LITERAL(20, 362, 28), // "transceiver_TCIframesWritten"
QT_MOC_LITERAL(21, 391, 24), // "transceiver_TCImodActive"
QT_MOC_LITERAL(22, 416, 24), // "transceiver_jtty_drained"
QT_MOC_LITERAL(23, 441, 22), // "TxAudioQueueDrainState"
QT_MOC_LITERAL(24, 464, 5), // "drain"
QT_MOC_LITERAL(25, 470, 33), // "transceiver_jtty_enqueue_acce..."
QT_MOC_LITERAL(26, 504, 9), // "enqueueId"
QT_MOC_LITERAL(27, 514, 11), // "sampleCount"
QT_MOC_LITERAL(28, 526, 20), // "TxAudioQueueProgress"
QT_MOC_LITERAL(29, 547, 8), // "progress"
QT_MOC_LITERAL(30, 556, 31), // "transceiver_jtty_enqueue_failed"
QT_MOC_LITERAL(31, 588, 17), // "TxAudioQueueEpoch"
QT_MOC_LITERAL(32, 606, 5), // "epoch"
QT_MOC_LITERAL(33, 612, 15), // "leavingSettings"
QT_MOC_LITERAL(34, 628, 19), // "transceiver_failure"
QT_MOC_LITERAL(35, 648, 6), // "reason"
QT_MOC_LITERAL(36, 655, 18), // "tx_inhibit_changed"
QT_MOC_LITERAL(37, 674, 9), // "inhibited"
QT_MOC_LITERAL(38, 684, 6), // "source"
QT_MOC_LITERAL(39, 691, 7), // "hold_rx"
QT_MOC_LITERAL(40, 699, 10), // "release_rx"
QT_MOC_LITERAL(41, 710, 8), // "expiries"
QT_MOC_LITERAL(42, 719, 7), // "invalid"
QT_MOC_LITERAL(43, 727, 23), // "tx_inhibit_port_changed"
QT_MOC_LITERAL(44, 751, 4), // "port"
QT_MOC_LITERAL(45, 756, 25), // "enumerating_audio_devices"
QT_MOC_LITERAL(46, 782, 21), // "transceiver_frequency"
QT_MOC_LITERAL(47, 804, 9), // "Frequency"
QT_MOC_LITERAL(48, 814, 24), // "transceiver_tx_frequency"
QT_MOC_LITERAL(49, 839, 16), // "transceiver_mode"
QT_MOC_LITERAL(50, 856, 4), // "MODE"
QT_MOC_LITERAL(51, 861, 15), // "transceiver_ptt"
QT_MOC_LITERAL(52, 877, 17), // "transceiver_audio"
QT_MOC_LITERAL(53, 895, 16), // "transceiver_tune"
QT_MOC_LITERAL(54, 912, 18), // "transceiver_period"
QT_MOC_LITERAL(55, 931, 21), // "transceiver_blocksize"
QT_MOC_LITERAL(56, 953, 27), // "transceiver_modulator_start"
QT_MOC_LITERAL(57, 981, 26), // "transceiver_modulator_stop"
QT_MOC_LITERAL(58, 1008, 28), // "transceiver_enqueue_jtty_pcm"
QT_MOC_LITERAL(59, 1037, 26), // "transceiver_clear_jtty_pcm"
QT_MOC_LITERAL(60, 1064, 18), // "transceiver_spread"
QT_MOC_LITERAL(61, 1083, 16), // "transceiver_nsym"
QT_MOC_LITERAL(62, 1100, 23), // "transceiver_trfrequency"
QT_MOC_LITERAL(63, 1124, 16), // "sync_transceiver"
QT_MOC_LITERAL(64, 1141, 12), // "force_signal"
QT_MOC_LITERAL(65, 1154, 22), // "enforce_mode_and_split"
QT_MOC_LITERAL(66, 1177, 29), // "invalidate_audio_input_device"
QT_MOC_LITERAL(67, 1207, 5), // "error"
QT_MOC_LITERAL(68, 1213, 30), // "invalidate_audio_output_device"
QT_MOC_LITERAL(69, 1244, 18), // "transceiver_volume"
QT_MOC_LITERAL(70, 1263, 20), // "transceiver_txvolume"
QT_MOC_LITERAL(71, 1284, 8), // "DataMode"
QT_MOC_LITERAL(72, 1293, 14), // "data_mode_none"
QT_MOC_LITERAL(73, 1308, 13), // "data_mode_USB"
QT_MOC_LITERAL(74, 1322, 14), // "data_mode_data"
QT_MOC_LITERAL(75, 1337, 11), // "Type2MsgGen"
QT_MOC_LITERAL(76, 1349, 17), // "type_2_msg_1_full"
QT_MOC_LITERAL(77, 1367, 17), // "type_2_msg_3_full"
QT_MOC_LITERAL(78, 1385, 17) // "type_2_msg_5_only"

    },
    "Configuration\0text_font_changed\0\0"
    "decoded_text_font_changed\0udp_server_changed\0"
    "QString&\0udp_server_name\0network_interfaces\0"
    "udp_server_port_changed\0port_type\0"
    "server_port\0udp_TTL_changed\0TTL\0"
    "accept_udp_requests_changed\0checked\0"
    "udp_wsjtx_compatibility_mode_changed\0"
    "decode_highlighting_changed\0"
    "DecodeHighlightingModel\0transceiver_update\0"
    "Transceiver::TransceiverState\0"
    "transceiver_TCIframesWritten\0"
    "transceiver_TCImodActive\0"
    "transceiver_jtty_drained\0"
    "TxAudioQueueDrainState\0drain\0"
    "transceiver_jtty_enqueue_accepted\0"
    "enqueueId\0sampleCount\0TxAudioQueueProgress\0"
    "progress\0transceiver_jtty_enqueue_failed\0"
    "TxAudioQueueEpoch\0epoch\0leavingSettings\0"
    "transceiver_failure\0reason\0"
    "tx_inhibit_changed\0inhibited\0source\0"
    "hold_rx\0release_rx\0expiries\0invalid\0"
    "tx_inhibit_port_changed\0port\0"
    "enumerating_audio_devices\0"
    "transceiver_frequency\0Frequency\0"
    "transceiver_tx_frequency\0transceiver_mode\0"
    "MODE\0transceiver_ptt\0transceiver_audio\0"
    "transceiver_tune\0transceiver_period\0"
    "transceiver_blocksize\0transceiver_modulator_start\0"
    "transceiver_modulator_stop\0"
    "transceiver_enqueue_jtty_pcm\0"
    "transceiver_clear_jtty_pcm\0"
    "transceiver_spread\0transceiver_nsym\0"
    "transceiver_trfrequency\0sync_transceiver\0"
    "force_signal\0enforce_mode_and_split\0"
    "invalidate_audio_input_device\0error\0"
    "invalidate_audio_output_device\0"
    "transceiver_volume\0transceiver_txvolume\0"
    "DataMode\0data_mode_none\0data_mode_USB\0"
    "data_mode_data\0Type2MsgGen\0type_2_msg_1_full\0"
    "type_2_msg_3_full\0type_2_msg_5_only"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Configuration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      62,   14, // methods
       0,    0, // properties
       2,  576, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  324,    2, 0x06 /* Public */,
       3,    1,  327,    2, 0x06 /* Public */,
       4,    2,  330,    2, 0x06 /* Public */,
       8,    1,  335,    2, 0x06 /* Public */,
      11,    1,  338,    2, 0x06 /* Public */,
      13,    1,  341,    2, 0x06 /* Public */,
      15,    1,  344,    2, 0x06 /* Public */,
      16,    1,  347,    2, 0x06 /* Public */,
      18,    1,  350,    2, 0x06 /* Public */,
      20,    1,  353,    2, 0x06 /* Public */,
      21,    1,  356,    2, 0x06 /* Public */,
      22,    1,  359,    2, 0x06 /* Public */,
      25,    3,  362,    2, 0x06 /* Public */,
      30,    2,  369,    2, 0x06 /* Public */,
      33,    1,  374,    2, 0x06 /* Public */,
      34,    1,  377,    2, 0x06 /* Public */,
      36,    6,  380,    2, 0x06 /* Public */,
      43,    1,  393,    2, 0x06 /* Public */,
      45,    0,  396,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      46,    1,  397,    2, 0x0a /* Public */,
      48,    1,  400,    2, 0x0a /* Public */,
      48,    0,  403,    2, 0x2a /* Public | MethodCloned */,
      49,    1,  404,    2, 0x0a /* Public */,
      51,    1,  407,    2, 0x0a /* Public */,
      51,    0,  410,    2, 0x2a /* Public | MethodCloned */,
      52,    1,  411,    2, 0x0a /* Public */,
      52,    0,  414,    2, 0x2a /* Public | MethodCloned */,
      53,    1,  415,    2, 0x0a /* Public */,
      53,    0,  418,    2, 0x2a /* Public | MethodCloned */,
      54,    1,  419,    2, 0x0a /* Public */,
      54,    0,  422,    2, 0x2a /* Public | MethodCloned */,
      55,    1,  423,    2, 0x0a /* Public */,
      55,    0,  426,    2, 0x2a /* Public | MethodCloned */,
      56,    9,  427,    2, 0x0a /* Public */,
      56,    8,  446,    2, 0x2a /* Public | MethodCloned */,
      56,    7,  463,    2, 0x2a /* Public | MethodCloned */,
      56,    6,  478,    2, 0x2a /* Public | MethodCloned */,
      56,    5,  491,    2, 0x2a /* Public | MethodCloned */,
      56,    4,  502,    2, 0x2a /* Public | MethodCloned */,
      56,    3,  511,    2, 0x2a /* Public | MethodCloned */,
      56,    2,  518,    2, 0x2a /* Public | MethodCloned */,
      56,    1,  523,    2, 0x2a /* Public | MethodCloned */,
      56,    0,  526,    2, 0x2a /* Public | MethodCloned */,
      57,    1,  527,    2, 0x0a /* Public */,
      57,    0,  530,    2, 0x2a /* Public | MethodCloned */,
      58,    3,  531,    2, 0x0a /* Public */,
      59,    1,  538,    2, 0x0a /* Public */,
      60,    1,  541,    2, 0x0a /* Public */,
      60,    0,  544,    2, 0x2a /* Public | MethodCloned */,
      61,    1,  545,    2, 0x0a /* Public */,
      61,    0,  548,    2, 0x2a /* Public | MethodCloned */,
      62,    1,  549,    2, 0x0a /* Public */,
      62,    0,  552,    2, 0x2a /* Public | MethodCloned */,
      63,    2,  553,    2, 0x0a /* Public */,
      63,    1,  558,    2, 0x2a /* Public | MethodCloned */,
      63,    0,  561,    2, 0x2a /* Public | MethodCloned */,
      66,    1,  562,    2, 0x0a /* Public */,
      68,    1,  565,    2, 0x0a /* Public */,
      69,    1,  568,    2, 0x0a /* Public */,
      69,    0,  571,    2, 0x2a /* Public | MethodCloned */,
      70,    1,  572,    2, 0x0a /* Public */,
      70,    0,  575,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QFont,    2,
    QMetaType::Void, QMetaType::QFont,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QStringList,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong, 0x80000000 | 28,   26,   27,   29,
    QMetaType::Void, 0x80000000 | 31, QMetaType::LongLong,   32,   26,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   37,   38,   39,   40,   41,   42,
    QMetaType::Void, QMetaType::UShort,   44,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 47,    2,
    QMetaType::Void, 0x80000000 | 47,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 50,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool, QMetaType::Bool, QMetaType::Double,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool, QMetaType::Bool,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 31, QMetaType::LongLong,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 31,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   64,   65,
    QMetaType::Void, QMetaType::Bool,   64,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      71,   71, 0x0,    3,  586,
      75,   75, 0x0,    3,  592,

 // enum data: key, value
      72, uint(Configuration::data_mode_none),
      73, uint(Configuration::data_mode_USB),
      74, uint(Configuration::data_mode_data),
      76, uint(Configuration::type_2_msg_1_full),
      77, uint(Configuration::type_2_msg_3_full),
      78, uint(Configuration::type_2_msg_5_only),

       0        // eod
};

void Configuration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Configuration *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->text_font_changed((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 1: _t->decoded_text_font_changed((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 2: _t->udp_server_changed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        case 3: _t->udp_server_port_changed((*reinterpret_cast< port_type(*)>(_a[1]))); break;
        case 4: _t->udp_TTL_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->accept_udp_requests_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->udp_wsjtx_compatibility_mode_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->decode_highlighting_changed((*reinterpret_cast< const DecodeHighlightingModel(*)>(_a[1]))); break;
        case 8: _t->transceiver_update((*reinterpret_cast< const Transceiver::TransceiverState(*)>(_a[1]))); break;
        case 9: _t->transceiver_TCIframesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->transceiver_TCImodActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->transceiver_jtty_drained((*reinterpret_cast< TxAudioQueueDrainState(*)>(_a[1]))); break;
        case 12: _t->transceiver_jtty_enqueue_accepted((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< TxAudioQueueProgress(*)>(_a[3]))); break;
        case 13: _t->transceiver_jtty_enqueue_failed((*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 14: _t->leavingSettings((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->transceiver_failure((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->tx_inhibit_changed((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< quint32(*)>(_a[5])),(*reinterpret_cast< quint32(*)>(_a[6]))); break;
        case 17: _t->tx_inhibit_port_changed((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 18: _t->enumerating_audio_devices(); break;
        case 19: _t->transceiver_frequency((*reinterpret_cast< Frequency(*)>(_a[1]))); break;
        case 20: _t->transceiver_tx_frequency((*reinterpret_cast< Frequency(*)>(_a[1]))); break;
        case 21: _t->transceiver_tx_frequency(); break;
        case 22: _t->transceiver_mode((*reinterpret_cast< MODE(*)>(_a[1]))); break;
        case 23: _t->transceiver_ptt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->transceiver_ptt(); break;
        case 25: _t->transceiver_audio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->transceiver_audio(); break;
        case 27: _t->transceiver_tune((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->transceiver_tune(); break;
        case 29: _t->transceiver_period((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->transceiver_period(); break;
        case 31: _t->transceiver_blocksize((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 32: _t->transceiver_blocksize(); break;
        case 33: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9]))); break;
        case 34: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8]))); break;
        case 35: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        case 36: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 37: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5]))); break;
        case 38: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 39: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 40: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 41: _t->transceiver_modulator_start((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 42: _t->transceiver_modulator_start(); break;
        case 43: _t->transceiver_modulator_stop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->transceiver_modulator_stop(); break;
        case 45: _t->transceiver_enqueue_jtty_pcm((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 46: _t->transceiver_clear_jtty_pcm((*reinterpret_cast< TxAudioQueueEpoch(*)>(_a[1]))); break;
        case 47: _t->transceiver_spread((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 48: _t->transceiver_spread(); break;
        case 49: _t->transceiver_nsym((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->transceiver_nsym(); break;
        case 51: _t->transceiver_trfrequency((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 52: _t->transceiver_trfrequency(); break;
        case 53: _t->sync_transceiver((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 54: _t->sync_transceiver((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->sync_transceiver(); break;
        case 56: _t->invalidate_audio_input_device((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 57: _t->invalidate_audio_output_device((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 58: _t->transceiver_volume((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 59: _t->transceiver_volume(); break;
        case 60: _t->transceiver_txvolume((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 61: _t->transceiver_txvolume(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Transceiver::TransceiverState >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueDrainState >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueProgress >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueEpoch >(); break;
            }
            break;
        case 45:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TxAudioQueueEpoch >(); break;
            }
            break;
        case 46:
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
            using _t = void (Configuration::*)(QFont ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::text_font_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(QFont ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::decoded_text_font_changed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(QString & , QStringList const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::udp_server_changed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(port_type ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::udp_server_port_changed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(int ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::udp_TTL_changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::accept_udp_requests_changed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::udp_wsjtx_compatibility_mode_changed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(DecodeHighlightingModel const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::decode_highlighting_changed)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(Transceiver::TransceiverState const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_update)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(qint64 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_TCIframesWritten)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_TCImodActive)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(TxAudioQueueDrainState ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_jtty_drained)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(qint64 , qint64 , TxAudioQueueProgress ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_jtty_enqueue_accepted)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(TxAudioQueueEpoch , qint64 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_jtty_enqueue_failed)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(bool ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::leavingSettings)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(QString const & ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::transceiver_failure)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(bool , QString const & , quint32 , quint32 , quint32 , quint32 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::tx_inhibit_changed)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Configuration::*)(quint16 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::tx_inhibit_port_changed)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Configuration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Configuration::enumerating_audio_devices)) {
                *result = 18;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Configuration::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Configuration.data,
    qt_meta_data_Configuration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Configuration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Configuration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Configuration.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Configuration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 62)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 62;
    }
    return _id;
}

// SIGNAL 0
void Configuration::text_font_changed(QFont _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Configuration::decoded_text_font_changed(QFont _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Configuration::udp_server_changed(QString & _t1, QStringList const & _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Configuration::udp_server_port_changed(port_type _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Configuration::udp_TTL_changed(int _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Configuration::accept_udp_requests_changed(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Configuration::udp_wsjtx_compatibility_mode_changed(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Configuration::decode_highlighting_changed(DecodeHighlightingModel const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Configuration::transceiver_update(Transceiver::TransceiverState const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Configuration::transceiver_TCIframesWritten(qint64 _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Configuration::transceiver_TCImodActive(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Configuration::transceiver_jtty_drained(TxAudioQueueDrainState _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Configuration::transceiver_jtty_enqueue_accepted(qint64 _t1, qint64 _t2, TxAudioQueueProgress _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Configuration::transceiver_jtty_enqueue_failed(TxAudioQueueEpoch _t1, qint64 _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Configuration::leavingSettings(bool _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Configuration::transceiver_failure(QString const & _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Configuration::tx_inhibit_changed(bool _t1, QString const & _t2, quint32 _t3, quint32 _t4, quint32 _t5, quint32 _t6)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Configuration::tx_inhibit_port_changed(quint16 _t1)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(const_cast< Configuration *>(this), &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Configuration::enumerating_audio_devices()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
