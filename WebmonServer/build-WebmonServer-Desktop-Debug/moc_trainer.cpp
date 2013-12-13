/****************************************************************************
** Meta object code from reading C++ file 'trainer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WebmonServer/trainer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_trainer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   35,    8,    8, 0x0a,
      73,    8,    8,    8, 0x0a,
      83,    8,    8,    8, 0x0a,
     104,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_trainer[] = {
    "trainer\0\0id\0endConnection(QString)\0"
    "socketDescriptor,id\0init(int,QString)\0"
    "newInfo()\0ClientDisconnected()\0"
    "printSocketDestroyed()\0"
};

void trainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        trainer *_t = static_cast<trainer *>(_o);
        switch (_id) {
        case 0: _t->endConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->newInfo(); break;
        case 3: _t->ClientDisconnected(); break;
        case 4: _t->printSocketDestroyed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData trainer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject trainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_trainer,
      qt_meta_data_trainer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &trainer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *trainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *trainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_trainer))
        return static_cast<void*>(const_cast< trainer*>(this));
    return QObject::qt_metacast(_clname);
}

int trainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void trainer::endConnection(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
