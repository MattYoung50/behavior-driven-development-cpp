#pragma once

enum Button {
    Add = 0,
    Subtract = 1,
    Equals = 2
};

class Calculator {
    private:
        Button _action;
        int _firstNumber;
        int _secondNumber;
    public:
        void InputFirstNumber(int number);
        void InputSecondNumber(int number);
        void Add();
        void Subtract();
        void Equals();
        int Result;
};