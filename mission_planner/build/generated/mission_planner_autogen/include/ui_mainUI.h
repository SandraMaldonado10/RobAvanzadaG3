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
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelX;
    QLabel *labelY;
    QLabel *labelTheta;
    QSpacerItem *horizontalSpacer;
    QLabel *labelLength;
    QLCDNumber *lcdNumber_length;
    QLabel *labelElapsed;
    QLCDNumber *lcdNumber_elapsed;
    QFrame *frame;

    void setupUi(QWidget *guiDlg)
    {
        if (guiDlg->objectName().isEmpty())
            guiDlg->setObjectName("guiDlg");
        guiDlg->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(guiDlg);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        labelX = new QLabel(guiDlg);
        labelX->setObjectName("labelX");
        labelX->setMinimumWidth(150);

        horizontalLayout->addWidget(labelX);

        labelY = new QLabel(guiDlg);
        labelY->setObjectName("labelY");
        labelY->setMinimumWidth(150);

        horizontalLayout->addWidget(labelY);

        labelTheta = new QLabel(guiDlg);
        labelTheta->setObjectName("labelTheta");
        labelTheta->setMinimumWidth(150);

        horizontalLayout->addWidget(labelTheta);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelLength = new QLabel(guiDlg);
        labelLength->setObjectName("labelLength");
        labelLength->setMinimumWidth(120);

        horizontalLayout->addWidget(labelLength);

        lcdNumber_length = new QLCDNumber(guiDlg);
        lcdNumber_length->setObjectName("lcdNumber_length");
        lcdNumber_length->setMaximumWidth(100);
        lcdNumber_length->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcdNumber_length);

        labelElapsed = new QLabel(guiDlg);
        labelElapsed->setObjectName("labelElapsed");
        labelElapsed->setMinimumWidth(80);

        horizontalLayout->addWidget(labelElapsed);

        lcdNumber_elapsed = new QLCDNumber(guiDlg);
        lcdNumber_elapsed->setObjectName("lcdNumber_elapsed");
        lcdNumber_elapsed->setMaximumWidth(100);
        lcdNumber_elapsed->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(lcdNumber_elapsed);


        verticalLayout->addLayout(horizontalLayout);

        frame = new QFrame(guiDlg);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(guiDlg);

        QMetaObject::connectSlotsByName(guiDlg);
    } // setupUi

    void retranslateUi(QWidget *guiDlg)
    {
        guiDlg->setWindowTitle(QCoreApplication::translate("guiDlg", "mission_planner", nullptr));
        labelX->setText(QCoreApplication::translate("guiDlg", "X: 0.00", nullptr));
        labelY->setText(QCoreApplication::translate("guiDlg", "Y: 0.00", nullptr));
        labelTheta->setText(QCoreApplication::translate("guiDlg", "Theta: 0.00", nullptr));
        labelLength->setText(QCoreApplication::translate("guiDlg", "Path Length (m):", nullptr));
        labelElapsed->setText(QCoreApplication::translate("guiDlg", "Time (s):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiDlg: public Ui_guiDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
