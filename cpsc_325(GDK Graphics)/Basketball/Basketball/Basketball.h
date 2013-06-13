#ifndef Basketball_H
#define Basketball_H

#include "Core.h"
#include "Channels.h"

class Basketball
{
public:
    Basketball();
    virtual ~Basketball();

    Core myCore;
    Channels myChannels;

    void createVAO(GLint program);

    void drawBasketball();

protected:
private:
};

#endif // Basketball_H