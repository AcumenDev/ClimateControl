#ifndef VALUE_H
#define VALUE_H

class Value {
    float current = 0;
    int target;
    int maxTarget;
    int minTarget;
    int output = 0;
    float gisteris = 1;
    bool heating = 0;
    bool cooling = 0;
    bool humidity = 0;
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

    void setHeating(bool value) { this->heating = value; }

    bool getHeating() { return heating; }


    void setCooling(bool value) { this->cooling = value; }

    bool getCooling() { return cooling; }


    void setHumidity(bool value) { this->humidity = value; }

    bool getHumidity() { return humidity; }
};

#endif
