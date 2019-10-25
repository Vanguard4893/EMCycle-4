/****************************************************************************
** Meta object code from reading C++ file 'w_g_emr300.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CassSerial/w_g_emr300.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_g_emr300.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cass__SerialIO__W_G_Emr300_t {
    QByteArrayData data[21];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cass__SerialIO__W_G_Emr300_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cass__SerialIO__W_G_Emr300_t qt_meta_stringdata_Cass__SerialIO__W_G_Emr300 = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Cass::SerialIO::W_G_Emr300"
QT_MOC_LITERAL(1, 27, 13), // "probeNewError"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(4, 71, 15), // "serialPortError"
QT_MOC_LITERAL(5, 87, 20), // "handleNewSerialError"
QT_MOC_LITERAL(6, 108, 8), // "newError"
QT_MOC_LITERAL(7, 117, 12), // "CommandError"
QT_MOC_LITERAL(8, 130, 9), // "Undefined"
QT_MOC_LITERAL(9, 140, 7), // "NoError"
QT_MOC_LITERAL(10, 148, 16), // "MissingParameter"
QT_MOC_LITERAL(11, 165, 14), // "UnknownCommand"
QT_MOC_LITERAL(12, 180, 14), // "DataOutOfRange"
QT_MOC_LITERAL(13, 195, 21), // "IllegalParameterValue"
QT_MOC_LITERAL(14, 217, 9), // "ModeError"
QT_MOC_LITERAL(15, 227, 13), // "CalcFieldAxes"
QT_MOC_LITERAL(16, 241, 22), // "DispTotalSerialXYZ_ALL"
QT_MOC_LITERAL(17, 264, 24), // "DispTotalSerialTotal_EFF"
QT_MOC_LITERAL(18, 289, 14), // "DispXSerialX_X"
QT_MOC_LITERAL(19, 304, 14), // "DispYSerialY_Y"
QT_MOC_LITERAL(20, 319, 14) // "DispZSerialZ_Z"

    },
    "Cass::SerialIO::W_G_Emr300\0probeNewError\0"
    "\0QSerialPort::SerialPortError\0"
    "serialPortError\0handleNewSerialError\0"
    "newError\0CommandError\0Undefined\0NoError\0"
    "MissingParameter\0UnknownCommand\0"
    "DataOutOfRange\0IllegalParameterValue\0"
    "ModeError\0CalcFieldAxes\0DispTotalSerialXYZ_ALL\0"
    "DispTotalSerialTotal_EFF\0DispXSerialX_X\0"
    "DispYSerialY_Y\0DispZSerialZ_Z"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cass__SerialIO__W_G_Emr300[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       2,   30, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,

 // enums: name, alias, flags, count, data
       7,    7, 0x2,    7,   40,
      15,   15, 0x2,    6,   54,

 // enum data: key, value
       8, uint(Cass::SerialIO::W_G_Emr300::CommandError::Undefined),
       9, uint(Cass::SerialIO::W_G_Emr300::CommandError::NoError),
      10, uint(Cass::SerialIO::W_G_Emr300::CommandError::MissingParameter),
      11, uint(Cass::SerialIO::W_G_Emr300::CommandError::UnknownCommand),
      12, uint(Cass::SerialIO::W_G_Emr300::CommandError::DataOutOfRange),
      13, uint(Cass::SerialIO::W_G_Emr300::CommandError::IllegalParameterValue),
      14, uint(Cass::SerialIO::W_G_Emr300::CommandError::ModeError),
       8, uint(Cass::SerialIO::W_G_Emr300::CalcFieldAxes::Undefined),
      16, uint(Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialXYZ_ALL),
      17, uint(Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispTotalSerialTotal_EFF),
      18, uint(Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispXSerialX_X),
      19, uint(Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispYSerialY_Y),
      20, uint(Cass::SerialIO::W_G_Emr300::CalcFieldAxes::DispZSerialZ_Z),

       0        // eod
};

void Cass::SerialIO::W_G_Emr300::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        W_G_Emr300 *_t = static_cast<W_G_Emr300 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->probeNewError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 1: _t->handleNewSerialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (W_G_Emr300::*)(QSerialPort::SerialPortError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&W_G_Emr300::probeNewError)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cass::SerialIO::W_G_Emr300::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cass__SerialIO__W_G_Emr300.data,
    qt_meta_data_Cass__SerialIO__W_G_Emr300,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cass::SerialIO::W_G_Emr300::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cass::SerialIO::W_G_Emr300::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cass__SerialIO__W_G_Emr300.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "I_Serial_Probe"))
        return static_cast< I_Serial_Probe*>(this);
    return QObject::qt_metacast(_clname);
}

int Cass::SerialIO::W_G_Emr300::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Cass::SerialIO::W_G_Emr300::probeNewError(QSerialPort::SerialPortError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
