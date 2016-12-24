#ifndef CLIMAT_HPP
#define CLIMAT_HPP

#include "Arduino.h"
#include "Sensors.hpp"
#include "Keys.hpp"
#include "Display.hpp"
#include "Relays.hpp"
#include "ClimateControl.hpp"
#include "Config.hpp"

class Climate {
 public:
    Values * values;
    Sensors * sensors;
    Keys * keys;
    Display * display;
    Relays * relays;
    ClimateControl *  climateControl;
    unsigned long previousMillis;
  
    Climate();
    void setup();
    void loop(unsigned long currentMillis);
};
#endif
