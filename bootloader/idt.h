#ifndef __IDT_H__
#define __IDT_H__

#include "types.h"

#define setFlag(x, flag) x |= (flag)
#define unsetFlag(x, flag) x &= ~(flag)

typedef enum
{
    IDT_FLAG_GATE_TASK = 0x5,
    IDT_FLAG_GATE_16BIT_INT = 0x6,
    IDT_FLAG_GATE_16BIT_TRAP = 0x7,
    IDT_FLAG_GATE_32BIT_INT = 0xE,
    IDT_FLAG_GATE_32BIT_TRAP = 0xF,

    IDT_FLAG_RING0 = (0 << 5),
    IDT_FLAG_RING1 = (1 << 5),
    IDT_FLAG_RING2 = (2 << 5),
    IDT_FLAG_RING3 = (3 << 5),

    IDT_FLAG_PRESENT = 0x80,

} IDT_FLAGS;

void initializeIDT();
void setIdtGate(int interruptNumber, void *base, uint16_t segmentDescriptor, uint8_t flags);
void enableIdtGate(int interruptNumber);
void disableIdtGate(int interruptNumber);

#endif // __IDT_H__