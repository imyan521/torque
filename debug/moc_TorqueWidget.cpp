/****************************************************************************
** Meta object code from reading C++ file 'TorqueWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TorqueWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TorqueWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TorqueWidget_t {
    QByteArrayData data[12];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TorqueWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TorqueWidget_t qt_meta_stringdata_TorqueWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TorqueWidget"
QT_MOC_LITERAL(1, 13, 21), // "device_connect_Window"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "updateSampleData"
QT_MOC_LITERAL(4, 53, 20), // "onStartButtonClicked"
QT_MOC_LITERAL(5, 74, 20), // "onPauseButtonClicked"
QT_MOC_LITERAL(6, 95, 20), // "onResetButtonClicked"
QT_MOC_LITERAL(7, 116, 11), // "updatePlots"
QT_MOC_LITERAL(8, 128, 15), // "newDataReceived"
QT_MOC_LITERAL(9, 144, 14), // "Connect_device"
QT_MOC_LITERAL(10, 159, 29), // "onSaveTorqueZeroButtonClicked"
QT_MOC_LITERAL(11, 189, 28) // "onSaveAngleZeroButtonClicked"

    },
    "TorqueWidget\0device_connect_Window\0\0"
    "updateSampleData\0onStartButtonClicked\0"
    "onPauseButtonClicked\0onResetButtonClicked\0"
    "updatePlots\0newDataReceived\0Connect_device\0"
    "onSaveTorqueZeroButtonClicked\0"
    "onSaveAngleZeroButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TorqueWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TorqueWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TorqueWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->device_connect_Window(); break;
        case 1: _t->updateSampleData(); break;
        case 2: _t->onStartButtonClicked(); break;
        case 3: _t->onPauseButtonClicked(); break;
        case 4: _t->onResetButtonClicked(); break;
        case 5: _t->updatePlots((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->Connect_device(); break;
        case 7: _t->onSaveTorqueZeroButtonClicked(); break;
        case 8: _t->onSaveAngleZeroButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TorqueWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TorqueWidget::device_connect_Window)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TorqueWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TorqueWidget.data,
    qt_meta_data_TorqueWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TorqueWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TorqueWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TorqueWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TorqueWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TorqueWidget::device_connect_Window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
