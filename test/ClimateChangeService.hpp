#ifndef CHANGESERVICE_HPP
#define CHANGESERVICE_HPP

#include <DHT.h>
#include "Arduino.h"
#include "../climate/Values.h"

class ClimateChangeService{
    DHT *dht;
    Values * values;
    long updateTempPreviousMillis = 0;
public:
    void update(unsigned long currentMillis );

    ClimateChangeService(DHT *pDHT, Values *pValues);
};


#endif //TEST_CLIMATE_СLIMATEСHANGESERVICE_HPP
