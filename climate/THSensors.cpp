#include "THSensors.hpp"

THSensors::THSensors(uint8_t sensorPin, int interval, Values *values)
        : IntervalWorckerBase(interval) {
    this->values = values;
    dht = new DHT(sensorPin, DHT22);
    dht->begin();
    for (uint8_t i = 0; i < ARITHMETIC_SUM_SIZE; i++) {
        temperatureValuesTick[i] = 0;
    }
}

void THSensors::work(unsigned long currentMillis) {
    values->setCurrentValue(HUMIDITY, _getHumidity(dht->readHumidity()));
    values->setCurrentValue(TEMPERATURE, _getTemperature(dht->readTemperature()));
}

float THSensors::_getTemperature(float currentTemperature) {
    temperatureValuesTick[temperatureIndexStack] = currentTemperature;
    if (temperatureIndexStack == ARITHMETIC_SUM_SIZE - 1) {
        temperatureIndexStack = 0;
    } else {
        temperatureIndexStack++;
    }

    float temperatureSum = 0;
    uint8_t count = 0;
    for (uint8_t i = 0; i <= ARITHMETIC_SUM_SIZE - 1; i++) {
        if (temperatureValuesTick[i] != 0) {
            temperatureSum = temperatureSum + temperatureValuesTick[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return temperatureSum / count;
}

float THSensors::_getHumidity(float currentHumidity) {
    humidityValuesTick[humidityIndexStack] = currentHumidity;
    if (humidityIndexStack == ARITHMETIC_SUM_SIZE - 1) {
        humidityIndexStack = 0;
    } else {
        humidityIndexStack++;
    }

    float humiditySum = 0;
    uint8_t count = 0;
    for (uint8_t i = 0; i <= ARITHMETIC_SUM_SIZE - 1; i++) {
        if (humidityValuesTick[i] != 0) {
            humiditySum = humiditySum + humidityValuesTick[i];
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return humiditySum / count;
}