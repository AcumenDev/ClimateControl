//
// Created by vst on 5/21/17.
//

#ifndef TEST_CLIMATE_ADAFRUIT_BME280_H
#define TEST_CLIMATE_ADAFRUIT_BME280_H

class Adafruit_BME280 {
public:
    float temperature = 0;
    float humanity = 0;

    bool begin(uint8_t addr) {
        return true;
    }

    float readHumidity() {
        return humanity;
    }

    float readTemperature() {
        return temperature;
    }

    void setTemperature(float val) {
        temperature = val;
    }

    void setHumanity(float val) {
        humanity = val;
    }
};

#endif //TEST_CLIMATE_ADAFRUIT_BME280_H
