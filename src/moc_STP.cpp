/****************************************************************************
** Meta object code from reading C++ file 'STP.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "STP.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'STP.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SwitchSTP_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchSTP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchSTP_t qt_meta_stringdata_SwitchSTP = {
    {
QT_MOC_LITERAL(0, 0, 9) // "SwitchSTP"

    },
    "SwitchSTP"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchSTP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SwitchSTP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SwitchSTP::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SwitchSTP.data,
      qt_meta_data_SwitchSTP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SwitchSTP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchSTP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchSTP.stringdata0))
        return static_cast<void*>(const_cast< SwitchSTP*>(this));
    return QObject::qt_metacast(_clname);
}

int SwitchSTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_STP_t {
    QByteArrayData data[16];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_STP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_STP_t qt_meta_stringdata_STP = {
    {
QT_MOC_LITERAL(0, 0, 3), // "STP"
QT_MOC_LITERAL(1, 4, 16), // "onLinkDiscovered"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "switch_and_port"
QT_MOC_LITERAL(4, 38, 4), // "from"
QT_MOC_LITERAL(5, 43, 2), // "to"
QT_MOC_LITERAL(6, 46, 12), // "onLinkBroken"
QT_MOC_LITERAL(7, 59, 18), // "onSwitchDiscovered"
QT_MOC_LITERAL(8, 78, 7), // "Switch*"
QT_MOC_LITERAL(9, 86, 2), // "dp"
QT_MOC_LITERAL(10, 89, 12), // "onSwitchDown"
QT_MOC_LITERAL(11, 102, 10), // "onSwitchUp"
QT_MOC_LITERAL(12, 113, 8), // "onPortUp"
QT_MOC_LITERAL(13, 122, 10), // "of13::Port"
QT_MOC_LITERAL(14, 133, 4), // "port"
QT_MOC_LITERAL(15, 138, 19) // "computeSpanningTree"

    },
    "STP\0onLinkDiscovered\0\0switch_and_port\0"
    "from\0to\0onLinkBroken\0onSwitchDiscovered\0"
    "Switch*\0dp\0onSwitchDown\0onSwitchUp\0"
    "onPortUp\0of13::Port\0port\0computeSpanningTree"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_STP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x09 /* Protected */,
       6,    2,   54,    2, 0x09 /* Protected */,
       7,    1,   59,    2, 0x09 /* Protected */,
      10,    1,   62,    2, 0x09 /* Protected */,
      11,    1,   65,    2, 0x09 /* Protected */,
      12,    2,   68,    2, 0x09 /* Protected */,
      15,    0,   73,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 13,    9,   14,
    QMetaType::Void,

       0        // eod
};

void STP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        STP *_t = static_cast<STP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onLinkDiscovered((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
        case 1: _t->onLinkBroken((*reinterpret_cast< switch_and_port(*)>(_a[1])),(*reinterpret_cast< switch_and_port(*)>(_a[2]))); break;
        case 2: _t->onSwitchDiscovered((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 3: _t->onSwitchDown((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 4: _t->onSwitchUp((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 5: _t->onPortUp((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< of13::Port(*)>(_a[2]))); break;
        case 6: _t->computeSpanningTree(); break;
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
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::Port >(); break;
            }
            break;
        }
    }
}

const QMetaObject STP::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_STP.data,
      qt_meta_data_STP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *STP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *STP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_STP.stringdata0))
        return static_cast<void*>(const_cast< STP*>(this));
    return Application::qt_metacast(_clname);
}

int STP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Application::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
