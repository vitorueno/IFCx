#ifndef __LIB_H__
#define __LIB_H__

#include "types.h"

void *memcpy(void *dest, void *src, size_t count);             // copy bytes from source to dest
void *memset(void *dest, char val, size_t count);              // sets count bytes of dest to val
uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count); // 32-bit version of memset
size_t strlen(const char *str);                                // returns the size of a string
size_t numLen(const uint64_t num);                              // returns the size of a number

#endif // __LIB_H__