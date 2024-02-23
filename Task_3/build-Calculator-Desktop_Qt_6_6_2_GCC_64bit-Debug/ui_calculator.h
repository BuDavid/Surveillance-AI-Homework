/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Button7;
    QPushButton *Button0;
    QPushButton *Button5;
    QPushButton *ButtonEQ;
    QLineEdit *Display;
    QPushButton *ButtonDIV;
    QPushButton *ButtonADD;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *Button1;
    QPushButton *ButtonSGN;
    QPushButton *Button4;
    QPushButton *ButtonMUL;
    QPushButton *Button3;
    QPushButton *Button2;
    QPushButton *ButtonAC;
    QPushButton *ButtonSUB;
    QPushButton *Button6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName("Calculator");
        Calculator->resize(245, 303);
        Calculator->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: #07475a;\n"
"}"));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #07475a;\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        Button7 = new QPushButton(centralwidget);
        Button7->setObjectName("Button7");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button7->sizePolicy().hasHeightForWidth());
        Button7->setSizePolicy(sizePolicy);
        Button7->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button7, 5, 1, 1, 1);

        Button0 = new QPushButton(centralwidget);
        Button0->setObjectName("Button0");
        sizePolicy.setHeightForWidth(Button0->sizePolicy().hasHeightForWidth());
        Button0->setSizePolicy(sizePolicy);
        Button0->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button0, 2, 0, 1, 1);

        Button5 = new QPushButton(centralwidget);
        Button5->setObjectName("Button5");
        sizePolicy.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy);
        Button5->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button5, 4, 1, 1, 1);

        ButtonEQ = new QPushButton(centralwidget);
        ButtonEQ->setObjectName("ButtonEQ");
        sizePolicy.setHeightForWidth(ButtonEQ->sizePolicy().hasHeightForWidth());
        ButtonEQ->setSizePolicy(sizePolicy);
        ButtonEQ->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonEQ, 1, 2, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName("Display");
        sizePolicy.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu Mono")});
        font.setPointSize(18);
        font.setBold(true);
        Display->setFont(font);
        Display->setAutoFillBackground(false);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: #07475a;\n"
"	border: solid #07475a;\n"
"	color: white;\n"
"}"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Display, 0, 0, 1, 3);

        ButtonDIV = new QPushButton(centralwidget);
        ButtonDIV->setObjectName("ButtonDIV");
        sizePolicy.setHeightForWidth(ButtonDIV->sizePolicy().hasHeightForWidth());
        ButtonDIV->setSizePolicy(sizePolicy);
        ButtonDIV->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonDIV, 5, 2, 1, 1);

        ButtonADD = new QPushButton(centralwidget);
        ButtonADD->setObjectName("ButtonADD");
        sizePolicy.setHeightForWidth(ButtonADD->sizePolicy().hasHeightForWidth());
        ButtonADD->setSizePolicy(sizePolicy);
        ButtonADD->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonADD, 3, 2, 1, 1);

        Button8 = new QPushButton(centralwidget);
        Button8->setObjectName("Button8");
        sizePolicy.setHeightForWidth(Button8->sizePolicy().hasHeightForWidth());
        Button8->setSizePolicy(sizePolicy);
        Button8->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button8, 6, 0, 1, 1);

        Button9 = new QPushButton(centralwidget);
        Button9->setObjectName("Button9");
        sizePolicy.setHeightForWidth(Button9->sizePolicy().hasHeightForWidth());
        Button9->setSizePolicy(sizePolicy);
        Button9->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button9, 6, 1, 1, 1);

        Button1 = new QPushButton(centralwidget);
        Button1->setObjectName("Button1");
        sizePolicy.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy);
        Button1->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button1, 2, 1, 1, 1);

        ButtonSGN = new QPushButton(centralwidget);
        ButtonSGN->setObjectName("ButtonSGN");
        sizePolicy.setHeightForWidth(ButtonSGN->sizePolicy().hasHeightForWidth());
        ButtonSGN->setSizePolicy(sizePolicy);
        ButtonSGN->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonSGN, 1, 1, 1, 1);

        Button4 = new QPushButton(centralwidget);
        Button4->setObjectName("Button4");
        sizePolicy.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy);
        Button4->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button4, 4, 0, 1, 1);

        ButtonMUL = new QPushButton(centralwidget);
        ButtonMUL->setObjectName("ButtonMUL");
        sizePolicy.setHeightForWidth(ButtonMUL->sizePolicy().hasHeightForWidth());
        ButtonMUL->setSizePolicy(sizePolicy);
        ButtonMUL->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonMUL, 4, 2, 1, 1);

        Button3 = new QPushButton(centralwidget);
        Button3->setObjectName("Button3");
        sizePolicy.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy);
        Button3->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button3, 3, 1, 1, 1);

        Button2 = new QPushButton(centralwidget);
        Button2->setObjectName("Button2");
        sizePolicy.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy);
        Button2->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button2, 3, 0, 1, 1);

        ButtonAC = new QPushButton(centralwidget);
        ButtonAC->setObjectName("ButtonAC");
        sizePolicy.setHeightForWidth(ButtonAC->sizePolicy().hasHeightForWidth());
        ButtonAC->setSizePolicy(sizePolicy);
        ButtonAC->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonAC, 1, 0, 1, 1);

        ButtonSUB = new QPushButton(centralwidget);
        ButtonSUB->setObjectName("ButtonSUB");
        ButtonSUB->setEnabled(true);
        sizePolicy.setHeightForWidth(ButtonSUB->sizePolicy().hasHeightForWidth());
        ButtonSUB->setSizePolicy(sizePolicy);
        ButtonSUB->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a4307;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(119, 118, 123);\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ButtonSUB, 2, 2, 1, 1);

        Button6 = new QPushButton(centralwidget);
        Button6->setObjectName("Button6");
        sizePolicy.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy);
        Button6->setStyleSheet(QString::fromUtf8("QPushButton \n"
"{\n"
"	background-color: #5a071d;\n"
"	border: 1px #5a071d;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: rgb(165, 29, 45);\n"
"	border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(Button6, 5, 0, 1, 1);

        Calculator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calculator);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 245, 22));
        Calculator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName("statusbar");
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        Button7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        Button0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        Button5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        ButtonEQ->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        Display->setText(QCoreApplication::translate("Calculator", "0.0", nullptr));
        ButtonDIV->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        ButtonADD->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        Button8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        Button9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        Button1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        ButtonSGN->setText(QCoreApplication::translate("Calculator", "-/+", nullptr));
        Button4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        ButtonMUL->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        Button3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        Button2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        ButtonAC->setText(QCoreApplication::translate("Calculator", "AC", nullptr));
        ButtonSUB->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        Button6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
