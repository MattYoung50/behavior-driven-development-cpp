#pragma once

enum Button {
    Equals = 0,
    Subtract = 1,
    Add = 2
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