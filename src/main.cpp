#include "Calculator.h"
#include <iostream>

using namespace std;

int main() {
  Calculator calc;
  calc.InputFirstNumber(9);
  calc.InputSecondNumber(8);
  calc.Add();
  calc.Equals();
  cout << "9 + 8 is " << calc.Result << endl;
  calc.InputFirstNumber(9);
  calc.InputSecondNumber(8);
  calc.Subtract();
  calc.Equals();
  cout << "9 - 8 is " << calc.Result << endl;
}