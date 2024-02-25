/********************************************************************************
** Form generated from reading UI file 'photos.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHOTOS_H
#define UI_PHOTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Photos
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *display_image;
    QVBoxLayout *verticalLayout;
    QLabel *photo_name;
    QLabel *photo_size;
    QListView *listView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Photos)
    {
        if (Photos->objectName().isEmpty())
            Photos->setObjectName("Photos");
        Photos->resize(771, 571);
        Photos->setAcceptDrops(false);
        centralwidget = new QWidget(Photos);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        display_image = new QGraphicsView(centralwidget);
        display_image->setObjectName("display_image");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(display_image->sizePolicy().hasHeightForWidth());
        display_image->setSizePolicy(sizePolicy);
        display_image->setInteractive(true);

        gridLayout->addWidget(display_image, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        photo_name = new QLabel(centralwidget);
        photo_name->setObjectName("photo_name");

        verticalLayout->addWidget(photo_name);

        photo_size = new QLabel(centralwidget);
        photo_size->setObjectName("photo_size");

        verticalLayout->addWidget(photo_size);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setFlow(QListView::TopToBottom);
        listView->setProperty("isWrapping", QVariant(true));
        listView->setResizeMode(QListView::Adjust);
        listView->setViewMode(QListView::IconMode);

        gridLayout->addWidget(listView, 1, 0, 1, 2);

        Photos->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Photos);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 771, 22));
        Photos->setMenuBar(menubar);
        statusbar = new QStatusBar(Photos);
        statusbar->setObjectName("statusbar");
        Photos->setStatusBar(statusbar);

        retranslateUi(Photos);

        QMetaObject::connectSlotsByName(Photos);
    } // setupUi

    void retranslateUi(QMainWindow *Photos)
    {
        Photos->setWindowTitle(QCoreApplication::translate("Photos", "Photos", nullptr));
        photo_name->setText(QString());
        photo_size->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Photos: public Ui_Photos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHOTOS_H
