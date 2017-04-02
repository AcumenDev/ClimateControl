#ifndef VALUES_H
#define VALUES_H

#include "Arduino.h"
#include "EEPROM.h"
#include "Value.hpp"

#define TARGET_TEMPERATURE_EEPROM_ADR 0
#define TARGET_HUMIDITY_EEPROM_ADR 1
#define TARGET_CO2_EEPROM_ADR 3

#define MIN_TARGET_HUMIDITY 20
#define MAX_TARGET_HUMIDITY 100
#define HUMIDITY_GISTERIS 2

#define MIN_TARGET_TEMPERATURE 10
#define MAX_TARGET_TEMPERATURE 40
#define TEMPERATURE_GISTERIS 1

#define MIN_TAGET_CO2 300
#define MAX_TAGET_CO2 1500
#define CO2_GISTERIS 100


enum TYPE_CLIMATE_VALUE {
    TEMPERATURE = 0,
    HUMIDITY = 1,
    CO2 = 2
};

class Values {
public:

    unsigned long changeTimeStamp = 0;
    bool changed = false;

    Value *climateValues[3];

    unsigned int changeDelay = 1500;

    unsigned char currentSelection = TYPE_CLIMATE_VALUE::TEMPERATURE;

    Values() {
        climateValues[TYPE_CLIMATE_VALUE::TEMPERATURE] = new Value(MIN_TARGET_TEMPERATURE, MAX_TARGET_TEMPERATURE,
                                                                   TEMPERATURE_GISTERIS);
        climateValues[TYPE_CLIMATE_VALUE::HUMIDITY] = new Value(MIN_TARGET_HUMIDITY, MAX_TARGET_HUMIDITY,
                                                                HUMIDITY_GISTERIS);
        climateValues[TYPE_CLIMATE_VALUE::CO2] = new Value(MIN_TAGET_CO2, MAX_TAGET_CO2, CO2_GISTERIS);

    }

    void loadFromEEprom() {
        climateValues[TYPE_CLIMATE_VALUE::TEMPERATURE]->setTarget((int) EEPROM.read(TARGET_TEMPERATURE_EEPROM_ADR));
        climateValues[TYPE_CLIMATE_VALUE::HUMIDITY]->setTarget((int) EEPROM.read(TARGET_HUMIDITY_EEPROM_ADR));
        //   climateValues[TYPE_CLIMATE_VALUE::CO2].setTarget((int) EEPROM.read(TARGET_CO2_EEPROM_ADR)); ///// FIXME Не прочтет так как 2 байта
    }

    void saveToEEprom() { //// FIXME Не прочтет так как 2 байта
        //  EEPROM.update(TARGET_TEMPERATURE_EEPROM_ADR, (byte) targetTemperature);
        //   EEPROM.update(TARGET_HUMIDITY_EEPROM_ADR, (byte) targetHumidity);
    }

    bool isAfterChange(unsigned long currentMillis) {
        return currentMillis - changeTimeStamp < changeDelay;
    }

    void update(unsigned long currentMillis) {
        if (!changed) {
            return;
        }

        if (currentMillis - changeTimeStamp > changeDelay) {
            saveToEEprom();
            changed = false;
        }
    }

    void changeSelection(unsigned long currentMillis) {
        if (currentSelection < TYPE_CLIMATE_VALUE::CO2) {
            currentSelection++;
        } else {
            currentSelection = TYPE_CLIMATE_VALUE::TEMPERATURE;
        }
        setTimestamp(currentMillis);
    }

    void plus(unsigned long currentMillis) {
        climateValues[currentSelection]->plus(currentMillis);
        setTimestamp(currentMillis);
    }

    void minus(unsigned long currentMillis) {
        climateValues[currentSelection]->minus(currentMillis);
        setTimestamp(currentMillis);
    }

    int getTarget(TYPE_CLIMATE_VALUE climateValue) {
        climateValues[climateValue]->getTarget();
    }

    int getGisteris(TYPE_CLIMATE_VALUE climateValue) {
        climateValues[climateValue]->getGisteris();
    }

    float getCurrentValue(TYPE_CLIMATE_VALUE climateValue) {
        climateValues[climateValue]->getCurrent();
    }


    void setTarget(TYPE_CLIMATE_VALUE climateValue, int target) {
        climateValues[climateValue]->setTarget(target);
    }

    void setCurrentValue(TYPE_CLIMATE_VALUE climateValue, float value) {
        climateValues[climateValue]->setCurrent(value);
    }


private:
    void setTimestamp(unsigned long currentMillis) {
        changeTimeStamp = currentMillis;
        changed = true;
    }
};

#endif
