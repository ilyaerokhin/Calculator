#ifndef CALCULATOR_H
#define CALCULATOR_H

namespace Ui {
class Dialog;
class Calculator;
}

class Calculator
{
    private:
        double cur_number;
        double saved_number;
        bool plus;
        bool minus;
        bool next_operand;

    public:
        Calculator();
        ~Calculator();
        void set_current(double n);
        double get_current();
        void set_saved(double n);
        double get_saved();
        void PlusUp();
        void PlusDown();
        void MinusUp();
        void MinusDown();
        double task();
        bool get_Minus();
        bool get_Plus();
        int check_flags();
        void NextUp();
        void NextDown();
        bool get_Next_Operand();

};

#endif // CALCULATOR_H
