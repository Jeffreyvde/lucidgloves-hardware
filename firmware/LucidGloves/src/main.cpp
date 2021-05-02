#include "Encoder.h"
#include "Gesture.h"
#include "ICommunication.h"
#include "Input.h"
#include "SerialCommunication.h"
#include "lucidgloves-firmware.h"
#include <Arduino.h>

#define ALWAYS_CALIBRATING CALIBRATION_LOOPS == -1

ICommunication* comm;
Input input;

int loops = 0;
void setup()
{
#if COMMUNICATION == COMM_SERIAL
    comm = new SerialCommunication();
#elif COMMUNICATION == COMM_BTSERIAL
    comm = new BTSerialCommunication();
#endif
    comm->start();

    input.setupInputs();
}

void loop()
{
    if (comm->isOpen())
    {

        bool calibrate = false;
        if (loops < CALIBRATION_LOOPS || ALWAYS_CALIBRATING)
        {
            calibrate = true;
            loops++;
        }

        const int_array5& fingerPos = input.getFingerPositions(calibrate);
        bool joyButton = input.getButton(PIN_JOY_BTN);

#if TRIGGER_GESTURE
        bool triggerButton = Gesture::triggerGesture(fingerPos);
#else
        bool triggerButton = getButton(PIN_TRIG_BTN);
#endif

        bool aButton = input.getButton(PIN_A_BTN);
        bool bButton = input.getButton(PIN_B_BTN);

#if GRAB_GESTURE
        bool grabButton = Gesture::grabGesture(fingerPos);
#else
        bool grabButton = Gesture::getButton(PIN_GRAB_BTN);
#endif

#if PINCH_GESTURE
        bool pinchButton = Gesture::grabGesture(fingerPos);
#else
        bool pinchButton = input.getButton(PIN_PNCH_BTN);
#endif

        comm->output(Encoder::Encode(fingerPos, input.getJoyX(), input.getJoyY(), joyButton, triggerButton, aButton, bButton, grabButton, pinchButton));
        delay(LOOP_TIME);
    }
}
