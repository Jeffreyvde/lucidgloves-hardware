#ifndef INPUT_H
#define INPUT_H

#include "Config/Config.h"
#include "Config/Definitions.h"
#include <Arduino.h>

class Input
{
private:
    int maxFingers[5] = {0, 0, 0, 0, 0};
    int minFingers[5] = {ANALOG_MAX, ANALOG_MAX, ANALOG_MAX, ANALOG_MAX, ANALOG_MAX};

public:
    Input();
    ~Input() = default;

    void SetupInputs();
    const int_array5& GetFingerPositions(bool calibrating);
    int GetJoyX();
    int GetJoyY();
    bool GetButton(uint8_t pin);
};

#endif // INPUT_H