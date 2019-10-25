/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SerialCommsAsync/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[43];
    char stringdata0[1116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_btnStart_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 38), // "on_lstSerialPorts_itemSelecti..."
QT_MOC_LITERAL(4, 71, 19), // "handleNewSerialData"
QT_MOC_LITERAL(5, 91, 7), // "newData"
QT_MOC_LITERAL(6, 99, 11), // "fromTimeOut"
QT_MOC_LITERAL(7, 111, 20), // "handleNewSerialError"
QT_MOC_LITERAL(8, 132, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 161, 8), // "newError"
QT_MOC_LITERAL(10, 170, 20), // "on_btnSentIt_clicked"
QT_MOC_LITERAL(11, 191, 25), // "handleNewNardaSerialError"
QT_MOC_LITERAL(12, 217, 26), // "on_btnNardaVersion_clicked"
QT_MOC_LITERAL(13, 244, 30), // "on_btnNardaTakeReading_clicked"
QT_MOC_LITERAL(14, 275, 30), // "on_btnNardaCalibration_clicked"
QT_MOC_LITERAL(15, 306, 31), // "on_btnNardaSerialNumber_clicked"
QT_MOC_LITERAL(16, 338, 33), // "on_btnNardaBatteryVoltage_cli..."
QT_MOC_LITERAL(17, 372, 30), // "on_btnNardaTemperature_clicked"
QT_MOC_LITERAL(18, 403, 28), // "on_btnNardaThreeAxes_clicked"
QT_MOC_LITERAL(19, 432, 34), // "on_btnNardaSetPowerOffTime_cl..."
QT_MOC_LITERAL(20, 467, 27), // "on_btnNardaPowerOff_clicked"
QT_MOC_LITERAL(21, 495, 22), // "handleNewWGSerialError"
QT_MOC_LITERAL(22, 518, 28), // "on_btnWGQueryVersion_clicked"
QT_MOC_LITERAL(23, 547, 30), // "on_btnWGQueryBatteryOK_clicked"
QT_MOC_LITERAL(24, 578, 26), // "on_btnWGQueryField_clicked"
QT_MOC_LITERAL(25, 605, 29), // "on_btnWGQueryCmdError_clicked"
QT_MOC_LITERAL(26, 635, 20), // "on_btnWGBeep_clicked"
QT_MOC_LITERAL(27, 656, 29), // "on_btnWGQueryFastMode_clicked"
QT_MOC_LITERAL(28, 686, 30), // "on_btnWGToggleFastMode_clicked"
QT_MOC_LITERAL(29, 717, 29), // "on_btnWGQueryCalcAxis_clicked"
QT_MOC_LITERAL(30, 747, 30), // "on_btnWGToggleCalcAxis_clicked"
QT_MOC_LITERAL(31, 778, 27), // "on_btnCCQueryStatus_clicked"
QT_MOC_LITERAL(32, 806, 24), // "on_btnCCSetReset_clicked"
QT_MOC_LITERAL(33, 831, 28), // "on_btnCCSetDigitalOP_clicked"
QT_MOC_LITERAL(34, 860, 25), // "on_btnCCSetAnIPOn_clicked"
QT_MOC_LITERAL(35, 886, 26), // "on_btnCCSetAnIPOff_clicked"
QT_MOC_LITERAL(36, 913, 25), // "on_btnCCSetDAAnIP_clicked"
QT_MOC_LITERAL(37, 939, 32), // "on_btnCCSetAnOPSweepTime_clicked"
QT_MOC_LITERAL(38, 972, 31), // "on_btnCCSetAnIPScanTime_clicked"
QT_MOC_LITERAL(39, 1004, 27), // "on_btnCCSetBaudRate_clicked"
QT_MOC_LITERAL(40, 1032, 25), // "on_btnCCSetAnOPOn_clicked"
QT_MOC_LITERAL(41, 1058, 26), // "on_btnCCSetAnOPOff_clicked"
QT_MOC_LITERAL(42, 1085, 30) // "on_btnCCSetLoadOPSweep_clicked"

    },
    "MainWindow\0on_btnStart_clicked\0\0"
    "on_lstSerialPorts_itemSelectionChanged\0"
    "handleNewSerialData\0newData\0fromTimeOut\0"
    "handleNewSerialError\0QSerialPort::SerialPortError\0"
    "newError\0on_btnSentIt_clicked\0"
    "handleNewNardaSerialError\0"
    "on_btnNardaVersion_clicked\0"
    "on_btnNardaTakeReading_clicked\0"
    "on_btnNardaCalibration_clicked\0"
    "on_btnNardaSerialNumber_clicked\0"
    "on_btnNardaBatteryVoltage_clicked\0"
    "on_btnNardaTemperature_clicked\0"
    "on_btnNardaThreeAxes_clicked\0"
    "on_btnNardaSetPowerOffTime_clicked\0"
    "on_btnNardaPowerOff_clicked\0"
    "handleNewWGSerialError\0"
    "on_btnWGQueryVersion_clicked\0"
    "on_btnWGQueryBatteryOK_clicked\0"
    "on_btnWGQueryField_clicked\0"
    "on_btnWGQueryCmdError_clicked\0"
    "on_btnWGBeep_clicked\0on_btnWGQueryFastMode_clicked\0"
    "on_btnWGToggleFastMode_clicked\0"
    "on_btnWGQueryCalcAxis_clicked\0"
    "on_btnWGToggleCalcAxis_clicked\0"
    "on_btnCCQueryStatus_clicked\0"
    "on_btnCCSetReset_clicked\0"
    "on_btnCCSetDigitalOP_clicked\0"
    "on_btnCCSetAnIPOn_clicked\0"
    "on_btnCCSetAnIPOff_clicked\0"
    "on_btnCCSetDAAnIP_clicked\0"
    "on_btnCCSetAnOPSweepTime_clicked\0"
    "on_btnCCSetAnIPScanTime_clicked\0"
    "on_btnCCSetBaudRate_clicked\0"
    "on_btnCCSetAnOPOn_clicked\0"
    "on_btnCCSetAnOPOff_clicked\0"
    "on_btnCCSetLoadOPSweep_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  199,    2, 0x08 /* Private */,
       3,    0,  200,    2, 0x08 /* Private */,
       4,    2,  201,    2, 0x08 /* Private */,
       7,    1,  206,    2, 0x08 /* Private */,
      10,    0,  209,    2, 0x08 /* Private */,
      11,    1,  210,    2, 0x08 /* Private */,
      12,    0,  213,    2, 0x08 /* Private */,
      13,    0,  214,    2, 0x08 /* Private */,
      14,    0,  215,    2, 0x08 /* Private */,
      15,    0,  216,    2, 0x08 /* Private */,
      16,    0,  217,    2, 0x08 /* Private */,
      17,    0,  218,    2, 0x08 /* Private */,
      18,    0,  219,    2, 0x08 /* Private */,
      19,    0,  220,    2, 0x08 /* Private */,
      20,    0,  221,    2, 0x08 /* Private */,
      21,    1,  222,    2, 0x08 /* Private */,
      22,    0,  225,    2, 0x08 /* Private */,
      23,    0,  226,    2, 0x08 /* Private */,
      24,    0,  227,    2, 0x08 /* Private */,
      25,    0,  228,    2, 0x08 /* Private */,
      26,    0,  229,    2, 0x08 /* Private */,
      27,    0,  230,    2, 0x08 /* Private */,
      28,    0,  231,    2, 0x08 /* Private */,
      29,    0,  232,    2, 0x08 /* Private */,
      30,    0,  233,    2, 0x08 /* Private */,
      31,    0,  234,    2, 0x08 /* Private */,
      32,    0,  235,    2, 0x08 /* Private */,
      33,    0,  236,    2, 0x08 /* Private */,
      34,    0,  237,    2, 0x08 /* Private */,
      35,    0,  238,    2, 0x08 /* Private */,
      36,    0,  239,    2, 0x08 /* Private */,
      37,    0,  240,    2, 0x08 /* Private */,
      38,    0,  241,    2, 0x08 /* Private */,
      39,    0,  242,    2, 0x08 /* Private */,
      40,    0,  243,    2, 0x08 /* Private */,
      41,    0,  244,    2, 0x08 /* Private */,
      42,    0,  245,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnStart_clicked(); break;
        case 1: _t->on_lstSerialPorts_itemSelectionChanged(); break;
        case 2: _t->handleNewSerialData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->handleNewSerialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 4: _t->on_btnSentIt_clicked(); break;
        case 5: _t->handleNewNardaSerialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 6: _t->on_btnNardaVersion_clicked(); break;
        case 7: _t->on_btnNardaTakeReading_clicked(); break;
        case 8: _t->on_btnNardaCalibration_clicked(); break;
        case 9: _t->on_btnNardaSerialNumber_clicked(); break;
        case 10: _t->on_btnNardaBatteryVoltage_clicked(); break;
        case 11: _t->on_btnNardaTemperature_clicked(); break;
        case 12: _t->on_btnNardaThreeAxes_clicked(); break;
        case 13: _t->on_btnNardaSetPowerOffTime_clicked(); break;
        case 14: _t->on_btnNardaPowerOff_clicked(); break;
        case 15: _t->handleNewWGSerialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 16: _t->on_btnWGQueryVersion_clicked(); break;
        case 17: _t->on_btnWGQueryBatteryOK_clicked(); break;
        case 18: _t->on_btnWGQueryField_clicked(); break;
        case 19: _t->on_btnWGQueryCmdError_clicked(); break;
        case 20: _t->on_btnWGBeep_clicked(); break;
        case 21: _t->on_btnWGQueryFastMode_clicked(); break;
        case 22: _t->on_btnWGToggleFastMode_clicked(); break;
        case 23: _t->on_btnWGQueryCalcAxis_clicked(); break;
        case 24: _t->on_btnWGToggleCalcAxis_clicked(); break;
        case 25: _t->on_btnCCQueryStatus_clicked(); break;
        case 26: _t->on_btnCCSetReset_clicked(); break;
        case 27: _t->on_btnCCSetDigitalOP_clicked(); break;
        case 28: _t->on_btnCCSetAnIPOn_clicked(); break;
        case 29: _t->on_btnCCSetAnIPOff_clicked(); break;
        case 30: _t->on_btnCCSetDAAnIP_clicked(); break;
        case 31: _t->on_btnCCSetAnOPSweepTime_clicked(); break;
        case 32: _t->on_btnCCSetAnIPScanTime_clicked(); break;
        case 33: _t->on_btnCCSetBaudRate_clicked(); break;
        case 34: _t->on_btnCCSetAnOPOn_clicked(); break;
        case 35: _t->on_btnCCSetAnOPOff_clicked(); break;
        case 36: _t->on_btnCCSetLoadOPSweep_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 37;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
