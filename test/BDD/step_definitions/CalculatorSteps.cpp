#include <Calculator.h>
#include <GUnit/GSteps.h>
#include <GUnit/GTest.h>

GSTEPS("Calc*") {
  Calculator calculator;

  Given("I have entered first input {n} into the calculator") = [&](int n) {
    calculator.InputFirstNumber(n);
  };

  Given("I have entered second input {n} into the calculator") = [&](int n) {
    calculator.InputSecondNumber(n);
  };

  Given("I press add") = [&] { calculator.Add(); };

  When("I press equals") = [&] { calculator.Equals(); };

  Then("the correct {expectedResult} should be calculated") =
      [&](int expected) { EXPECT_EQ(expected, calculator.Result); };
}