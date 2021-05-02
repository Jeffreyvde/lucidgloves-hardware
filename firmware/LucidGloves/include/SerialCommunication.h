#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

#include "ICommunication.h"

class SerialCommunication final : public ICommunication
{
private:
    bool m_isOpen;

public:
    SerialCommunication();
    ~SerialCommunication() override = default;

    bool IsOpen() override;

    void Start() override;

    void Output(char* data) override;
};

#endif
