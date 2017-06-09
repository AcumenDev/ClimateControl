#ifndef CHANGESERVICE_HPP
#define CHANGESERVICE_HPP

#include <DHT.h>
#include <Adafruit_BME280.h>
#include "Arduino.h"
#include "../climate/Values.h"

class ClimateChangeService{
    Adafruit_BME280 *bme280;
    Values * values;
    long updateTempPreviousMillis = 0;
public:
    void update(unsigned long currentMillis );

    ClimateChangeService(Adafruit_BME280 *bme280, Values *pValues);
};


#endif //TEST_CLIMATE_СLIMATEСHANGESERVICE_HPP
