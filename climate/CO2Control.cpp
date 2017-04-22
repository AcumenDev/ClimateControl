//
// Created by vst on 4/23/17.
//

#include "CO2Control.hpp"


CO2Control::CO2Control(Values *values) {
    this->values = values;
    inputValue = values->getCurrentValue(CO2);
    targetValue = values->getTarget(CO2);

    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
}

void CO2Control::update() {
    inputValue = values->getCurrentValue(CO2);
    targetValue = values->getTarget(CO2);

    pid->Compute();
    DEBUG_PRINT(outputValue);
}
