/**
 * Arduino Serial mock
 */
#ifndef SERIAL_H
#define SERIAL_H

#include <stdint.h>
#include <gmock/gmock.h>

#include <Stream.h>

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class SerialMock {
  public:
    MOCK_METHOD0(getWriteError, int());
    MOCK_METHOD0(clearWriteError, void());
    MOCK_METHOD1(write, size_t(uint8_t));
    MOCK_METHOD1(write, size_t(const char *str));
    MOCK_METHOD2(write, size_t(const uint8_t *buffer, size_t size));

    MOCK_METHOD1(print, size_t(const char[]));
    MOCK_METHOD1(print, size_t(char));
    MOCK_METHOD2(print, size_t(unsigned char, int));
    MOCK_METHOD2(print, size_t(int, int));
    MOCK_METHOD2(print, size_t(unsigned int, int));
    MOCK_METHOD2(print, size_t(long, int));
    MOCK_METHOD2(print, size_t(unsigned long, int));
    MOCK_METHOD2(print, size_t(double, int));

    MOCK_METHOD1(println, size_t(const char[]));
    MOCK_METHOD1(println, size_t(char));
    MOCK_METHOD2(println, size_t(int, int));
    MOCK_METHOD0(println, size_t(void));

    MOCK_METHOD1(begin, uint8_t(uint16_t));

    MOCK_METHOD0(available, uint8_t());
    MOCK_METHOD0(read, uint8_t());

    MOCK_METHOD0(flush, void());

    /* Not implemented yet
    MOCK_METHOD2(println, size_t(unsigned char, int));
    MOCK_METHOD2(println, size_t(unsigned int, int));
    MOCK_METHOD2(println, size_t(long, int));
    MOCK_METHOD2(println, size_t(unsigned long, int));
    MOCK_METHOD2(println, size_t(double, int));
    */
};

class Serial_ : public Stream {

  private:
    static bool printToCout;

  public:
    static void setPrintToCout(bool flag);

    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);

    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
    size_t println(void);

    size_t write(uint8_t);
    size_t write(const char *str);
    size_t write(const uint8_t *buffer, size_t size) override;

    uint8_t begin(uint32_t);

    uint8_t available() override;
    uint8_t read() override;
    int8_t peek() override;

    void flush() override;

    bool find(char *target) override;
    bool find(uint8_t *target) override;

    bool find(char *target, size_t length) override;
    bool find(uint8_t *target, size_t length) override;

    size_t readBytes( char *buffer, size_t length) override;
    size_t readBytes( uint8_t *buffer, size_t length) override;

    /*
    TODO: Not implemented yet.
    int getWriteError();
    void clearWriteError();
    static size_t print(const __FlashStringHelper *);
    static size_t print(const String &);
    static size_t print(const Printable&);
    static size_t println(const __FlashStringHelper *);
    static size_t println(const String &s);
    static size_t println(const Printable&);
    */
};
extern Serial_ Serial;

SerialMock* serialMockInstance();
void releaseSerialMock();


#endif // SERIAL_H
