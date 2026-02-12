/********************************************************************************
** Form generated from reading UI file 'mainUI.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiDlg
{
public:
    QWidget *centralwidget;
    QFrame *viewer_lidar;
    QFrame *viewer_room;
    QStatusBar *statusbar;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName("guiDlg");
        guiDlg->resize(1122, 887);
        centralwidget = new QWidget(guiDlg);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 1101, 881));
        viewer_lidar = new QFrame(centralwidget);
        viewer_lidar->setObjectName("viewer_lidar");
        viewer_lidar->setGeometry(QRect(0, 0, 551, 881));
        viewer_lidar->setFrameShape(QFrame::StyledPanel);
        viewer_lidar->setFrameShadow(QFrame::Raised);
        viewer_room = new QFrame(centralwidget);
        viewer_room->setObjectName("viewer_room");
        viewer_room->setGeometry(QRect(550, 0, 551, 881));
        viewer_room->setFrameShape(QFrame::StyledPanel);
        viewer_room->setFrameShadow(QFrame::Raised);
        statusbar = new QStatusBar(guiDlg);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 23));

        retranslateUi(guiDlg);

        QMetaObject::connectSlotsByName(guiDlg);
    } // setupUi

    void retranslateUi(QWidget *guiDlg)
    {
        guiDlg->setWindowTitle(QCoreApplication::translate("guiDlg", "mapa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
