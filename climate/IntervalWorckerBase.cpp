#include "IntervalWorkerBase.hpp"


IntervalWorckerBase::IntervalWorckerBase(int interval) {
    this->_interval = interval;
}

bool IntervalWorckerBase::isWorkTime(unsigned long currentMillis) {
    return TimeUtils::isWorkTime(_prev_ms, currentMillis, _interval);
}

bool IntervalWorckerBase::isWorkTime(unsigned long currentMillis, int interval) {
    return TimeUtils::isWorkTime(_prev_ms, currentMillis, interval);
}


void IntervalWorckerBase::update(Values *values, unsigned long currentMillis) {
    if (isWorkTime(currentMillis)) {
        work(values, currentMillis);
        _prev_ms = currentMillis;
    }
}