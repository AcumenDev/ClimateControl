#ifndef CLIMAT_CONTROL_HPP
#define CLIMAT_CONTROL_HPP
#include "Values.h"
#include "Relays.hpp"
enum WorkType {
  HEATING,
  COOLING,
  OFF
};
class ClimateControl {
    unsigned long previousMillis;
    Values * values;
    Relays * relays;
    int interval;
    float gisteris;
    WorkType workType;
    unsigned long timestamp;
    unsigned long waitingTime;
  public:
    ClimateControl(Values * values, Relays * relays, int interval);

    void update(unsigned long currentMillis);
    void temperatureControl(unsigned long currentMillis);
    void heating(unsigned long currentMillis);
    void cooling(unsigned long currentMillis);
    void humidityControl();
};
#endif
