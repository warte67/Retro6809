//// types.h //////////////////////////////////

#pragma once
#ifndef __TYPES_H__
#define __TYPES_H__

#ifdef __LINUX__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <stdio.h>
#include <string>
#include <vector>

#ifndef __DEFINED_BYTE__
#define __BYTE__
typedef Uint8 Byte;
#endif
#ifndef __DEFINED_WORD__ 
#define __DEFINED_WORD__
typedef Uint16 Word;
#endif

#ifndef __DEFINED_DWORD__ 
#define __DEFINED_DWORD__
typedef uint32_t	DWord;
#endif

//#ifdef LINUX
//#include <SDL2/SDL.h>
//#else
//#pragma comment(lib, "SDL2.lib")
//#pragma comment(lib, "SDL2main.lib")
//#include <SDL.h>
//#endif

#endif // __TYPES_H__