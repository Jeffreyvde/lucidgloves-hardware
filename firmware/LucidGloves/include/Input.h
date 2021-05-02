#ifndef INPUT_H
#define INPUT_H

#include "Definitions.h"
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
    const int_array5& getFingerPositions(bool calibrating);
    int getJoyX();
    int getJoyY();
    bool getButton(uint8_t pin);
};

#endif // INPUT_H