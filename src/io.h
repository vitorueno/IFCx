#ifndef __IO_H__
#define __IO_H__

#include "types.h"

uint8_t inportb(uint16_t _port);              // C version of the 'in' instruction
void outportb(uint16_t _port, uint8_t _data); // C version of the 'out' instruction
void iowait();                                // old hardware needs an interval between operations in PIC
extern __attribute__((cdecl)) void disableInterrupts();
extern __attribute__((cdecl)) void enableInterrupts();

#endif