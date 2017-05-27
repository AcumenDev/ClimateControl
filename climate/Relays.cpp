#include "Relays.hpp"

Relays::Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin, uint8_t coolingRelayPin,
               uint8_t ventilationRelayPin) {
    this->humidificationRelayPin = humidificationRelayPin;
    this->heatingRelayPin = heatingRelayPin;
    this->coolingRelayPin = coolingRelayPin;
    this->ventilationRelayPin = ventilationRelayPin;

    pinMode(humidificationRelayPin, OUTPUT);
    pinMode(heatingRelayPin, OUTPUT);
    pinMode(coolingRelayPin, OUTPUT);
    pinMode(ventilationRelayPin, OUTPUT);

    digitalWrite(humidificationRelayPin, HIGH);
    digitalWrite(heatingRelayPin, HIGH);
    digitalWrite(coolingRelayPin, HIGH);
    digitalWrite(ventilationRelayPin, HIGH);
}

void Relays::humidification(uint8_t val) {
    digitalWrite(humidificationRelayPin, val);
}

void Relays::cooling(uint8_t val) {
    if (val > digitalRead(coolingRelayPin)) {
        digitalWrite(coolingRelayPin, val);
    }
}

void Relays::heating(uint8_t val) {
    digitalWrite(heatingRelayPin, val);
}

void Relays::ventilation(uint8_t val) {
    digitalWrite(ventilationRelayPin, val);
}

void Relays::draining(uint8_t val) {
    if (val > digitalRead(coolingRelayPin)) {
        digitalWrite(coolingRelayPin, val);
    }
}
