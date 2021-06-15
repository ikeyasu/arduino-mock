#include "gtest/gtest.h"
#include "EEPROM.h"
#include "Arduino.h"
using ::testing::Return;

TEST(EEPROM, access) {
  EEPROMMock* mock = EEPROMMockInstance();
  int expected_address = 5;
  int expected_value = 6;
  EXPECT_CALL(*mock, read(expected_value));
  EXPECT_CALL(*mock, write(expected_address, expected_value));
  EEPROM.read(expected_value);
  EEPROM.write(expected_address, expected_value);
  releaseEEPROMMock();
}
