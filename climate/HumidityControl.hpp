//
// Created by vst on 4/26/17.
//

#ifndef TEST_CLIMATE_HUMIDITYCONTROL_HPP
#define TEST_CLIMATE_HUMIDITYCONTROL_HPP


#include "Values.h"
#include "Relays.hpp"
#include "PID_v1.h"
#include "IntervalWorkerBase.hpp"

class HumidityControl : IntervalWorckerBase {
public:
    HumidityControl(float Kp, float Ki, float Kd, int interval);

    void work(Values *values, unsigned long currentMillis) override;

private:
    PIDT<float> *pid;
    float inputValue = 0;
    float targetValue = 0;
    float outputValue = 0;
};


#endif //TEST_CLIMATE_HUMIDITYCONTROL_HPP
