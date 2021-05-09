#ifndef GESTURE_H
#define GESTURE_H

#include "Config/Definitions.h"

class Gesture
{
private:
public:
    bool static GrabGesture(const int_array5& flexion);

    bool static PinchGesture(const int_array5& flexion);

    bool static TriggerGesture(const int_array5& flexion);
};

#endif // GESTURE_H