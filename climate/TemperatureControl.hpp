#ifndef CLIMAT_CONTROL_HPP
#define CLIMAT_CONTROL_HPP

#include "Values.h"
#include "Relays.hpp"
#include "PID_v1.h"
#include "IntervalWorkerBase.hpp"


class TemperatureControl : public IntervalWorckerBase {
    enum WorkType {
        HEATING,
        COOLING,
        OFF
    };

    WorkType workType;
    PIDT<float> *pid;
    float inputValue = 0;
    float targetValue = 0;
    float outputValue = 0;

    void  control_v1(Value *values,unsigned long currentMillis);

    void  heating(Value *values,unsigned long currentMillis);
    void   cooling(Value *values,unsigned long currentMillis);

public:
    TemperatureControl(float Kp, float Ki, float Kd, int interval);

    void work(Values *values, unsigned long currentMillis) override;
};

#endif
