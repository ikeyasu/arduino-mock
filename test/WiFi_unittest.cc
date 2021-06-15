#include "gtest/gtest.h"
#include "WiFi.h"
#include "Arduino.h"

WiFi_ wifi;

using ::testing::Return;
TEST(wire, access) {
  WiFiMock* mock = WiFiMockInstance();
  char IPAddr[] = "192.168.0.1";
  uint8_t n_times = 10;
  EXPECT_CALL(*mock, on());
  EXPECT_CALL(*mock, off());
  EXPECT_CALL(*mock, connect());
  EXPECT_CALL(*mock, disconnect());
  EXPECT_CALL(*mock, connecting());
  EXPECT_CALL(*mock, ready());
  EXPECT_CALL(*mock, listen());
  EXPECT_CALL(*mock, listening());
  EXPECT_CALL(*mock, setCredentials());
  EXPECT_CALL(*mock, clearCredentials());
  EXPECT_CALL(*mock, hasCredentials());
  EXPECT_CALL(*mock, macAddress());
  EXPECT_CALL(*mock, SSID());
  EXPECT_CALL(*mock, ping(IPAddr));
  EXPECT_CALL(*mock, ping(IPAddr, n_times));
  EXPECT_CALL(*mock, localIP());
  EXPECT_CALL(*mock, subnetMask());
  EXPECT_CALL(*mock, gatewayIP());

  wifi.on();
  wifi.off();
  wifi.connect();
  wifi.disconnect();
  wifi.connecting();
  wifi.ready();
  wifi.listen();
  wifi.listening();
  wifi.setCredentials();
  wifi.clearCredentials();
  wifi.hasCredentials();
  wifi.macAddress();
  wifi.SSID();
  wifi.ping(IPAddr);
  wifi.ping(IPAddr, n_times);
  wifi.localIP();
  wifi.subnetMask();
  wifi.gatewayIP();
  releaseWiFiMock();
}
