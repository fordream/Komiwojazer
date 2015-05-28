#ifndef KOMIWOJAZERINTERFACE_H
#define KOMIWOJAZERINTERFACE_H

class KomiwojazerInterface
{
public:
    KomiwojazerInterface();
    virtual int* calculate() = 0;
    virtual ~KomiwojazerInterface();
};

#endif // KOMIWOJAZERINTERFACE_H
