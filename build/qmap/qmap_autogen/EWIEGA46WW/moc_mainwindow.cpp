/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../qmap/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[75];
    char stringdata0[1555];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "showSoundInError"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "errorMsg"
QT_MOC_LITERAL(4, 38, 17), // "showStatusMessage"
QT_MOC_LITERAL(5, 56, 9), // "statusMsg"
QT_MOC_LITERAL(6, 66, 8), // "dataSink"
QT_MOC_LITERAL(7, 75, 1), // "k"
QT_MOC_LITERAL(8, 77, 7), // "diskDat"
QT_MOC_LITERAL(9, 85, 4), // "iret"
QT_MOC_LITERAL(10, 90, 15), // "decoderFinished"
QT_MOC_LITERAL(11, 106, 12), // "freezeDecode"
QT_MOC_LITERAL(12, 119, 1), // "n"
QT_MOC_LITERAL(13, 121, 9), // "guiUpdate"
QT_MOC_LITERAL(14, 131, 24), // "on_monitorButton_clicked"
QT_MOC_LITERAL(15, 156, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(16, 180, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(17, 205, 25), // "on_actionLinrad_triggered"
QT_MOC_LITERAL(18, 231, 26), // "on_actionCuteSDR_triggered"
QT_MOC_LITERAL(19, 258, 26), // "on_tolSpinBox_valueChanged"
QT_MOC_LITERAL(20, 285, 4), // "arg1"
QT_MOC_LITERAL(21, 290, 29), // "on_actionAstro_Data_triggered"
QT_MOC_LITERAL(22, 320, 33), // "on_actionWide_Waterfall_trigg..."
QT_MOC_LITERAL(23, 354, 27), // "on_actionBand_Map_triggered"
QT_MOC_LITERAL(24, 382, 43), // "on_actionOpen_QMAP_data_direc..."
QT_MOC_LITERAL(25, 426, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(26, 450, 41), // "on_actionOpen_next_in_directo..."
QT_MOC_LITERAL(27, 492, 54), // "on_actionDecode_remaining_fil..."
QT_MOC_LITERAL(28, 547, 49), // "on_actionDelete_all_iq_files_..."
QT_MOC_LITERAL(29, 597, 23), // "on_actionNone_triggered"
QT_MOC_LITERAL(30, 621, 27), // "on_actionSave_all_triggered"
QT_MOC_LITERAL(31, 649, 23), // "on_DecodeButton_clicked"
QT_MOC_LITERAL(32, 673, 6), // "decode"
QT_MOC_LITERAL(33, 680, 10), // "decodeBusy"
QT_MOC_LITERAL(34, 691, 1), // "b"
QT_MOC_LITERAL(35, 693, 22), // "on_EraseButton_clicked"
QT_MOC_LITERAL(36, 716, 6), // "bumpDF"
QT_MOC_LITERAL(37, 723, 19), // "handleCallsignClick"
QT_MOC_LITERAL(38, 743, 4), // "call"
QT_MOC_LITERAL(39, 748, 8), // "freq_khz"
QT_MOC_LITERAL(40, 757, 4), // "grid"
QT_MOC_LITERAL(41, 762, 4), // "mode"
QT_MOC_LITERAL(42, 767, 11), // "even_period"
QT_MOC_LITERAL(43, 779, 9), // "fsked_khz"
QT_MOC_LITERAL(44, 789, 9), // "start_qso"
QT_MOC_LITERAL(45, 799, 21), // "handleDecodeLineClick"
QT_MOC_LITERAL(46, 821, 4), // "line"
QT_MOC_LITERAL(47, 826, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(48, 854, 21), // "on_NBcheckBox_toggled"
QT_MOC_LITERAL(49, 876, 7), // "checked"
QT_MOC_LITERAL(50, 884, 24), // "on_NBslider_valueChanged"
QT_MOC_LITERAL(51, 909, 5), // "value"
QT_MOC_LITERAL(52, 915, 25), // "on_actionAFMHot_triggered"
QT_MOC_LITERAL(53, 941, 23), // "on_actionBlue_triggered"
QT_MOC_LITERAL(54, 965, 23), // "on_actionQ65A_triggered"
QT_MOC_LITERAL(55, 989, 23), // "on_actionQ65B_triggered"
QT_MOC_LITERAL(56, 1013, 23), // "on_actionQ65C_triggered"
QT_MOC_LITERAL(57, 1037, 23), // "on_actionQ65D_triggered"
QT_MOC_LITERAL(58, 1061, 23), // "on_actionQ65E_triggered"
QT_MOC_LITERAL(59, 1085, 43), // "on_actionQuick_Start_Guide_to..."
QT_MOC_LITERAL(60, 1129, 59), // "on_actionQuick_Start_Guide_to..."
QT_MOC_LITERAL(61, 1189, 29), // "on_actionAlso_Q65_30x_toggled"
QT_MOC_LITERAL(62, 1219, 26), // "on_sbMaxDrift_valueChanged"
QT_MOC_LITERAL(63, 1246, 31), // "on_actionSave_decoded_triggered"
QT_MOC_LITERAL(64, 1278, 42), // "on_actionExport_wav_file_at_f..."
QT_MOC_LITERAL(65, 1321, 46), // "on_actionExport_wav_file_at_f..."
QT_MOC_LITERAL(66, 1368, 46), // "on_actionExport_wav_file_at_f..."
QT_MOC_LITERAL(67, 1415, 32), // "on_actionFadd_controls_triggered"
QT_MOC_LITERAL(68, 1448, 25), // "on_fAddComboBox_activated"
QT_MOC_LITERAL(69, 1474, 16), // "on_pbSet_clicked"
QT_MOC_LITERAL(70, 1491, 16), // "on_pbAdd_clicked"
QT_MOC_LITERAL(71, 1508, 11), // "handleReply"
QT_MOC_LITERAL(72, 1520, 15), // "mousePressEvent"
QT_MOC_LITERAL(73, 1536, 12), // "QMouseEvent*"
QT_MOC_LITERAL(74, 1549, 5) // "event"

    },
    "MainWindow\0showSoundInError\0\0errorMsg\0"
    "showStatusMessage\0statusMsg\0dataSink\0"
    "k\0diskDat\0iret\0decoderFinished\0"
    "freezeDecode\0n\0guiUpdate\0"
    "on_monitorButton_clicked\0"
    "on_actionExit_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionLinrad_triggered\0"
    "on_actionCuteSDR_triggered\0"
    "on_tolSpinBox_valueChanged\0arg1\0"
    "on_actionAstro_Data_triggered\0"
    "on_actionWide_Waterfall_triggered\0"
    "on_actionBand_Map_triggered\0"
    "on_actionOpen_QMAP_data_directory_triggered\0"
    "on_actionOpen_triggered\0"
    "on_actionOpen_next_in_directory_triggered\0"
    "on_actionDecode_remaining_files_in_directory_triggered\0"
    "on_actionDelete_all_iq_files_in_SaveDir_triggered\0"
    "on_actionNone_triggered\0"
    "on_actionSave_all_triggered\0"
    "on_DecodeButton_clicked\0decode\0"
    "decodeBusy\0b\0on_EraseButton_clicked\0"
    "bumpDF\0handleCallsignClick\0call\0"
    "freq_khz\0grid\0mode\0even_period\0fsked_khz\0"
    "start_qso\0handleDecodeLineClick\0line\0"
    "on_actionSettings_triggered\0"
    "on_NBcheckBox_toggled\0checked\0"
    "on_NBslider_valueChanged\0value\0"
    "on_actionAFMHot_triggered\0"
    "on_actionBlue_triggered\0on_actionQ65A_triggered\0"
    "on_actionQ65B_triggered\0on_actionQ65C_triggered\0"
    "on_actionQ65D_triggered\0on_actionQ65E_triggered\0"
    "on_actionQuick_Start_Guide_to_Q65_triggered\0"
    "on_actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP_triggered\0"
    "on_actionAlso_Q65_30x_toggled\0"
    "on_sbMaxDrift_valueChanged\0"
    "on_actionSave_decoded_triggered\0"
    "on_actionExport_wav_file_at_fQSO_triggered\0"
    "on_actionExport_wav_file_at_fQSO_30a_triggered\0"
    "on_actionExport_wav_file_at_fQSO_30b_triggered\0"
    "on_actionFadd_controls_triggered\0"
    "on_fAddComboBox_activated\0on_pbSet_clicked\0"
    "on_pbAdd_clicked\0handleReply\0"
    "mousePressEvent\0QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  284,    2, 0x0a /* Public */,
       4,    1,  287,    2, 0x0a /* Public */,
       6,    1,  290,    2, 0x0a /* Public */,
       8,    1,  293,    2, 0x0a /* Public */,
      10,    0,  296,    2, 0x0a /* Public */,
      11,    1,  297,    2, 0x0a /* Public */,
      13,    0,  300,    2, 0x0a /* Public */,
      14,    0,  301,    2, 0x08 /* Private */,
      15,    0,  302,    2, 0x08 /* Private */,
      16,    0,  303,    2, 0x08 /* Private */,
      17,    0,  304,    2, 0x08 /* Private */,
      18,    0,  305,    2, 0x08 /* Private */,
      19,    1,  306,    2, 0x08 /* Private */,
      21,    0,  309,    2, 0x08 /* Private */,
      22,    0,  310,    2, 0x08 /* Private */,
      23,    0,  311,    2, 0x08 /* Private */,
      24,    0,  312,    2, 0x08 /* Private */,
      25,    0,  313,    2, 0x08 /* Private */,
      26,    0,  314,    2, 0x08 /* Private */,
      27,    0,  315,    2, 0x08 /* Private */,
      28,    0,  316,    2, 0x08 /* Private */,
      29,    0,  317,    2, 0x08 /* Private */,
      30,    0,  318,    2, 0x08 /* Private */,
      31,    0,  319,    2, 0x08 /* Private */,
      32,    0,  320,    2, 0x08 /* Private */,
      33,    1,  321,    2, 0x08 /* Private */,
      35,    0,  324,    2, 0x08 /* Private */,
      36,    1,  325,    2, 0x08 /* Private */,
      37,    7,  328,    2, 0x08 /* Private */,
      45,    2,  343,    2, 0x08 /* Private */,
      47,    0,  348,    2, 0x08 /* Private */,
      48,    1,  349,    2, 0x08 /* Private */,
      50,    1,  352,    2, 0x08 /* Private */,
      52,    0,  355,    2, 0x08 /* Private */,
      53,    0,  356,    2, 0x08 /* Private */,
      54,    0,  357,    2, 0x08 /* Private */,
      55,    0,  358,    2, 0x08 /* Private */,
      56,    0,  359,    2, 0x08 /* Private */,
      57,    0,  360,    2, 0x08 /* Private */,
      58,    0,  361,    2, 0x08 /* Private */,
      59,    0,  362,    2, 0x08 /* Private */,
      60,    0,  363,    2, 0x08 /* Private */,
      61,    1,  364,    2, 0x08 /* Private */,
      62,    1,  367,    2, 0x08 /* Private */,
      63,    0,  370,    2, 0x08 /* Private */,
      64,    0,  371,    2, 0x08 /* Private */,
      65,    0,  372,    2, 0x08 /* Private */,
      66,    0,  373,    2, 0x08 /* Private */,
      67,    0,  374,    2, 0x08 /* Private */,
      68,    0,  375,    2, 0x08 /* Private */,
      69,    0,  376,    2, 0x08 /* Private */,
      70,    0,  377,    2, 0x08 /* Private */,
      71,    0,  378,    2, 0x08 /* Private */,
      72,    1,  379,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Double, QMetaType::Bool,   38,   39,   40,   41,   42,   43,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   46,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 73,   74,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showSoundInError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->dataSink((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->diskDat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->decoderFinished(); break;
        case 5: _t->freezeDecode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->guiUpdate(); break;
        case 7: _t->on_monitorButton_clicked(); break;
        case 8: _t->on_actionExit_triggered(); break;
        case 9: _t->on_actionAbout_triggered(); break;
        case 10: _t->on_actionLinrad_triggered(); break;
        case 11: _t->on_actionCuteSDR_triggered(); break;
        case 12: _t->on_tolSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_actionAstro_Data_triggered(); break;
        case 14: _t->on_actionWide_Waterfall_triggered(); break;
        case 15: _t->on_actionBand_Map_triggered(); break;
        case 16: _t->on_actionOpen_QMAP_data_directory_triggered(); break;
        case 17: _t->on_actionOpen_triggered(); break;
        case 18: _t->on_actionOpen_next_in_directory_triggered(); break;
        case 19: _t->on_actionDecode_remaining_files_in_directory_triggered(); break;
        case 20: _t->on_actionDelete_all_iq_files_in_SaveDir_triggered(); break;
        case 21: _t->on_actionNone_triggered(); break;
        case 22: _t->on_actionSave_all_triggered(); break;
        case 23: _t->on_DecodeButton_clicked(); break;
        case 24: _t->decode(); break;
        case 25: _t->decodeBusy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_EraseButton_clicked(); break;
        case 27: _t->bumpDF((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->handleCallsignClick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        case 29: _t->handleDecodeLineClick((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->on_actionSettings_triggered(); break;
        case 31: _t->on_NBcheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_NBslider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_actionAFMHot_triggered(); break;
        case 34: _t->on_actionBlue_triggered(); break;
        case 35: _t->on_actionQ65A_triggered(); break;
        case 36: _t->on_actionQ65B_triggered(); break;
        case 37: _t->on_actionQ65C_triggered(); break;
        case 38: _t->on_actionQ65D_triggered(); break;
        case 39: _t->on_actionQ65E_triggered(); break;
        case 40: _t->on_actionQuick_Start_Guide_to_Q65_triggered(); break;
        case 41: _t->on_actionQuick_Start_Guide_to_WSJT_X_2_7_and_QMAP_triggered(); break;
        case 42: _t->on_actionAlso_Q65_30x_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_sbMaxDrift_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_actionSave_decoded_triggered(); break;
        case 45: _t->on_actionExport_wav_file_at_fQSO_triggered(); break;
        case 46: _t->on_actionExport_wav_file_at_fQSO_30a_triggered(); break;
        case 47: _t->on_actionExport_wav_file_at_fQSO_30b_triggered(); break;
        case 48: _t->on_actionFadd_controls_triggered(); break;
        case 49: _t->on_fAddComboBox_activated(); break;
        case 50: _t->on_pbSet_clicked(); break;
        case 51: _t->on_pbAdd_clicked(); break;
        case 52: _t->handleReply(); break;
        case 53: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 54;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
