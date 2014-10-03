#include "gtest/gtest.h"
#include "arduino-mock/wifi.h"
#include "arduino-mock/arduino.h"

WiFi wifi;

using ::testing::Return;
TEST(wire, access) {
  WiFiMock* mock = WiFiMockInstance();
  EXPECT_CALL(*mock, on());
//  EXPECT_CALL(*mock, begin());
//  EXPECT_CALL(*mock, requestFrom(a,b));
//  twowire.endTransmission(10);
//  twowire.begin();
  wifi.on();
  releaseWiFiMock();
}