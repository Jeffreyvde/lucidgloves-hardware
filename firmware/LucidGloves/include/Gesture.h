#include "lucidgloves-firmware.h"

#ifndef GESTURE_H
#define GESTURE_H

class Gesture
{
private:
public:
    bool static grabGesture(const int flexion[5]);

    bool static pinchGesture(const int flexion[5]);

    bool static triggerGesture(const int flexion[5]);
};

#endif // GESTURE_H