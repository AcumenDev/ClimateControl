//
// Created by vst on 4/23/17.
//

#include "CO2Control.hpp"

CO2Control::CO2Control(float Kp, float Ki, float Kd, int interval) : IntervalWorckerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-180, 180);
}

void CO2Control::work(Values *values, unsigned long millis) {
    inputValue = values->getCurrentValue(CO2);
    targetValue = values->getTarget(CO2);
    pid->Compute();

    if (outputValue > 0) {
        outputValue = 0;
    } else {
        outputValue = abs(outputValue);
    }
    values->setOutputValue(CO2, outputValue);
}
