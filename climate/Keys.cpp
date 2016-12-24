#include "Keys.hpp"

Keys::Keys(
        uint8_t coolingButtonPlusPin,
        uint8_t coolingButtonMinusPin,
        uint8_t heatingButtonPlusPin,
        uint8_t heatingButtonMinusPin,
        uint8_t controlButtonPin,
        Values *values) {
    this->values = values;
    this->coolingButtonPlusPin = coolingButtonPlusPin;
    this->coolingButtonMinusPin = coolingButtonMinusPin;
    this->heatingButtonPlusPin = heatingButtonPlusPin;
    this->heatingButtonMinusPin = heatingButtonMinusPin;
    this->controlButtonPin = controlButtonPin;

    pinMode(this->coolingButtonPlusPin, INPUT_PULLUP);
    pinMode(this->coolingButtonMinusPin, INPUT_PULLUP);
    pinMode(this->heatingButtonPlusPin, INPUT_PULLUP);
    pinMode(this->heatingButtonMinusPin, INPUT_PULLUP);
    pinMode(this->controlButtonPin, INPUT_PULLUP);

    coolingButtonPlus = new Button(coolingButtonPlusPin);
    coolingButtonMinus = new Button(coolingButtonMinusPin);
    heatingButtonPlus = new Button(heatingButtonPlusPin);
    heatingButtonMinus = new Button(heatingButtonMinusPin);
    controlButton = new Button(controlButtonPin);
}

void Keys::update(unsigned long currentMillis) {
    coolingButtonPlus->update(currentMillis);
    coolingButtonMinus->update(currentMillis);
    heatingButtonPlus->update(currentMillis);
    heatingButtonMinus->update(currentMillis);
    controlButton->update(currentMillis);

    if (coolingButtonPlus->isPressed()) {
        values->plusTemp(currentMillis);
    }

    if (coolingButtonMinus->isPressed()) {
        values->minusTemp(currentMillis);
    }

    if (heatingButtonPlus->isPressed()) {
        values->plusHumidity(currentMillis);
    }

    if (heatingButtonMinus->isPressed()) {
        values->minusHumidity(currentMillis);
    }

    if (controlButton->isPressed()) {
        values->controlSet();
    }
}

void Keys::check_key() { }
