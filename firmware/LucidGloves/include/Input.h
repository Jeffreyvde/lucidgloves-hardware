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

    void SetupInputs();
    const int_array5& GetFingerPositions(bool calibrating);
    int GetJoyX();
    int GetJoyY();
    bool GetButton(uint8_t pin);
};

#endif // INPUT_H