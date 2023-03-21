#include "print.h"

extern "C" int main() // definindo como externa para o linker solucionar referências
{
    // print(length("teste"));
    print(123, 10, 5);
    return 0; // retornando o controle para kernel_entry (assembly)
}