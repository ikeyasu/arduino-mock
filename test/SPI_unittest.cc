#include "gtest/gtest.h"
#include "SPI.h"
#include "Arduino.h"


using ::testing::Return;
TEST(SPITest, access) {
  uint8_t value1 = 10;
  uint8_t value2 = 12;
  uint16_t value = 3;
  char text[] = "Mock test";
  uint8_t* callback_func = NULL;
  void* voidTest = NULL;

  SPISettings settings(1, 2, 3);
  SPIMock* mock = SPIMockInstance();

  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, usingInterrupt(value1));
  EXPECT_CALL(*mock, notUsingInterrupt(value1));
  EXPECT_CALL(*mock, beginTransaction(settings));
  EXPECT_CALL(*mock, transfer(value1));
  EXPECT_CALL(*mock, transfer16(value));
  EXPECT_CALL(*mock, transfer(voidTest, value1));
  EXPECT_CALL(*mock, endTransaction());
  EXPECT_CALL(*mock, end());
  EXPECT_CALL(*mock, setBitOrder(value1));
  EXPECT_CALL(*mock, setDataMode(value1));
  EXPECT_CALL(*mock, setClockDivider(value1));
  EXPECT_CALL(*mock, attachInterrupt());
  EXPECT_CALL(*mock, detachInterrupt());


  SPI.begin();
  SPI.usingInterrupt(value1);
  SPI.notUsingInterrupt(value1);
  SPI.beginTransaction(settings);
  SPI.transfer(value1);
  SPI.transfer16(value);
  SPI.transfer(voidTest, value1);
  SPI.endTransaction();
  SPI.end();
  SPI.setBitOrder(value1);
  SPI.setDataMode(value1);
  SPI.setClockDivider(value1);
  SPI.attachInterrupt();
  SPI.detachInterrupt();

  releaseSPIMock();
}
