#ifndef CLIMAT_HPP
#define CLIMAT_HPP

#include "Arduino.h"
#include "THSensors.hpp"
#include "Keys.hpp"
#include "Display.hpp"
#include "Relays.hpp"
#include "ClimateControl.hpp"
#include "Config.hpp"
#include "Monitoring.hpp"
#include "CO2Sensor.hpp"
#include "CO2Control.hpp"

class Climate {
public:
    Values *values;
    THSensors *thSensors;
    CO2Sensor *co2Sensor;
    Keys *keys;
    Display *display;
    Relays *relays;
    ClimateControl *climateControl;
    Monitoring *monitoring;
    CO2Control * co2Control;
    bool startTimeOut;

    Climate();

    void setup();

    void loop(unsigned long currentMillis);
};

#endif
