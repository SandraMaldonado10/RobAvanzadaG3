/********************************************************************************
** Form generated from reading UI file 'mainUI.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiDlg
{
public:
    QVBoxLayout *verticalLayout_main;
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
    QHBoxLayout *horizontalLayout_metrics;
    QLabel *label_distanceToTargetTitle;
    QLabel *label_distanceToTargetValue;
    QLabel *label_etaTitle;
    QLabel *label_etaValue;
    QLabel *label_currentSpeedTitle;
    QLabel *label_currentSpeedValue;
    QSpacerItem *horizontalSpacer_metrics;
    QFrame *frame;
    QTextEdit *object_prompt;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName("guiDlg");
        guiDlg->resize(800, 600);
        verticalLayout_main = new QVBoxLayout(guiDlg);
        verticalLayout_main->setObjectName("verticalLayout_main");
        horizontalLayout_top = new QHBoxLayout();
        horizontalLayout_top->setObjectName("horizontalLayout_top");
        pushButton_startFollow = new QPushButton(guiDlg);
        pushButton_startFollow->setObjectName("pushButton_startFollow");

        horizontalLayout_top->addWidget(pushButton_startFollow);

        pushButton_stopFollow = new QPushButton(guiDlg);
        pushButton_stopFollow->setObjectName("pushButton_stopFollow");

        horizontalLayout_top->addWidget(pushButton_stopFollow);

        pushButton_resumeFollow = new QPushButton(guiDlg);
        pushButton_resumeFollow->setObjectName("pushButton_resumeFollow");

        horizontalLayout_top->addWidget(pushButton_resumeFollow);

        line_separator_top = new QFrame(guiDlg);
        line_separator_top->setObjectName("line_separator_top");
        line_separator_top->setFrameShape(QFrame::Shape::VLine);
        line_separator_top->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_top->addWidget(line_separator_top);

        label_robotCoordsTitle = new QLabel(guiDlg);
        label_robotCoordsTitle->setObjectName("label_robotCoordsTitle");

        horizontalLayout_top->addWidget(label_robotCoordsTitle);

        label_robotCoordsValue = new QLabel(guiDlg);
        label_robotCoordsValue->setObjectName("label_robotCoordsValue");

        horizontalLayout_top->addWidget(label_robotCoordsValue);

        label_missionStatusTitle = new QLabel(guiDlg);
        label_missionStatusTitle->setObjectName("label_missionStatusTitle");

        horizontalLayout_top->addWidget(label_missionStatusTitle);

        label_missionStatusValue = new QLabel(guiDlg);
        label_missionStatusValue->setObjectName("label_missionStatusValue");

        horizontalLayout_top->addWidget(label_missionStatusValue);

        horizontalSpacer_top = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_top->addItem(horizontalSpacer_top);


        verticalLayout_main->addLayout(horizontalLayout_top);

        horizontalLayout_metrics = new QHBoxLayout();
        horizontalLayout_metrics->setObjectName("horizontalLayout_metrics");
        label_distanceToTargetTitle = new QLabel(guiDlg);
        label_distanceToTargetTitle->setObjectName("label_distanceToTargetTitle");

        horizontalLayout_metrics->addWidget(label_distanceToTargetTitle);

        label_distanceToTargetValue = new QLabel(guiDlg);
        label_distanceToTargetValue->setObjectName("label_distanceToTargetValue");

        horizontalLayout_metrics->addWidget(label_distanceToTargetValue);

        label_etaTitle = new QLabel(guiDlg);
        label_etaTitle->setObjectName("label_etaTitle");

        horizontalLayout_metrics->addWidget(label_etaTitle);

        label_etaValue = new QLabel(guiDlg);
        label_etaValue->setObjectName("label_etaValue");

        horizontalLayout_metrics->addWidget(label_etaValue);

        label_currentSpeedTitle = new QLabel(guiDlg);
        label_currentSpeedTitle->setObjectName("label_currentSpeedTitle");

        horizontalLayout_metrics->addWidget(label_currentSpeedTitle);

        label_currentSpeedValue = new QLabel(guiDlg);
        label_currentSpeedValue->setObjectName("label_currentSpeedValue");

        horizontalLayout_metrics->addWidget(label_currentSpeedValue);

        horizontalSpacer_metrics = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_metrics->addItem(horizontalSpacer_metrics);


        verticalLayout_main->addLayout(horizontalLayout_metrics);

        frame = new QFrame(guiDlg);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        object_prompt = new QTextEdit(frame);
        object_prompt->setObjectName("object_prompt");
        object_prompt->setGeometry(QRect(0, 0, 791, 31));

        verticalLayout_main->addWidget(frame);


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
        object_prompt->setPlaceholderText(QCoreApplication::translate("guiDlg", "Cualquier cosa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
