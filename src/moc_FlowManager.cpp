/****************************************************************************
** Meta object code from reading C++ file 'FlowManager.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FlowManager.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlowManager.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FlowManager_t {
    QByteArrayData data[11];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlowManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlowManager_t qt_meta_stringdata_FlowManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FlowManager"
QT_MOC_LITERAL(1, 12, 12), // "onSwitchDown"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "Switch*"
QT_MOC_LITERAL(4, 34, 2), // "dp"
QT_MOC_LITERAL(5, 37, 10), // "onResponse"
QT_MOC_LITERAL(6, 48, 19), // "SwitchConnectionPtr"
QT_MOC_LITERAL(7, 68, 4), // "conn"
QT_MOC_LITERAL(8, 73, 27), // "std::shared_ptr<OFMsgUnion>"
QT_MOC_LITERAL(9, 101, 5), // "reply"
QT_MOC_LITERAL(10, 107, 10) // "onSwitchUp"

    },
    "FlowManager\0onSwitchDown\0\0Switch*\0dp\0"
    "onResponse\0SwitchConnectionPtr\0conn\0"
    "std::shared_ptr<OFMsgUnion>\0reply\0"
    "onSwitchUp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlowManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x09 /* Protected */,
       5,    2,   32,    2, 0x09 /* Protected */,
      10,    1,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void FlowManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FlowManager *_t = static_cast<FlowManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSwitchDown((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 1: _t->onResponse((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<OFMsgUnion>(*)>(_a[2]))); break;
        case 2: _t->onSwitchUp((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::shared_ptr<OFMsgUnion> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            }
            break;
        }
    }
}

const QMetaObject FlowManager::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_FlowManager.data,
      qt_meta_data_FlowManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FlowManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlowManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FlowManager.stringdata0))
        return static_cast<void*>(const_cast< FlowManager*>(this));
    if (!strcmp(_clname, "RestHandler"))
        return static_cast< RestHandler*>(const_cast< FlowManager*>(this));
    return Application::qt_metacast(_clname);
}

int FlowManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Application::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
