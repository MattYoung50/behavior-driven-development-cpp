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

GTEST("Blah Tests") {
  SHOULD("0 should equal 0") {
    MockTestInterface test;
    EXPECT_CALL(test, bar()).Times(0);
    EXPECT(0 == 0);
  }
}