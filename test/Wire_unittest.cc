#include "gtest/gtest.h"
#include "Wire.h"
#include "Arduino.h"

using ::testing::Return;
TEST(Wire, access) {
  uint8_t value1 = 10;
  uint8_t value2 = 12;
  char text[] = "Mock test";
  uint8_t* callback_func = NULL;
  WireMock* mock = WireMockInstance();
  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, beginTransmission(value1));
  EXPECT_CALL(*mock, endTransmission(value1));
  EXPECT_CALL(*mock, requestFrom(value1, value2));
  EXPECT_CALL(*mock, write(text));
  EXPECT_CALL(*mock, available());
  EXPECT_CALL(*mock, read());
  EXPECT_CALL(*mock, onReceive(callback_func));
  EXPECT_CALL(*mock, onRequest(callback_func));
  Wire.begin();
  Wire.beginTransmission(value1);
  Wire.endTransmission(value1);
  Wire.requestFrom(value1, value2);
  Wire.write(text);
  Wire.available();
  Wire.read();
  Wire.onReceive(callback_func);
  Wire.onRequest(callback_func);
  releaseWireMock();
}
