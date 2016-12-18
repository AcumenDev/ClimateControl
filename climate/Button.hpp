#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
//#include "Button.h"
class Button {

    // the following variables are unsigned long's because the time, measured in miliseconds,
    // will quickly become a bigger number than can be stored in an int.
    unsigned long lastDebounceTime;  // the last time the output pin was toggled
    unsigned long debounceDelay;    // the debounce time; increase if the output flickers
   
    int buttonState;             // the current reading from the input pin
    int lastButtonState;   // the previous reading from the input pin

    byte buttonPin;
    bool readPresed;

  public:
    Button(byte buttonPin);

    void update(unsigned long currentMillis);
    bool isPressed();
};
#endif
