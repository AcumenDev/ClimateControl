#ifndef VALUES_H
#define VALUES_H


#include "Arduino.h"
#include "EEPROM.h"


#define TARGET_TEMPERATURE_EEPROM_ADR 0
#define TARGET_HUMIDITY_EEPROM_ADR 1


class Values {
public:

    float humidity;
    float temperature;
    float targetHumidity;
    float targetTemperature;

    char maxHumidity = 99;
    char minHumidity = 40;
    char maxtargetTemperature = 30;
    char mintargetTemperature = 10;
    unsigned long changeTimeStamp = 0;
    bool changed = false;

    bool control = true;

    int changeDelay = 2000;

    Values() {
        humidity = 0;
        temperature = 0;

        ////загрузить из памяти
        targetHumidity = 70;
        targetTemperature = 20;
    }

    void controlSet() {
        control = !control;
    }


    void loadFromEEprom() {
        byte saveTargetTemperature = EEPROM.read(TARGET_TEMPERATURE_EEPROM_ADR);
        byte saveTargetHumidity = EEPROM.read(TARGET_HUMIDITY_EEPROM_ADR);

        if (saveTargetTemperature >= mintargetTemperature && saveTargetTemperature <= maxtargetTemperature) {
            targetTemperature = (int) saveTargetTemperature;
        }
        if (saveTargetHumidity >= minHumidity && saveTargetHumidity <= maxHumidity) {
            targetHumidity = (int) saveTargetHumidity;
        }
    }

    void saveToEEprom() {
        EEPROM.update(TARGET_TEMPERATURE_EEPROM_ADR, (byte) targetTemperature);
        EEPROM.update(TARGET_HUMIDITY_EEPROM_ADR, (byte) targetHumidity);
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

    void plusTemp(unsigned long currentMillis) {
        if (targetTemperature < maxtargetTemperature) {
            targetTemperature++;

        }
        setTimestamp(currentMillis);
    }

    void minusTemp(unsigned long currentMillis) {
        if (targetTemperature > mintargetTemperature) {
            targetTemperature--;
        }
        setTimestamp(currentMillis);
    }

    void plusHumidity(unsigned long currentMillis) {
        if (targetHumidity < maxHumidity) {
            targetHumidity++;
        }
        setTimestamp(currentMillis);
    }

    void minusHumidity(unsigned long currentMillis) {
        if (targetHumidity > minHumidity) {
            targetHumidity--;
        }
        setTimestamp(currentMillis);
    }

private:
    void setTimestamp(unsigned long currentMillis) {
        changeTimeStamp = currentMillis;
        changed = true;
    }
};

#endif
