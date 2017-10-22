//
// Created by vst on 4/23/17.
//

#ifndef TEST_CLIMATE_CO2CONTROL_HPP
#define TEST_CLIMATE_CO2CONTROL_HPP

#include "PID_v1.h"
#include "Values.h"
#include "IntervalWorkerBase.hpp"

class CO2Control : public IntervalWorkerBase {
    PIDT<float> *pid;
    float outputValue = 0; ////TODO убрать переменные переписать либу пид
    float inputValue = 0;
    float targetValue = 0;

public:
    CO2Control(float Kp, float Ki, float Kd, int interval);

    void work(Values *values, unsigned long millis);
};


#endif //TEST_CLIMATE_CO2CONTROL_HPP
