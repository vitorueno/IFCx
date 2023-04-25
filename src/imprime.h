#ifndef __IMPRIME_H_
#define __IMPRIME_H_

#include "types.h"
#include "lib.h"

extern void cls();
extern void putch(uint8_t c);
extern void puts(uint8_t *str);
extern void settextcolor(uint8_t forecolor, uint8_t backcolor);
extern void init_video();



#endif