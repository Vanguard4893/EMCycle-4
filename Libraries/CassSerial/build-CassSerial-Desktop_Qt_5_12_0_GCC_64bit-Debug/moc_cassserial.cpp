/****************************************************************************
** Meta object code from reading C++ file 'cassserial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CassSerial/cassserial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cassserial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cass__SerialIO__CassSerial_t {
    QByteArrayData data[15];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cass__SerialIO__CassSerial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cass__SerialIO__CassSerial_t qt_meta_stringdata_Cass__SerialIO__CassSerial = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Cass::SerialIO::CassSerial"
QT_MOC_LITERAL(1, 27, 12), // "serialDataRx"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "theData"
QT_MOC_LITERAL(4, 49, 7), // "timeout"
QT_MOC_LITERAL(5, 57, 14), // "serialNewError"
QT_MOC_LITERAL(6, 72, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(7, 101, 15), // "serialPortError"
QT_MOC_LITERAL(8, 117, 15), // "serialRxTimeout"
QT_MOC_LITERAL(9, 133, 34), // "serialRxAllDataReceivedOrAllT..."
QT_MOC_LITERAL(10, 168, 15), // "handleReadyRead"
QT_MOC_LITERAL(11, 184, 11), // "handleError"
QT_MOC_LITERAL(12, 196, 5), // "error"
QT_MOC_LITERAL(13, 202, 22), // "handleRxMessageTimeout"
QT_MOC_LITERAL(14, 225, 23) // "handleTxMessageComplete"

    },
    "Cass::SerialIO::CassSerial\0serialDataRx\0"
    "\0theData\0timeout\0serialNewError\0"
    "QSerialPort::SerialPortError\0"
    "serialPortError\0serialRxTimeout\0"
    "serialRxAllDataReceivedOrAllTxSent\0"
    "handleReadyRead\0handleError\0error\0"
    "handleRxMessageTimeout\0handleTxMessageComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cass__SerialIO__CassSerial[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       5,    1,   59,    2, 0x06 /* Public */,
       8,    0,   62,    2, 0x06 /* Public */,
       9,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,
      13,    0,   68,    2, 0x08 /* Private */,
      14,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cass::SerialIO::CassSerial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CassSerial *_t = static_cast<CassSerial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serialDataRx((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->serialNewError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 2: _t->serialRxTimeout(); break;
        case 3: _t->serialRxAllDataReceivedOrAllTxSent(); break;
        case 4: _t->handleReadyRead(); break;
        case 5: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 6: _t->handleRxMessageTimeout(); break;
        case 7: _t->handleTxMessageComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CassSerial::*)(QByteArray , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CassSerial::serialDataRx)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CassSerial::*)(QSerialPort::SerialPortError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CassSerial::serialNewError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CassSerial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CassSerial::serialRxTimeout)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CassSerial::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CassSerial::serialRxAllDataReceivedOrAllTxSent)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cass::SerialIO::CassSerial::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cass__SerialIO__CassSerial.data,
    qt_meta_data_Cass__SerialIO__CassSerial,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cass::SerialIO::CassSerial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cass::SerialIO::CassSerial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cass__SerialIO__CassSerial.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "I_Serial_Port"))
        return static_cast< I_Serial_Port*>(this);
    return QObject::qt_metacast(_clname);
}

int Cass::SerialIO::CassSerial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Cass::SerialIO::CassSerial::serialDataRx(QByteArray _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cass::SerialIO::CassSerial::serialNewError(QSerialPort::SerialPortError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cass::SerialIO::CassSerial::serialRxTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Cass::SerialIO::CassSerial::serialRxAllDataReceivedOrAllTxSent()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
