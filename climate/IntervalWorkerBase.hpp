#ifndef INTERVAL_WORKER_BASE_HPP
#define INTERVAL_WORKER_BASE_HPP

class IntervalWorckerBase {

    unsigned long _prev_ms = 0;
    int _interval = 0;

public:
    IntervalWorckerBase(int interval);

    virtual void work(unsigned long currentMillis) {};

    bool isWorkTime(unsigned long currentMillis);

    bool isWorkTime(unsigned long currentMillis, int interval);

    virtual void update(unsigned long currentMillis);
};

#endif //DISPLAY_H
