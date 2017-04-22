//
// Created by vst on 4/22/17.
//

#ifndef TEST_CLIMATE_CO2SENSOR_HPP
#define TEST_CLIMATE_CO2SENSOR_HPP

#include <SoftwareSerial.h>
#include "IntervalWorkerBase.hpp"
#include "Values.h"
#include "string.h"

class CO2Sensor : public IntervalWorckerBase {
    SoftwareSerial *serial;
    byte readCO2Command[9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
    Values *values;
    unsigned char response[9];

    float _getCO2();

public:

    CO2Sensor(uint8_t sensorTXPin, uint8_t sensorRXPin, int interval, Values *values);

    void work(unsigned long currentMillis);

};

#endif //TEST_CLIMATE_CO2SENSOR_HPP
