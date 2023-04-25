#include "imprime.h"
#include "types.h"
#include "lib.h"

int main (void) // definindo como externa para o linker solucionar referências
{
    // testando os boleanos
    init_video();
    settextcolor(15, 0);
    putch('a');
    puts("abcd\n123");

    cls();

    puts("abcd\n123456");

    
    return 0; // retornando o controle para kernel_entry (assembly)
}