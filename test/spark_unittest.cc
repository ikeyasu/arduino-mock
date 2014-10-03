/* Copyright 2014 http://switchdevice.com */
/* vim: set ts=2  sw=2 sts=2 et si: */
/* astyle --style=google --indent=spaces=2 --pad-oper milkcarton-1_unittest.cc*/

#define DEBUG_LOG false

#include "gtest/gtest.h"
#include "arduino-mock/arduino.h"

#include "arduino-mock/spark.h"
Spark_ Spark;

using ::testing::StrCaseEq;

TEST(publish, normal) {
  SparkMock* sparkMock = sparkMockInstance();
  int analogvalue = 10;
  int sleeptime = 20;
  uint16_t wakeUpPin = 1;
  uint16_t edgeTriggerMode = FALLING;
  EXPECT_CALL(*sparkMock, variable(StrCaseEq("analogvalue"), &analogvalue));
  EXPECT_CALL(*sparkMock, function(StrCaseEq("funckey"), StrCaseEq("funcname")));
  EXPECT_CALL(*sparkMock, publish(StrCaseEq("test"), StrCaseEq("test")));
  EXPECT_CALL(*sparkMock, subscribe(StrCaseEq("temp_test"), StrCaseEq("myHandler")));
  EXPECT_CALL(*sparkMock, connect());
  EXPECT_CALL(*sparkMock, disconnect());
  EXPECT_CALL(*sparkMock, connected());
  EXPECT_CALL(*sparkMock, process());
  EXPECT_CALL(*sparkMock, deviceID());
  EXPECT_CALL(*sparkMock, sleep());
  EXPECT_CALL(*sparkMock, sleep(sleeptime));
  EXPECT_CALL(*sparkMock, sleep(StrCaseEq("deep_sleep_mode"), sleeptime));
  EXPECT_CALL(*sparkMock, sleep(wakeUpPin, edgeTriggerMode, sleeptime));
  EXPECT_CALL(*sparkMock, syncTime());
  Spark.variable("analogvalue", &analogvalue);
  Spark.publish("test", "test");
  Spark.function("funckey", "funcname");
  Spark.subscribe("temp_test", "myHandler");
  Spark.connect();
  Spark.disconnect();
  Spark.connected();
  Spark.process();
  Spark.deviceID();
  Spark.sleep();
  Spark.sleep(sleeptime);
  Spark.sleep("deep_sleep_mode", sleeptime);
  Spark.sleep(wakeUpPin, edgeTriggerMode, sleeptime);
  Spark.syncTime();
  releaseSparkMock();
}
