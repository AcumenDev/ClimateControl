//
// Created by vst on 4/22/17.
//


#include "CO2Sensor.hpp"

CO2Sensor::CO2Sensor(uint8_t sensorTXPin, uint8_t sensorRXPin, int interval) : IntervalWorckerBase(
        interval) {
    pinMode(sensorRXPin, INPUT);
    pinMode(sensorTXPin, OUTPUT);
    co2Serial = new SoftwareSerial(sensorTXPin, sensorRXPin);
    delay(100);
    co2Serial->begin(9600);
}

float CO2Sensor::_getCO2() {
    co2Serial->write(readCO2Command, 9);
    memset(response, 0, 9);
    co2Serial->readBytes(response, 9);
    int i;
    byte crc = 0;
    for (i = 1; i < 8; i++) crc += response[i];
    crc = (byte) (255 - crc);
    crc++;

    if (!(response[0] == 0xFF && response[1] == 0x86 && response[8] == crc)) {
        //Serial.println("CRC error: " + String(crc) + " / " + String(response[8]));
        return 0.0f;
    } else {
        unsigned int responseHigh = (unsigned int) response[2];
        unsigned int responseLow = (unsigned int) response[3];
        float ppm = (256 * responseHigh) + responseLow;
        return ppm;
    }
}

void CO2Sensor::work(Values *values, unsigned long currentMillis) {
    values->setCurrentValue(CO2, _getCO2());
}

