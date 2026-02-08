/****************************************************************************
** Meta object code from reading C++ file 'specificworker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/specificworker.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'specificworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_SpecificWorker_t {
    uint offsetsAndSizes[44];
    char stringdata0[15];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[11];
    char stringdata5[25];
    char stringdata6[16];
    char stringdata7[16];
    char stringdata8[6];
    char stringdata9[12];
    char stringdata10[36];
    char stringdata11[5];
    char stringdata12[4];
    char stringdata13[19];
    char stringdata14[16];
    char stringdata15[24];
    char stringdata16[12];
    char stringdata17[16];
    char stringdata18[11];
    char stringdata19[10];
    char stringdata20[8];
    char stringdata21[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SpecificWorker_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SpecificWorker_t qt_meta_stringdata_SpecificWorker = {
    {
        QT_MOC_LITERAL(0, 14),  // "SpecificWorker"
        QT_MOC_LITERAL(15, 10),  // "initialize"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "compute"
        QT_MOC_LITERAL(35, 10),  // "draw_lidar"
        QT_MOC_LITERAL(46, 24),  // "RoboCompLidar3D::TPoints"
        QT_MOC_LITERAL(71, 15),  // "filtered_points"
        QT_MOC_LITERAL(87, 15),  // "QGraphicsScene*"
        QT_MOC_LITERAL(103, 5),  // "scene"
        QT_MOC_LITERAL(109, 11),  // "update_pose"
        QT_MOC_LITERAL(121, 35),  // "RoboCompWebots2Robocomp::Obje..."
        QT_MOC_LITERAL(157, 4),  // "pose"
        QT_MOC_LITERAL(162, 3),  // "yaw"
        QT_MOC_LITERAL(166, 18),  // "transform_to_world"
        QT_MOC_LITERAL(185, 15),  // "Eigen::Vector2f"
        QT_MOC_LITERAL(201, 23),  // "RoboCompLidar3D::TPoint"
        QT_MOC_LITERAL(225, 11),  // "local_point"
        QT_MOC_LITERAL(237, 15),  // "Eigen::Affine2f"
        QT_MOC_LITERAL(253, 10),  // "robot_pose"
        QT_MOC_LITERAL(264, 9),  // "emergency"
        QT_MOC_LITERAL(274, 7),  // "restore"
        QT_MOC_LITERAL(282, 13)   // "startup_check"
    },
    "SpecificWorker",
    "initialize",
    "",
    "compute",
    "draw_lidar",
    "RoboCompLidar3D::TPoints",
    "filtered_points",
    "QGraphicsScene*",
    "scene",
    "update_pose",
    "RoboCompWebots2Robocomp::ObjectPose",
    "pose",
    "yaw",
    "transform_to_world",
    "Eigen::Vector2f",
    "RoboCompLidar3D::TPoint",
    "local_point",
    "Eigen::Affine2f",
    "robot_pose",
    "emergency",
    "restore",
    "startup_check"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SpecificWorker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    2,   64,    2, 0x0a,    3 /* Public */,
       9,    2,   69,    2, 0x0a,    6 /* Public */,
      13,    2,   74,    2, 0x0a,    9 /* Public */,
      19,    0,   79,    2, 0x0a,   12 /* Public */,
      20,    0,   80,    2, 0x0a,   13 /* Public */,
      21,    0,   81,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Double,   11,   12,
    0x80000000 | 14, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,

       0        // eod
};

Q_CONSTINIT const QMetaObject SpecificWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<GenericWorker::staticMetaObject>(),
    qt_meta_stringdata_SpecificWorker.offsetsAndSizes,
    qt_meta_data_SpecificWorker,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SpecificWorker_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SpecificWorker, std::true_type>,
        // method 'initialize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'compute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'draw_lidar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const RoboCompLidar3D::TPoints &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsScene *, std::false_type>,
        // method 'update_pose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<RoboCompWebots2Robocomp::ObjectPose, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'transform_to_world'
        QtPrivate::TypeAndForceComplete<Eigen::Vector2f, std::false_type>,
        QtPrivate::TypeAndForceComplete<const RoboCompLidar3D::TPoint &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Eigen::Affine2f &, std::false_type>,
        // method 'emergency'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'restore'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startup_check'
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SpecificWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpecificWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initialize(); break;
        case 1: _t->compute(); break;
        case 2: _t->draw_lidar((*reinterpret_cast< std::add_pointer_t<RoboCompLidar3D::TPoints>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsScene*>>(_a[2]))); break;
        case 3: _t->update_pose((*reinterpret_cast< std::add_pointer_t<RoboCompWebots2Robocomp::ObjectPose>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 4: { Eigen::Vector2f _r = _t->transform_to_world((*reinterpret_cast< std::add_pointer_t<RoboCompLidar3D::TPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Eigen::Affine2f>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Eigen::Vector2f*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->emergency(); break;
        case 6: _t->restore(); break;
        case 7: { int _r = _t->startup_check();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsScene* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *SpecificWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpecificWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpecificWorker.stringdata0))
        return static_cast<void*>(this);
    return GenericWorker::qt_metacast(_clname);
}

int SpecificWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericWorker::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
