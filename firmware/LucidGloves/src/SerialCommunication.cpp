#include "SerialCommunication.h"
#include <Arduino.h>

SerialCommunication::SerialCommunication()
{
    m_isOpen = false;
}

bool SerialCommunication::isOpen()
{
    return m_isOpen;
}

void SerialCommunication::start()
{
    Serial.begin(95);
    m_isOpen = true;
}

void SerialCommunication::output(char* data)
{
    Serial.print(data);
    Serial.flush();
}