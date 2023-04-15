#include "imprime.h"
#include "types.h"
#include "lib.h"

int main (void) // definindo como externa para o linker solucionar referências
{
    // testando os boleanos
    bool teste = true;
    char *mensagem = "Bem vindo ao IFCX";

    if (teste == true) {
        puts(mensagem); 
        putch('\n');
        char sizeMessage = strlen(mensagem);
        putch(sizeMessage);
    }


    char csrc[] = "Teste memcpy";
    char cdest[100];
    memcpy(cdest, csrc, strlen(csrc) + 1);
    puts(cdest);
    memset(cdest, 'x', 80);
    puts(cdest);

    size_t a = 10;

    
    return 0; // retornando o controle para kernel_entry (assembly)
}