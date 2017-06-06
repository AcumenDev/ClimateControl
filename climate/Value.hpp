#ifndef VALUE_H
#define VALUE_H

class Value {
    float current = 0;
    int target;
    int maxTarget;
    int minTarget;
    int output = 0;
    float gisteris = 1;
    uint8_t heating = 0;
    uint8_t cooling = 0;
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

    void setHeating(uint8_t value) { this->heating = value; }
    uint8_t getHeating() { return heating; }


    void setCooling(uint8_t value) { this->cooling = value; }
    uint8_t getCooling() { return cooling; }
};

#endif
