#ifndef PRINTBASE_H
#define PRINTBASE_H

#define BITLEN_8   8
#define BITLEN_16 16
#define BITLEN_32 32
#define BITLEN_64 64

#include <stdint.h>

void printBase10(uint64_t number);
void printBase2(uint64_t number, int bitlen);
void printBase16(uint64_t number, int bitlen);

#endif
