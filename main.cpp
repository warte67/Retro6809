/**** main.cpp ***************************
 *
 * Linux
 *      build:
 *          g++ -Werror -std=c++17 -pthread test.cpp -o test -lSDL2 -D__LINUX__
 *      run:
 *          ./test
 * 
 * Github now enabled?
 *
 ****************/

// #define __LINUX__

#include "Bus.h"
#include "Gfx.h"


int main(int argc, char* argv[])
{
    Bus bus;
    bus.run();


    return 0;
}