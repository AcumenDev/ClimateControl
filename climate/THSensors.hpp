#ifndef Sensors_h
#define Sensors_h


#include "DHT.h"
#include "Values.h"
#include "IntervalWorkerBase.hpp"
#include <Adafruit_BME280.h>

class THSensors : public IntervalWorckerBase {
#define BME_280_ADDRESS 0x76
    Adafruit_BME280 bme;

public:

    THSensors(int interval);

    void work(Values *values, unsigned long currentMillis) override;

};

#endif
