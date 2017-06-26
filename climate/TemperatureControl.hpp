#ifndef CLIMAT_CONTROL_HPP
#define CLIMAT_CONTROL_HPP

#include "Values.h"
#include "Relays.hpp"
#include "PID_v1.h"
#include "IntervalWorkerBase.hpp"
#include "DebugUtils.hpp"


class TemperatureControl : public IntervalWorckerBase {
    enum WorkType {
        OFF = 0,
        COOLING = 1,
        HEATING = 2
    };

    WorkType workType;
    PIDT<float> *pid;
    float inputValue = 0;
    float targetValue = 0;
    float outputValue = 0;

    void control_v1(Value *values);

    void heating(Value *values);

    void cooling(Value *values);

    void _setWorkType(WorkType type);

public:
    TemperatureControl(float Kp, float Ki, float Kd, int interval);

    void work(Values *values, unsigned long currentMillis) override;
};

#endif
