#include "HumidityControl.hpp"

HumidityControl::HumidityControl(float Kp, float Ki, float Kd, int interval) : IntervalWorkerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-180, 180);
}

void HumidityControl::work(Values *values, unsigned long millis) {
    Value *value = values->getClimatVal(HUMIDITY);

    inputValue = value->getCurrent();
    targetValue = value->getTarget();
    pid->Compute();
    value->setOutput((int) outputValue);

    if (value->getCurrent() >= value->getTarget() + value->getGisteris()) {
        value->setHumidity(false);
    } else {
        value->setHumidity(value->getCurrent() < value->getTarget() - value->getGisteris());
    }
}
