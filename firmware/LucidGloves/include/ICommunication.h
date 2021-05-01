#ifndef ICOMMUNICATION_H
#define ICOMMUNICATION_H

class ICommunication
{
public:
    virtual ~ICommunication() = default;

    virtual bool isOpen() = 0;

    virtual void start() = 0;

    virtual void output(char* data) = 0;
};

#endif
