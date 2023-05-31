#include "imprime.h"
#include "types.h"
#include "lib.h"
#include "io.h"
#include "idt.h"
#include "isr.h"
#include "irq.h"
#include "print.h"

void onTimerTick(Registers *regs)
{
    //puts("O timer foi disparado");
    putc('\n');
    puts(intToAscii(-123));
}

void onKeyPress(Registers *regs)
{
    puts("Uma tecla foi pressionada");
}

int main()
{
    init_video();
    initializeIDT();
    initializeISR();
    initializeIRQ();


    char *mensagem = "Bem vindo ao IFCX\0";
    puts(mensagem);

    irqRegisterHandler(0, onTimerTick);
    irqRegisterHandler(1, onKeyPress);

    bool testarTTY = false;

    if (testarTTY)
    {
        putc('\n');
        putc('a');
        putc('\n');
        putc('z');
    }

    return 0; // returning control to assembly code
}