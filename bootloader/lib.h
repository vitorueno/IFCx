#ifndef __LIB_H__
#define __LIB_H__

#include "types.h"

extern void *memcpy(void *dest, void *src, size_t count);  // copia bytes de src para dest 
extern void *memset(void *dest, char val, size_t count); // settar bytes de dest para val
extern uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count); // memset versão word (32 bytes)
extern size_t strlen(const char *str); // retorna o tamanho de uma string
extern uint8_t inportb (uint16_t _port); // versão C da instrução in 
extern void outportb (uint16_t _port, uint8_t _data); // versão C da instrução out


#endif // __LIB_H__