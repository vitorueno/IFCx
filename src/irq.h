#ifndef __IRQ_H__
#define __IRQ_H__

#include "isr.h"
#include "pic.h"

typedef void (*IRQHandler)(Registers *regs);

void initializeIRQ();
void irqRegisterHandler(int irq, IRQHandler handler);

#endif // __IRQ_H__