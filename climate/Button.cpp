#include "Button.hpp"

Button::Button(byte buttonPin) {
  this->buttonPin = buttonPin;

  lastDebounceTime = 0;  
  debounceDelay = 50;    

  buttonState = false;             
  lastButtonState = LOW;
  readPresed = false;
}

void Button::update(unsigned long currentMillis) {
  int reading = digitalRead(buttonPin);

  if (readPresed) {
    if (reading == LOW) {
      return;
    }
    readPresed= false;
  }

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (lastDebounceTime != 0) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (reading == LOW) {
        buttonState = true;
      } else {
        buttonState = false;
      }
      lastDebounceTime = 0;
    }
  }
  lastButtonState = reading;

}
bool Button::isPressed() {
  if (buttonState) {
    readPresed = true;
    buttonState = false;
    return true;
  }
  return buttonState;
}
