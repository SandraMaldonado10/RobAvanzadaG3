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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiDlg
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelLength;
    QLCDNumber *lcdNumber_length;
    QLabel *labelElapsed;
    QLCDNumber *lcdNumber_elapsed;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTheta;
    QLabel *labelX;
    QLabel *labelY;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *infoLayout;
    QHBoxLayout *statusLayout;
    QLabel *statusLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *distLabel;
    QLCDNumber *lcdNumber_Dist;
    QHBoxLayout *speedLayout;
    QLabel *speedLabel;
    QLCDNumber *lcdNumber_Speed;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName("guiDlg");
        guiDlg->resize(1019, 600);
        verticalLayoutWidget_2 = new QWidget(guiDlg);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 10, 1011, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelLength = new QLabel(verticalLayoutWidget_2);
        labelLength->setObjectName("labelLength");

        horizontalLayout_3->addWidget(labelLength);

        lcdNumber_length = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_length->setObjectName("lcdNumber_length");
        lcdNumber_length->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcdNumber_length);

        labelElapsed = new QLabel(verticalLayoutWidget_2);
        labelElapsed->setObjectName("labelElapsed");

        horizontalLayout_3->addWidget(labelElapsed);

        lcdNumber_elapsed = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_elapsed->setObjectName("lcdNumber_elapsed");
        lcdNumber_elapsed->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(lcdNumber_elapsed);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        labelTheta = new QLabel(verticalLayoutWidget_2);
        labelTheta->setObjectName("labelTheta");

        horizontalLayout_3->addWidget(labelTheta);

        labelX = new QLabel(verticalLayoutWidget_2);
        labelX->setObjectName("labelX");

        horizontalLayout_3->addWidget(labelX);

        labelY = new QLabel(verticalLayoutWidget_2);
        labelY->setObjectName("labelY");

        horizontalLayout_3->addWidget(labelY);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(verticalLayoutWidget_2);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame);

        infoLayout = new QVBoxLayout();
        infoLayout->setObjectName("infoLayout");
        statusLayout = new QHBoxLayout();
        statusLayout->setObjectName("statusLayout");
        statusLabel = new QLabel(verticalLayoutWidget_2);
        statusLabel->setObjectName("statusLabel");

        statusLayout->addWidget(statusLabel);


        infoLayout->addLayout(statusLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        distLabel = new QLabel(verticalLayoutWidget_2);
        distLabel->setObjectName("distLabel");

        horizontalLayout->addWidget(distLabel);

        lcdNumber_Dist = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_Dist->setObjectName("lcdNumber_Dist");

        horizontalLayout->addWidget(lcdNumber_Dist);


        infoLayout->addLayout(horizontalLayout);

        speedLayout = new QHBoxLayout();
        speedLayout->setObjectName("speedLayout");
        speedLabel = new QLabel(verticalLayoutWidget_2);
        speedLabel->setObjectName("speedLabel");

        speedLayout->addWidget(speedLabel);

        lcdNumber_Speed = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_Speed->setObjectName("lcdNumber_Speed");

        speedLayout->addWidget(lcdNumber_Speed);


        infoLayout->addLayout(speedLayout);


        horizontalLayout_2->addLayout(infoLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(guiDlg);

        QMetaObject::connectSlotsByName(guiDlg);
    } // setupUi

    void retranslateUi(QWidget *guiDlg)
    {
        guiDlg->setWindowTitle(QCoreApplication::translate("guiDlg", "mission_planner", nullptr));
        labelLength->setText(QCoreApplication::translate("guiDlg", "Path Length (m):", nullptr));
        labelElapsed->setText(QCoreApplication::translate("guiDlg", "Time (s):", nullptr));
        labelTheta->setText(QCoreApplication::translate("guiDlg", "Theta: 0.00", nullptr));
        labelX->setText(QCoreApplication::translate("guiDlg", "X: 0.00", nullptr));
        labelY->setText(QCoreApplication::translate("guiDlg", "Y: 0.00", nullptr));
        statusLabel->setText(QCoreApplication::translate("guiDlg", "Status", nullptr));
        distLabel->setText(QCoreApplication::translate("guiDlg", "Distance", nullptr));
        speedLabel->setText(QCoreApplication::translate("guiDlg", "Speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
