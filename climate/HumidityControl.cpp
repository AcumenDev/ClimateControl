//
// Created by vst on 4/26/17.
//

#include "HumidityControl.hpp"

HumidityControl::HumidityControl(float Kp, float Ki, float Kd, int interval) : IntervalWorckerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-255, 255);
}

void HumidityControl::work(Values *values, unsigned long currentMillis) {
    inputValue = values->getCurrentValue(HUMIDITY);
    targetValue = values->getTarget(HUMIDITY);
    pid->Compute();
    values->setOutputValue(HUMIDITY, outputValue);
}
