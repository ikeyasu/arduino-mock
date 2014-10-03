#include "arduino-mock/wifi.h"

static WiFiMock* p_WiFiMock = NULL;
WiFiMock* WiFiMockInstance()
{
	if (!p_WiFiMock){
		p_WiFiMock = new WiFiMock();
		}
	return p_WiFiMock;
}

void releaseWiFiMock()
{
	if (p_WiFiMock){
		delete p_WiFiMock;
		p_WiFiMock = NULL;
	}
}

void WiFi::on(){
  p_WiFiMock->on();
}

void WiFi::off(){
  p_WiFiMock->off();
}

void WiFi::connect(){
  p_WiFiMock->connect();
}

void WiFi::disconnect(){
  p_WiFiMock->disconnect();
}

bool WiFi::connecting(){
  return p_WiFiMock->connecting();
}

bool WiFi::ready(){
  return p_WiFiMock->ready();
}

void WiFi::listen(){
  p_WiFiMock->listen();
}

bool WiFi::listening(){
  return p_WiFiMock->listening();
}

void WiFi::setCredentials(){
  p_WiFiMock->setCredentials();
}
	
bool WiFi::clearCredentials(){
  return p_WiFiMock->clearCredentials();
}

bool WiFi::hasCredentials(){
  return p_WiFiMock->hasCredentials();
}

uint8_t WiFi::macAddress(){
  return p_WiFiMock->macAddress();
}

char* WiFi::SSID(){
  return p_WiFiMock->SSID();
}

int WiFi::RSSI(){
  return p_WiFiMock->RSSI();
}

void WiFi::ping(char* a){
  p_WiFiMock->ping(a);
}

void WiFi::ping(char* a, uint8_t b){
  p_WiFiMock->ping(a, b);
}

char* WiFi::localIP(){
  return p_WiFiMock->localIP();
}

char* WiFi::subnetMask(){
  return p_WiFiMock->subnetMask();
}

char* WiFi::gatewayIP(){
  return p_WiFiMock->gatewayIP();
}
