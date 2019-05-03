/****************************************************************************
** Meta object code from reading C++ file 'RestMultipart.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RestMultipart.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RestMultipart.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RestMultipart_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RestMultipart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RestMultipart_t qt_meta_stringdata_RestMultipart = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RestMultipart"
QT_MOC_LITERAL(1, 14, 24), // "ResponseHandlingFinished"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "onResponse"
QT_MOC_LITERAL(4, 51, 19), // "SwitchConnectionPtr"
QT_MOC_LITERAL(5, 71, 4), // "conn"
QT_MOC_LITERAL(6, 76, 27), // "std::shared_ptr<OFMsgUnion>"
QT_MOC_LITERAL(7, 104, 5) // "reply"

    },
    "RestMultipart\0ResponseHandlingFinished\0"
    "\0onResponse\0SwitchConnectionPtr\0conn\0"
    "std::shared_ptr<OFMsgUnion>\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RestMultipart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   25,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

       0        // eod
};

void RestMultipart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RestMultipart *_t = static_cast<RestMultipart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ResponseHandlingFinished(); break;
        case 1: _t->onResponse((*reinterpret_cast< SwitchConnectionPtr(*)>(_a[1])),(*reinterpret_cast< std::shared_ptr<OFMsgUnion>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (RestMultipart::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RestMultipart::ResponseHandlingFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RestMultipart::staticMetaObject = {
    { &Application::staticMetaObject, qt_meta_stringdata_RestMultipart.data,
      qt_meta_data_RestMultipart,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RestMultipart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RestMultipart::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RestMultipart.stringdata0))
        return static_cast<void*>(const_cast< RestMultipart*>(this));
    if (!strcmp(_clname, "RestHandler"))
        return static_cast< RestHandler*>(const_cast< RestMultipart*>(this));
    return Application::qt_metacast(_clname);
}

int RestMultipart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void RestMultipart::ResponseHandlingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
