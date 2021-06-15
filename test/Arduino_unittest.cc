// Copyright 2014 http://switchdevice.com
// This example code is in the public domain.

#include "gtest/gtest.h"
#include "Arduino.h"

using ::testing::Return;
TEST(digitalRead, 2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(2)).WillOnce(Return(1));
  digitalRead(2);
  releaseArduinoMock();
}

TEST(delay, normal) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, delay(1));
  delay(1);
  releaseArduinoMock();
}

