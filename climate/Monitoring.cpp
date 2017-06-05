//
// Created by vst on 4/22/17.
//

#include "Monitoring.hpp"

Monitoring::Monitoring(int interval) : IntervalWorckerBase(interval) {}

void Monitoring::work(Values *values, unsigned long currentMillis) {
    Serial.print(currentMillis / 1000);
    Serial.print("\t");
    //  Serial.print(" T: ");
    Serial.print(values->getClimatVal(TEMPERATURE)->getCurrent());
    Serial.print("\t");
    Serial.print(values->getClimatVal(TEMPERATURE)->getTarget());
    Serial.print("\t");
    Serial.print(values->getClimatVal(TEMPERATURE)->getOutput());


    //  Serial.print(" H: ");


    Serial.print("\t");
    Serial.print(values->getClimatVal(HUMIDITY)->getCurrent());
    Serial.print("\t");
    Serial.print(values->getClimatVal(HUMIDITY)->getTarget());
    Serial.print("\t");
    Serial.print(values->getClimatVal(HUMIDITY)->getOutput());


    Serial.print("\t");
    Serial.print((int) values->getClimatVal(CO2)->getCurrent());
    Serial.print("\t");
    Serial.print(values->getClimatVal(CO2)->getTarget());
    Serial.print("\t");
    Serial.print(values->getClimatVal(CO2)->getOutput());


    //  Serial.print(" relays:");

    Serial.print("\t");
    Serial.print(!digitalRead(HUMIDIFICATION_RELAY_PIN));
    // Serial.print("\t");
    Serial.print(!digitalRead(HEATING_RELAY_PIN));
    // Serial.print("\t");
    Serial.print(!digitalRead(COOLING_RELAY_PIN));
    // Serial.print("\t");
    Serial.print(!digitalRead(VENTILATION_RELAY_PIN));
/*     Serial.print("\t");
     Serial.print(DebugUtils::getfreeRam());*/
    Serial.print("\n");
    Serial.flush();
}
