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
  EXPECT_CALL(*sparkMock, variable(StrCaseEq("analogvalue"), &analogvalue));
  EXPECT_CALL(*sparkMock,
              publish(StrCaseEq("test"), StrCaseEq("test")));
  Spark.variable("analogvalue", &analogvalue);
  Spark.publish("test", "test");
  releaseSparkMock();
}
