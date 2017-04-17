/****************************************************************************
** Meta object code from reading C++ file 'clientWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_clientWindow_t {
    QByteArrayData data[16];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_clientWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_clientWindow_t qt_meta_stringdata_clientWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "clientWindow"
QT_MOC_LITERAL(1, 13, 11), // "dataRecived"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "updateFunction"
QT_MOC_LITERAL(4, 41, 11), // "updateLabel"
QT_MOC_LITERAL(5, 53, 14), // "on_Bon_clicked"
QT_MOC_LITERAL(6, 68, 16), // "on_Bcout_clicked"
QT_MOC_LITERAL(7, 85, 16), // "on_Btemp_clicked"
QT_MOC_LITERAL(8, 102, 13), // "on_W1_clicked"
QT_MOC_LITERAL(9, 116, 13), // "on_W2_clicked"
QT_MOC_LITERAL(10, 130, 13), // "on_W3_clicked"
QT_MOC_LITERAL(11, 144, 9), // "connected"
QT_MOC_LITERAL(12, 154, 10), // "clientRead"
QT_MOC_LITERAL(13, 165, 12), // "displayError"
QT_MOC_LITERAL(14, 178, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(15, 207, 11) // "socketError"

    },
    "clientWindow\0dataRecived\0\0updateFunction\0"
    "updateLabel\0on_Bon_clicked\0on_Bcout_clicked\0"
    "on_Btemp_clicked\0on_W1_clicked\0"
    "on_W2_clicked\0on_W3_clicked\0connected\0"
    "clientRead\0displayError\0"
    "QAbstractSocket::SocketError\0socketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clientWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void clientWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clientWindow *_t = static_cast<clientWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataRecived(); break;
        case 1: _t->updateFunction(); break;
        case 2: _t->updateLabel(); break;
        case 3: _t->on_Bon_clicked(); break;
        case 4: _t->on_Bcout_clicked(); break;
        case 5: _t->on_Btemp_clicked(); break;
        case 6: _t->on_W1_clicked(); break;
        case 7: _t->on_W2_clicked(); break;
        case 8: _t->on_W3_clicked(); break;
        case 9: _t->connected(); break;
        case 10: _t->clientRead(); break;
        case 11: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (clientWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clientWindow::dataRecived)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject clientWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_clientWindow.data,
      qt_meta_data_clientWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *clientWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clientWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_clientWindow.stringdata0))
        return static_cast<void*>(const_cast< clientWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int clientWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void clientWindow::dataRecived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
