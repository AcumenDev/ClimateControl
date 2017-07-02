//
// Created by vst on 4/22/17.
//


#include "CO2Sensor.hpp"

CO2Sensor::CO2Sensor(uint8_t sensorTXPin, uint8_t sensorRXPin, int interval) : IntervalWorckerBase(
        interval) {
    this->sensorRXPin = sensorRXPin;
    this->sensorTXPin = sensorTXPin;

    /*co2Serial = new SoftwareSerial(sensorTXPin, sensorRXPin);
    delay(500);
    co2Serial->begin(9600);*/
}


float CO2Sensor::_getCO2() {
    if (!_stated) {
        return 1.0f;
    }

    co2Serial->write(readCO2Command, 9);
    memset(response, 0, 9);
    co2Serial->readBytes(response, 9);
    char crc = 0;
    for (int i = 1; i < 8; i++) {
        crc += response[i];
    }
    crc = (char) (255 - crc);
    crc++;

    if (!(response[0] == 0xFF && response[1] == 0x86 && response[8] == crc)) {
        Serial.println("CRC error: ");
        Serial.println(crc + " / " + response[8]);
        Serial.println(response[8]);
        return 3.0f;
    } else {
        unsigned int responseHigh = (unsigned int) response[2];
        unsigned int responseLow = (unsigned int) response[3];
        float ppm = (256 * responseHigh) + responseLow;
        return ppm;
    }
}

void CO2Sensor::work(Values *values, unsigned long currentMillis) {
    values->getClimatVal(CO2)->setCurrent(_getCO2());
}

void CO2Sensor::start() {
    pinMode(sensorRXPin, INPUT);
    pinMode(sensorTXPin, OUTPUT);
    co2Serial = new SoftwareSerial(sensorTXPin, sensorRXPin);
    delay(500);
    co2Serial->begin(9600);
    _stated = true;
}

