#include "IntervalWorkerBase.hpp"

IntervalWorckerBase::IntervalWorckerBase(int interval) {
    this->_interval = interval;
}

bool IntervalWorckerBase::isWorkTime(unsigned long currentMillis) {
    return isWorkTime(currentMillis, _interval);
}

bool IntervalWorckerBase::isWorkTime(unsigned long currentMillis, int interval) {
    if (currentMillis < _prev_ms) {//проверка обнуления миллисекунд раз в 50 дней
        _prev_ms = currentMillis;
    }
    if ((currentMillis - _prev_ms) >= interval) {
        _prev_ms = currentMillis;
        return true;
    }
    return false;
}