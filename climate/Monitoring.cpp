//
// Created by vst on 4/22/17.
//

#include "Monitoring.hpp"

Monitoring::Monitoring(int interval) : IntervalWorckerBase(interval) {}

void Monitoring::work(Values *values, unsigned long currentMillis) {
    Serial.print(currentMillis / 1000);
    Serial.print("\t");
    //  Serial.print(" T: ");
    Serial.print(values->getCurrentValue(TEMPERATURE));
    Serial.print("\t");
    Serial.print(values->getTarget(TEMPERATURE));
    Serial.print("\t");
    Serial.print(values->getOutputValue(TEMPERATURE));


    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(values->getCurrentValue(HUMIDITY));
    Serial.print("\t");
    Serial.print(values->getTarget(HUMIDITY));
    Serial.print("\t");
    Serial.print(values->getOutputValue(HUMIDITY));


    Serial.print("\t");
    Serial.print((int)values->getCurrentValue(CO2));
    Serial.print("\t");
    Serial.print(values->getTarget(CO2));
    Serial.print("\t");
    Serial.print(values->getOutputValue(CO2));


    //  Serial.print(" relays:");

    Serial.print("\t");
    Serial.print(!digitalRead(HUMIDIFICATION_RELAY_PIN));
    Serial.print("\t");
    Serial.print(!digitalRead(HEATING_RELAY_PIN));
    Serial.print("\t");
    Serial.print(!digitalRead(COOLING_RELAY_PIN));
    Serial.print("\t");
    Serial.print(!digitalRead(VENTILATION_RELAY_PIN));
     Serial.print("\t");
     Serial.print(DebugUtils::getfreeRam());
    Serial.print("\n");
    Serial.flush();
}
