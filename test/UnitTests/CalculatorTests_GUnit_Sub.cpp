#include <Calculator.h>
#include <GUnit.h>

GTEST("Calculator Tests GUnit Sub") {
  Calculator uut;

  SHOULD("Return Correct Difference Of 9 - 8") {
    uut.InputFirstNumber(9);
    uut.InputSecondNumber(8);
    uut.Subtract();
    uut.Equals();
    EXPECT(1 == uut.Result);
  }

  SHOULD("Return Correct Difference Of 9 - 9") {
    uut.InputFirstNumber(9);
    uut.InputSecondNumber(9);
    uut.Subtract();
    uut.Equals();
    EXPECT(0 == uut.Result);
  }
}