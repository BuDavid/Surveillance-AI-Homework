#ifndef IMG_DELEGATE_H
#define IMG_DELEGATE_H

#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStyledItemDelegate>
#include <QPixmap>
#include <QPainter>

class ImageDelegate : public QStyledItemDelegate
{
public:
    ImageDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // IMG_DELEGATE_H
