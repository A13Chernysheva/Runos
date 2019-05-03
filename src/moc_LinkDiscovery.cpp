/****************************************************************************
** Meta object code from reading C++ file 'LinkDiscovery.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "LinkDiscovery.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LinkDiscovery.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LinkDiscovery_t {
    QByteArrayData data[18];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinkDiscovery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinkDiscovery_t qt_meta_stringdata_LinkDiscovery = {
    {
QT_MOC_LITERAL(0, 0, 13), // "LinkDiscovery"
QT_MOC_LITERAL(1, 14, 14), // "linkDiscovered"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "switch_and_port"
QT_MOC_LITERAL(4, 46, 4), // "from"
QT_MOC_LITERAL(5, 51, 2), // "to"
QT_MOC_LITERAL(6, 54, 10), // "linkBroken"
QT_MOC_LITERAL(7, 65, 6), // "portUp"
QT_MOC_LITERAL(8, 72, 7), // "Switch*"
QT_MOC_LITERAL(9, 80, 2), // "dp"
QT_MOC_LITERAL(10, 83, 10), // "of13::Port"
QT_MOC_LITERAL(11, 94, 4), // "port"
QT_MOC_LITERAL(12, 99, 12), // "portModified"
QT_MOC_LITERAL(13, 112, 8), // "old_port"
QT_MOC_LITERAL(14, 121, 8), // "portDown"
QT_MOC_LITERAL(15, 130, 8), // "uint32_t"
QT_MOC_LITERAL(16, 139, 7), // "port_no"
QT_MOC_LITERAL(17, 147, 12) // "handleBeacon"

    },
    "LinkDiscovery\0linkDiscovered\0\0"
    "switch_and_port\0from\0to\0linkBroken\0"
    "portUp\0Switch*\0dp\0of13::Port\0port\0"
    "portModified\0old_port\0portDown\0uint32_t\0"
    "port_no\0handleBeacon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinkDiscovery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       6,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   54,    2, 0x0a /* Public */,
      12,    3,   59,    2, 0x0a /* Public */,
      14,    2,   66,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    2,   71,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 10,    9,   11,   13,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 15,    9,   16,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

       0        // eod
};

void LinkDiscovery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LinkDiscovery *_t = static_cast<LinkDiscovery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->linkDiscovered((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
        case 1: _t->linkBroken((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
        case 2: _t->portUp((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< of13::Port(*)>(_a[2]))); break;
        case 3: _t->portModified((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< of13::Port(*)>(_a[2])),(*reinterpret_cast< of13::Port(*)>(_a[3]))); break;
        case 4: _t->portDown((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 5: _t->handleBeacon((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< switch_and_port >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< switch_and_port >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::Port >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::Port >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uint32_t >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< switch_and_port >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LinkDiscovery::*_t)(switch_and_port , switch_and_port );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LinkDiscovery::linkDiscovered)) {
                *result = 0;
            }
        }
        {
            typedef void (LinkDiscovery::*_t)(switch_and_port , switch_and_port );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LinkDiscovery::linkBroken)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LinkDiscovery::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_LinkDiscovery.data,
      qt_meta_data_LinkDiscovery,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LinkDiscovery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinkDiscovery::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LinkDiscovery.stringdata0))
        return static_cast<void*>(const_cast< LinkDiscovery*>(this));
    if (!strcmp(_clname, "ILinkDiscovery"))
        return static_cast< ILinkDiscovery*>(const_cast< LinkDiscovery*>(this));
    if (!strcmp(_clname, "ru.arccn.link-discovery/0.2"))
        return static_cast< ILinkDiscovery*>(const_cast< LinkDiscovery*>(this));
    return Application::qt_metacast(_clname);
}

int LinkDiscovery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Application::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LinkDiscovery::linkDiscovered(switch_and_port _t1, switch_and_port _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LinkDiscovery::linkBroken(switch_and_port _t1, switch_and_port _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
