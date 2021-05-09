#include "Communication/SerialBTCommunication.h"
#include "Config/Config.h"
#include <Arduino.h>

SerialBTCommunication::SerialBTCommunication()
{
    m_isOpen = false;
}

bool SerialBTCommunication::IsOpen()
{
    return m_isOpen;
}

void SerialBTCommunication::Start()
{
    Serial.begin(SERIAL_BAUD_RATE);
    m_isOpen = true;
}

void SerialBTCommunication::Output(char* data)
{
}