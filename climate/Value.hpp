#ifndef VALUE_H
#define VALUE_H


class Value {
    float current = 0;
    int target;
    int maxTarget;
    int minTarget;
    float gisteris = 1;
public:
    Value(int minTarget, int maxTarget, float gisteris) {
        this->minTarget = minTarget;
        this->maxTarget = maxTarget;
        this->gisteris = gisteris;
    }

    void plus(unsigned long currentMillis) {
        if (target < maxTarget) {
            target++;
        }
    }

    void minus(unsigned long currentMillis) {
        if (target > minTarget) {
            target--;
        }
    }

    int getTarget() { return target; }

    float getCurrent() { return current; }

    void setTarget(int target) { this->target = target; }

    void setCurrent(float current) { this->current = current; }

    float getGisteris() { return this->gisteris; }
};

#endif
