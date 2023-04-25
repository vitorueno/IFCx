#include "imprime.h"
#include "types.h"
#include "lib.h"

int main (void) // definindo como externa para o linker solucionar referências
{
    // 'Abre' a porta de video
    init_video();

    // Define cor de fonte e fundo
    settextcolor(15, 0);

    puts("Rodrigo\nCabral\nBock");

    cls();

    puts("Exemplo 1"); 

    cls();
   

    
    return 0; // retornando o controle para kernel_entry (assembly)
}