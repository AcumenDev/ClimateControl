#include "HumidityControl.hpp"

HumidityControl::HumidityControl(float Kp, float Ki, float Kd, int interval) : IntervalWorckerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-180, 180);
}

void HumidityControl::work(Values *values, unsigned long millis) {
    inputValue = values->getClimatVal(HUMIDITY)->getCurrent();
    targetValue = values->getClimatVal(HUMIDITY)->getTarget();
    pid->Compute();
    values->getClimatVal(HUMIDITY)->setOutput((int) outputValue);
}
