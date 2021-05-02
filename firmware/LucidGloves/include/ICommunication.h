#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

class ICommunication
{
public:
    virtual ~ICommunication() = default;

    virtual bool IsOpen() = 0;

    virtual void Start() = 0;

    virtual void Output(char* data) = 0;
};

#endif
