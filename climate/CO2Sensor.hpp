//
// Created by vst on 4/22/17.
//

#ifndef TEST_CLIMATE_CO2SENSOR_HPP
#define TEST_CLIMATE_CO2SENSOR_HPP

#include <SoftwareSerial.h>
#include "IntervalWorkerBase.hpp"
#include "Values.h"
#include "string.h"

class CO2Sensor : public IntervalWorkerBase {
    uint8_t sensorTXPin;
    uint8_t sensorRXPin;

    SoftwareSerial *co2Serial;
    byte readCO2Command[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};

    unsigned char response[9];

    float _getCO2();
    bool _stated = false;
public:
    void start();

    CO2Sensor(uint8_t sensorTXPin, uint8_t sensorRXPin, int interval);

    void work(Values *values, unsigned long currentMillis);


};

#endif //TEST_CLIMATE_CO2SENSOR_HPP
