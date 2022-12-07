/****************************************************************************
** Meta object code from reading C++ file 'luottoraja.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend/luottoraja.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'luottoraja.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_luottoraja_t {
    QByteArrayData data[17];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_luottoraja_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_luottoraja_t qt_meta_stringdata_luottoraja = {
    {
QT_MOC_LITERAL(0, 0, 10), // "luottoraja"
QT_MOC_LITERAL(1, 11, 23), // "on_luottoPoistu_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 20), // "on_luotto500_clicked"
QT_MOC_LITERAL(4, 57, 21), // "on_luotto1000_clicked"
QT_MOC_LITERAL(5, 79, 21), // "on_luotto2000_clicked"
QT_MOC_LITERAL(6, 101, 21), // "on_luotto5000_clicked"
QT_MOC_LITERAL(7, 123, 22), // "on_luotto10000_clicked"
QT_MOC_LITERAL(8, 146, 8), // "setlimit"
QT_MOC_LITERAL(9, 155, 5), // "maara"
QT_MOC_LITERAL(10, 161, 11), // "timeoutSlot"
QT_MOC_LITERAL(11, 173, 22), // "on_uusi_luotto_clicked"
QT_MOC_LITERAL(12, 196, 18), // "getAccountTypeSlot"
QT_MOC_LITERAL(13, 215, 14), // "QNetworkReply*"
QT_MOC_LITERAL(14, 230, 5), // "reply"
QT_MOC_LITERAL(15, 236, 15), // "transactionSlot"
QT_MOC_LITERAL(16, 252, 16) // "updateCreditSlot"

    },
    "luottoraja\0on_luottoPoistu_clicked\0\0"
    "on_luotto500_clicked\0on_luotto1000_clicked\0"
    "on_luotto2000_clicked\0on_luotto5000_clicked\0"
    "on_luotto10000_clicked\0setlimit\0maara\0"
    "timeoutSlot\0on_uusi_luotto_clicked\0"
    "getAccountTypeSlot\0QNetworkReply*\0"
    "reply\0transactionSlot\0updateCreditSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_luottoraja[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    2,   80,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    1,   87,    2, 0x08 /* Private */,
      15,    1,   90,    2, 0x08 /* Private */,
      16,    1,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    0,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void luottoraja::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<luottoraja *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_luottoPoistu_clicked(); break;
        case 1: _t->on_luotto500_clicked(); break;
        case 2: _t->on_luotto1000_clicked(); break;
        case 3: _t->on_luotto2000_clicked(); break;
        case 4: _t->on_luotto5000_clicked(); break;
        case 5: _t->on_luotto10000_clicked(); break;
        case 6: _t->setlimit((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->timeoutSlot(); break;
        case 8: _t->on_uusi_luotto_clicked(); break;
        case 9: _t->getAccountTypeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->transactionSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->updateCreditSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject luottoraja::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_luottoraja.data,
    qt_meta_data_luottoraja,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *luottoraja::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *luottoraja::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_luottoraja.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int luottoraja::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
