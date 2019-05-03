/****************************************************************************
** Meta object code from reading C++ file 'Topology.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Topology.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Topology.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Topology_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Topology_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Topology_t qt_meta_stringdata_Topology = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Topology"
QT_MOC_LITERAL(1, 9, 14), // "linkDiscovered"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "switch_and_port"
QT_MOC_LITERAL(4, 41, 4), // "from"
QT_MOC_LITERAL(5, 46, 2), // "to"
QT_MOC_LITERAL(6, 49, 10) // "linkBroken"

    },
    "Topology\0linkDiscovered\0\0switch_and_port\0"
    "from\0to\0linkBroken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Topology[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x09 /* Protected */,
       6,    2,   29,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

       0        // eod
};

void Topology::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Topology *_t = static_cast<Topology *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->linkDiscovered((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
        case 1: _t->linkBroken((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
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
        }
    }
}

const QMetaObject Topology::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_Topology.data,
      qt_meta_data_Topology,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Topology::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Topology::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Topology.stringdata0))
        return static_cast<void*>(const_cast< Topology*>(this));
    if (!strcmp(_clname, "RestHandler"))
        return static_cast< RestHandler*>(const_cast< Topology*>(this));
    return Application::qt_metacast(_clname);
}

int Topology::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Application::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
