#ifndef Sensors_h
#define Sensors_h

#include "DHT.h"
#include "Values.h"
#include "IntervalWorkerBase.hpp"

#define ARITHMETIC_SUM_SIZE 10

class THSensors : public IntervalWorckerBase {
    DHT *dht;
    Values *values;

    float temperatureValuesTick[ARITHMETIC_SUM_SIZE];
    float humidityValuesTick[ARITHMETIC_SUM_SIZE];
    uint8_t temperatureIndexStack = 0;
    uint8_t humidityIndexStack = 0;

    float _getTemperature(float currentTemperature);

    float _getHumidity(float currentHumidity);

public:

    THSensors(uint8_t sensorPin, int interval, Values *values);

    void work(unsigned long currentMillis);

};

#endif