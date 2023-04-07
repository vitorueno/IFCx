#include "print.h"
#include "types.h"
#include "lib.h"
#include "idt.h"
#include "isr.h"

extern void teste(char c);

int main() // definindo como externa para o linker solucionar referências
{
    initializeIDT();
    initializeISR();

    char *mensagem = "Bem vindo ao IFCX\0";
    printString(mensagem);

    bool isTest = false;

    if (isTest)
    {
        teste('A');
        printNumAt(strLen(mensagem), 1, 1);
        char csrc[] = "Teste memcpy";
        char cdest[100];
        memcpy(cdest, csrc, strlen(csrc) + 1);
        printStringAt(cdest, 2, 1);
        memset(cdest, 'x', 80);
        printStringAt(cdest, 3, 1);
        size_t a = 10;

        // error handling
        // printNumAt(10/0, 6,1);
    }

    return 0; // retornando o controle para kernel_entry (assembly)
}