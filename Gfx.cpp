//// Bus.cpp //////////////////////////////////


#include "Gfx.h"
#include "Bus.h"

Gfx::Gfx(Bus* pBus)
{
    printf("Gfx::Gfx() \n");

    bus = pBus;
}

Gfx::~Gfx()
{
    printf("Gfx::~Gfx() \n");
}

void Gfx::_onceInit()
{
    printf("Gfx::_onceInit()\n");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL Failed to initialize: %s\n", SDL_GetError());
        bus->IsRunning(false);
    }
}

void Gfx::_onceQuit()
{
    printf("Gfx::_onceQuit()\n");

    SDL_Quit();
}

void Gfx::OnCreate()
{
    if(bIsDirty)
    {
        window = SDL_CreateWindow("SDL Test",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1024, 768, SDL_WINDOW_SHOWN);
        surface = SDL_GetWindowSurface(window);
        bIsDirty = false;
    }
}

void Gfx::OnDestroy()
{
    if (surface)
    {
        SDL_FreeSurface(surface);   
        surface = nullptr;
    }
    if (window)
    {
        SDL_DestroyWindow(window);  
        window = nullptr;
    }
    bIsDirty = true;
}