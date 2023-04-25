#include "idt.h"
#include "print.h"

typedef struct
{
    uint16_t baseLow;
    uint16_t segmentSelector;
    uint8_t reserved;
    uint8_t flags;
    uint16_t baseHigh;
} __attribute__((packed)) IdtEntry;

typedef struct
{
    uint16_t limit;
    IdtEntry *base;
} __attribute__((packed)) IdtPointer;

IdtEntry idt[256];
IdtPointer idtPointer = {sizeof(idt) - 1, idt};

void setIdtGate(int interruptNumber, void *base, uint16_t segmentDescriptor, uint8_t flags)
{
    idt[interruptNumber].baseLow = ((uint32_t)base) & 0xFFFF;
    idt[interruptNumber].segmentSelector = segmentDescriptor;
    idt[interruptNumber].reserved = 0;
    idt[interruptNumber].flags = flags;
    idt[interruptNumber].baseHigh = ((uint32_t)base >> 16) & 0xFFFF;
}

void enableIdtGate(int interruptNumber)
{
    setFlag(idt[interruptNumber].flags, IDT_FLAG_PRESENT);
}

void disableIdtGate(int interruptNumber)
{
    unsetFlag(idt[interruptNumber].flags, IDT_FLAG_PRESENT);
}

extern void __attribute__((cdecl)) loadIDT(IdtPointer *idtPtr); // written in the assembly file

void initializeIDT()
{
    loadIDT(&idtPointer);
    printStringAt("IDT carregada", 22, 1);
}