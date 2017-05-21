//
// Created by vst on 5/21/17.
//

#ifndef TEST_CLIMATE_EXECUTIVEDEVICES_HPP
#define TEST_CLIMATE_EXECUTIVEDEVICES_HPP


#include "Values.h"
#include "Relays.hpp"
#include "ServoMotors.hpp"

class ExecutiveDevices {
     Relays *relays;
     ServoMotors *servoMotors;

public:
    ExecutiveDevices(Relays *relays, ServoMotors *servoMotors);

    void update(Values *pValues);


    void temperature(Values *values);

    void humidity(Values *values);

    void co2(Values *values);
};


#endif //TEST_CLIMATE_EXECUTIVEDEVICES_HPP
