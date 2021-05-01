#include "SerialBTCommunication.h"
#include <Arduino.h>

SerialBTCommunication::SerialBTCommunication()
{
    m_isOpen = false;
}

bool SerialBTCommunication::isOpen()
{
    return m_isOpen;
}

void SerialBTCommunication::start()
{
    Serial.begin(95);
    m_isOpen = true;
}

void SerialBTCommunication::output(char* data)
{
    Serial.print(data);
    Serial.flush();
}