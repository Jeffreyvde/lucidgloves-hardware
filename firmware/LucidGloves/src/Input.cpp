#include "Input.h"
#include "Config.h"

void Input::SetupInputs()
{
    pinMode(PIN_JOY_BTN, INPUT_PULLUP);
    pinMode(PIN_A_BTN, INPUT_PULLUP);
    pinMode(PIN_B_BTN, INPUT_PULLUP);

#if !TRIGGER_GESTURE
    pinMode(PIN_TRIG_BTN, INPUT_PULLUP);
#endif

#if !GRAB_GESTURE
    pinMode(PIN_GRAB_BTN, AFINPUT_PULLUP);
#endif

#if !PINCH_GESTURE
    pinMode(PIN_PNCH_BTN, INPUT_PULLUP);
#endif
}

const int_array5& Input::GetFingerPositions(bool calibrating)
{
    int rawFingers[5] = {analogRead(PIN_PINKY), analogRead(PIN_RING), analogRead(PIN_MIDDLE), analogRead(PIN_INDEX), NO_THUMB ? 0 : analogRead(PIN_THUMB)};

//flip pot values if needed
#if FLIP_POTS
    for (int i = 0; i < 5; i++)
    {
        rawFingers[i] = ANALOG_MAX - rawFingers[i];
    }
#endif

    //if during the calibration sequence, make sure to update max and mins
    if (calibrating)
    {
        for (int i = 0; i < 5; i++)
        {
            if (rawFingers[i] > rightFingers[i])
                rightFingers[i] = rawFingers[i];
            if (rawFingers[i] < leftFingers[i])
                leftFingers[i] = rawFingers[i];
        }
    }

    static int calibrated[5] = {511, 511, 511, 511, 511};

    for (int i = 0; i < 5; i++)
    {
        if (leftFingers[i] != rightFingers[i])
        {
            calibrated[i] = (int)((float)(rawFingers[i] - leftFingers[i]) / (float)(rightFingers[i] - leftFingers[i]) * ANALOG_MAX);
        }
        else
        {
            calibrated[i] = ANALOG_MAX / 2;
        }
    }
    return calibrated;
}

int Input::GetJoyX()
{
#if JOYSTICK_BLANK
    return ANALOG_MAX / 2;
#elif JOY_FLIP_X
    int rawValue = ANALOG_MAX - analogRead(PIN_JOY_X);
#else
    int rawValue = analogRead(PIN_JOY_X);
#endif
}

int Input::GetJoyY()
{
#if JOYSTICK_BLANK
    return ANALOG_MAX / 2;
#elif JOY_FLIP_Y
    return ANALOG_MAX - analogRead(PIN_JOY_Y);
#else
    return analogRead(PIN_JOY_Y);
#endif
}

bool Input::GetButton(uint8_t pin)
{
    return digitalRead(pin) == HIGH;
}
