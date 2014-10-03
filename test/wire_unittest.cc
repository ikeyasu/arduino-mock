#include "gtest/gtest.h"
#include "arduino-mock/wire.h"
#include "arduino-mock/arduino.h"
Wire wire;

using ::testing::Return;
TEST(wire, access) {
  uint8_t value1 = 10;
  uint8_t value2 = 12;
  char text[] = "Mock test";
  uint8_t* callback_func=NULL;
  WireMock* mock = WireMockInstance();
  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, beginTransmission(value1));
  EXPECT_CALL(*mock, endTransmission(value1));
  EXPECT_CALL(*mock, requestFrom(value1,value2));
  EXPECT_CALL(*mock, write(text));
  EXPECT_CALL(*mock, available());
  EXPECT_CALL(*mock, read());
  EXPECT_CALL(*mock, onReceive(callback_func));
  EXPECT_CALL(*mock, onRequest(callback_func));
  wire.begin();
  wire.beginTransmission(value1);
  wire.endTransmission(value1);
  wire.requestFrom(value1,value2);
  wire.write(text);
  wire.available();
  wire.read();
  wire.onReceive(callback_func);
  wire.onRequest(callback_func);
  releaseWireMock();
}