#ifndef VALUE_H
#define VALUE_H


class Value {
    float current = 0;
    int target;
    int maxTarget;
    int minTarget;
    int output;
    float gisteris = 1;
public:
    Value(int minTarget, int maxTarget, float gisteris) {
        this->minTarget = minTarget;
        this->maxTarget = maxTarget;
        this->gisteris = gisteris;
        target = minTarget + ((maxTarget - minTarget) / 2);
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

    const float &getCurrent() { return current; }

    void setTarget(int target) {
        if (target >= minTarget && target <= maxTarget) {
            this->target = target;
        }
    }

    void setCurrent(float current) { this->current = current; }

    float getGisteris() { return this->gisteris; }

    void setOutput(int value) { this->output = value; }

    int getOutput() { return output; }
};

#endif
