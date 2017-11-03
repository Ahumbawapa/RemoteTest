/****************************************************************************
** Meta object code from reading C++ file 'remotecontrolPresenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../remotecontrolPresenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remotecontrolPresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemoteControlPresenter_t {
    QByteArrayData data[15];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoteControlPresenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoteControlPresenter_t qt_meta_stringdata_RemoteControlPresenter = {
    {
QT_MOC_LITERAL(0, 0, 22), // "RemoteControlPresenter"
QT_MOC_LITERAL(1, 23, 15), // "isServerChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 8), // "isServer"
QT_MOC_LITERAL(4, 49, 16), // "ipAddressChanged"
QT_MOC_LITERAL(5, 66, 9), // "ipAddress"
QT_MOC_LITERAL(6, 76, 11), // "portChanged"
QT_MOC_LITERAL(7, 88, 4), // "port"
QT_MOC_LITERAL(8, 93, 11), // "serverError"
QT_MOC_LITERAL(9, 105, 12), // "errorMessage"
QT_MOC_LITERAL(10, 118, 11), // "setIsServer"
QT_MOC_LITERAL(11, 130, 12), // "setIpAddress"
QT_MOC_LITERAL(12, 143, 7), // "setPort"
QT_MOC_LITERAL(13, 151, 19), // "onServerRoleChanged"
QT_MOC_LITERAL(14, 171, 17) // "onListenOrConnect"

    },
    "RemoteControlPresenter\0isServerChanged\0"
    "\0isServer\0ipAddressChanged\0ipAddress\0"
    "portChanged\0port\0serverError\0errorMessage\0"
    "setIsServer\0setIpAddress\0setPort\0"
    "onServerRoleChanged\0onListenOrConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoteControlPresenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::UShort, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void RemoteControlPresenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RemoteControlPresenter *_t = static_cast<RemoteControlPresenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isServerChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ipAddressChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->portChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->serverError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setIsServer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setIpAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setPort((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 7: _t->onServerRoleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onListenOrConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RemoteControlPresenter::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RemoteControlPresenter::isServerChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RemoteControlPresenter::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RemoteControlPresenter::ipAddressChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RemoteControlPresenter::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RemoteControlPresenter::portChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RemoteControlPresenter::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RemoteControlPresenter::serverError)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        RemoteControlPresenter *_t = static_cast<RemoteControlPresenter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isServer(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->ipAddress(); break;
        case 2: *reinterpret_cast< quint16*>(_v) = _t->port(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        RemoteControlPresenter *_t = static_cast<RemoteControlPresenter *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIsServer(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setIpAddress(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setPort(*reinterpret_cast< quint16*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject RemoteControlPresenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RemoteControlPresenter.data,
      qt_meta_data_RemoteControlPresenter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RemoteControlPresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoteControlPresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemoteControlPresenter.stringdata0))
        return static_cast<void*>(const_cast< RemoteControlPresenter*>(this));
    return QObject::qt_metacast(_clname);
}

int RemoteControlPresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RemoteControlPresenter::isServerChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RemoteControlPresenter::ipAddressChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RemoteControlPresenter::portChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RemoteControlPresenter::serverError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
