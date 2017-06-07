/****************************************************************************
** Meta object code from reading C++ file 'serverWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serverWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_serverWindow_t {
    QByteArrayData data[12];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serverWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serverWindow_t qt_meta_stringdata_serverWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "serverWindow"
QT_MOC_LITERAL(1, 13, 12), // "dataRecivedS"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "newConn"
QT_MOC_LITERAL(4, 35, 10), // "readClient"
QT_MOC_LITERAL(5, 46, 14), // "updateFunction"
QT_MOC_LITERAL(6, 61, 11), // "updateLabel"
QT_MOC_LITERAL(7, 73, 17), // "on_Bpower_clicked"
QT_MOC_LITERAL(8, 91, 18), // "on_Bcancel_clicked"
QT_MOC_LITERAL(9, 110, 18), // "on_Bcommit_clicked"
QT_MOC_LITERAL(10, 129, 16), // "on_Bhalt_clicked"
QT_MOC_LITERAL(11, 146, 17) // "on_Bquery_clicked"

    },
    "serverWindow\0dataRecivedS\0\0newConn\0"
    "readClient\0updateFunction\0updateLabel\0"
    "on_Bpower_clicked\0on_Bcancel_clicked\0"
    "on_Bcommit_clicked\0on_Bhalt_clicked\0"
    "on_Bquery_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serverWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void serverWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serverWindow *_t = static_cast<serverWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataRecivedS(); break;
        case 1: _t->newConn(); break;
        case 2: _t->readClient(); break;
        case 3: _t->updateFunction(); break;
        case 4: _t->updateLabel(); break;
        case 5: _t->on_Bpower_clicked(); break;
        case 6: _t->on_Bcancel_clicked(); break;
        case 7: _t->on_Bcommit_clicked(); break;
        case 8: _t->on_Bhalt_clicked(); break;
        case 9: _t->on_Bquery_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (serverWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&serverWindow::dataRecivedS)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject serverWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_serverWindow.data,
      qt_meta_data_serverWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *serverWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serverWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_serverWindow.stringdata0))
        return static_cast<void*>(const_cast< serverWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int serverWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void serverWindow::dataRecivedS()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
