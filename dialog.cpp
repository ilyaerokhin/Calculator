#include "dialog.h"
#include "ui_dialog.h"
#include "calculator.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setText("0");
    calc = new Calculator();
    setFocus();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setNumber(int n)
{
    if(calc->get_Next_Operand())
    {
        ui->textEdit->setText(QString::number(n));
        calc->NextDown();
    }
    else
    {
        ui->textEdit->setText(ui->textEdit->toPlainText() + QString::number(n));
    }
    calc->set_current(ui->textEdit->toPlainText().toDouble());
}

void Dialog::singleDelete()
{
    if(ui->textEdit->toPlainText().length() == 1)
    {
        ui->textEdit->setText("0");
        calc->NextUp();
        calc->set_current(ui->textEdit->toPlainText().toDouble());
    }
    else
    {
        ui->textEdit->setText(ui->textEdit->toPlainText().mid(0,ui->textEdit->toPlainText().length()-1));
    }
    calc->set_current(ui->textEdit->toPlainText().toDouble());
}

void Dialog::Point()
{
    if(calc->get_Next_Operand())
    {
        calc->NextDown();
    }

    if(!ui->textEdit->toPlainText().contains("."))
    {
        ui->textEdit->setText(ui->textEdit->toPlainText() + ".");
    }

    if(ui->textEdit->toPlainText().compare("0.") == 0)
    {
        calc->NextDown();
        calc->set_current(0);
    }
}

void Dialog::plus()
{
    if (calc->check_flags() == 0)
    {
        ui->textEdit->setText(QString::number(calc->task()));
    }

    calc->set_saved(ui->textEdit->toPlainText().toDouble());
    calc->set_current(0);
    calc->NextUp();
    calc->PlusUp();
}

void Dialog::minus()
{
    if (calc->check_flags() == 0)
    {
        ui->textEdit->setText(QString::number(calc->task()));
    }

    calc->set_saved(ui->textEdit->toPlainText().toDouble());
    calc->set_current(0);
    calc->NextUp();
    calc->MinusUp();
}

void Dialog::allDelete()
{
    ui->textEdit->setText("0");
    calc->NextUp();
    calc->set_current(0);
    calc->set_saved(0);
}

void Dialog::ravno()
{
    if (calc->check_flags() == -1)
    {
        calc->MinusDown();
        calc->PlusDown();
        return;
    }
    else
    {
        ui->textEdit->setText(QString::number(calc->task()));
        calc->NextUp();
    }
}

void Dialog::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
        case Qt::Key_0:
            Dialog::setNumber(0);
            break;
        case Qt::Key_1:
            Dialog::setNumber(1);
            break;
        case Qt::Key_2:
            Dialog::setNumber(2);
            break;
        case Qt::Key_3:
            Dialog::setNumber(3);
            break;
        case Qt::Key_4:
            Dialog::setNumber(4);
            break;
        case Qt::Key_5:
            Dialog::setNumber(5);
            break;
        case Qt::Key_6:
            Dialog::setNumber(6);
            break;
        case Qt::Key_7:
            Dialog::setNumber(7);
            break;
        case Qt::Key_8:
            Dialog::setNumber(8);
            break;
        case Qt::Key_9:
            Dialog::setNumber(9);
            break;
        case Qt::Key_Backspace:
            Dialog::singleDelete();
            break;
        case Qt::Key_Period:
            Dialog::Point();
            break;
        case Qt::Key_Plus:
            Dialog::plus();
            break;
        case Qt::Key_Minus:
            Dialog::minus();
            break;
        case Qt::Key_Equal:
            Dialog::ravno();
            break;
        case Qt::Key_Delete:
            Dialog::allDelete();
            break;
    }
}

void Dialog::on_pushButton_1_clicked()
{
    Dialog::setNumber(1);
}

void Dialog::on_pushButton_2_clicked()
{
    Dialog::setNumber(2);
}

void Dialog::on_pushButton_3_clicked()
{
    Dialog::setNumber(3);
}

void Dialog::on_pushButton_4_clicked()
{
    Dialog::setNumber(4);
}

void Dialog::on_pushButton_5_clicked()
{
    Dialog::setNumber(5);
}

void Dialog::on_pushButton_6_clicked()
{
    Dialog::setNumber(6);
}

void Dialog::on_pushButton_7_clicked()
{
    Dialog::setNumber(7);
}

void Dialog::on_pushButton_8_clicked()
{
    Dialog::setNumber(8);
}

void Dialog::on_pushButton_9_clicked()
{
    Dialog::setNumber(9);
}

void Dialog::on_pushButton_0_clicked()
{
    Dialog::setNumber(0);
}

void Dialog::on_pushButton_del_clicked()
{
    Dialog::singleDelete();
}

void Dialog::on_pushButton_point_clicked()
{
    Dialog::Point();
}

void Dialog::on_pushButton_plus_clicked()
{
    Dialog::plus();
}

void Dialog::on_pushButton_minus_clicked()
{
    Dialog::minus();
}

void Dialog::on_pushButton_ravno_clicked()
{
    Dialog::ravno();
}

void Dialog::on_pushButton_del_2_clicked()
{
    Dialog::allDelete();
}
