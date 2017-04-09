#ifndef CLIMAT_CONTROL_HPP
#define CLIMAT_CONTROL_HPP

#include "Values.h"
#include "Relays.hpp"
#include "IntervalWorkerBase.hpp"

enum WorkType {
    HEATING,
    COOLING,
    OFF
};

class ClimateControl : public IntervalWorckerBase {
    Values *values;
    Relays *relays;
    WorkType workType;
public:
    ClimateControl(Values *values, Relays *relays, int interval);

    void update(unsigned long currentMillis);

private:
    void temperatureControl();

    void heating();

    void cooling();

    void humidityControl();

    void co2Control();
};

#endif
