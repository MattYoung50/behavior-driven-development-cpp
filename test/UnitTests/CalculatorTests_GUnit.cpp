#include <Calculator.h>
#include <GUnit.h>

GTEST("Calculator Tests") {
  Calculator uut;

  SHOULD("Return correct sum of 2 numbers") {
    uut.InputFirstNumber(9);
    uut.InputSecondNumber(8);
    uut.Add();
    uut.Equals();
    EXPECT(16 == uut.Result);
  }
}