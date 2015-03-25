#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include "calculator.h"

namespace Ui {
class Dialog;
class Calculator;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
     Dialog(QWidget *parent = 0);
    ~Dialog();
     Calculator *calc;
     void keyPressEvent(QKeyEvent * event);

private:
    Ui::Dialog *ui;
    void setNumber(int n);
    void singleDelete();
    void Point();
    void plus();
    void minus();
    void allDelete();
    void ravno();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_del_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_ravno_clicked();
    void on_pushButton_del_2_clicked();

};

#endif // DIALOG_H
