#ifndef Keys_h
#define Keys_h
#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
#include "Button.hpp"

class Keys {
    Values * values;
    int value, old_value;

    uint8_t coolingButtonPlusPin;
    uint8_t coolingButtonMinusPin;
    uint8_t heatingButtonPlusPin;
    uint8_t heatingButtonMinusPin;
    uint8_t controlButtonPin;

    Button * coolingButtonPlus;
    Button * coolingButtonMinus;
    Button * heatingButtonPlus;
    Button * heatingButtonMinus;
    Button * controlButton;

  public:
    Keys(uint8_t coolingButtonPlusPin, uint8_t coolingButtonMinusPin, uint8_t heatingButtonPlusPin, uint8_t heatingButtonMinusPin, uint8_t controlButtonPin, Values * values);
    void update(unsigned long currentMillis);

  private:
    void check_key();
};
#endif
