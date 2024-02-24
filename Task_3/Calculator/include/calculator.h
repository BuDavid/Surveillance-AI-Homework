#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
	double val_buffer = 0.0;
	bool div_button = false;
	bool mul_button = false;
	bool add_button = false;
	bool sub_button = false;

private slots:
	void num_pressed();
    void operation_pressed();
    void sign_change_pressed();
    void clear_pressed();
    void equal_pressed();

};

#endif // CALCULATOR_H
