#ifndef INTERVAL_WORKER_BASE_HPP
#define INTERVAL_WORKER_BASE_HPP

class IntervalWorckerBase {

    unsigned long _prev_ms = 0;
    int _interval = 0;

public:
    IntervalWorckerBase(int interval);

    bool isWorkTime(unsigned long currentMillis);
    bool isWorkTime(unsigned long currentMillis, int interval);
};

#endif //DISPLAY_H
