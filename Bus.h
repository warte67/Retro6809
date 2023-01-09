//// Bus.h //////////////////////////////////

#pragma once
#ifndef __BUS_H__
#define __BUS_H__

#include "types.h"

class Gfx;

class Bus
{
public:
    Bus();
    ~Bus();

    void _onceInit();
    void _onceQuit();

    void run();

    bool IsRunning() { return bIsRunning; }
    void IsRunning(bool running) { bIsRunning = running; }

private:
    Gfx* gfx = nullptr;

    bool bIsRunning = true;
};







#endif // __BUS_H__
