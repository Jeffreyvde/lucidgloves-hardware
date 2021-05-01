#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>

class Input
{
private:
    int rightFingers[5];
    int leftFingers[5];

public:
    Input() = default;
    ~Input() = default;

    void setupInputs();
    int* getFingerPositions(bool calibrating);
    int getJoyX();
    int getJoyY();
    bool getButton(byte pin);
};

#endif // INPUT_H