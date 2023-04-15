#ifndef __LIB_H__
#define __LIB_H__

#include "types.h"
#include "lib.h"

extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

#endif