#include "gtest/gtest.h"
#include "arduino-mock/wire.h"
#include "arduino-mock/arduino.h"
TwoWire twowire;

using ::testing::Return;
TEST(wire, access) {
  uint8_t a = 10;
  uint8_t b = 12;
  TwoWireMock* mock = TwoWireMockInstance();
  EXPECT_CALL(*mock, endTransmission(10));
  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, requestFrom(a,b));
  twowire.endTransmission(10);
  twowire.begin();
  twowire.requestFrom(a,b);
  releaseTwoWireMock();
}