#ifndef Relays_h
#define Relays_h
#include "Arduino.h"
#include "inttypes.h"
class Relays {
    uint8_t humidificationRelayPin;
    uint8_t heatingRelayPin;
    uint8_t coolingRelayPin;

  public:
    Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin, uint8_t coolingRelayPin);
    void humidificationOn();
    void humidificationOff();
    void heatingOn();
    void heatingOff();
    void coolingOn();
    void coolingOff();

    void ventilationOn();

    void ventilationOff();
};
#endif
