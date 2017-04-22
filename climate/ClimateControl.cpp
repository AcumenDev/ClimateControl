#include "ClimateControl.hpp"

ClimateControl::ClimateControl(Values *values, Relays *relays, int interval)
        : IntervalWorckerBase(interval) {
    this->values = values;
    this->relays = relays;
    this->workType = OFF;
}

void ClimateControl::work(unsigned long currentMillis) {
    temperatureControl();
    humidityControl();
    co2Control();
}

void ClimateControl::temperatureControl() {
    switch (workType) {
        case OFF: {
            if (values->getCurrentValue(TEMPERATURE) < values->getTarget(TEMPERATURE)) {
                heating();
            } else if (values->getCurrentValue(TEMPERATURE) > values->getTarget(TEMPERATURE)) {
                cooling();
            }
            break;
        }
        case HEATING: {
            heating();
            break;
        }
        case COOLING: {
            cooling();
            break;
        }
    }
}

void ClimateControl::heating() {
    if (values->getCurrentValue(TEMPERATURE) < values->getTarget(TEMPERATURE)) {
        if (workType == HEATING) {
            if (values->getCurrentValue(TEMPERATURE) <
                (values->getTarget(TEMPERATURE) - values->getGisteris(TEMPERATURE))) {
                relays->heatingOn();
            }
        } else {
            workType = HEATING;
            relays->heatingOn();
        }
    } else if (values->getCurrentValue(TEMPERATURE) >= values->getTarget(TEMPERATURE)) {
        relays->heatingOff();
        if (values->getCurrentValue(TEMPERATURE) > values->getTarget(TEMPERATURE) + values->getGisteris(TEMPERATURE)) {
            this->workType = OFF;
        }
    }
}


void ClimateControl::cooling() {
    if (values->getCurrentValue(TEMPERATURE) > values->getTarget(TEMPERATURE)) {
        if (workType == COOLING) {
            if (values->getCurrentValue(TEMPERATURE) >
                (values->getTarget(TEMPERATURE) + values->getGisteris(TEMPERATURE))) {
                relays->coolingOn();
            }
        } else {
            workType = COOLING;
            relays->coolingOn();
        }
    } else if (values->getCurrentValue(TEMPERATURE) <= values->getTarget(TEMPERATURE)) {
        relays->coolingOff();

        if (values->getCurrentValue(TEMPERATURE) < values->getTarget(TEMPERATURE) - values->getGisteris(TEMPERATURE)) {
            this->workType = OFF;
        }
    }
}


void ClimateControl::humidityControl() {
    if (values->getCurrentValue(HUMIDITY) < values->getTarget(HUMIDITY) - values->getGisteris(HUMIDITY)) {
        relays->humidificationOn();
    } else if (values->getCurrentValue(HUMIDITY) >= values->getTarget(HUMIDITY)) {
        relays->humidificationOff();
    }
}


void ClimateControl::co2Control() {
    if (values->getCurrentValue(CO2) > values->getTarget(CO2)) {
        relays->ventilationOn();
    } else if (values->getCurrentValue(CO2) < (values->getTarget(CO2) - values->getGisteris(CO2))) {
        relays->ventilationOff();
    }
}
