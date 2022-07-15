#include "Calculator.h"



void Calculator::InputFirstNumber(int number)
{
    _firstNumber = number;
}

void Calculator::InputSecondNumber(int number)
{
    _secondNumber = number;
}

void Calculator::Add()
{
    _action = Button::Add;
}

void Calculator::Subtract()
{
    _action = Button::Subtract;
}

void Calculator::Equals()
{
    if (_action == Button::Add)
    {
        Result = _firstNumber + _secondNumber;
    } 
    else if (_action == Button::Subtract)
    {
        Result = _firstNumber - _secondNumber;
    }  
    else
    {
        Result = 0;
    }
    _action = Button::Equals;
}