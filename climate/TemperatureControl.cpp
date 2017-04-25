#include "TemperatureControl.hpp"

TemperatureControl::TemperatureControl(float Kp, float Ki, float Kd, int interval) : IntervalWorckerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-255, 255);
}

void TemperatureControl::work(Values *values, unsigned long currentMillis) {
    inputValue = values->getCurrentValue(TEMPERATURE);
    targetValue = values->getTarget(TEMPERATURE);
    pid->Compute();
    values->setOutputValue(TEMPERATURE, outputValue);
}