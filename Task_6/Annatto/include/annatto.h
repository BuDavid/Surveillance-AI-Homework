#ifndef ANNATTO_H
#define ANNATTO_H

#include <QMainWindow>
#include <QtWidgets>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDialog>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class Annatto;
}
QT_END_NAMESPACE

class Annatto : public QMainWindow
{
    Q_OBJECT

public:
    Annatto(QWidget *parent = nullptr);
    void add_input();
    ~Annatto();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_recipe_list_itemClicked(QListWidgetItem *item);

    void on_delete_2_clicked();

    void on_recipe_display_textChanged();

    void on_add_new_clicked();

    void on_change_name_clicked();

    void on_add_photo_clicked();

private:
    void get_data_from_file();
    void save_data_to_file();
    void save_recipe_text();

    Ui::Annatto *ui;
    QDialog *add_dialog;
    QLineEdit *dialog_line_edit;
    QPushButton *dialog_button;
    QVBoxLayout *dialog_layout;
    QVBoxLayout *image_layout;
    QMap<QString, QString> recipe_info;
    QString selected_recipe;
    bool was_recipe_changed;
    bool add_change;
};
#endif // ANNATTO_H
