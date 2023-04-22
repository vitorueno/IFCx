#ifndef __TTY_H__
#define __TTY_H__

#define VIDEO_BASE 0xb8000

struct t_tty
{
    int column;
    int row;
    int nColumns;
    int nRows;
    char *pos;
};

void initTTY();
void putc(char c);

#endif