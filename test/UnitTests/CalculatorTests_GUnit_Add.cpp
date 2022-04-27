#include <Calculator.h>
#include <GUnit.h>

#include <gmock/gmock.h>
using namespace testing;

class TestInterface {
public:
  virtual void bar() = 0;
  virtual ~TestInterface(){};
};

class MockTestInterface : public TestInterface {
public:
  MOCK_METHOD(void, bar, (), (override));
};

GTEST("Calculator Tests GUnit Add") {
  Calculator uut;

  SHOULD("Return Correct Sum Of 9 + 8") {
    uut.InputFirstNumber(9);
    uut.InputSecondNumber(8);
    uut.Add();
    uut.Equals();
    EXPECT(17 == uut.Result);
  }

  SHOULD("Return Correct Sum Of  9 + 9") {
    uut.InputFirstNumber(9);
    uut.InputSecondNumber(9);
    uut.Add();
    uut.Equals();
    EXPECT(18 == uut.Result);
  }
}