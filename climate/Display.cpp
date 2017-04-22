#include "Display.hpp"

Display::Display(char dataPin, char clkPin, char csPin, int intervalChange, int interval, Values *values)
        : IntervalWorckerBase(interval) {
    this->intervalChange = intervalChange;
    this->values = values;
    this->ledControl = new LedControl(dataPin, clkPin, csPin, 2);

    initDisplay(0,8);
    initDisplay(1,4);
}

void Display::update(unsigned long currentMillis) {
    if (values->isAfterChange(currentMillis)) { ////TODO Надо подписаться на событые изменения
        if (!isWorkTime(currentMillis, intervalChange)) {
            return;
        }
        ledControl->clearDisplay(0);
        showTemp(0, values->getTarget(TYPE_CLIMATE_VALUE::TEMPERATURE));
        showHeating(0, values->getTarget(TYPE_CLIMATE_VALUE::HUMIDITY));
        ledControl->clearDisplay(1);
        showCO2(1, values->getTarget(TYPE_CLIMATE_VALUE::CO2));
    } else {
        if (!isWorkTime(currentMillis)) {
            return;
        }
        ledControl->clearDisplay(0);

        showTemp(0, values->getCurrentValue(TYPE_CLIMATE_VALUE::TEMPERATURE));
        showHeating(0, values->getCurrentValue(TYPE_CLIMATE_VALUE::HUMIDITY));
        ledControl->clearDisplay(1);
        showCO2(1, values->getCurrentValue(TYPE_CLIMATE_VALUE::CO2));
        values->changeTimeStamp = 0;
    }
}

void Display::showTemp(int deviceNumb, float temp) {
    showNumber(deviceNumb, temp, 8);
}

void Display::showHeating(int deviceNumb, float heating) {
    showNumber(deviceNumb, heating, 4);
}

void Display::initDisplay(int deviceNumb,int scanLimit) {
    ledControl->shutdown(deviceNumb, false);
    ledControl->setScanLimit(deviceNumb, scanLimit);
    ledControl->setIntensity(deviceNumb, 15);
}

void Display::showNumber(int deviceNumb, float number, int startPos, int size,
                         int precision) { ////todo дописать чтобы 0 красиво отображался у float 00.0 сейчас 0
    startPos -= size;
    int operateNumb;
    if (precision > 0) {
        operateNumb = (int) (number * (10 * precision));
    } else {
        operateNumb = (int) (number);
        precision = -1;
    }
    int dot = 0;
    do {
        showDigit(deviceNumb, (byte) (operateNumb % 10), startPos, dot == precision);
        operateNumb /= 10;
        startPos++;
        dot++;
    } while (operateNumb > 0);

    return;
}

// Отображаем заданное число на данном разряде 7-сегментного индикатора
void Display::showDigit(int deviceNumb, byte oneNumber, int pos, bool dot) {
    ledControl->setDigit(deviceNumb, pos, oneNumber, dot);
}

void Display::showCO2(int displayNum, float value) {
    if (value > 999) {
        value = 999;
    }
    showNumber(displayNum, value, 4, 3, 0);
}