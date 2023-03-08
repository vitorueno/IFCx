extern "C" int main() // definindo como externa para o linker solucionar referências
{
    /* imprimindo um caracter na tela (modo de vídeo 0x3)
       início 0xb8000 no modo 32 bits
       funciona sempre com um byte para o caracter e um para sua formatação
    */
    char bla = 'a';
    char *ptr = (char *)0xb8000;
    for (int i=0; i<26; i++) {
        *ptr = bla;
        ptr += 2;
        bla++;
    }
    // *(char *)0xb8000 = 'O';
    // *(char *)0xb8002 = 'I';
    // *(char *)0xb8004 = ' ';
    // *(char *)0xb8006 = ':';
    // *(char *)0xb8008 = ')';
    return 0; // retornando o controle para kernel_entry (assembly)
}