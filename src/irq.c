#include "irq.h"
#include "pic.h"
#include "io.h"
#include "imprime.h"
#include "lib.h"
#include "types.h"

#define PIC_REMAP_OFFSET 32 // first available interrupt after the exceptions

IRQHandler irqHandlers[16];

void irqHandler(Registers *regs)
{
    int irq = regs->interrupt - PIC_REMAP_OFFSET;

    if (irqHandlers[irq] != NULL)
    {
        irqHandlers[irq](regs);
    }
    else
    {
        puts("IRQ nao tratada:\n");
        puts(intToAscii(irq));
    }

    sendEOI(irq);
}

void initializeIRQ()
{
    configurePIC(PIC_REMAP_OFFSET, PIC_REMAP_OFFSET + 8);

    for (int i = 0; i < 16; i++)
        isrRegisterHandler(PIC_REMAP_OFFSET + i, irqHandler);

    enableInterrupts();

    puts("IRQs carregadas\n");
}

void irqRegisterHandler(int irq, IRQHandler handler)
{
    irqHandlers[irq] = handler;
}