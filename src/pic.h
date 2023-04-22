#ifndef __PIC_H__
#define __PIC_H__

#include "types.h"
#include "io.h"

void configurePIC(uint8_t offsetPIC1, uint8_t offsetPIC2);
void maskIRQ(int irq);
void unmaskIRQ(int irq);
void disablePIC();
void sendEOI(int irq);
uint16_t getIRR();
uint16_t getISR();

#endif