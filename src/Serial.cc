// Copyright 2014 http://switchdevice.com

#include "arduino-mock/Serial.h"

static SerialMock* gSerialMock = NULL;
SerialMock* serialMockInstance() {
  if(!gSerialMock) {
    gSerialMock = new SerialMock();
  }
  return gSerialMock;
}

void releaseSerialMock() {
  if(gSerialMock) {
    delete gSerialMock;
    gSerialMock = NULL;
  }
}

size_t Serial_::print(const char *s) {
  return gSerialMock->print(s);
}

size_t Serial_::print(char c) {
  return gSerialMock->print(c);
}

size_t Serial_::print(unsigned char c, int base) {
  return gSerialMock->print(c, base);
}

size_t Serial_::print(int num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(unsigned int num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(long num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(unsigned long num, int base) {
  return gSerialMock->print(num, base);
}

size_t Serial_::print(double num, int digits) {
  return gSerialMock->print(num, digits);
}

size_t Serial_::println(const char *s) {
  return gSerialMock->println(s);
}

size_t Serial_::println(char c) {
  return gSerialMock->println(c);
}

size_t Serial_::println(unsigned char c, int base) {
  return gSerialMock->println(c, base);
}

size_t Serial_::println(int num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(unsigned int num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(long num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(unsigned long num, int base) {
  return gSerialMock->println(num, base);
}

size_t Serial_::println(double num, int digits) {
  return gSerialMock->println(num, digits);
}

size_t Serial_::println(void) {
  return gSerialMock->println();
}

size_t Serial_::write(uint8_t val) {
  return gSerialMock->write(val);
}

size_t Serial_::write(const char *str) {
  return gSerialMock->write(str);
}

size_t Serial_::write(const uint8_t *buffer, size_t size) {
  return gSerialMock->write(buffer, size);
}

uint8_t Serial_::begin(uint32_t port) {
  return gSerialMock->begin(port);
}

void Serial_::flush() {
  return gSerialMock->flush();
}

uint8_t Serial_::available() {
  return gSerialMock->available();
}

uint8_t Serial_::read() {
  return gSerialMock->read();
}

uint8_t Serial_::peek() {
  return gSerialMock->peek();
}

String Serial_::readStringUntil(const char term) {
  return gSerialMock->readStringUntil(term);
}

// Preinstantiate Objects
Serial_ Serial;
