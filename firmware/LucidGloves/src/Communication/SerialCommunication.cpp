#include "Communication/SerialCommunication.h"
#include "Config/Config.h"
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
    Serial.begin(SERIAL_BAUD_RATE);
    m_isOpen = true;
}

void SerialCommunication::Output(char* data)
{
    Serial.println(data);
    Serial.flush();
}