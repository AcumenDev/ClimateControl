#ifndef DISPLAY_H
#define DISPLAY_H

#include "Values.h"
#include "Arduino.h"
#include "inttypes.h"
#include "LedControl.h"
#include "IntervalWorkerBase.hpp"

class Display : public IntervalWorkerBase {
    LedControl *ledControl;
    int intervalChange;

public:
    Display(char dataPin, char clkPin, char csPin, int intervalChange, int interval);

    void update(Values *values, unsigned long currentMillis);

    void showTemp(int deviceNumb, float temp);

    void showHeating(int deviceNumb, float number);

private:

    void showNumber(int deviceNumb, float number, int startPos, int size = 3, int precision = 1);

    void showDigit(int deviceNumb, byte number, int pos, bool dot);

    void showCO2(int displayNum, float value);

    void initDisplay(int deviceNumb, int scanLimit);
};

#endif //DISPLAY_H
