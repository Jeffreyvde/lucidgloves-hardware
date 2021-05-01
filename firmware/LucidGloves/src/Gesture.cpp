#include "Gesture.h"

bool Gesture::grabGesture(const int flexion[5])
{
    return (flexion[0] + flexion[1] + flexion[2] + flexion[3]) / 4 <= ANALOG_MAX / 2 ? 0 : 1;
}

bool Gesture::pinchGesture(const int flexion[5])
{
    return (flexion[0] + flexion[1]) / 2 <= ANALOG_MAX / 2 ? 0 : 1;
}

bool Gesture::triggerGesture(const int flexion[5])
{
    return flexion[1] <= (1023 / 2) ? 0 : 1;
}
