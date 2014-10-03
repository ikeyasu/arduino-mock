#include "gtest/gtest.h"
#include "arduino-mock/eeprom.h"
#include "arduino-mock/arduino.h"
EEPROM eeprom;
using ::testing::Return;

TEST(eeprom, access) {
  EEPROMMock* mock = EEPROMMockInstance();
  int expected_address = 5; int expected_value = 6;
  EXPECT_CALL(*mock, read(expected_value));
  EXPECT_CALL(*mock, write(expected_address,expected_value));
  eeprom.read(expected_value);
  eeprom.write(expected_address,expected_value);
  releaseEEPROMMock();
}
