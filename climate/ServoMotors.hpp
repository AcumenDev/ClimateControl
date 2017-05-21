//
// Created by vst on 5/22/17.
//

#ifndef TEST_CLIMATE_SERVOMOTORS_HPP
#define TEST_CLIMATE_SERVOMOTORS_HPP


class ServoMotors {

public:
    void humidification(int i);

    void ventilation(int val);

    void cooling(int val);

    void heating(int val);
};


#endif //TEST_CLIMATE_SERVOMOTORS_HPP
