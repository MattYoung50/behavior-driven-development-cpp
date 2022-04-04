#include <Calculator.h>
#include <GUnit.h>

GTEST("Calculator Tests GUnit") {
  Calculator uut;

  SHOULD("Return Correct Sum Of 2 Numbers") {
    uut.InputFirstNumber(9);
    uut.InputSecondNumber(8);
    uut.Add();
    uut.Equals();
    EXPECT(17 == uut.Result);
  }
}