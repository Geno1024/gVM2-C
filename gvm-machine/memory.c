//
// Created by geno1024 on 2018-10-10.
//

#include <malloc.h>
#include "memory.h"

struct memory
{
    ulong size;
    uchar *memory;
};

Memory new_memory(ulong size)
{
    Memory mem = malloc(sizeof(Memory));
    mem->size = size;
    mem->memory = (uchar *) malloc(size);
    return mem;
}

unsigned char mread1(Memory mem, ulong pos)
{
    return mem->memory[pos];
}

void mwrite1(Memory mem, ulong pos, uchar data)
{
    mem->memory[pos] = data;
}

unsigned int mread4(Memory mem, ulong pos)
{
    return
    (mem->memory[pos    ] << 24) +
    (mem->memory[pos + 1] << 16) +
    (mem->memory[pos + 2] <<  8) +
     mem->memory[pos + 3];
}

void mwrite4(Memory mem, ulong pos, uint data)
{
    mem->memory[pos    ] = (uchar) (data >> 24);
    mem->memory[pos + 1] = (uchar) (data >> 16);
    mem->memory[pos + 2] = (uchar) (data >>  8);
    mem->memory[pos + 3] = (uchar) (data      );
}

unsigned long mread8(Memory mem, ulong pos)
{
    return
    ((ulong) mem->memory[pos    ] << 56) +
    ((ulong) mem->memory[pos + 1] << 48) +
    ((ulong) mem->memory[pos + 2] << 40) +
    ((ulong) mem->memory[pos + 3] << 32) +
    ((ulong) mem->memory[pos + 4] << 24) +
    ((ulong) mem->memory[pos + 5] << 16) +
    ((ulong) mem->memory[pos + 6] <<  8) +
     (ulong) mem->memory[pos + 7];
}

void mwrite8(Memory mem, ulong pos, ulong data)
{
    mem->memory[pos    ] = (uchar) (data >> 56);
    mem->memory[pos + 1] = (uchar) (data >> 48);
    mem->memory[pos + 2] = (uchar) (data >> 40);
    mem->memory[pos + 3] = (uchar) (data >> 32);
    mem->memory[pos + 4] = (uchar) (data >> 24);
    mem->memory[pos + 5] = (uchar) (data >> 16);
    mem->memory[pos + 6] = (uchar) (data >>  8);
    mem->memory[pos + 7] = (uchar) (data      );
}

void mdump(Memory mem, ulong start, ulong end)
{
    // zeroth line
    printf("----------------:  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");

    // first line
    unsigned long startLine = start & 0x7ffffffffffffff0;
    unsigned long endLine = end & 0x7ffffffffffffff0;

    printf("%016lx:", startLine);
    for (unsigned long i = startLine; i < start; i++) printf("   ");

    for (unsigned long i = start; i < min(startLine + 16, end + 1); i++) printf(" %02x", mread1(mem, i));

    // last line, if exists
    if (startLine - endLine)
    {
        for (unsigned long i = end; i < startLine + 16; i++) printf(" %02x", mread1(mem, i));
        for (unsigned long i = startLine + 16; i < endLine; i++)
        {
            if (!(i & 15)) printf("\n%016lx:", i);
            printf(" %02x", mread1(mem, i));
        }
        printf("\n%016lx:", endLine);
        for (unsigned long i = endLine; i <= end; i++) printf(" %02x", mread1(mem, i));
    }
    printf("\n");
};