/****************************************************************************
** Meta object code from reading C++ file 'Tab2Widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.17)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Tab2Widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tab2Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.17. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tab2Widget_t {
    QByteArrayData data[23];
    char stringdata0[375];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tab2Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tab2Widget_t qt_meta_stringdata_Tab2Widget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Tab2Widget"
QT_MOC_LITERAL(1, 11, 28), // "toggle_device_connect_Window"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 29), // "pressure_send_setting_message"
QT_MOC_LITERAL(4, 71, 7), // "message"
QT_MOC_LITERAL(5, 79, 19), // "onChooseSizeChanged"
QT_MOC_LITERAL(6, 99, 5), // "index"
QT_MOC_LITERAL(7, 105, 20), // "Start_Button_clicked"
QT_MOC_LITERAL(8, 126, 19), // "Stop_Button_clicked"
QT_MOC_LITERAL(9, 146, 21), // "handleConfigConfirmed"
QT_MOC_LITERAL(10, 168, 8), // "vertical"
QT_MOC_LITERAL(11, 177, 10), // "horizontal"
QT_MOC_LITERAL(12, 188, 11), // "maxPressure"
QT_MOC_LITERAL(13, 200, 11), // "minPressure"
QT_MOC_LITERAL(14, 212, 20), // "updateClientComboBox"
QT_MOC_LITERAL(15, 233, 10), // "clientList"
QT_MOC_LITERAL(16, 244, 14), // "Connect_device"
QT_MOC_LITERAL(17, 259, 22), // "onComboBoxIndexChanged"
QT_MOC_LITERAL(18, 282, 10), // "ui_process"
QT_MOC_LITERAL(19, 293, 17), // "updateMatrixTable"
QT_MOC_LITERAL(20, 311, 35), // "std::vector<std::vector<uint1..."
QT_MOC_LITERAL(21, 347, 6), // "matrix"
QT_MOC_LITERAL(22, 354, 20) // "get_pressure_message"

    },
    "Tab2Widget\0toggle_device_connect_Window\0"
    "\0pressure_send_setting_message\0message\0"
    "onChooseSizeChanged\0index\0"
    "Start_Button_clicked\0Stop_Button_clicked\0"
    "handleConfigConfirmed\0vertical\0"
    "horizontal\0maxPressure\0minPressure\0"
    "updateClientComboBox\0clientList\0"
    "Connect_device\0onComboBoxIndexChanged\0"
    "ui_process\0updateMatrixTable\0"
    "std::vector<std::vector<uint16_t> >\0"
    "matrix\0get_pressure_message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tab2Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   78,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    4,   83,    2, 0x08 /* Private */,
      14,    1,   92,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,
      17,    1,   96,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,
      19,    1,  100,    2, 0x0a /* Public */,
      22,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void Tab2Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tab2Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->toggle_device_connect_Window(); break;
        case 1: _t->pressure_send_setting_message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onChooseSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Start_Button_clicked(); break;
        case 4: _t->Stop_Button_clicked(); break;
        case 5: _t->handleConfigConfirmed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 6: _t->updateClientComboBox((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 7: _t->Connect_device(); break;
        case 8: _t->onComboBoxIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ui_process(); break;
        case 10: _t->updateMatrixTable((*reinterpret_cast< const std::vector<std::vector<uint16_t> >(*)>(_a[1]))); break;
        case 11: _t->get_pressure_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tab2Widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab2Widget::toggle_device_connect_Window)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tab2Widget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tab2Widget::pressure_send_setting_message)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tab2Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Tab2Widget.data,
    qt_meta_data_Tab2Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tab2Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tab2Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tab2Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tab2Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Tab2Widget::toggle_device_connect_Window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tab2Widget::pressure_send_setting_message(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
