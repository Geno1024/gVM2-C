//
// Created by geno1024 on 2018-10-10.
//

#ifndef GVM2_C_MEMORY_H
#define GVM2_C_MEMORY_H

struct memory;
typedef struct memory *Memory;

Memory new_memory(long size);

// read 1 byte
unsigned char mread1(Memory mem, long pos);
// write 1 byte
void mwrite1(Memory mem, long pos, unsigned char data);

// read 4 bytes
unsigned int mread4(Memory mem, long pos);
// write 4 bytes
void mwrite4(Memory mem, long pos, unsigned int data);

// read 8 bytes
unsigned long mread8(Memory mem, long pos);
// write 8 bytes
void mwrite8(Memory mem, long pos, unsigned long data);

#endif //GVM2_C_MEMORY_H
