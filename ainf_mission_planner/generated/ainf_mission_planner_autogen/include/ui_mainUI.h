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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiDlg
{
public:
    QFrame *frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_top;
    QPushButton *pushButton_startFollow;
    QPushButton *pushButton_stopFollow;
    QPushButton *pushButton_resumeFollow;
    QFrame *line_separator_top;
    QLabel *label_robotCoordsTitle;
    QLabel *label_robotCoordsValue;
    QLabel *label_missionStatusTitle;
    QLabel *label_missionStatusValue;
    QSpacerItem *horizontalSpacer_top;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_distanceToTargetTitle;
    QLabel *label_distanceToTargetValue;
    QLabel *label_etaTitle;
    QLabel *label_etaValue;
    QLabel *label_currentSpeedTitle;
    QLabel *label_currentSpeedValue;
    QSpacerItem *horizontalSpacer_metrics;
    QLineEdit *object_prompt;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName("guiDlg");
        guiDlg->resize(800, 600);
        frame = new QFrame(guiDlg);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(11, 129, 779, 461));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        layoutWidget = new QWidget(guiDlg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 672, 28));
        horizontalLayout_top = new QHBoxLayout(layoutWidget);
        horizontalLayout_top->setObjectName("horizontalLayout_top");
        horizontalLayout_top->setContentsMargins(0, 0, 0, 0);
        pushButton_startFollow = new QPushButton(layoutWidget);
        pushButton_startFollow->setObjectName("pushButton_startFollow");

        horizontalLayout_top->addWidget(pushButton_startFollow);

        pushButton_stopFollow = new QPushButton(layoutWidget);
        pushButton_stopFollow->setObjectName("pushButton_stopFollow");

        horizontalLayout_top->addWidget(pushButton_stopFollow);

        pushButton_resumeFollow = new QPushButton(layoutWidget);
        pushButton_resumeFollow->setObjectName("pushButton_resumeFollow");

        horizontalLayout_top->addWidget(pushButton_resumeFollow);

        line_separator_top = new QFrame(layoutWidget);
        line_separator_top->setObjectName("line_separator_top");
        line_separator_top->setFrameShape(QFrame::VLine);
        line_separator_top->setFrameShadow(QFrame::Sunken);

        horizontalLayout_top->addWidget(line_separator_top);

        label_robotCoordsTitle = new QLabel(layoutWidget);
        label_robotCoordsTitle->setObjectName("label_robotCoordsTitle");

        horizontalLayout_top->addWidget(label_robotCoordsTitle);

        label_robotCoordsValue = new QLabel(layoutWidget);
        label_robotCoordsValue->setObjectName("label_robotCoordsValue");

        horizontalLayout_top->addWidget(label_robotCoordsValue);

        label_missionStatusTitle = new QLabel(layoutWidget);
        label_missionStatusTitle->setObjectName("label_missionStatusTitle");

        horizontalLayout_top->addWidget(label_missionStatusTitle);

        label_missionStatusValue = new QLabel(layoutWidget);
        label_missionStatusValue->setObjectName("label_missionStatusValue");

        horizontalLayout_top->addWidget(label_missionStatusValue);

        horizontalSpacer_top = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_top->addItem(horizontalSpacer_top);

        layoutWidget1 = new QWidget(guiDlg);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 50, 505, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_distanceToTargetTitle = new QLabel(layoutWidget1);
        label_distanceToTargetTitle->setObjectName("label_distanceToTargetTitle");

        horizontalLayout->addWidget(label_distanceToTargetTitle);

        label_distanceToTargetValue = new QLabel(layoutWidget1);
        label_distanceToTargetValue->setObjectName("label_distanceToTargetValue");

        horizontalLayout->addWidget(label_distanceToTargetValue);

        label_etaTitle = new QLabel(layoutWidget1);
        label_etaTitle->setObjectName("label_etaTitle");

        horizontalLayout->addWidget(label_etaTitle);

        label_etaValue = new QLabel(layoutWidget1);
        label_etaValue->setObjectName("label_etaValue");

        horizontalLayout->addWidget(label_etaValue);

        label_currentSpeedTitle = new QLabel(layoutWidget1);
        label_currentSpeedTitle->setObjectName("label_currentSpeedTitle");

        horizontalLayout->addWidget(label_currentSpeedTitle);

        label_currentSpeedValue = new QLabel(layoutWidget1);
        label_currentSpeedValue->setObjectName("label_currentSpeedValue");

        horizontalLayout->addWidget(label_currentSpeedValue);

        horizontalSpacer_metrics = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(horizontalSpacer_metrics);

        object_prompt = new QLineEdit(guiDlg);
        object_prompt->setObjectName("object_prompt");
        object_prompt->setGeometry(QRect(10, 90, 781, 26));

        retranslateUi(guiDlg);

        QMetaObject::connectSlotsByName(guiDlg);
    } // setupUi

    void retranslateUi(QWidget *guiDlg)
    {
        guiDlg->setWindowTitle(QCoreApplication::translate("guiDlg", "ainf_mission_planner", nullptr));
        pushButton_startFollow->setText(QCoreApplication::translate("guiDlg", "Start Follow", nullptr));
        pushButton_stopFollow->setText(QCoreApplication::translate("guiDlg", "Stop", nullptr));
        pushButton_resumeFollow->setText(QCoreApplication::translate("guiDlg", "Resume", nullptr));
        label_robotCoordsTitle->setText(QCoreApplication::translate("guiDlg", "Robot (m, rad):", nullptr));
        label_robotCoordsValue->setText(QCoreApplication::translate("guiDlg", "x=0.00  y=0.00  \316\270=0.00", nullptr));
        label_missionStatusTitle->setText(QCoreApplication::translate("guiDlg", "Status:", nullptr));
        label_missionStatusValue->setText(QCoreApplication::translate("guiDlg", "IDLE", nullptr));
        label_distanceToTargetTitle->setText(QCoreApplication::translate("guiDlg", "Distance to target (m):", nullptr));
        label_distanceToTargetValue->setText(QCoreApplication::translate("guiDlg", "0.00", nullptr));
        label_etaTitle->setText(QCoreApplication::translate("guiDlg", "ETA (s):", nullptr));
        label_etaValue->setText(QCoreApplication::translate("guiDlg", "0.00", nullptr));
        label_currentSpeedTitle->setText(QCoreApplication::translate("guiDlg", "Current speed (m/s):", nullptr));
        label_currentSpeedValue->setText(QCoreApplication::translate("guiDlg", "0.00", nullptr));
        object_prompt->setPlaceholderText(QCoreApplication::translate("guiDlg", "Introduzca el objeto al que quiere ir...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
