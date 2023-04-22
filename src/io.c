#include "io.h"

#define UNUSED_PORT 0x80

uint8_t inportb(uint16_t _port)
{
    uint8_t rv;
    __asm__ __volatile__("inb %1, %0"
                         : "=a"(rv)
                         : "dN"(_port));
    return rv;
}

void outportb(uint16_t _port, uint8_t _data)
{
    __asm__ __volatile__("outb %1, %0"
                         :
                         : "dN"(_port), "a"(_data));
}

void iowait()
{
    outportb(UNUSED_PORT, 0);
}

// void disableInterrupts()
// {
//     __asm__ __volatile__("cli"
//                          :
//                          :
//                          : "memory");
// }

// void enableInterrupts()
// {
//     __asm__ __volatile__("sti"
//                          :
//                          :
//                          : "memory");
// }