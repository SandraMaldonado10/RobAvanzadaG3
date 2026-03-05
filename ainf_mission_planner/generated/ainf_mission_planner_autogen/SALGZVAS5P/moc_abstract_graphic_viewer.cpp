/****************************************************************************
** Meta object code from reading C++ file 'abstract_graphic_viewer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../classes/abstract_graphic_viewer/abstract_graphic_viewer.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstract_graphic_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN21AbstractGraphicViewerE_t {};
} // unnamed namespace

template <> constexpr inline auto AbstractGraphicViewer::qt_create_metaobjectdata<qt_meta_tag_ZN21AbstractGraphicViewerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AbstractGraphicViewer",
        "new_mouse_coordinates",
        "",
        "right_click",
        "robot_moved",
        "robot_drag_start",
        "robot_dragging",
        "robot_drag_end",
        "robot_rotate"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'new_mouse_coordinates'
        QtMocHelpers::SignalData<void(QPointF)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
        // Signal 'right_click'
        QtMocHelpers::SignalData<void(QPointF)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
        // Signal 'robot_moved'
        QtMocHelpers::SignalData<void(QPointF)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
        // Signal 'robot_drag_start'
        QtMocHelpers::SignalData<void(QPointF)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
        // Signal 'robot_dragging'
        QtMocHelpers::SignalData<void(QPointF)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
        // Signal 'robot_drag_end'
        QtMocHelpers::SignalData<void(QPointF)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
        // Signal 'robot_rotate'
        QtMocHelpers::SignalData<void(QPointF)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AbstractGraphicViewer, qt_meta_tag_ZN21AbstractGraphicViewerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AbstractGraphicViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21AbstractGraphicViewerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21AbstractGraphicViewerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21AbstractGraphicViewerE_t>.metaTypes,
    nullptr
} };

void AbstractGraphicViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AbstractGraphicViewer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->new_mouse_coordinates((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 1: _t->right_click((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 2: _t->robot_moved((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 3: _t->robot_drag_start((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 4: _t->robot_dragging((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 5: _t->robot_drag_end((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 6: _t->robot_rotate((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::new_mouse_coordinates, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::right_click, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::robot_moved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::robot_drag_start, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::robot_dragging, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::robot_drag_end, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (AbstractGraphicViewer::*)(QPointF )>(_a, &AbstractGraphicViewer::robot_rotate, 6))
            return;
    }
}

const QMetaObject *AbstractGraphicViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractGraphicViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21AbstractGraphicViewerE_t>.strings))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int AbstractGraphicViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AbstractGraphicViewer::new_mouse_coordinates(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void AbstractGraphicViewer::right_click(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void AbstractGraphicViewer::robot_moved(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void AbstractGraphicViewer::robot_drag_start(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void AbstractGraphicViewer::robot_dragging(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void AbstractGraphicViewer::robot_drag_end(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void AbstractGraphicViewer::robot_rotate(QPointF _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP
