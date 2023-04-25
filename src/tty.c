#include "tty.h"
#include "io.h"
#include "types.h"

struct t_tty tty;

void initTTY()
{
    tty.column = 0;
    tty.row = 0;
    tty.nRows = 25;
    tty.nColumns = 80;
    tty.pos = (char *)VIDEO_BASE;
}

void putc(char c)
{
    if (c == '\n')
    {
        int col = (((int)tty.pos - VIDEO_BASE) / 2) % tty.nColumns;
        tty.pos += (tty.nColumns - col) * 2;
        return;
    }

    *tty.pos = c;
    // tty.pos = (char *)((tty.pos + 2 - VIDEO_BASE) % (tty.nColumns * 2 + tty.nRows)) + VIDEO_BASE;
    tty.pos += 2;

    // uint16_t pos = (tty.nColumns * tty.row + tty.column);
    // char *console = (char *)VIDEO_BASE;
    // console += 2 * pos;

    // *console = c;
    // tty.column = (tty.column + 1) % tty.nColumns;
    // // tty.row = (tty.row + 1) % tty.nRows;

    outportb(0x3d4, 0xf);
    outportb(0x3d5, (((int)tty.pos - VIDEO_BASE) >> 1) & 0xff);

    outportb(0x3d4, 0xe);
    outportb(0x3d5, ((((int)tty.pos - VIDEO_BASE) >> 1) & 0xff00) >> 8);
}
