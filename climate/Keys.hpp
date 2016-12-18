#ifndef Keys_h
#define Keys_h
#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
#include "Button.hpp"

class Keys {
    Values * values;
    int value, old_value;

    char coolingButtonPlusPin;
    char coolingButtonMinusPin;
    char heatingButtonPlusPin;
    char heatingButtonMinusPin;
    char controlButtonPin;

    Button * coolingButtonPlus;
    Button * coolingButtonMinus;
    Button * heatingButtonPlus;
    Button * heatingButtonMinus;
    Button * controlButton;

  public:
    Keys(char coolingButtonPlusPin, char coolingButtonMinusPin, char heatingButtonPlusPin, char heatingButtonMinusPin, char controlButtonPin, Values * values);
    void update(unsigned long currentMillis);

  private:
    void check_key();
};
#endif
