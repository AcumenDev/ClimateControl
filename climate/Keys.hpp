#ifndef Keys_h
#define Keys_h
#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
#include "Button.hpp"
#include "DebugUtils.hpp"

class Keys {
    Values * values;
    int value, old_value;

    uint8_t buttonSelectPin;
    uint8_t buttonMinusPin;
    uint8_t buttonPlusPin;

    Button * buttonSelect;
    Button * buttonPlus;
    Button * buttonMinus;


  public:
    Keys(uint8_t buttonSelectPin, uint8_t buttonMinusPin, uint8_t buttonPlusPin, Values * values);
    void update(unsigned long currentMillis);

  private:
    void check_key();
};
#endif
