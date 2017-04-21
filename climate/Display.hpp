#ifndef DISPLAY_H
#define DISPLAY_H

#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
#include "LedControl.h"
#include "IntervalWorkerBase.hpp"

class Display : public IntervalWorckerBase {
    Values *values;
    LedControl *ledControl;
    int intervalChange;

public:
    Display(char dataPin, char clkPin, char csPin, int intervalChange, int interval, Values *values);

    void update(unsigned long currentMillis);

    void showTemp(int deviceNumb, float temp);

    void showHeating(int deviceNumb, float number);

private:
    void initDisplay(int deviceNumb);

    void showNumber(int deviceNumb, float number, int startPos, int size = 3, int precision = 1);

    void showDigit(int deviceNumb, byte number, int pos, bool dot);

    void showCO2(int displayNum, float value);
};

#endif //DISPLAY_H
