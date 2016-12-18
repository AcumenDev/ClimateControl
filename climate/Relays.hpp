#ifndef Relays_h
#define Relays_h
#include "Arduino.h"
#include "inttypes.h"
class Relays {
    char humidificationRelayPin;
    char heatingRelayPin;
    char coolingRelayPin;

  public:
    Relays(char humidificationRelayPin, char heatingRelayPin, char coolingRelayPin);
    void humidificationOn();
    void humidificationOff();
    void heatingOn();
    void heatingOff();
    void coolingOn();
    void coolingOff();
};
#endif
