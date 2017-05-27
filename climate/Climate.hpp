#ifndef CLIMAT_HPP
#define CLIMAT_HPP

#include "Arduino.h"
#include "THSensors.hpp"
#include "Keys.hpp"
#include "Display.hpp"
#include "Relays.hpp"
#include "TemperatureControl.hpp"
#include "Config.hpp"
#include "Monitoring.hpp"
#include "CO2Sensor.hpp"
#include "CO2Control.hpp"
#include "ExecutiveDevices.hpp"
#include "HumidityControl.hpp"

class Climate {
public:
    Values values;
    THSensors *thSensors;
    CO2Sensor *co2Sensor;
    Keys *keys;
    Display *display;
    Relays *relays;
    TemperatureControl *temperatureControl;
    HumidityControl *humidityControl;

    CO2Control *co2Control;
    Monitoring *monitoring;
    ServoMotors *servoMotors;

    ExecutiveDevices *executiveDevices;

    bool startTimeOut = false;

    Climate();

    void setup();

    void loop(unsigned long currentMillis);
};

#endif
