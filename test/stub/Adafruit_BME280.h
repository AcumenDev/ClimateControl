//
// Created by vst on 5/21/17.
//

#ifndef TEST_CLIMATE_ADAFRUIT_BME280_H
#define TEST_CLIMATE_ADAFRUIT_BME280_H

class Adafruit_BME280 {
public:
    bool begin(uint8_t addr) {
        return true;
    }

    float readHumidity() {
        return 0;
    }

    float readTemperature() {
        return 0;
    }
};

#endif //TEST_CLIMATE_ADAFRUIT_BME280_H
