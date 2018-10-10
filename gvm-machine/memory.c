//
// Created by geno1024 on 2018-10-10.
//

#include <malloc.h>
#include "memory.h"

struct memory
{
    long size;
    unsigned char *memory;
};

Memory new_memory(long size)
{
    Memory mem = malloc(sizeof(Memory));
    mem->size = size;
    mem->memory = (unsigned char *) malloc(size);
    return mem;
};

unsigned char mread1(Memory mem, long pos)
{
    return mem->memory[pos];
};

void mwrite1(Memory mem, long pos, unsigned char data)
{
    mem->memory[pos] = data;
};

unsigned int mread4(Memory mem, long pos)
{
    return
    (mem->memory[pos    ] << 24) +
    (mem->memory[pos + 1] << 16) +
    (mem->memory[pos + 2] <<  8) +
     mem->memory[pos + 3];
}

void mwrite4(Memory mem, long pos, unsigned int data)
{
    mem->memory[pos    ] = (unsigned char) (data >> 24);
    mem->memory[pos + 1] = (unsigned char) (data >> 16);
    mem->memory[pos + 2] = (unsigned char) (data >>  8);
    mem->memory[pos + 3] = (unsigned char) (data      );
};

unsigned long mread8(Memory mem, long pos)
{
    return
    ((unsigned long) mem->memory[pos    ] << 56) +
    ((unsigned long) mem->memory[pos + 1] << 48) +
    ((unsigned long) mem->memory[pos + 2] << 40) +
    ((unsigned long) mem->memory[pos + 3] << 32) +
    ((unsigned long) mem->memory[pos + 4] << 24) +
    ((unsigned long) mem->memory[pos + 5] << 16) +
    ((unsigned long) mem->memory[pos + 6] <<  8) +
     (unsigned long) mem->memory[pos + 7];
};

void mwrite8(Memory mem, long pos, unsigned long data)
{
    mem->memory[pos    ] = (unsigned char) (data >> 56);
    mem->memory[pos + 1] = (unsigned char) (data >> 48);
    mem->memory[pos + 2] = (unsigned char) (data >> 40);
    mem->memory[pos + 3] = (unsigned char) (data >> 32);
    mem->memory[pos + 4] = (unsigned char) (data >> 24);
    mem->memory[pos + 5] = (unsigned char) (data >> 16);
    mem->memory[pos + 6] = (unsigned char) (data >>  8);
    mem->memory[pos + 7] = (unsigned char) (data      );
};