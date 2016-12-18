#ifndef CLIMAT_HPP
#define CLIMAT_HPP

#include "Arduino.h"
#include "Sensors.hpp"
#include "Keys.hpp"
#include "Display.hpp"
#include "Relays.hpp"
#include "ClimateControl.hpp"

#define DEBUG

#define DISPLAY_CS_PIN 13
#define DISPLAY_CLK_PIN 12
#define DISPLAY_DATA_PIN 11

#define SENSOR_PIN 10


#define HUMIDIFICATION_RELAY_PIN 9
#define HEATING_RELAY_PIN 8
#define COOLING_RELAY_PIN 7


#define COOLING_BUTTON_PLUS_PIN 6
#define COOLING_BUTTON_MINUS_PIN 5

#define HEATING_BUTTON_PLUS_PIN 4
#define HEATING_BUTTON_MINUS_PIN 3

#define BUTTON_CONTROL_ON 2

class Climate {
  private:
    Values * values;
    Sensors * sensors;
    Keys * keys;
    Display * display;
    Relays * relays;
    ClimateControl *  climateControl;
    unsigned long previousMillis;
  public:
    Climate();
    void setup();
    void loop(unsigned long currentMillis);
};
#endif
