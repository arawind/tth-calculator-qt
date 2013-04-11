/****************************************************************************
** Meta object code from reading C++ file 'dirviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dirviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dirviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dirViewer_t {
    QByteArrayData data[5];
    char stringdata[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_dirViewer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_dirViewer_t qt_meta_stringdata_dirViewer = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 15),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 5),
QT_MOC_LITERAL(4, 33, 16)
    },
    "dirViewer\0on_tree_clicked\0\0index\0"
    "on_butOK_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dirViewer[] = {

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
       1,    1,   24,    2, 0x08,
       4,    0,   27,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,

       0        // eod
};

void dirViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dirViewer *_t = static_cast<dirViewer *>(_o);
        switch (_id) {
        case 0: _t->on_tree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_butOK_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject dirViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dirViewer.data,
      qt_meta_data_dirViewer,  qt_static_metacall, 0, 0}
};


const QMetaObject *dirViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dirViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dirViewer.stringdata))
        return static_cast<void*>(const_cast< dirViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int dirViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
