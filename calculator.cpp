#include "calculator.h"

Calculator::Calculator()
{
    Calculator::cur_number = 0;
    Calculator::saved_number = 0;
    Calculator::minus = false;
    Calculator::plus = false;
    Calculator::NextUp();
}

void Calculator::set_current(double n)
{
    Calculator::cur_number = n;
    return;
}

double Calculator::get_current()
{
    return Calculator::cur_number;
}

void Calculator::set_saved(double n)
{
    Calculator::saved_number = n;
    return;
}

double Calculator::get_saved()
{
    return Calculator::saved_number;
}

void Calculator::MinusUp()
{
    Calculator::minus = true;
}

void Calculator::MinusDown()
{
    Calculator::minus = false;
}

void Calculator::PlusUp()
{
    Calculator::plus = true;
}

void Calculator::PlusDown()
{
    Calculator::plus = false;
}

bool Calculator::get_Minus()
{
    return Calculator::minus;
}

bool Calculator::get_Plus()
{
    return Calculator::plus;
}

double Calculator::task()
{
    if (Calculator::get_Minus())
    {
        Calculator::MinusDown();
        return Calculator::get_saved() - Calculator::get_current();
    }

    if (Calculator::get_Plus())
    {
        Calculator::PlusDown();
        return Calculator::get_saved() + Calculator::get_current();
    }

    return 0;
}

int Calculator::check_flags()
{
    if(Calculator::get_Minus() == Calculator::get_Plus())
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Calculator::NextDown()
{
    Calculator::next_operand = false;
}

void Calculator::NextUp()
{
    Calculator::next_operand = true;
}

bool Calculator::get_Next_Operand()
{
    return Calculator::next_operand;
}
