#ifndef DISPLAY_H
#define DISPLAY_H

#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
#include "LedControl.h"
#include "IntervalWorkerBase.hpp"

class Display : public IntervalWorckerBase {
    Values *values;
    char displayDataPin;
    char displayClkPin;
    char displayCsPin;
    LedControl *ledControl;
    float i = 0;
    int intervalChange;
    int intervalInner;
public:
    Display(char displayDataPin, char displayClkPin, char displayCsPin, int intervalChange, int interval,
            Values *values);

    void update(unsigned long currentMillis);

    void showTemp(float temp);

    void showHeating(float number);

private:
    void reInitDisplay();
    void showNumber(float number, int startDig);

    void showDigit(int number, int digit, bool dot);
};

#endif //DISPLAY_H
