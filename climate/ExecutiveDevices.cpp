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
    int val = values->getClimatVal(TEMPERATURE)->getOutput();
    if (val == 0) {
        servoMotors->cooling(0);
        servoMotors->heating(0);
        return;
    }

    if (val > 0) { ///охлаждать
        servoMotors->cooling(abs(val));
    } else if (val < 0) { ///нагревать
        servoMotors->heating(abs(val));
    }
}

void ExecutiveDevices::humidity(Values *values) {
    int val = values->getClimatVal(HUMIDITY)->getOutput();
    if (val == 0) {
        servoMotors->humidification(0);
        relays->humidification(0);
        return;
    }
    if (val > 0) { ///осушать
        servoMotors->humidification(val);
    } else if (val < 0) { ///увлажнять
        relays->humidification(1);
    }
}

void ExecutiveDevices::co2(Values *values) {
    servoMotors->ventilation(values->getClimatVal(CO2)->getOutput());
}

