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
    Values * values;
    Relays * relays;
    float temperatureGisteris;
    float humidityGisteris;
    WorkType workType;
    unsigned long timestamp;
  //  unsigned long waitingTime;
  public:
    ClimateControl(Values *values, Relays *relays, int interval);

    void update(unsigned long currentMillis);
    void temperatureControl(unsigned long currentMillis);
    void heating(unsigned long currentMillis);
    void cooling(unsigned long currentMillis);
    void humidityControl();
};
#endif
