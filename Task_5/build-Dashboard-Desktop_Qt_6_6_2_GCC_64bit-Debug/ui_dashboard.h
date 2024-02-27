/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QFrame *bar_frame;
    QFrame *line_frame;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *closing_price;
    QLCDNumber *high_price;
    QLCDNumber *low_price;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(545, 408);
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName("radioButton");

        verticalLayout_3->addWidget(radioButton);

        radioButton_4 = new QRadioButton(frame);
        radioButton_4->setObjectName("radioButton_4");

        verticalLayout_3->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(frame);
        radioButton_3->setObjectName("radioButton_3");

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName("radioButton_2");

        verticalLayout_3->addWidget(radioButton_2);


        gridLayout->addWidget(frame, 0, 1, 1, 1);

        bar_frame = new QFrame(centralwidget);
        bar_frame->setObjectName("bar_frame");
        bar_frame->setFrameShape(QFrame::StyledPanel);
        bar_frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(bar_frame, 1, 1, 1, 1);

        line_frame = new QFrame(centralwidget);
        line_frame->setObjectName("line_frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_frame->sizePolicy().hasHeightForWidth());
        line_frame->setSizePolicy(sizePolicy1);
        line_frame->setFrameShape(QFrame::StyledPanel);
        line_frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(line_frame, 0, 0, 1, 1);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_4);
        horizontalLayout->setObjectName("horizontalLayout");
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_5);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(frame_5);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_3 = new QLabel(frame_5);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(frame_5);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);


        horizontalLayout->addWidget(frame_5);

        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        closing_price = new QLCDNumber(frame_6);
        closing_price->setObjectName("closing_price");

        verticalLayout_2->addWidget(closing_price);

        high_price = new QLCDNumber(frame_6);
        high_price->setObjectName("high_price");

        verticalLayout_2->addWidget(high_price);

        low_price = new QLCDNumber(frame_6);
        low_price->setObjectName("low_price");

        verticalLayout_2->addWidget(low_price);


        horizontalLayout->addWidget(frame_6);


        gridLayout->addWidget(frame_4, 1, 0, 1, 1);

        Dashboard->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Dashboard);
        statusbar->setObjectName("statusbar");
        Dashboard->setStatusBar(statusbar);

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        radioButton->setText(QCoreApplication::translate("Dashboard", "Update every 5 min.", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Dashboard", "Update every 15 min.", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Dashboard", "Update every 30 min.", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Dashboard", "Update every 60 min.", nullptr));
        label->setText(QCoreApplication::translate("Dashboard", "Closing", nullptr));
        label_3->setText(QCoreApplication::translate("Dashboard", "High", nullptr));
        label_2->setText(QCoreApplication::translate("Dashboard", "Low", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
