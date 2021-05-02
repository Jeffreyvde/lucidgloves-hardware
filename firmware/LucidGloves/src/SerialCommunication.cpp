#include "SerialCommunication.h"
#include <Arduino.h>

SerialCommunication::SerialCommunication()
{
    m_isOpen = false;
}

bool SerialCommunication::IsOpen()
{
    return m_isOpen;
}

void SerialCommunication::Start()
{
    Serial.begin(95);
    m_isOpen = true;
}

void SerialCommunication::Output(char* data)
{
    Serial.print(data);
    Serial.flush();
}