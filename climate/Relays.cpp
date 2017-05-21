#include "Relays.hpp"

Relays::Relays(uint8_t humidificationRelayPin, uint8_t heatingRelayPin, uint8_t coolingRelayPin) {
    this->humidificationRelayPin = humidificationRelayPin;
    this->heatingRelayPin = heatingRelayPin;
    this->coolingRelayPin = coolingRelayPin;
    pinMode(humidificationRelayPin, OUTPUT);
    pinMode(heatingRelayPin, OUTPUT);
    pinMode(coolingRelayPin, OUTPUT);
    digitalWrite(humidificationRelayPin, HIGH);
    digitalWrite(heatingRelayPin, HIGH);
    digitalWrite(coolingRelayPin, HIGH);
}

void Relays::humidificationOn() {
    digitalWrite(humidificationRelayPin, LOW);
}

void Relays::humidificationOff() {
    digitalWrite(humidificationRelayPin, HIGH);
}
void Relays::humidification(uint8_t val) {
    digitalWrite(humidificationRelayPin, val);
}

void Relays::heatingOn() {
    digitalWrite(heatingRelayPin, LOW);
    digitalWrite(coolingRelayPin, HIGH);
}

void Relays::heatingOff() {
    digitalWrite(heatingRelayPin, HIGH);
}

void Relays::coolingOn() {
    digitalWrite(coolingRelayPin, LOW);
    digitalWrite(heatingRelayPin, HIGH);
}

void Relays::coolingOff() {
    digitalWrite(coolingRelayPin, HIGH);
}

void Relays::ventilationOn() {
///TODO
}

void Relays::ventilationOff() {
///TODO
}



