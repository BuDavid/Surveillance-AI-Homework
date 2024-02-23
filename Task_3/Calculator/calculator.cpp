#include "calculator.h"
#include "ui_calculator.h"

double val_buffer = 0.0;
bool div_button = false;
bool mul_button = false;
bool add_button = false;
bool sub_button = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
	ui->Display->setText(QString::number(val_buffer));
	QPushButton* num_buttons[10];
	for (int i = 0; i < 10; i++) {
        QString button_name = "Button" + QString::number(i);
		num_buttons[i] = Calculator::findChild<QPushButton*>(button_name);
		connect(num_buttons[i], SIGNAL(released()), this, SLOT(num_pressed()));
	}
	connect(ui->ButtonMUL, SIGNAL(released()), this, SLOT(operation_pressed()));
	connect(ui->ButtonDIV, SIGNAL(released()), this, SLOT(operation_pressed()));
	connect(ui->ButtonADD, SIGNAL(released()), this, SLOT(operation_pressed()));
	connect(ui->ButtonSUB, SIGNAL(released()), this, SLOT(operation_pressed()));
	connect(ui->ButtonSGN, SIGNAL(released()), this, SLOT(sign_change_pressed()));
	connect(ui->ButtonEQ, SIGNAL(released()), this, SLOT(equal_pressed()));
	connect(ui->ButtonAC, SIGNAL(released()), this, SLOT(clear_pressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::operation_pressed()
{
	div_button = false;
	mul_button = false;
	add_button = false;
	sub_button = false;

	QPushButton* button = (QPushButton*) sender();
    QString _operation = button->text();

	QString display_val = ui->Display->text();
    val_buffer = display_val.toDouble();

    if (QString::compare(_operation, "/", Qt::CaseInsensitive) == 0) {
			div_button = true;
    } else if (QString::compare(_operation, "*", Qt::CaseInsensitive) == 0) {
    ui->Display->setText(_operation);
			mul_button = true;
    } else if (QString::compare(_operation, "+", Qt::CaseInsensitive) == 0) {
    ui->Display->setText(_operation);
        add_button = true;
    } else {
    ui->Display->setText(_operation);
        sub_button = true;
    }
    ui->Display->setText(_operation);
}

void Calculator::num_pressed()
{
	QPushButton* button = (QPushButton*) sender();
	QString button_val = button->text();
	QString display_val = ui->Display->text();

    if (QString::compare(display_val, "error", Qt::CaseInsensitive) == 0) {
        ui->Display->setText(button_val);
        return;
    }

    if ((display_val.toDouble() == 0) || (display_val.toDouble() == 0.0)) {
		ui->Display->setText(button_val);
	} else {
		QString new_val = display_val + button_val;
		double new_val_num = new_val.toDouble();
		ui->Display->setText(QString::number(new_val_num, 'g', 16));
	}

}

void Calculator::equal_pressed() 
{
    double ans = 0.0;
	QString display_val = ui->Display->text();
	double display_val_num = display_val.toDouble();

	if (div_button) {
		if (display_val_num) {
			ans = val_buffer / display_val_num;
		} else {
            ui->Display->setText("error");
			val_buffer = 0;
			return;
		}
	} else if (mul_button) {
		ans = val_buffer * display_val_num;
	} else if (add_button) {
		ans = val_buffer + display_val_num;
	} else if (sub_button) {
		ans = val_buffer - display_val_num;
	} else {
		return;
	}

    ui->Display->setText(QString::number(ans));
}

void Calculator::sign_change_pressed() 
{
	QString display_val = ui->Display->text();

	double new_val_num = display_val.toDouble();
	new_val_num = -new_val_num;
	ui->Display->setText(QString::number(new_val_num, 'g', 16));
}

void Calculator::clear_pressed() 
{
	div_button = false;
	mul_button = false;
	add_button = false;
	sub_button = false;
	val_buffer = 0;
    ui->Display->setText("");
}

