//
// Created by geno1024 on 2018-10-10.
//

#ifndef GVM2_C_MEMORY_H
#define GVM2_C_MEMORY_H

#include "../gutils.h"

struct memory;
typedef struct memory *Memory;

Memory new_memory(ulong size);

// read 1 byte
uchar mread1(Memory mem, ulong pos);
// write 1 byte
void mwrite1(Memory mem, ulong pos, uchar data);

// read 4 bytes
uint mread4(Memory mem, ulong pos);
// write 4 bytes
void mwrite4(Memory mem, ulong pos, uint data);

// read 8 bytes
ulong mread8(Memory mem, ulong pos);
// write 8 bytes
void mwrite8(Memory mem, ulong pos, ulong data);

// dump a range of memory
void mdump(Memory mem, ulong start, ulong end);

#endif //GVM2_C_MEMORY_H
