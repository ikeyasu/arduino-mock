// Copyright 2014 http://switchdevice.com
// This example code is in the public domain.

#include "gtest/gtest.h"
#include "Arduino.h"
#include "Serial.h"
#include "serialHelper.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Matcher;
using ::testing::AtLeast;
using ::testing::Invoke;


// static size_t println(int, int = DEC);
TEST(serial, println1) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, println(1, 10))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(1, 10));
  releaseSerialMock();
}

// static size_t println(const char[]);
TEST(serial, println2) {
  SerialMock* serialMock = serialMockInstance();
  const char lala[] = "haha";
  EXPECT_CALL(*serialMock, println(lala))
  .WillRepeatedly(Return(4));
  EXPECT_EQ(4, Serial.println(lala));
  releaseSerialMock();
}

// static size_t println(char);
TEST(serial, println3) {
  SerialMock* serialMock = serialMockInstance();
  char lala = 'a';
  EXPECT_CALL(*serialMock, println(lala))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(lala));
  releaseSerialMock();
}

//static size_t println(unsigned char, int = DEC);
TEST(serial, println4) {
  SerialMock* serialMock = serialMockInstance();
  unsigned char lala = 'a';
  EXPECT_CALL(*serialMock, println(lala, DEC))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(lala));
  releaseSerialMock();
}

//static size_t println(unsigned int, int = DEC);
TEST(serial, println5) {
  SerialMock* serialMock = serialMockInstance();
  unsigned int lala = 1234;
  EXPECT_CALL(*serialMock, println(lala, DEC))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(lala, DEC));
  releaseSerialMock();
}

// static size_t println(long, int = DEC);
TEST(serial, println6) {
  SerialMock* serialMock = serialMockInstance();
  long lala = 1234567;
  EXPECT_CALL(*serialMock, println(lala, DEC))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(lala, DEC));
  releaseSerialMock();
}

// static size_t println(unsigned long, int = DEC);
TEST(serial, println7) {
  SerialMock* serialMock = serialMockInstance();
  unsigned long lala = 2345678;
  EXPECT_CALL(*serialMock, println(lala, DEC))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(lala, DEC));
  releaseSerialMock();
}

// static size_t println(double, int = 2);
TEST(serial, println8) {
  SerialMock* serialMock = serialMockInstance();
  double lala = 3.14;
  EXPECT_CALL(*serialMock, println(lala, 2))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println(lala, 2));
  releaseSerialMock();
}

// static size_t println(void);
TEST(serial, println9) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, println())
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.println());
  releaseSerialMock();
}

// static size_t print(int, int = DEC);
TEST(serial, print1) {
  SerialMock* serialMock = serialMockInstance();
  int lala = 123;
  EXPECT_CALL(*serialMock, print(Matcher<int>(lala), Matcher<int>(10)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala, 10));
  releaseSerialMock();
}

// static size_t print(const char[]);
TEST(serial, print2) {
  SerialMock* serialMock = serialMockInstance();
  const char lala[] = "haha";
  EXPECT_CALL(*serialMock, print(Matcher<const char*>(lala)))
  .WillRepeatedly(Return(4));
  EXPECT_EQ(4, Serial.print(lala));
  releaseSerialMock();
}

// static size_t print(char);
TEST(serial, print3) {
  SerialMock* serialMock = serialMockInstance();
  char lala = 'a';
  EXPECT_CALL(*serialMock, print(Matcher<char>(lala)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala));
  releaseSerialMock();
}

//static size_t print(unsigned char, int = DEC);
TEST(serial, print4) {
  SerialMock* serialMock = serialMockInstance();
  unsigned char lala = 'a';
  EXPECT_CALL(*serialMock, print(Matcher<unsigned char>(lala), Matcher<int>(DEC)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala));
  releaseSerialMock();
}

//static size_t print(unsigned int, int = DEC);
TEST(serial, print5) {
  SerialMock* serialMock = serialMockInstance();
  unsigned int lala = 1234;
  EXPECT_CALL(*serialMock, print(Matcher<unsigned int>(lala), Matcher<int>(DEC)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala, DEC));
  releaseSerialMock();
}

// static size_t print(long, int = DEC);
TEST(serial, print6) {
  SerialMock* serialMock = serialMockInstance();
  long lala = 1234567;
  EXPECT_CALL(*serialMock, print(Matcher<long>(lala), Matcher<int>(DEC)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala, DEC));
  releaseSerialMock();
}

// static size_t print(unsigned long, int = DEC);
TEST(serial, print7) {
  SerialMock* serialMock = serialMockInstance();
  unsigned long lala = 2345678;
  EXPECT_CALL(*serialMock, print(Matcher<unsigned long>(lala), Matcher<int>(DEC)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala, DEC));
  releaseSerialMock();
}

// static size_t println(double, int = 2);
TEST(serial, print8) {
  SerialMock* serialMock = serialMockInstance();
  double lala = 3.14;
  EXPECT_CALL(*serialMock, print(Matcher<double>(lala), Matcher<int>(2)))
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.print(lala, 2));
  releaseSerialMock();
}

TEST(serial, flush) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, flush());
  Serial.flush();
  releaseSerialMock();
}

TEST(serial, write1) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, write('a'));
  Serial.write('a');
  releaseSerialMock();
}

TEST(serial, available) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, available())
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.available());
  releaseSerialMock();
}

TEST(serial, read1) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, read())
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.read());
  releaseSerialMock();
}

TEST(serial, read2) {
  SerialMock* serialMock = serialMockInstance();
  EXPECT_CALL(*serialMock, read())
  .WillRepeatedly(Return(1));
  EXPECT_EQ(1, Serial.read());
  releaseSerialMock();
}
