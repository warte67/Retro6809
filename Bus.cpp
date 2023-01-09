//// Bus.cpp //////////////////////////////////

#include "Gfx.h"
#include "Bus.h"

Bus::Bus()
{
    printf("Bus::Bus()\n");

    gfx = new Gfx(this);

    // call _onceInit() only after every device has been created
    _onceInit();    
}

Bus::~Bus()
{
    printf("Bus::~Bus()\n");

    // call _onceQuit for every device
    _onceQuit();

    // destroy devices that were created by Bus
    if (gfx)
    {
        delete gfx;
        gfx = nullptr;
    }
}


void Bus::_onceInit()
{
    printf("Bus::_onceInit()\n");
    gfx->_onceInit();
}

void Bus::_onceQuit()
{
    printf("Bus::_onceQuit()\n");
    gfx->_onceInit();
}

void Bus::run()
{
    while (bIsRunning)
    {
        if (gfx->IsDirty())
        {
            // refresh the screen when toggling resolution
            // or fullscreen/windowed i.e. "when dirty"
            gfx->OnDestroy();
            gfx->OnCreate();
        }

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_QUIT:
                {
                    bIsRunning = false;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    if (e.key.keysym.sym == SDLK_ESCAPE)
                        bIsRunning = false;
                    break;
                }
            }
        }
    }
    gfx->OnDestroy();
}
