#ifndef Encoder_H
#define Encoder_H

#include "Definitions.h"
#include <Arduino.h>

class Encoder
{
public:
    static char* Encode(const int_array5& flexion, int joyX, int joyY, bool joyClick, bool triggerButton, bool aButton, bool bButton, bool grab, bool pinch);
};

#endif // Encoder_H