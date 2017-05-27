#ifndef TEST_CLIMATE_HUMIDITYCONTROL_HPP
#define TEST_CLIMATE_HUMIDITYCONTROL_HPP

#include "Values.h"
#include "Relays.hpp"
#include "PID_v1.h"
#include "IntervalWorkerBase.hpp"

class HumidityControl : public IntervalWorckerBase {
    PIDT<float> *pid;
    float inputValue = 0;
    float targetValue = 0;
    float outputValue = 0;
public:
    HumidityControl(float Kp, float Ki, float Kd, int interval);

    void work(Values *values, unsigned long millis) override;
};

#endif