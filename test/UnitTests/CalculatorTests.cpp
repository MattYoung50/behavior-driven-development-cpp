#include <Calculator.h>
#include <gtest/gtest.h>

TEST(CalculatorAdd, Add) {
  Calculator uut;
  uut.InputFirstNumber(9);
  uut.InputSecondNumber(8);
  uut.Add();
  uut.Equals();
  EXPECT_EQ(uut.Result, 16);
}