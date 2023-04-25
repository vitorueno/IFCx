#ifndef __IMPRIME_H_
#define __IMPRIME_H_

#include "types.h"
#include "lib.h"

extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

#endif