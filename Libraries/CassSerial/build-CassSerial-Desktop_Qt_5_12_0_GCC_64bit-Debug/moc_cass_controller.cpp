/****************************************************************************
** Meta object code from reading C++ file 'cass_controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CassSerial/cass_controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cass_controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cass__SerialIO__Cass_Controller_t {
    QByteArrayData data[7];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cass__SerialIO__Cass_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cass__SerialIO__Cass_Controller_t qt_meta_stringdata_Cass__SerialIO__Cass_Controller = {
    {
QT_MOC_LITERAL(0, 0, 31), // "Cass::SerialIO::Cass_Controller"
QT_MOC_LITERAL(1, 32, 13), // "probeNewError"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(4, 76, 15), // "serialPortError"
QT_MOC_LITERAL(5, 92, 20), // "handleNewSerialError"
QT_MOC_LITERAL(6, 113, 8) // "newError"

    },
    "Cass::SerialIO::Cass_Controller\0"
    "probeNewError\0\0QSerialPort::SerialPortError\0"
    "serialPortError\0handleNewSerialError\0"
    "newError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cass__SerialIO__Cass_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
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

       0        // eod
};

void Cass::SerialIO::Cass_Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cass_Controller *_t = static_cast<Cass_Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->probeNewError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 1: _t->handleNewSerialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cass_Controller::*)(QSerialPort::SerialPortError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cass_Controller::probeNewError)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Cass::SerialIO::Cass_Controller::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cass__SerialIO__Cass_Controller.data,
    qt_meta_data_Cass__SerialIO__Cass_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cass::SerialIO::Cass_Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cass::SerialIO::Cass_Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cass__SerialIO__Cass_Controller.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "I_Serial_Probe"))
        return static_cast< I_Serial_Probe*>(this);
    return QObject::qt_metacast(_clname);
}

int Cass::SerialIO::Cass_Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Cass::SerialIO::Cass_Controller::probeNewError(QSerialPort::SerialPortError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
