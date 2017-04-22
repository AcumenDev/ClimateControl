//
// Created by vst on 4/22/17.
//

#include "Monitoring.hpp"

Monitoring::Monitoring(Values *values, int interval) : IntervalWorckerBase(interval) {
    this->values = values;

}

void Monitoring::work(unsigned long currentMillis) {
    Serial.print(currentMillis / 1000);
    Serial.print("\t");
    //  Serial.print(" T: ");
    Serial.print(values->getCurrentValue(TYPE_CLIMATE_VALUE::TEMPERATURE));
    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(values->getCurrentValue(TYPE_CLIMATE_VALUE::HUMIDITY));
    Serial.print("\t");
    Serial.print((int) values->getCurrentValue(TYPE_CLIMATE_VALUE::CO2));
    //  Serial.print(" set:");
    //  Serial.print(" T: ");
    Serial.print("\t");
    Serial.print(values->getTarget(TYPE_CLIMATE_VALUE::TEMPERATURE));
    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(values->getTarget(TYPE_CLIMATE_VALUE::HUMIDITY));
    Serial.print("\t");
    Serial.print((int) values->getTarget(TYPE_CLIMATE_VALUE::CO2));
    Serial.print("\t");
    //  Serial.print(" relays:");

    //  Serial.print(" HU: ");
    Serial.print(!digitalRead(HUMIDIFICATION_RELAY_PIN));
    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(!digitalRead(HEATING_RELAY_PIN));
    //  Serial.print(" C: ");
    Serial.print("\t");
    Serial.print(!digitalRead(COOLING_RELAY_PIN));
    Serial.print("\t");
    Serial.print(DebugUtils::getfreeRam());
    Serial.print("\n");
    Serial.flush();
}
