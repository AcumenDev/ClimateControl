//
// Created by vladimir on 12/18/16.
//

#ifndef TEST_CLIMATE_ARDUINO_H
#define TEST_CLIMATE_ARDUINO_H

#include <stdint.h>
#include <iostream>
#include <cmath>
#include <cfloat>
#include "HardwareSerial.hpp"
#include "../../climate/Config.hpp"


#define A2 22
#define A1 22
#define A0 22

typedef uint8_t byte;
typedef bool boolean;
#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

unsigned long millis();


int digitalRead(int pin);

void pinMode(uint8_t pin, uint8_t mode);

int digitalRead(uint8_t pin);

void digitalWrite(uint8_t pin, uint8_t val);

#endif //TEST_CLIMATE_ARDUINO_H
