//
// Created by vst on 4/22/17.
//

#ifndef TEST_CLIMATE_MONITORING_HPP
#define TEST_CLIMATE_MONITORING_HPP

#include "IntervalWorkerBase.hpp"
#include "Values.h"

class Monitoring : public IntervalWorckerBase {
public:
    Monitoring(int interval);

private:
    void work(Values *values, unsigned long currentMillis) override;

    Values *values;
};


#endif //TEST_CLIMATE_MONITORING_HPP
