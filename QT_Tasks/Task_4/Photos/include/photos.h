#ifndef PHOTOS_H
#define PHOTOS_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDir>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

#include "img_delegate.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Photos;
}
QT_END_NAMESPACE

class Photos : public QMainWindow
{
    Q_OBJECT

public:
    Photos(QWidget *parent = nullptr);
    void on_item_clicked(const QModelIndex &index);
    ~Photos();

private:
    Ui::Photos *ui;
    QFileSystemModel *file_model;
    QStandardItemModel *photo_model;
    ImageDelegate *delegate;
    QGraphicsPixmapItem *pixmap_item;
    QGraphicsScene *scene;
};
#endif // PHOTOS_H
