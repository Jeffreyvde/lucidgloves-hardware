#include "SerialBTCommunication.h"
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
    Serial.begin(95);
    m_isOpen = true;
}

void SerialBTCommunication::Output(char* data)
{
    Serial.print(data);
    Serial.flush();
}