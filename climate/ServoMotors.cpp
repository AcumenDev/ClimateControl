//
// Created by vst on 5/22/17.
//

#include "ServoMotors.hpp"


ServoMotors::ServoMotors(int coolingMotorPin, int heatingMotorPin, int ventilationMotorPin) {
    this->coolingMotor = new Servo();
    this->heatingMotor = new Servo();
    this->ventilationMotor = new Servo();
    this->coolingMotor->attach(coolingMotorPin);
    this->heatingMotor->attach(heatingMotorPin);
    this->ventilationMotor->attach(ventilationMotorPin);
}

void ServoMotors::heating(int val) {
    heatingMotor->write(val);
}

void ServoMotors::ventilation(int val) {
    ventilationMotor->write(val);
}

void ServoMotors::humidification(int val) {
///int motorAngl = map(val,0, 1024, 180,0);//Преобразуем диапазон выдаваемый датчиком в диапазон углов сервы
///    motor.write(motorAngl);// Устанавливаем серву на угол который получаем через преобразование

    if (val > coolingMotor->read()) {
        coolingMotor->write(val);
    }
}

void ServoMotors::cooling(int val) {
    if (val > coolingMotor->read()) {
        coolingMotor->write(val);
    }
}