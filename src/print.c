#include "print.h"

/*
as funções escrevem diretamente na memória a partir do endereço 0xb8000
levando em conta que estamos usando o modo de vídeo 0x3 -> 24 linhas e 80 colunas
*/

// retorna o tamanho de uma string
int strLen(const char *str)
{
    int size = 0;
    while (*str != '\0')
    {
        size++;
        str++;
    }
    return size;
}

// retorna o tamanho de um número inteiro
int numLen(int numero)
{
    int size = 0;

    if (numero == 0)
    {
        return 1;
    }

    while (numero != 0)
    {
        numero /= 10;
        size++;
    }

    return size;
}

// calcula a potência de um número base^expoente
int pow(int base, int expoente)
{
    int resultado = 1;
    for (int i = 0; i < expoente; i++)
    {
        resultado *= base;
    }

    return resultado;
}

/* Função que imprime a mensagem no canto superior esquerdo da tela */
int printString(const char *message)
{
    // endereço do início do endereço de memória de vídeo
    char *console = (char *)0xb8000;

    // iterando pela String (até encontrar \0 -> fim da string)
    for (int i = 0; message[i] != '\0'; i++)
    {
        console[i * 2] = message[i]; // escreve o caracter na posição
        console[i * 2 + 1] = 0x0F;   // o byte seguinte recebe a formatação (branco no fundo preto aqui)
    }

    return 0;
}

/* Função que imprime um número no canto superior esquerdo da tela */
int printNum(int numero)
{
    if (numero < 0)
    {
        numero = 0;
    }

    char *console = (char *)0xb8000;

    if (numero == 0)
    {
        int ascii_code = numero + 48;
        *console = (char)ascii_code;
    }

    while (numero > 0)
    {
        int tamanho = numLen(numero);
        int divisor = pow(10, tamanho-1);

        int digito = numero / (divisor);
        numero = numero % divisor;

        int ascii_code = digito + 48;
        *console = (char)ascii_code;
        console++;
        *console = 0x0F;
        console++;
    }

    return 0;
}

/* Função que imprime um número numa linha e coluna específica */
int printNumAt(int numero, int linha, int coluna)
{
    if (numero < 0)
    {
        numero = 0;
    }

    int offset_caracter = (160 * linha) + (2 * (coluna - 1));
    int posicao_caracter = 0xb8000 + offset_caracter;
    char *console = (char *)posicao_caracter;

    if (numero == 0)
    {
        int ascii_code = numero + 48;
        *console = (char)ascii_code;
    }

    while (numero > 0)
    {
        int tamanho = numLen(numero);
        int divisor = pow(10, tamanho-1);

        int digito = numero / (divisor);
        numero = numero % divisor;

        int ascii_code = digito + 48;
        *console = (char)ascii_code;
        console++;
        *console = 0x0F;
        console++;
    }

    return 0;
}

/* Função que imprime uma mensagem numa linha e coluna específica */
int printStringAt(const char *message, int linha, int coluna)
{
    bool cabe = (strLen(message) + coluna) < 80;

    if ((linha > 24) || (linha == 24 && !cabe))
    {
        return 1;
    }

    int offset_caracter = (160 * linha) + (2 * (coluna - 1));
    int posicao_caracter = 0xb8000 + offset_caracter;
    char *console = (char *)posicao_caracter;

    // iterando pela String (até encontrar \0 -> fim da string)
    for (int i = 0; message[i] != '\0'; i++)
    {
        console[i * 2] = message[i]; // escreve o caracter na posição
        console[i * 2 + 1] = 0x0F;   // o byte seguinte recebe a formatação (branco no fundo preto aqui)
    }

    return 0;
}