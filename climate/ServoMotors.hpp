//
// Created by vst on 5/22/17.
//

#ifndef TEST_CLIMATE_SERVOMOTORS_HPP
#define TEST_CLIMATE_SERVOMOTORS_HPP

#include <Servo.h>
#include <Arduino.h>

class ServoMotors {
    Servo *coolingMotor;
    Servo *heatingMotor;
    Servo *ventilationMotor;
public:
    ServoMotors(int coolingMotorPin, int heatingMotorPin, int ventilationMotorPin);

    void humidification(int i);

    void ventilation(int val);

    void cooling(int val);

    void heating(int val);
};


#endif //TEST_CLIMATE_SERVOMOTORS_HPP
