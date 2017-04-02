#include "ClimateControl.hpp"

ClimateControl::ClimateControl(Values *values, Relays *relays, int interval)
        : IntervalWorckerBase(interval) {
    this->values = values;
    this->relays = relays;
    this->temperatureGisteris = 1.0f;
    this->humidityGisteris = 1.0f;
    this->workType = OFF;
    this->timestamp = 0;
  //  this->waitingTime = 60 * 5 * 1000;
}

void ClimateControl::update(unsigned long currentMillis) {
    if (!isWorkTime(currentMillis)) {
        return;
    }

    temperatureControl(currentMillis);
    humidityControl();
}

void ClimateControl::humidityControl() {
    if (values->getCurrentValue(HUMIDITY) < values->getTarget(HUMIDITY) -  values->getGisteris(HUMIDITY)) {
        relays->humidificationOn();
    } else if (values->getCurrentValue(HUMIDITY) >= values->getTarget(HUMIDITY)) {
        relays->humidificationOff();
    }
}

void ClimateControl::temperatureControl(unsigned long currentMillis) {
    switch (workType) {
        case OFF: {
            if (values->getCurrentValue(TEMPERATURE) < values->getTarget(TEMPERATURE)) {
                heating(currentMillis);
            } else if (values->getCurrentValue(TEMPERATURE) > values->getTarget(TEMPERATURE)) {
                cooling(currentMillis);
            }
            break;
        }
        case HEATING: {
            heating(currentMillis);
            break;
        }
        case COOLING: {
            cooling(currentMillis);
            break;
        }
    }
}


void ClimateControl::heating(unsigned long currentMillis) {

    if (values->getCurrentValue(TEMPERATURE) < values->getTarget(TEMPERATURE)) {
        if (workType == HEATING) {
            if (values->getCurrentValue(TEMPERATURE) < (values->getTarget(TEMPERATURE) - values->getGisteris(TEMPERATURE))) {
                relays->heatingOn();
            }
        } else {
            workType = HEATING;
            relays->heatingOn();
        }
    } else if (values->getCurrentValue(TEMPERATURE) >= values->getTarget(TEMPERATURE)) {
        relays->heatingOff();

        if (values->getCurrentValue(TEMPERATURE) > values->getTarget(TEMPERATURE) + values->getGisteris(TEMPERATURE)) {
            //       if (timestamp == 0) {
            //           timestamp = currentMillis;
            //        }

            //     if (currentMillis - timestamp >= waitingTime) {
            this->workType = OFF;
            timestamp = 0;
            //        }
            //        if (values->temperature <= values->targetTemperature) {
            //            timestamp = 0;
            //         }
        }
    }
}


void ClimateControl::cooling(unsigned long currentMillis) {
    if (values->getCurrentValue(TEMPERATURE) > values->getTarget(TEMPERATURE)) {
        if (workType == COOLING) {
            if (values->getCurrentValue(TEMPERATURE) > (values->getTarget(TEMPERATURE) + values->getGisteris(TEMPERATURE))) {
                relays->coolingOn();
            }
        } else {
            workType = COOLING;
            relays->coolingOn();
        }
    } else if (values->getCurrentValue(TEMPERATURE) <= values->getTarget(TEMPERATURE)) {
        relays->coolingOff();

        if (values->getCurrentValue(TEMPERATURE) < values->getTarget(TEMPERATURE) - values->getGisteris(TEMPERATURE)) {
            // if (timestamp == 0) {
            //      timestamp = currentMillis;
            //  }

            //    if (currentMillis - timestamp >= waitingTime) {
            this->workType = OFF;
            timestamp = 0;
            //     }
        }
        //    if (values->temperature >= values->targetTemperature) {
        //       timestamp = 0;
        //   }
    }
}
