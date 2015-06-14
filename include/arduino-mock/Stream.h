#ifndef STREAM_H
#define STREAM_H

#include "Print.h"
#include <gmock/gmock.h>

class Stream : public Print {
  public:
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;
    // virtual void setTimeout(unsigned long timeout);

    virtual bool find(char *target) = 0;
    virtual bool find(uint8_t *target) = 0;

    virtual bool find(char *target, size_t length) = 0;
    virtual bool find(uint8_t *target, size_t length) = 0;

    // virtual bool findUntil(char *target, char *terminator) = 0;
    // virtual bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator) = 0; }
    //
    // virtual bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen) = 0;
    // virtual bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen) = 0; }
    //
    // virtual long parseInt() = 0;
    //
    // virtual float parseFloat() = 0;

    virtual size_t readBytes( char *buffer, size_t length) = 0;
    virtual size_t readBytes( uint8_t *buffer, size_t length) = 0;

    virtual size_t write(const uint8_t *buffer, size_t size) = 0;

    // virtual size_t readBytesUntil( char terminator, char *buffer, size_t length);
    // virtual size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
    //
    // virtual String readString();
    // virtual String readStringUntil(char terminator);

};

class StreamMock : public Stream {
  public:
    MOCK_METHOD0(available, int ());
    MOCK_METHOD0(read, int ());
    MOCK_METHOD0(peek, int ());
    MOCK_METHOD0(flush, void ());

    MOCK_METHOD1(find, bool (char *target));
    MOCK_METHOD1(find, bool (uint8_t *target));
    MOCK_METHOD2(find, bool (char *target, size_t length));
    MOCK_METHOD2(find, bool (uint8_t *target, size_t length));

    // virtual bool findUntil(char *target, char *terminator);
    // virtual bool findUntil(uint8_t *target, char *terminator) { return findUntil((char *)target, terminator); }
    //
    // virtual bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen);
    // virtual bool findUntil(uint8_t *target, size_t targetLen, char *terminate, size_t termLen) {return findUntil((char *)target, targetLen, terminate, termLen); }
    //
    // virtual long parseInt();
    //
    // virtual float parseFloat();
    MOCK_METHOD2(readBytes, size_t (char *buffer, size_t length));
    MOCK_METHOD2(readBytes, size_t (uint8_t *buffer, size_t length));

    // virtual size_t readBytesUntil( char terminator, char *buffer, size_t length);
    // virtual size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
    //
    // virtual String readString();
    // virtual String readStringUntil(char terminator);

    //Print functions
    MOCK_METHOD2(write, size_t (const uint8_t*, size_t size));
};

#endif
