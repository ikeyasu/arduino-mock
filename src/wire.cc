#include "arduino-mock/wire.h"

static TwoWireMock* p_TwoWireMock = NULL;
TwoWireMock* TwoWireMockInstance()
{
	if (!p_TwoWireMock){
		p_TwoWireMock = new TwoWireMock();
		}
	return p_TwoWireMock;
}

void releaseTwoWireMock()
{
	if (p_TwoWireMock){
		delete p_TwoWireMock;
		p_TwoWireMock = NULL;
	}
}

void TwoWire::begin(){
	p_TwoWireMock->begin();
}

void TwoWire::begin(uint8_t a){
	p_TwoWireMock->begin(a);
}

void TwoWire::begin(int a){
	p_TwoWireMock->begin(a);
}

void beginTransmission(uint8_t a){
	p_TwoWireMock->beginTransmission(a);
}

void beginTransmission(int a){
	p_TwoWireMock->beginTransmission(a);
}

uint8_t endTransmission(void){
	return p_TwoWireMock->endTransmission();
}

uint8_t TwoWire::endTransmission(uint8_t a){
	return p_TwoWireMock->endTransmission(a);
}

uint8_t TwoWire::requestFrom(uint8_t a, uint8_t b){
	return p_TwoWireMock->requestFrom(a,b);
}

uint8_t requestFrom(uint8_t a, uint8_t b, uint8_t c){
	return p_TwoWireMock->requestFrom(a,b,c);
}

