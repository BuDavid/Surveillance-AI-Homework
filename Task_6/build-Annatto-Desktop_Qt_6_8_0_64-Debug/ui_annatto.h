/********************************************************************************
** Form generated from reading UI file 'annatto.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNATTO_H
#define UI_ANNATTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Annatto
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *recipe_list;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_4;
    QPushButton *add_photo;
    QPushButton *delete_2;
    QPushButton *add_new;
    QPushButton *change_name;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *image_frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *image_display;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *recipe_display;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Annatto)
    {
        if (Annatto->objectName().isEmpty())
            Annatto->setObjectName("Annatto");
        Annatto->resize(624, 374);
        centralwidget = new QWidget(Annatto);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName("frame_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        recipe_list = new QListWidget(frame_4);
        recipe_list->setObjectName("recipe_list");
        sizePolicy1.setHeightForWidth(recipe_list->sizePolicy().hasHeightForWidth());
        recipe_list->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(recipe_list);

        frame_7 = new QFrame(frame_4);
        frame_7->setObjectName("frame_7");
        sizePolicy.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy);
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_7);
        verticalLayout_4->setObjectName("verticalLayout_4");
        add_photo = new QPushButton(frame_7);
        add_photo->setObjectName("add_photo");
        sizePolicy.setHeightForWidth(add_photo->sizePolicy().hasHeightForWidth());
        add_photo->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(add_photo);

        delete_2 = new QPushButton(frame_7);
        delete_2->setObjectName("delete_2");
        sizePolicy.setHeightForWidth(delete_2->sizePolicy().hasHeightForWidth());
        delete_2->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(delete_2);

        add_new = new QPushButton(frame_7);
        add_new->setObjectName("add_new");
        sizePolicy.setHeightForWidth(add_new->sizePolicy().hasHeightForWidth());
        add_new->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(add_new);

        change_name = new QPushButton(frame_7);
        change_name->setObjectName("change_name");
        sizePolicy.setHeightForWidth(change_name->sizePolicy().hasHeightForWidth());
        change_name->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(change_name);


        horizontalLayout_3->addWidget(frame_7);


        verticalLayout->addWidget(frame_4);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy3);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        image_frame = new QFrame(frame_2);
        image_frame->setObjectName("image_frame");
        sizePolicy1.setHeightForWidth(image_frame->sizePolicy().hasHeightForWidth());
        image_frame->setSizePolicy(sizePolicy1);
        image_frame->setFrameShape(QFrame::StyledPanel);
        image_frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(image_frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        image_display = new QLabel(image_frame);
        image_display->setObjectName("image_display");
        sizePolicy1.setHeightForWidth(image_display->sizePolicy().hasHeightForWidth());
        image_display->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(image_display);


        verticalLayout_2->addWidget(image_frame);

        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName("frame_6");
        sizePolicy1.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy1);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        recipe_display = new QTextEdit(frame_6);
        recipe_display->setObjectName("recipe_display");
        sizePolicy1.setHeightForWidth(recipe_display->sizePolicy().hasHeightForWidth());
        recipe_display->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(recipe_display);


        verticalLayout_2->addWidget(frame_6);


        horizontalLayout->addWidget(frame_2);

        Annatto->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Annatto);
        statusbar->setObjectName("statusbar");
        Annatto->setStatusBar(statusbar);

        retranslateUi(Annatto);

        QMetaObject::connectSlotsByName(Annatto);
    } // setupUi

    void retranslateUi(QMainWindow *Annatto)
    {
        Annatto->setWindowTitle(QCoreApplication::translate("Annatto", "Annatto", nullptr));
        add_photo->setText(QCoreApplication::translate("Annatto", "Photo", nullptr));
        delete_2->setText(QCoreApplication::translate("Annatto", "Delete", nullptr));
        add_new->setText(QCoreApplication::translate("Annatto", "Add", nullptr));
        change_name->setText(QCoreApplication::translate("Annatto", "Change name", nullptr));
        image_display->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Annatto: public Ui_Annatto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNATTO_H
