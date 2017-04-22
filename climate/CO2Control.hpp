//
// Created by vst on 4/23/17.
//

#ifndef TEST_CLIMATE_CO2CONTROL_HPP
#define TEST_CLIMATE_CO2CONTROL_HPP

#include "PID_v1.h"
#include "Values.h"

class CO2Control {
    float Kp=2, Ki=5, Kd=1;
    PIDT<float> *pid;
    Values *values;

public:
    CO2Control(Values *values);

void update();
    float outputValue;
    float inputValue;
    float targetValue;
};


#endif //TEST_CLIMATE_CO2CONTROL_HPP
