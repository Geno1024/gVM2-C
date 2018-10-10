#include <stdio.h>
#include "gvm-machine/memory.h"

int main()
{
    Memory memory = new_memory(1024);
    mwrite1(memory, 0, 0x40);
    mwrite1(memory, 1, 0x41);
    mwrite1(memory, 2, 0x42);
    mwrite1(memory, 3, 0x43);
//    printf("%x", mread4(memory, 0));
    mdump(memory, 0, 0x11);
    return 0;
}