#include "gtest/gtest.h"
#include "Arduino.h"
#include "Serial.h"

#include "serialHelper.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Matcher;
using ::testing::AtLeast;
using ::testing::Invoke;


TEST(serial, stringCapture1) {
  // Insert char first time
  SerialMock* serialMock = serialMockInstance();
  stringCapture c;

  testing::DefaultValue<uint8_t>::Set(1);
  EXPECT_CALL(*serialMock, write(Matcher<uint8_t>(_)))
  .WillRepeatedly(Invoke(&c, &stringCapture::captureUInt8));
  EXPECT_EQ(1, Serial.write('a'));

  EXPECT_EQ(c.get(), std::string("a"));

  // Clear data
  c.clear();

  EXPECT_EQ(c.get(), std::string(""));

  // Insert new char
  EXPECT_CALL(*serialMock, write(Matcher<uint8_t>(_)))
  .WillRepeatedly(Invoke(&c, &stringCapture::captureUInt8));
  EXPECT_EQ(1, Serial.write('b'));

  EXPECT_EQ(c.get(), std::string("b"));

  releaseSerialMock();
}


TEST(serial, stringCapture2) {
  // Insert char first time
  SerialMock* serialMock = serialMockInstance();
  stringCapture c;

  testing::DefaultValue<uint8_t>::Set(5);
  EXPECT_CALL(*serialMock, write(Matcher<const uint8_t *>(_), Matcher<size_t>(_)))
  .WillRepeatedly(Invoke(&c, &stringCapture::captureCStr));
  EXPECT_EQ(1, Serial.write((const uint8_t*)"abcde", 5));

  EXPECT_EQ(c.get(), std::string("abcde"));

}


TEST(serial, stringCapture3) {
  // Insert char first time
  SerialMock* serialMock = serialMockInstance();
  stringCapture c;

  testing::DefaultValue<uint8_t>::Set(1);
  EXPECT_CALL(*serialMock, write(Matcher<uint8_t>(_)))
  .WillRepeatedly(Invoke(&c, &stringCapture::captureUInt8));
  EXPECT_EQ(1, Serial.write('a'));

  EXPECT_EQ(c.get(), std::string("a"));

  // Insert new char
  EXPECT_CALL(*serialMock, write(Matcher<uint8_t>(_)))
  .WillRepeatedly(Invoke(&c, &stringCapture::captureUInt8));
  EXPECT_EQ(1, Serial.write('b'));

  EXPECT_EQ(c.get(), std::string("ab"));

  releaseSerialMock();
}
