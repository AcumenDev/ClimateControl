#ifndef Relays_h
#define Relays_h

#include "Arduino.h"
#include "inttypes.h"

class Relays {
    uint8_t humidificationRelayPin;
    uint8_t heatingRelayPin;
    uint8_t coolingRelayPin;
    uint8_t ventilationRelayPin;
public:
    Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin, uint8_t coolingRelayPin,
           uint8_t ventilationRelayPin);

    void humidification(uint8_t val);

    void heating(uint8_t val);

    void cooling(uint8_t val);

    void ventilation(uint8_t val);

    void draining(uint8_t val);


};

#endif
