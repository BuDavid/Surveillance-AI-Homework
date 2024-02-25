#include "photos.h"
#include "./ui_photos.h"

Photos::Photos(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Photos)
{
    ui->setupUi(this);

    file_model = new QFileSystemModel(this);

    QString relative_path = QDir::cleanPath(QDir::currentPath() + "/../Photos/data/pics");
    file_model->setRootPath(relative_path);
    QDir::setCurrent(relative_path);
    QDir directory(relative_path);

    photo_model = new QStandardItemModel(this);

    QStringList filter;
    filter << "*.jpg" << "*.jpeg" << "*.png";
    QStringList picture_files = directory.entryList(filter, QDir::Files);
    foreach(const QString &file_name, picture_files) {
        QString file_path = directory.absoluteFilePath(file_name);
        QPixmap pixmap(file_path);
        QStandardItem *item = new QStandardItem(QIcon(pixmap), NULL);
        item->setData(file_path, Qt::UserRole);
        photo_model->appendRow(item);
    }


    QString file_path = directory.absoluteFilePath(picture_files.first());
    QPixmap pixmap(file_path);

    QFileInfo fileInfo(file_path);
    QString photo_name = "Name: " + fileInfo.baseName();
    int photo_size = fileInfo.size();

    ui->photo_name->setText(photo_name);
    ui->photo_size->setText("Size: " + QString::number(photo_size));

    scene = new QGraphicsScene(this);
    scene->addPixmap(pixmap.scaled(640,330,Qt::KeepAspectRatio));

    ui->display_image->setScene(scene);

    delegate = new ImageDelegate(ui->listView);
    ui->listView->setTextElideMode(Qt::ElideNone);
    ui->listView->setGridSize(QSize(200, 100));
    ui->listView->setIconSize(QSize(200, 100));
    ui->listView->setSpacing(1);
    ui->listView->setDragDropMode(QAbstractItemView::NoDragDrop);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setModel(photo_model);

    connect(ui->listView, &QListView::clicked, this, &Photos::on_item_clicked);
}

void Photos::on_item_clicked(const QModelIndex &index)
{
    QVariant file_name = photo_model->data(index, Qt::UserRole);
    QString image_path = file_name.toString();
    QPixmap pixmap(image_path);

    scene = new QGraphicsScene(this);
    scene->addPixmap(pixmap.scaled(640,330,Qt::KeepAspectRatio));

    QFileInfo fileInfo(image_path);
    QString photo_name = "Name: " + fileInfo.baseName();
    int photo_size = fileInfo.size();

    ui->photo_name->setText(photo_name);
    ui->photo_size->setText("Size: " + QString::number(photo_size));

    ui->display_image->setScene(scene);
}

Photos::~Photos()
{
    delete ui;
    delete pixmap_item;
    delete delegate;
    delete photo_model;
    delete file_model;
}
