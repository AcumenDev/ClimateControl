#include "ClimateChangeService.hpp"



ClimateChangeService::ClimateChangeService(DHT *pDHT, Values *pValues) {
    dht = pDHT;
    values = pValues;
}

void ClimateChangeService::update(unsigned long currentMillis) {
    if ((currentMillis - updateTempPreviousMillis) < 1000) {
        return;
    }
    int Temperature = 2;
    float cof = 0.005;

    float cofPribor = 0.006;
    if (values->temperature > Temperature) {
        values->temperature = values->temperature - cof;
        dht->setTemp(dht->readTemperature()-cof);
    } else if (values->temperature < Temperature) {
        dht->setTemp(dht->readTemperature()+cof);
    }


    int Humidity = 55;
    float cofHumidity = 0.005;

    float cofPriborHumidity = 0.006;
    if (values->humidity > Humidity) {
        values->humidity = values->humidity - cofHumidity;
        dht->setHumidity(dht->readHumidity()-cofHumidity);
    } else if (values->humidity < Humidity) {
        dht->setHumidity(dht->readHumidity()+cofHumidity);
    }



/*    if (currentMillis - startTime < hour6) {
        Temperature = -22;
    } else if (currentMillis - startTime < hour12) {
        Temperature = 0;
    } else if (currentMillis - startTime < hour18) {
        Temperature = 15;
    } else if (currentMillis - startTime < hour24) {
        Temperature = -20;
    }*/








/*
    if (values->humidity > Humidity) {
        values->humidity = values->humidity - cof;
    } else if (values->humidity < Humidity) {
        values->humidity = values->humidity + cof;
    }*/


    if (!digitalRead(HUMIDIFICATION_RELAY_PIN)) {
      dht->setHumidity(dht->readHumidity()+cofPriborHumidity);
    }
    if (!digitalRead(HEATING_RELAY_PIN)) {
        dht->setTemp(dht->readTemperature()+cofPribor);
    }
    if (!digitalRead(COOLING_RELAY_PIN)) {
        dht->setTemp(dht->readTemperature()-cofPribor);
    }


    updateTempPreviousMillis = currentMillis;
}

