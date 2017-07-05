#include "THSensors.hpp"

THSensors::THSensors(int interval)
        : IntervalWorckerBase(interval) {

    for (int i = 0; i < RANGE_FILTER; i++) {
        tFilter[i] = 0;
        hFilter[i] = 0;
    }

    bool status = bme.begin(BME_280_ADDRESS);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
}

void THSensors::work(Values *values, unsigned long currentMillis) {
    values->getClimatVal(HUMIDITY)->setCurrent(_getVal(hFilter,bme.readHumidity()));
    values->getClimatVal(TEMPERATURE)->setCurrent(_getVal(tFilter,bme.readTemperature()));
    // bme.readPressure() / 100.0F
}

float THSensors::_getVal(float *values, float current) {
    for (int i = 0; i < RANGE_FILTER; i++) {
        values[i] = values[i + 1];
    }
    values[RANGE_FILTER - 1] = current;

    float result = 0;
    int count = 0;
    for (int i = 0; i < RANGE_FILTER; i++) {
        if (values[i] > 0) {
            result += values[i];
            count++;
        }
    }
    return result / count;
}
