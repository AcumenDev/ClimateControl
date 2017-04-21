#ifndef VALUES_H
#define VALUES_H

#include "Arduino.h"
#include "EEPROM.h"
#include "Value.hpp"
#include "Config.hpp"

#include "DebugUtils.hpp"
#include "EEPROMUtils.hpp"

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

    int currentSelection = TYPE_CLIMATE_VALUE::TEMPERATURE;

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

        int co2eepromValue;
        EEPROM_readAnything(TARGET_CO2_EEPROM_ADR, co2eepromValue);
        climateValues[TYPE_CLIMATE_VALUE::CO2]->setTarget(co2eepromValue);
    }

    void saveToEEprom() {
        EEPROM_writeAnything(TARGET_TEMPERATURE_EEPROM_ADR,climateValues[TYPE_CLIMATE_VALUE::TEMPERATURE]->getTarget());
        EEPROM_writeAnything(TARGET_HUMIDITY_EEPROM_ADR,climateValues[TYPE_CLIMATE_VALUE::HUMIDITY]->getTarget());
        EEPROM_writeAnything(TARGET_CO2_EEPROM_ADR,climateValues[TYPE_CLIMATE_VALUE::CO2]->getTarget());
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
        DEBUG_PRINT("select: ");
        DEBUG_PRINT(currentSelection);

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
        return climateValues[climateValue]->getTarget();
    }

    int getGisteris(TYPE_CLIMATE_VALUE climateValue) {
        return climateValues[climateValue]->getGisteris();
    }

    float getCurrentValue(TYPE_CLIMATE_VALUE climateValue) {
        return climateValues[climateValue]->getCurrent();
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
