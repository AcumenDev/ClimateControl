#include "ClimateControl.hpp"

ClimateControl::ClimateControl(Values *values, Relays *relays, int interval)
        : IntervalWorckerBase(interval) {
    this->values = values;
    this->relays = relays;
    this->gisteris = 1.0f;
    this->workType = OFF;
    this->timestamp = 0;
    this->waitingTime = 60 * 5 * 1000;
}

void ClimateControl::update(unsigned long currentMillis) {
     if (!isWorkTime(currentMillis)) {
        return;
    }

    temperatureControl(currentMillis);
    humidityControl();
}

void ClimateControl::humidityControl() {
    if (values->humidity < values->targetHumidity) {
        relays->humidificationOn();
    } else if (values->humidity >= values->targetHumidity) {
        relays->humidificationOff();
    }
}


void ClimateControl::temperatureControl(unsigned long currentMillis) {
    switch (workType) {
        case OFF: {
            if (values->temperature < values->targetTemperature) {
                heating(currentMillis);
            } else if (values->temperature > values->targetTemperature) {
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

    if (values->temperature < values->targetTemperature) {
        if (workType == HEATING) {
            if (values->temperature < (values->targetTemperature - gisteris)) {
                relays->heatingOn();
            }
        }
        else {
            workType = HEATING;
            relays->heatingOn();
        }
    } else if (values->temperature >= values->targetTemperature) {
        relays->heatingOff();

        if (values->temperature > values->targetTemperature + gisteris) {
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
    if (values->temperature > values->targetTemperature) {
        if (workType == COOLING) {
            if (values->temperature > (values->targetTemperature + gisteris)) {
                relays->coolingOn();
            }
        } else {
            workType = COOLING;
            relays->coolingOn();
        }
    } else if (values->temperature <= values->targetTemperature) {
        relays->coolingOff();

        if (values->temperature < values->targetTemperature - gisteris) {
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
