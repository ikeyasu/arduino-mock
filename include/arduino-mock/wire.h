#ifndef __TwoWire_h__
#define __TwoWire_h__
#include <stdint.h>
#include <gmock/gmock.h>

#define BUFFER_LENGTH 32
#define I2C2 0x4819c000
#define I2C1 0x00000000
#define WIRE_INTERFACES_COUNT 1

class TwoWire
{
  public:
	void begin();
	void begin(uint8_t);
	void begin(int);
	void beginTransmission(uint8_t);
	void beginTransmission(int);
	uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
	uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
//	using Print::write;
};

class TwoWireMock
{
	public:
		MOCK_METHOD0(begin, void());
		MOCK_METHOD1(begin, void(uint8_t));
		MOCK_METHOD1(begin, void(int));
		MOCK_METHOD1(beginTransmission, void(uint8_t));
		MOCK_METHOD1(beginTransmission, void(int));
		MOCK_METHOD0(endTransmission, uint8_t(void));
		MOCK_METHOD1(endTransmission, uint8_t(uint8_t));
		MOCK_METHOD2(requestFrom, uint8_t(uint8_t, uint8_t));
		MOCK_METHOD3(requestFrom, uint8_t(uint8_t, uint8_t, uint8_t));
};

TwoWireMock* TwoWireMockInstance();
void releaseTwoWireMock();

#endif