/****************************************************************************
** Meta object code from reading C++ file 'Controller.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Controller.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[15];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 8), // "switchUp"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 19), // "SwitchConnectionPtr"
QT_MOC_LITERAL(4, 41, 4), // "conn"
QT_MOC_LITERAL(5, 46, 19), // "of13::FeaturesReply"
QT_MOC_LITERAL(6, 66, 2), // "fr"
QT_MOC_LITERAL(7, 69, 10), // "portStatus"
QT_MOC_LITERAL(8, 80, 6), // "ofconn"
QT_MOC_LITERAL(9, 87, 16), // "of13::PortStatus"
QT_MOC_LITERAL(10, 104, 2), // "ps"
QT_MOC_LITERAL(11, 107, 10), // "switchDown"
QT_MOC_LITERAL(12, 118, 11), // "flowRemoved"
QT_MOC_LITERAL(13, 130, 7), // "ofconnl"
QT_MOC_LITERAL(14, 138, 17) // "of13::FlowRemoved"

    },
    "Controller\0switchUp\0\0SwitchConnectionPtr\0"
    "conn\0of13::FeaturesReply\0fr\0portStatus\0"
    "ofconn\0of13::PortStatus\0ps\0switchDown\0"
    "flowRemoved\0ofconnl\0of13::FlowRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       7,    2,   39,    2, 0x06 /* Public */,
      11,    1,   44,    2, 0x06 /* Public */,
      12,    2,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 14,   13,    6,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchUp((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< of13::FeaturesReply(*)>(_a[2]))); break;
        case 1: _t->portStatus((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< of13::PortStatus(*)>(_a[2]))); break;
        case 2: _t->switchDown((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1]))); break;
        case 3: _t->flowRemoved((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< of13::FlowRemoved(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::FeaturesReply >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::PortStatus >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::FlowRemoved >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)(SwitchConnectionPtr , of13::FeaturesReply );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::switchUp)) {
                *result = 0;
            }
        }
        {
            typedef void (Controller::*_t)(SwitchConnectionPtr , of13::PortStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::portStatus)) {
                *result = 1;
            }
        }
        {
            typedef void (Controller::*_t)(SwitchConnectionPtr );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::switchDown)) {
                *result = 2;
            }
        }
        {
            typedef void (Controller::*_t)(SwitchConnectionPtr , of13::FlowRemoved );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::flowRemoved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return Application::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Application::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Controller::switchUp(SwitchConnectionPtr _t1, of13::FeaturesReply _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::portStatus(SwitchConnectionPtr _t1, of13::PortStatus _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::switchDown(SwitchConnectionPtr _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::flowRemoved(SwitchConnectionPtr _t1, of13::FlowRemoved _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
