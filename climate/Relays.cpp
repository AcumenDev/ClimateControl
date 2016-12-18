#include "Relays.hpp"
Relays::Relays(char humidificationRelayPin, char heatingRelayPin, char coolingRelayPin)
{
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
  digitalWrite(humidificationRelayPin, LOW );
}
void Relays::humidificationOff() {
  digitalWrite(humidificationRelayPin, HIGH );
}
void Relays::heatingOn() {
  digitalWrite(heatingRelayPin, LOW );
  digitalWrite(coolingRelayPin, HIGH );
}
void Relays::heatingOff() {
  digitalWrite(heatingRelayPin, HIGH );
}
void Relays::coolingOn() {
  digitalWrite(coolingRelayPin, LOW );
  digitalWrite(heatingRelayPin, HIGH );
}
void Relays::coolingOff() {
  digitalWrite(coolingRelayPin, HIGH );
}

