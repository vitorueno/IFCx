#ifndef __LIB_H__
#define __LIB_H__


#include "types.h"

extern void *memcpy(void *dest, void *src, size_t count);  // copy bytes from source to dest
extern void *memset(void *dest, char val, size_t count); // sets count bytes of dest to val
extern uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count); // 32-bit version of memset
extern size_t strlen(const char *str); // returns the size of a string
extern uint8_t inportb (uint16_t _port); // C version of the 'in' instruction
extern void outportb (uint16_t _port, uint8_t _data); // C version of the 'out' instruction


#endif // __LIB_H__