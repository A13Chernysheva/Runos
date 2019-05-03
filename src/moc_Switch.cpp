/****************************************************************************
** Meta object code from reading C++ file 'Switch.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Switch.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Switch.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Switch_t {
    QByteArrayData data[14];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Switch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Switch_t qt_meta_stringdata_Switch = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Switch"
QT_MOC_LITERAL(1, 7, 6), // "portUp"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 7), // "Switch*"
QT_MOC_LITERAL(4, 23, 2), // "dp"
QT_MOC_LITERAL(5, 26, 10), // "of13::Port"
QT_MOC_LITERAL(6, 37, 4), // "port"
QT_MOC_LITERAL(7, 42, 12), // "portModified"
QT_MOC_LITERAL(8, 55, 7), // "oldPort"
QT_MOC_LITERAL(9, 63, 8), // "portDown"
QT_MOC_LITERAL(10, 72, 8), // "uint32_t"
QT_MOC_LITERAL(11, 81, 7), // "port_no"
QT_MOC_LITERAL(12, 89, 2), // "up"
QT_MOC_LITERAL(13, 92, 4) // "down"

    },
    "Switch\0portUp\0\0Switch*\0dp\0of13::Port\0"
    "port\0portModified\0oldPort\0portDown\0"
    "uint32_t\0port_no\0up\0down"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Switch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       7,    3,   44,    2, 0x06 /* Public */,
       9,    2,   51,    2, 0x06 /* Public */,
      12,    1,   56,    2, 0x06 /* Public */,
      13,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 10,    4,   11,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Switch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Switch *_t = static_cast<Switch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portUp((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< of13::Port(*)>(_a[2]))); break;
        case 1: _t->portModified((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< of13::Port(*)>(_a[2])),(*reinterpret_cast< of13::Port(*)>(_a[3]))); break;
        case 2: _t->portDown((*reinterpret_cast< Switch*(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 3: _t->up((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 4: _t->down((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
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
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::Port >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::Port >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Switch* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uint32_t >(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Switch::*_t)(Switch * , of13::Port );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Switch::portUp)) {
                *result = 0;
            }
        }
        {
            typedef void (Switch::*_t)(Switch * , of13::Port , of13::Port );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Switch::portModified)) {
                *result = 1;
            }
        }
        {
            typedef void (Switch::*_t)(Switch * , uint32_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Switch::portDown)) {
                *result = 2;
            }
        }
        {
            typedef void (Switch::*_t)(Switch * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Switch::up)) {
                *result = 3;
            }
        }
        {
            typedef void (Switch::*_t)(Switch * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Switch::down)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Switch::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Switch.data,
      qt_meta_data_Switch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Switch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Switch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Switch.stringdata0))
        return static_cast<void*>(const_cast< Switch*>(this));
    if (!strcmp(_clname, "AppObject"))
        return static_cast< AppObject*>(const_cast< Switch*>(this));
    return QObject::qt_metacast(_clname);
}

int Switch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Switch::portUp(Switch * _t1, of13::Port _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Switch::portModified(Switch * _t1, of13::Port _t2, of13::Port _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Switch::portDown(Switch * _t1, uint32_t _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Switch::up(Switch * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Switch::down(Switch * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_SwitchManager_t {
    QByteArrayData data[21];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchManager_t qt_meta_stringdata_SwitchManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SwitchManager"
QT_MOC_LITERAL(1, 14, 16), // "switchDiscovered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "Switch*"
QT_MOC_LITERAL(4, 40, 2), // "dp"
QT_MOC_LITERAL(5, 43, 8), // "switchUp"
QT_MOC_LITERAL(6, 52, 10), // "switchDown"
QT_MOC_LITERAL(7, 63, 10), // "onSwitchUp"
QT_MOC_LITERAL(8, 74, 19), // "SwitchConnectionPtr"
QT_MOC_LITERAL(9, 94, 4), // "conn"
QT_MOC_LITERAL(10, 99, 19), // "of13::FeaturesReply"
QT_MOC_LITERAL(11, 119, 2), // "fr"
QT_MOC_LITERAL(12, 122, 12), // "onPortStatus"
QT_MOC_LITERAL(13, 135, 16), // "of13::PortStatus"
QT_MOC_LITERAL(14, 152, 2), // "ps"
QT_MOC_LITERAL(15, 155, 12), // "onSwitchDown"
QT_MOC_LITERAL(16, 168, 18), // "onPortDescriptions"
QT_MOC_LITERAL(17, 187, 27), // "std::shared_ptr<OFMsgUnion>"
QT_MOC_LITERAL(18, 215, 3), // "msg"
QT_MOC_LITERAL(19, 219, 20), // "onSwitchDescriptions"
QT_MOC_LITERAL(20, 240, 6) // "ofconn"

    },
    "SwitchManager\0switchDiscovered\0\0Switch*\0"
    "dp\0switchUp\0switchDown\0onSwitchUp\0"
    "SwitchConnectionPtr\0conn\0of13::FeaturesReply\0"
    "fr\0onPortStatus\0of13::PortStatus\0ps\0"
    "onSwitchDown\0onPortDescriptions\0"
    "std::shared_ptr<OFMsgUnion>\0msg\0"
    "onSwitchDescriptions\0ofconn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   63,    2, 0x09 /* Protected */,
      12,    2,   68,    2, 0x09 /* Protected */,
      15,    1,   73,    2, 0x09 /* Protected */,
      16,    2,   76,    2, 0x09 /* Protected */,
      19,    2,   81,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 13,    9,   14,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 17,    9,   18,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 17,   20,   18,

       0        // eod
};

void SwitchManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SwitchManager *_t = static_cast<SwitchManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->switchDiscovered((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 1: _t->switchUp((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 2: _t->switchDown((*reinterpret_cast< Switch*(*)>(_a[1]))); break;
        case 3: _t->onSwitchUp((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< of13::FeaturesReply(*)>(_a[2]))); break;
        case 4: _t->onPortStatus((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< of13::PortStatus(*)>(_a[2]))); break;
        case 5: _t->onSwitchDown((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1]))); break;
        case 6: _t->onPortDescriptions((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<OFMsgUnion>(*)>(_a[2]))); break;
        case 7: _t->onSwitchDescriptions((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<OFMsgUnion>(*)>(_a[2]))); break;
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
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::FeaturesReply >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< of13::PortStatus >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::shared_ptr<OFMsgUnion> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::shared_ptr<OFMsgUnion> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SwitchManager::*_t)(Switch * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SwitchManager::switchDiscovered)) {
                *result = 0;
            }
        }
        {
            typedef void (SwitchManager::*_t)(Switch * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SwitchManager::switchUp)) {
                *result = 1;
            }
        }
        {
            typedef void (SwitchManager::*_t)(Switch * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SwitchManager::switchDown)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SwitchManager::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_SwitchManager.data,
      qt_meta_data_SwitchManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SwitchManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchManager.stringdata0))
        return static_cast<void*>(const_cast< SwitchManager*>(this));
    if (!strcmp(_clname, "RestHandler"))
        return static_cast< RestHandler*>(const_cast< SwitchManager*>(this));
    return Application::qt_metacast(_clname);
}

int SwitchManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Application::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SwitchManager::switchDiscovered(Switch * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SwitchManager::switchUp(Switch * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SwitchManager::switchDown(Switch * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
