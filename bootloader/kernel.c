#include "print.h"
#include "types.h"


int main() // definindo como externa para o linker solucionar referências
{

    // testando os boleanos
    bool teste = true;
    char *mensagem = "Bem vindo ao IFCX\0";

    if (teste == true) {
        printString(mensagem); 
        printNumAt(strLen(mensagem), 1,1);
    }
    
    return 0; // retornando o controle para kernel_entry (assembly)
}