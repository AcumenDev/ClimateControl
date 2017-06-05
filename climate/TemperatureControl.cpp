#include "TemperatureControl.hpp"

TemperatureControl::TemperatureControl(float Kp, float Ki, float Kd, int interval) : IntervalWorckerBase(interval) {
    pid = new PIDT<float>(&inputValue, &outputValue, &targetValue, Kp, Ki, Kd, DIRECT);
    pid->SetMode(AUTOMATIC);
    pid->SetSampleTime(interval);
    pid->SetOutputLimits(-180, 180);

    workType = OFF;
}

void TemperatureControl::work(Values *values, unsigned long currentMillis) {

    Value *temperatureVal = values->getClimatVal(TEMPERATURE);

    inputValue = temperatureVal->getCurrent();
    targetValue = temperatureVal->getTarget();
    pid->Compute();
    temperatureVal->setOutput((int) outputValue);

    control_v1(temperatureVal, currentMillis);
}

void TemperatureControl::control_v1(Value *value, unsigned long currentMillis) {
    switch (workType) {
        case OFF: {
            if (value->getCurrent() < value->getTarget()) {
                heating(value, currentMillis);
            } else if (value->getCurrent() > value->getTarget()) {
                cooling(value, currentMillis);
            }
            break;
        }
        case HEATING: {
            heating(value, currentMillis);
            break;
        }
        case COOLING: {
            cooling(value, currentMillis);
            break;
        }
    }
}


void TemperatureControl::heating(Value *value, unsigned long currentMillis) {

    if (value->getCurrent() < value->getTarget()) {
        if (workType == HEATING) {
            if (value->getCurrent() <
                (value->getTarget() - value->getGisteris())) {
         //       relays->heatingOn();
            }
        } else {
            workType = HEATING;
        //    relays->heatingOn();
        }
    } else if (value->getCurrent() >= value->getTarget()) {
      //  relays->heatingOff();

        if (value->getCurrent() > value->getTarget() + value->getGisteris()) {
            //       if (timestamp == 0) {
            //           timestamp = currentMillis;
            //        }

            //     if (currentMillis - timestamp >= waitingTime) {
            this->workType = OFF;
            //timestamp = 0;
            //        }
            //        if (value->getCurrent() <= value->targetTemperature) {
            //            timestamp = 0;
            //         }
        }
    }
}


void TemperatureControl::cooling(Value *value, unsigned long currentMillis) {
    if (value->getCurrent() > value->getTarget()) {
        if (workType == COOLING) {
            if (value->getCurrent() >
                (value->getTarget() + value->getGisteris())) {
    //            relays->coolingOn();
            }
        } else {
            workType = COOLING;
    //        relays->coolingOn();
        }
    } else if (value->getCurrent() <= value->getTarget()) {
    //    relays->coolingOff();

        if (value->getCurrent() < value->getTarget() - value->getGisteris()) {
            // if (timestamp == 0) {
            //      timestamp = currentMillis;
            //  }

            //    if (currentMillis - timestamp >= waitingTime) {
            this->workType = OFF;
            //timestamp = 0;
            //     }
        }
        //    if (value->getCurrent() >= value->target) {
        //       timestamp = 0;
        //   }
    }
}