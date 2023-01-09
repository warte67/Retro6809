//// Bus.h //////////////////////////////////

#pragma once
#ifndef __GFX_H__
#define __GFX_H__

#include "types.h"

class Bus;

class Gfx
{
	friend class Bus;

public:
	Gfx(Bus* pBus);
	~Gfx();

	void OnCreate();
	void OnDestroy();

	void IsDirty(bool dirty) { bIsDirty = dirty; }
	bool IsDirty() { return bIsDirty; }

private:
	Bus* bus = nullptr;
	bool bIsDirty = true;
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	void _onceInit();
	void _onceQuit();

};



#endif // __GFX_H__