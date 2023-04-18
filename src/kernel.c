#include "print.h"
#include "types.h"
#include "lib.h"
#include "idt.h"
#include "isr.h"

int main()
{
    initializeIDT();
    initializeISR();

    char *mensagem = "Bem vindo ao IFCX\0";
    printString(mensagem);

    return 0; // returning control to assembly code
}