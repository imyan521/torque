/****************************************************************************
** Meta object code from reading C++ file 'datareceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../datareceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datareceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataReceiver_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataReceiver_t qt_meta_stringdata_DataReceiver = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DataReceiver"
QT_MOC_LITERAL(1, 13, 14), // "startreceiving"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "DataReceiver\0startreceiving\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DataReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startreceiving(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DataReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataReceiver.data,
    qt_meta_data_DataReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SerialReceiver_t {
    QByteArrayData data[14];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialReceiver_t qt_meta_stringdata_SerialReceiver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SerialReceiver"
QT_MOC_LITERAL(1, 15, 12), // "serial_state"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "state"
QT_MOC_LITERAL(4, 35, 11), // "matrixReady"
QT_MOC_LITERAL(5, 47, 35), // "std::vector<std::vector<uint1..."
QT_MOC_LITERAL(6, 83, 6), // "matrix"
QT_MOC_LITERAL(7, 90, 8), // "readData"
QT_MOC_LITERAL(8, 99, 13), // "handletimeout"
QT_MOC_LITERAL(9, 113, 14), // "openSerialPort"
QT_MOC_LITERAL(10, 128, 8), // "portName"
QT_MOC_LITERAL(11, 137, 15), // "closeSerialPort"
QT_MOC_LITERAL(12, 153, 11), // "processdata"
QT_MOC_LITERAL(13, 165, 4) // "data"

    },
    "SerialReceiver\0serial_state\0\0state\0"
    "matrixReady\0std::vector<std::vector<uint16_t> >\0"
    "matrix\0readData\0handletimeout\0"
    "openSerialPort\0portName\0closeSerialPort\0"
    "processdata\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x0a /* Public */,
      11,    0,   60,    2, 0x0a /* Public */,
      12,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   13,

       0        // eod
};

void SerialReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->serial_state((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->matrixReady((*reinterpret_cast< const std::vector<std::vector<uint16_t> >(*)>(_a[1]))); break;
        case 2: _t->readData(); break;
        case 3: _t->handletimeout(); break;
        case 4: _t->openSerialPort((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->closeSerialPort(); break;
        case 6: _t->processdata((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (SerialReceiver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialReceiver::serial_state)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialReceiver::*)(const std::vector<std::vector<uint16_t>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialReceiver::matrixReady)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<DataReceiver::staticMetaObject>(),
    qt_meta_stringdata_SerialReceiver.data,
    qt_meta_data_SerialReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialReceiver.stringdata0))
        return static_cast<void*>(this);
    return DataReceiver::qt_metacast(_clname);
}

int SerialReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DataReceiver::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
int SerialReceiver::serial_state(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void SerialReceiver::matrixReady(const std::vector<std::vector<uint16_t>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_NetWork_t {
    QByteArrayData data[10];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetWork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetWork_t qt_meta_stringdata_NetWork = {
    {
QT_MOC_LITERAL(0, 0, 7), // "NetWork"
QT_MOC_LITERAL(1, 8, 16), // "pressure_connect"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "torque_connect"
QT_MOC_LITERAL(4, 41, 20), // "get_pressure_message"
QT_MOC_LITERAL(5, 62, 7), // "message"
QT_MOC_LITERAL(6, 70, 18), // "get_torque_message"
QT_MOC_LITERAL(7, 89, 13), // "newConnection"
QT_MOC_LITERAL(8, 103, 8), // "readData"
QT_MOC_LITERAL(9, 112, 24) // "sendToAllPressureDevices"

    },
    "NetWork\0pressure_connect\0\0torque_connect\0"
    "get_pressure_message\0message\0"
    "get_torque_message\0newConnection\0"
    "readData\0sendToAllPressureDevices"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetWork[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void NetWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetWork *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pressure_connect(); break;
        case 1: _t->torque_connect(); break;
        case 2: _t->get_pressure_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->get_torque_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->newConnection(); break;
        case 5: _t->readData(); break;
        case 6: _t->sendToAllPressureDevices((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetWork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWork::pressure_connect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetWork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWork::torque_connect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetWork::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWork::get_pressure_message)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetWork::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWork::get_torque_message)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetWork::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NetWork.data,
    qt_meta_data_NetWork,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetWork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetWork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void NetWork::pressure_connect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NetWork::torque_connect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NetWork::get_pressure_message(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetWork::get_torque_message(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
