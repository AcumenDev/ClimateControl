//
// Created by vladimir on 12/18/16.
//

#ifndef TEST_CLIMATE_DHT_H
#define TEST_CLIMATE_DHT_H

#include <cstdint>

#define DHT22 1

class DHT {
public:
    DHT(uint8_t pin, uint8_t type);
    void begin(void);
    float readTemperature(bool S=false, bool force=false);
    float readHumidity(bool force=false);
};


#endif //TEST_CLIMATE_DHT_H
