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

    bool isOpen() override;

    void start() override;

    void output(char* data) override;
};

#endif
