#include "annatto.h"
#include "ui_annatto.h"

Annatto::Annatto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Annatto)
{
    ui -> setupUi(this);

    add_dialog = new QDialog(this);

    selected_recipe = NULL;

    was_recipe_changed = 0;
    add_change = 0;

    dialog_line_edit = new QLineEdit(add_dialog);
    dialog_button = new QPushButton("Ok", add_dialog);

    dialog_layout = new QVBoxLayout(add_dialog);
    dialog_layout -> addWidget(dialog_line_edit);
    dialog_layout -> addWidget(dialog_button);

    image_layout = new QVBoxLayout(ui -> image_frame);

    image_layout->setAlignment(Qt::AlignCenter);
    image_layout->setContentsMargins(0, 0, 0, 0);
    image_layout->setStretchFactor(ui->image_display, 1);
    ui -> image_display -> setScaledContents(true);

    connect(dialog_button, &QPushButton::clicked, this, &Annatto::add_input);

    get_data_from_file();
    connect(QCoreApplication::instance(), &QCoreApplication::aboutToQuit, this, &Annatto::save_data_to_file);

    if (ui -> recipe_list -> count() > 0) {
        ui -> recipe_list -> setCurrentRow(0);
        Q_EMIT ui->recipe_list->itemClicked(ui -> recipe_list -> item(0));
    }
}

void Annatto::get_data_from_file()
{
    QString recipe_dir = QDir::currentPath() + "/../Annatto/data/recipe_info.txt";
    QFile recipe_file(recipe_dir);

    if (!recipe_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could'nt open the file";
        return;
    }

    QTextStream in(&recipe_file);
    QString text = in.readAll();
    QStringList lines = text.split("<delE>");

    for (int i = 0; i < lines.size()-1; i++) {
        QStringList parts = lines[i].split("<del>");
        ui -> recipe_list -> addItem(parts[0]);
        recipe_info.insert(parts[0], parts[1]);
    }

    recipe_file.close();
}

void Annatto::save_data_to_file()
{
    save_recipe_text();

    QString recipe_dir = QDir::currentPath() + "/../Annatto/data/recipe_info.txt";
    QFile recipe_file(recipe_dir);

    if (!recipe_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could'nt open the file";
        return;
    }
    QTextStream out(&recipe_file);
    for (int i = 0; i < ui -> recipe_list -> count(); i++) {
        QString text = ui -> recipe_list -> item(i) -> text();
        out << text << "<del>" << recipe_info.value(text) << "<delE>";
    }

    recipe_file.close();
}

Annatto::~Annatto()
{
    delete image_layout;
    delete dialog_line_edit;
    delete dialog_button;
    delete dialog_layout;
    delete add_dialog;
    delete ui;
}

void Annatto::save_recipe_text()
{
    if (selected_recipe.compare("NULL") == 0 || was_recipe_changed == 0) {
        return;
    }

    QString text = ui -> recipe_display -> toPlainText();

    if (text.isEmpty()) {
        recipe_info[selected_recipe] = "MY_NULL";
        was_recipe_changed = 0;
    }

    recipe_info[selected_recipe] = text;
    was_recipe_changed = 0;
}

void Annatto::on_lineEdit_textChanged(const QString &arg1)
{
    for (int i = 0; i < ui -> recipe_list -> count(); i++){
        QString item = ui -> recipe_list -> item(i) -> text();

        if (item.startsWith(arg1) || arg1.isEmpty()) {
            ui -> recipe_list -> item(i) -> setHidden(false);
            continue;
        }
        ui -> recipe_list -> item(i) -> setHidden(true);
    }
}

void Annatto::on_recipe_list_itemClicked(QListWidgetItem *item)
{
    save_recipe_text();

    selected_recipe = item -> text();

    if (recipe_info.value(selected_recipe).compare("MY_NULL") == 0) {
        ui -> recipe_display -> setText("");
        return;
    }
    ui -> recipe_display -> setText(recipe_info.value(selected_recipe));

    QString pictures_dir = QDir::currentPath() + "/../Annatto/data/pictures/";
    QString new_path = pictures_dir + selected_recipe + ".png";
    QPixmap image(new_path);
    if (!image.isNull()) {
        ui -> image_display -> setPixmap(image);
    } else {
        QPixmap image(pictures_dir + "default.png");
        ui -> image_display -> setPixmap(image);
    }
}

void Annatto::on_delete_2_clicked()
{
    if (selected_recipe.compare("NULL") == 0) {
        return;
    }

    recipe_info.remove(selected_recipe);

    QListWidgetItem *item = ui -> recipe_list -> currentItem();

    if (item) {
        int index = ui -> recipe_list -> row(item);
        QListWidgetItem *removed_item = ui -> recipe_list -> takeItem(index);
        delete removed_item;
    } else {
        qDebug() << "No item selected.";
    }

    selected_recipe = NULL;
}

void Annatto::on_recipe_display_textChanged()
{
    was_recipe_changed = 1;
}

void Annatto::add_input() {
    QString text = dialog_line_edit -> text();

    if ((text.compare("default")) == 0 || text.compare("") == 0) {
        dialog_line_edit -> setStyleSheet("background-color: red;");
        return;
    }

    for (int i = 0; i < ui -> recipe_list -> count(); i++) {
        if ((ui -> recipe_list -> item(i) -> text().compare(text)) == 0) {
            dialog_line_edit -> setStyleSheet("background-color: red;");
            return;
        }
    }
    if (add_change) {
        ui -> recipe_list -> addItem(text);
        recipe_info.insert(text, "MY_NULL");
    } else {
        QString value = recipe_info.value(selected_recipe);

        recipe_info.remove(selected_recipe);

        recipe_info.insert(text, value);

        QList<QListWidgetItem*> items = ui->recipe_list->findItems(selected_recipe, Qt::MatchExactly);
        if (!items.isEmpty()) {
            items.first()->setText(text);
        }

        selected_recipe = text;
    }

    dialog_line_edit -> clear();
    dialog_line_edit -> setStyleSheet("");
    add_dialog->close();
}

void Annatto::on_add_new_clicked()
{
    add_change = 1;
    add_dialog -> exec();
}

void Annatto::on_change_name_clicked()
{
    if ((selected_recipe.compare("NULL")) == 0) {
        return;
    }
    add_change = 0;
    add_dialog -> exec();
}

void Annatto::on_add_photo_clicked()
{
    if ((selected_recipe.compare("NULL")) == 0) {
        return;
    }

    QString pictures_dir = QDir::currentPath() + "/../Annatto/data/pictures/";
    QString image_path = QFileDialog::getOpenFileName(nullptr, tr("Select Image"), pictures_dir, tr("Image Files (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if (image_path.isEmpty()) {
        qDebug() << "Error:" << image_path;
    }

    QString new_path = pictures_dir + selected_recipe + ".png";
    if (new_path == image_path) {
        return;
    }

    if (!(QFile::rename(image_path, new_path))) {
        qDebug() << "Failed to rename file.";
        return;
    }

    QPixmap image(new_path);
    if (!image.isNull()) {
        ui -> image_display -> setPixmap(image);
    } else {
        qDebug() << "Failed to load image from path:" << new_path;
    }
}
