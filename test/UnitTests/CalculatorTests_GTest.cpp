#include <Calculator.h>
#include <gtest/gtest.h>

struct CalculatorTests : testing::Test {
  Calculator uut;
  void SetUp() override {}
  void TearDown() override {}
};

TEST(CalculatorTests, ShouldReturnCorrectSumOf2Numbers) {
  Calculator uut;
  uut.InputFirstNumber(9);
  uut.InputSecondNumber(8);
  uut.Add();
  uut.Equals();
  EXPECT_EQ(uut.Result, 17);
}