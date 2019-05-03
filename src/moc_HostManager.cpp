/****************************************************************************
** Meta object code from reading C++ file 'HostManager.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "HostManager.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HostManager.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HostManager_t {
    QByteArrayData data[12];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HostManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HostManager_t qt_meta_stringdata_HostManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HostManager"
QT_MOC_LITERAL(1, 12, 14), // "hostDiscovered"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "Host*"
QT_MOC_LITERAL(4, 34, 3), // "dev"
QT_MOC_LITERAL(5, 38, 18), // "onSwitchDiscovered"
QT_MOC_LITERAL(6, 57, 7), // "Switch*"
QT_MOC_LITERAL(7, 65, 2), // "dp"
QT_MOC_LITERAL(8, 68, 12), // "onSwitchDown"
QT_MOC_LITERAL(9, 81, 7), // "newPort"
QT_MOC_LITERAL(10, 89, 10), // "of13::Port"
QT_MOC_LITERAL(11, 100, 4) // "port"

    },
    "HostManager\0hostDiscovered\0\0Host*\0dev\0"
    "onSwitchDiscovered\0Switch*\0dp\0"
    "onSwitchDown\0newPort\0of13::Port\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HostManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   37,    2, 0x0a /* Public */,
       8,    1,   40,    2, 0x0a /* Public */,
       9,    2,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 10,    7,   11,

       0        // eod
};

void HostManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HostManager *_t = static_cast<HostManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hostDiscovered((*reinterpret_cast< Host*(*)>(_a[1]))); break;
        case 1: _t->onSwitchDiscovered((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 2: _t->onSwitchDown((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 3: _t->newPort((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< of13::Port(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::Port >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HostManager::*_t)(Host * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HostManager::hostDiscovered)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HostManager::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_HostManager.data,
      qt_meta_data_HostManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HostManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HostManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HostManager.stringdata0))
        return static_cast<void*>(const_cast< HostManager*>(this));
    if (!strcmp(_clname, "RestHandler"))
        return static_cast< RestHandler*>(const_cast< HostManager*>(this));
    return Application::qt_metacast(_clname);
}

int HostManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HostManager::hostDiscovered(Host * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
