#include "Display.hpp"

Display::Display(char displayDataPin, char displayClkPin, char displayCsPin, int intervalChange, int interval,
                 Values *values)
        : IntervalWorckerBase(interval) {
    this->displayDataPin = displayDataPin;
    this->displayClkPin = displayClkPin;
    this->displayCsPin = displayCsPin;
    this->intervalChange = intervalChange;
    this->values = values;
    this->ledControl = new LedControl(displayDataPin, displayClkPin, displayCsPin);

    reInitDisplay();
}

void Display::update(unsigned long currentMillis) {

    if (values->isAfterChange(currentMillis)) {
        if (!isWorkTime(currentMillis, intervalChange)) {
            return;
        }
        reInitDisplay();
        showTemp(values->getTarget(TYPE_CLIMATE_VALUE::TEMPERATURE));
        showHeating(values->getTarget(TYPE_CLIMATE_VALUE::HUMIDITY));
    } else {
        if (!isWorkTime(currentMillis)) {
            return;
        }
        reInitDisplay();
        showTemp(values->getCurrentValue(TYPE_CLIMATE_VALUE::TEMPERATURE));
        showHeating(values->getCurrentValue(TYPE_CLIMATE_VALUE::HUMIDITY));
        values->changeTimeStamp = 0;
    }
}

void Display::showTemp(float temp) {
    showNumber(temp, 8);
}

void Display::showHeating(float heating) {
    showNumber(heating, 4);
}

void Display::reInitDisplay() {
    ledControl->shutdown(0, false);
    ledControl->setScanLimit(0, 8);
    ledControl->setIntensity(0, 15);
    ledControl->clearDisplay(0);
}

void Display::showNumber(float number, int startDig) {
    if (number == 0) {
        showDigit(0, startDig - 3, false); // отображаем 0 в правом разряде
    } else {
        // отображаем значение, соответствующее каждой цифре
        // крайняя левая цифра 0, правая на единицу меньше, чем число позиций

        showDigit((int) number % 10, startDig - 2, true);
        int nextNumber = (int) number / 10;

        int i = nextNumber % 10;
        if (i > 0) {
            showDigit(nextNumber % 10, startDig - 1, false);
        }


        int dec = 0;
        if (number > 1) {
            dec = (int) ((number - (int) number) * 10);
        } else {
            dec = (int) (number * 10.0f);
        }
        showDigit(dec, startDig - 3, false);
    }
}

// Отображаем заданное число на данном разряде 7-сегментного индикатора
void Display::showDigit(int oneNumber, int digit, bool dot) {

    ledControl->setDigit(0, digit, oneNumber, dot);
}






