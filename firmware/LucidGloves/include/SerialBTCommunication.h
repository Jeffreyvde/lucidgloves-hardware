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

    bool IsOpen() override;

    void Start() override;

    void Output(char* data) override;
};

#endif
