#if !defined(BT_SERIAL_COMMUNICATION_H) && COMMUNICATION == COMM_BTSERIAL
#define BT_SERIAL_COMMUNICATION_H

#include "ICommunication.h"

class SerialBTCommunication final : public ICommunication
{
private:
    bool m_isOpen;

public:
    SerialBTCommunication();
    ~SerialBTCommunication() override = default;

    bool isOpen() override;

    void start() override;

    void output(char* data) override;
};

#endif
