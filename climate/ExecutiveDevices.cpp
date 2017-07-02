//
// Created by vst on 5/21/17.
//

#include "ExecutiveDevices.hpp"

ExecutiveDevices::ExecutiveDevices(Relays *relays, ServoMotors *servoMotors) {
    this->relays = relays;
    this->servoMotors = servoMotors;
}

void ExecutiveDevices::update(Values *values) {
    temperature(values);
    humidity(values);
    co2(values);
}

void ExecutiveDevices::temperature(Values *values) {
    Value *val = values->getClimatVal(TEMPERATURE);

    relays->heating(val->getHeating());
    relays->cooling(val->getCooling());
}

void ExecutiveDevices::humidity(Values *values) {
    Value *val = values->getClimatVal(HUMIDITY);
    relays->humidification(val->getHumidity());
}

void ExecutiveDevices::co2(Values *values) {
    Value *val = values->getClimatVal(CO2);
   // servoMotors->ventilation(values->getClimatVal(CO2)->getOutput());
    relays->ventilation(val->getVentilation());
}

