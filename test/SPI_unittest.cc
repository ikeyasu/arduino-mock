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


  SPIInstance.begin();
  SPIInstance.usingInterrupt(value1);
  SPIInstance.notUsingInterrupt(value1);
  SPIInstance.beginTransaction(settings);
  SPIInstance.transfer(value1);
  SPIInstance.transfer16(value);
  SPIInstance.transfer(voidTest, value1);
  SPIInstance.endTransaction();
  SPIInstance.end();
  SPIInstance.setBitOrder(value1);
  SPIInstance.setDataMode(value1);
  SPIInstance.setClockDivider(value1);
  SPIInstance.attachInterrupt();
  SPIInstance.detachInterrupt();

  releaseSPIMock();
}
