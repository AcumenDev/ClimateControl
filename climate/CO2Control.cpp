//
// Created by vst on 4/23/17.
//

#include "CO2Control.hpp"

CO2Control::CO2Control(float Kp, float Ki, float Kd, int interval) : IntervalWorkerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-180, 180);
}

void CO2Control::work(Values *values, unsigned long millis) {

    Value *value = values->getClimatVal(CO2);

    inputValue = value->getCurrent();

    if (inputValue < 100) {
        value->setVentilation(false);
        value->setOutput(0);
        return;
    }
    targetValue = value->getTarget();
    pid->Compute();

    if (outputValue > 0) {
        outputValue = 0;
    } else {
        outputValue = abs(outputValue);
    }
    value->setOutput((int) outputValue);

    if (value->getCurrent() <= value->getTarget() - value->getGisteris()) {
        value->setVentilation(false);
    } else {
        value->setVentilation(value->getCurrent() >= value->getTarget() + value->getGisteris());
    }
}
