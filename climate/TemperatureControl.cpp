#include "TemperatureControl.hpp"

TemperatureControl::TemperatureControl(float Kp, float Ki, float Kd, int interval) : IntervalWorckerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-180, 180);

    _setWorkType(OFF);
}

void TemperatureControl::work(Values *values, unsigned long) {

    Value *temperatureVal = values->getClimatVal(TEMPERATURE);

    inputValue = temperatureVal->getCurrent();
    targetValue = temperatureVal->getTarget();
    pid->Compute();
    temperatureVal->setOutput((int) outputValue);

    control_v1(temperatureVal);
}

void TemperatureControl::control_v1(Value *value) {
    switch (workType) {
        case OFF: {
            if (value->getCurrent() < value->getTarget() - (value->getGisteris() / 2)) {
                _setWorkType(HEATING);
                heating(value);
            } else if (value->getCurrent() > value->getTarget() + (value->getGisteris() / 2)) {
                _setWorkType(COOLING);
                cooling(value);
            }
            break;
        }
        case HEATING: {
            heating(value);
            break;
        }
        case COOLING: {
            cooling(value);
            break;
        }
    }
}

void TemperatureControl::heating(Value *value) {
    if (value->getCurrent() >= value->getTarget() + value->getGisteris()) {
        value->setHeating(false);
        _setWorkType(OFF);
    } else {
        value->setHeating(value->getCurrent() < value->getTarget());
    }
}

void TemperatureControl::cooling(Value *value) {
    if (value->getCurrent() <= value->getTarget() - value->getGisteris()) {
        value->setCooling(false);
        _setWorkType(OFF);
    } else {
        value->setCooling(value->getCurrent() > value->getTarget());
    }
}

void TemperatureControl::_setWorkType(TemperatureControl::WorkType type) {
    workType = type;
}
