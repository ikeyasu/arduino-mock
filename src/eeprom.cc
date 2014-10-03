/** Implementation of EEPROM mock **/

#include "arduino-mock/eeprom.h"

static EEPROMMock* p_EEPROMMock = NULL;
EEPROMMock* EEPROMMockInstance()
{
  if (!p_EEPROMMock){
    p_EEPROMMock = new EEPROMMock();
  }
  return p_EEPROMMock;
}

void releaseEEPROMMock()
{
  if (p_EEPROMMock){
    delete p_EEPROMMock;
    p_EEPROMMock = NULL;
  }
}

uint8_t EEPROM::read(int a){
  return p_EEPROMMock->read(a);
}

void EEPROM::write(int a, uint8_t b){
  p_EEPROMMock->write(a, b);
}