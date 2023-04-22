#include "print.h"
#include "types.h"
#include "lib.h"
#include "io.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"

void onTimerTick(Registers *regs)
{
    printStringAt("O timer foi disparado", 3, 1);
}

void onKeyPress(Registers *regs)
{
    printStringAt("Uma tecla foi pressionada", 4, 1);
}

int main()
{
    initializeIDT();
    initializeISR();
    initializeIRQ();

    char *mensagem = "Bem vindo ao IFCX\0";
    printString(mensagem);

    irqRegisterHandler(0, onTimerTick);
    irqRegisterHandler(1, onKeyPress);

    return 0; // returning control to assembly code
}