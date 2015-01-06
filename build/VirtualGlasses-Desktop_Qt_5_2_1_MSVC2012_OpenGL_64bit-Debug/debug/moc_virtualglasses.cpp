/****************************************************************************
** Meta object code from reading C++ file 'virtualglasses.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/virtualglasses.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'virtualglasses.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VirtualGlasses_t {
    QByteArrayData data[16];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VirtualGlasses_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VirtualGlasses_t qt_meta_stringdata_VirtualGlasses = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 18),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 10),
QT_MOC_LITERAL(4, 46, 8),
QT_MOC_LITERAL(5, 55, 14),
QT_MOC_LITERAL(6, 70, 5),
QT_MOC_LITERAL(7, 76, 8),
QT_MOC_LITERAL(8, 85, 9),
QT_MOC_LITERAL(9, 95, 9),
QT_MOC_LITERAL(10, 105, 9),
QT_MOC_LITERAL(11, 115, 10),
QT_MOC_LITERAL(12, 126, 7),
QT_MOC_LITERAL(13, 134, 10),
QT_MOC_LITERAL(14, 145, 10),
QT_MOC_LITERAL(15, 156, 10)
    },
    "VirtualGlasses\0getCurrentDateTime\0\0"
    "getTexture\0getImage\0getTranslation\0"
    "scale\0getScale\0getXAngle\0getZAngle\0"
    "getYAngle\0getZOrigin\0scale3d\0getYOrigin\0"
    "getXOrigin\0getScale3d\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VirtualGlasses[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x02,
       3,    0,   75,    2, 0x02,
       4,    0,   76,    2, 0x02,
       5,    1,   77,    2, 0x02,
       7,    0,   80,    2, 0x02,
       8,    0,   81,    2, 0x02,
       9,    0,   82,    2, 0x02,
      10,    0,   83,    2, 0x02,
      11,    1,   84,    2, 0x02,
      13,    1,   87,    2, 0x02,
      14,    1,   90,    2, 0x02,
      15,    0,   93,    2, 0x02,

 // methods: parameters
    QMetaType::QDateTime,
    QMetaType::QString,
    QMetaType::QImage,
    QMetaType::QVector3D, QMetaType::Float,    6,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::QVector3D, QMetaType::QVector3D,   12,
    QMetaType::QVector3D, QMetaType::QVector3D,   12,
    QMetaType::QVector3D, QMetaType::QVector3D,   12,
    QMetaType::QVector3D,

       0        // eod
};

void VirtualGlasses::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VirtualGlasses *_t = static_cast<VirtualGlasses *>(_o);
        switch (_id) {
        case 0: { QDateTime _r = _t->getCurrentDateTime();
            if (_a[0]) *reinterpret_cast< QDateTime*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->getTexture();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QImage _r = _t->getImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 3: { QVector3D _r = _t->getTranslation((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector3D*>(_a[0]) = _r; }  break;
        case 4: { float _r = _t->getScale();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 5: { float _r = _t->getXAngle();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: { float _r = _t->getZAngle();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 7: { float _r = _t->getYAngle();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 8: { QVector3D _r = _t->getZOrigin((*reinterpret_cast< QVector3D(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector3D*>(_a[0]) = _r; }  break;
        case 9: { QVector3D _r = _t->getYOrigin((*reinterpret_cast< QVector3D(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector3D*>(_a[0]) = _r; }  break;
        case 10: { QVector3D _r = _t->getXOrigin((*reinterpret_cast< QVector3D(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVector3D*>(_a[0]) = _r; }  break;
        case 11: { QVector3D _r = _t->getScale3d();
            if (_a[0]) *reinterpret_cast< QVector3D*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject VirtualGlasses::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VirtualGlasses.data,
      qt_meta_data_VirtualGlasses,  qt_static_metacall, 0, 0}
};


const QMetaObject *VirtualGlasses::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VirtualGlasses::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VirtualGlasses.stringdata))
        return static_cast<void*>(const_cast< VirtualGlasses*>(this));
    return QObject::qt_metacast(_clname);
}

int VirtualGlasses::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
