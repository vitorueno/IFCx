#include "print.h"
#include "types.h"
#include "lib.h"


int main() // definindo como externa para o linker solucionar referências
{
    // testando os boleanos
    bool teste = true;
    char *mensagem = "Bem vindo ao IFCX\0";

    if (teste == true) {
        printString(mensagem); 
        printNumAt(strLen(mensagem), 1,1);
    }


    char csrc[] = "Teste memcpy";
    char cdest[100]; 
    memcpy(cdest, csrc, strlen(csrc) +1);
    printStringAt(cdest, 2, 1);
    memset(cdest, 'x', 80);
    printStringAt(cdest, 3, 1);

    size_t a = 10;

    
    return 0; // retornando o controle para kernel_entry (assembly)
}