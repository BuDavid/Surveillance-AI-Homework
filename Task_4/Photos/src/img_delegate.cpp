#include "img_delegate.h"

void ImageDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid() && index.data(Qt::DecorationRole).canConvert<QPixmap>()) {
        QPixmap pixmap = qvariant_cast<QPixmap>(index.data(Qt::DecorationRole));
        painter->drawPixmap(option.rect, pixmap.scaled(option.rect.size(), Qt::KeepAspectRatio));
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }

    QRect rect = option.rect;
    QPen pen;

    pen.setColor(Qt::black);
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    painter->drawRect(rect);
}

QSize ImageDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid() && index.data(Qt::DecorationRole).canConvert<QPixmap>()) {
        QPixmap pixmap = qvariant_cast<QPixmap>(index.data(Qt::DecorationRole));
        return pixmap.size();
    }
    return QStyledItemDelegate::sizeHint(option, index);
}
