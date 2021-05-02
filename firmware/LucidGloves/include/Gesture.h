#ifndef GESTURE_H
#define GESTURE_H

#include "Definitions.h"

class Gesture
{
private:
public:
    bool static grabGesture(const int_array5& flexion);

    bool static pinchGesture(const int_array5& flexion);

    bool static triggerGesture(const int_array5& flexion);
};

#endif // GESTURE_H