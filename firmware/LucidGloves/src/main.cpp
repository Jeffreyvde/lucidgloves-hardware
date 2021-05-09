#include "Communication/ICommunication.h"
#include "Communication/SerialBTCommunication.h"
#include "Communication/SerialCommunication.h"
#include "Config/Config.h"
#include "Encoder.h"
#include "Gesture.h"
#include "Input.h"
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
    comm->Start();
    input.SetupInputs();
}
void loop()
{
    if (comm->IsOpen())
    {
        bool calibrate = false;
        if (loops < CALIBRATION_LOOPS || ALWAYS_CALIBRATING)
        {
            calibrate = true;
            loops++;
        }
        const int_array5& fingerPos = input.GetFingerPositions(calibrate);
        bool joyButton = input.GetButton(PIN_JOY_BTN);
#if TRIGGER_GESTURE
        bool triggerButton = Gesture::TriggerGesture(fingerPos);
#else
        bool triggerButton = input.GetButton(PIN_TRIG_BTN);
#endif
        bool aButton = input.GetButton(PIN_A_BTN);
        bool bButton = input.GetButton(PIN_B_BTN);
#if GRAB_GESTURE
        bool grabButton = Gesture::GrabGesture(fingerPos);
#else
        bool grabButton = Gesture::GetButton(PIN_GRAB_BTN);
#endif
#if PINCH_GESTURE
        bool pinchButton = Gesture::GrabGesture(fingerPos);
#else
        bool pinchButton = input.GetButton(PIN_PNCH_BTN);
#endif
        comm->Output(Encoder::Encode(fingerPos, input.GetJoyX(), input.GetJoyY(), joyButton, triggerButton, aButton, bButton, grabButton, pinchButton));
        delay(LOOP_TIME);
    }
}
