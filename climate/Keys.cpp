#include "Keys.hpp"

Keys::Keys(uint8_t buttonSelectPin, uint8_t buttonPlusPin,  uint8_t buttonMinusPin, Values *values) {
    this->values = values;
    this->buttonSelectPin = buttonSelectPin;
    this->buttonPlusPin = buttonPlusPin;
    this->buttonMinusPin = buttonMinusPin;

    pinMode(this->buttonSelectPin, INPUT_PULLUP);
    pinMode(this->buttonPlusPin, INPUT_PULLUP);
    pinMode(this->buttonMinusPin, INPUT_PULLUP);

    buttonSelect = new Button(buttonSelectPin);
    buttonPlus = new Button(buttonPlusPin);
    buttonMinus = new Button(buttonMinusPin);
}

void Keys::update(unsigned long currentMillis) {
    buttonSelect->update(currentMillis);
    buttonPlus->update(currentMillis);
    buttonMinus->update(currentMillis);

    if (buttonSelect->isPressed()) {
        values->changeSelection(currentMillis);
    }

    if (buttonMinus->isPressed()) {
        values->minus(currentMillis);
    }

    if (buttonPlus->isPressed()) {
        values->plus(currentMillis);
    }
}

void Keys::check_key() { }


