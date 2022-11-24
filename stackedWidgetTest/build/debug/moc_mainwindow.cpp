/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "SisaanWidget"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 14), // "KirjauduWidget"
QT_MOC_LITERAL(4, 40, 19), // "ValitseKorttiWidget"
QT_MOC_LITERAL(5, 60, 10), // "MenuWidget"
QT_MOC_LITERAL(6, 71, 11), // "SaldoWidget"
QT_MOC_LITERAL(7, 83, 20), // "TilitapahtumatWidget"
QT_MOC_LITERAL(8, 104, 10), // "OttoWidget"
QT_MOC_LITERAL(9, 115, 22), // "LuottorajanNostoWidget"
QT_MOC_LITERAL(10, 138, 9), // "loginSlot"
QT_MOC_LITERAL(11, 148, 14), // "QNetworkReply*"
QT_MOC_LITERAL(12, 163, 5), // "reply"
QT_MOC_LITERAL(13, 169, 22), // "on_btnKirjaudu_clicked"
QT_MOC_LITERAL(14, 192, 20), // "on_btnSisaan_clicked"
QT_MOC_LITERAL(15, 213, 20) // "on_btnPoistu_clicked"

    },
    "MainWindow\0SisaanWidget\0\0KirjauduWidget\0"
    "ValitseKorttiWidget\0MenuWidget\0"
    "SaldoWidget\0TilitapahtumatWidget\0"
    "OttoWidget\0LuottorajanNostoWidget\0"
    "loginSlot\0QNetworkReply*\0reply\0"
    "on_btnKirjaudu_clicked\0on_btnSisaan_clicked\0"
    "on_btnPoistu_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SisaanWidget(); break;
        case 1: _t->KirjauduWidget(); break;
        case 2: _t->ValitseKorttiWidget(); break;
        case 3: _t->MenuWidget(); break;
        case 4: _t->SaldoWidget(); break;
        case 5: _t->TilitapahtumatWidget(); break;
        case 6: _t->OttoWidget(); break;
        case 7: _t->LuottorajanNostoWidget(); break;
        case 8: _t->loginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->on_btnKirjaudu_clicked(); break;
        case 10: _t->on_btnSisaan_clicked(); break;
        case 11: _t->on_btnPoistu_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
