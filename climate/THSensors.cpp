#include "THSensors.hpp"

THSensors::THSensors(int interval)
        : IntervalWorckerBase(interval) {

    bool status = bme.begin(BME_280_ADDRESS);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
}

void THSensors::work(Values *values, unsigned long currentMillis) {
    values->setCurrentValue(HUMIDITY, bme.readHumidity());
    values->setCurrentValue(TEMPERATURE, bme.readTemperature());
    // bme.readPressure() / 100.0F
}