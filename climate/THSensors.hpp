#ifndef Sensors_h
#define Sensors_h


#include "DHT.h"
#include "Values.h"
#include "IntervalWorkerBase.hpp"
#include <Adafruit_BME280.h>

class THSensors : public IntervalWorkerBase {
#define BME_280_ADDRESS 0x76
    Adafruit_BME280 bme;
#define RANGE_FILTER 5

    float hFilter[RANGE_FILTER];
    float tFilter[RANGE_FILTER];
public:

    THSensors(int interval);

    void work(Values *values, unsigned long currentMillis) override;
float _getVal(float values[], float current);
};

#endif
