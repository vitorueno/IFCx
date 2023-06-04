#include "imprime.h"
#include "io.h"

#define MAX_DIGITS 11 // Máximo de dígitos para um número inteiro

uint16_t *textmemptr;

int text_color = 0x0F; // white

int csr_x = 0;
int csr_y = 0;

void scroll(void)
{
    // unsigned -> Valor precisa ser >= 0

    uint32_t espaco_em_branco;
    uint32_t temp;

    // Espaço em branco e cor do texto branco
    espaco_em_branco = 0x20 | (text_color << 8);

    // A última linha na tela é a linha 24 (começa na 0 -> 24)
    if(csr_y >= 25)
    {
        // limpa a ultima linha para criar efeito de rolagem de tela
        temp = csr_y - 25 + 1;
        memcpy (textmemptr, textmemptr + temp * 80, (25 - temp) * 80 * 2);

        // Preenche a ultima linha com espaço em branco
        memsetw (textmemptr + (25 - temp) * 80, espaco_em_branco, 80);
        csr_y = 25 - 1;
    }
}

void move_csr(void)
{
    uint32_t temp;

//  Temp recebe a posição atual do cursor na tela

    temp = csr_y * 80 + csr_x;

// -> O registro 14 é o registrador de alto byte do cursor, 
//    que controla a posição vertical do cursor na tela

    outportb(0x3D4, 14); 
    outportb(0x3D5, temp >> 8);

// -> O registro 15 é o registrador de baixo byte do cursor, 
//    que controla a posição horizontal do cursor na tela. 

    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void cls()
{
    uint32_t blank;
    int i;

    blank = 0x20 | (text_color << 8);

    // Coloca espaço em branco em toda a tela
    for(i = 0; i < 25; i++)
        memsetw (textmemptr + i * 80, blank, 80);

    //Move e coloca o cursor no inicio da tela
    csr_x = 0;
    csr_y = 0;
    move_csr();
}

/* Puts a single character on the screen */
void putc(uint8_t c)
{
    uint16_t *where;
    uint32_t att = text_color << 8;

    /* VK_BACK	0x08	Chave BACKSPACE */
    if(c == 0x08){
        if(csr_x != 0) csr_x--;
    }
    /* VK_TAB	0x09	tecla TAB */
    else if(c == 0x09) {
        csr_x = (csr_x + 8) & ~(8 - 1);

        /*
        Ela é feita para que a posição do cursor na linha seja ajustada de modo que fique alinhada com a próxima posição que é múltipla de 8.
        Isso ocorre porque, em sistemas antigos de computador, era comum que a largura de cada caractere fosse definida como sendo de 8 pixels.
        Sendo assim, ao posicionar o cursor em uma posição que não seja múltipla de 8, 
        o próximo caractere pode acabar sendo desenhado em uma posição que não esteja bem alinhada com os demais caracteres, 
        causando um efeito visual desagradável.
        Então, quando um caractere de tabulação é encontrado, a posição do cursor na linha é ajustada para ser 
        o próximo múltiplo de 8, garantindo que os caracteres seguintes sejam desenhados em posições alinhadas.
        */

    }
    /* Handles a 'Carriage Return' */
    else if(c == '\r') {
        csr_x = 0;

    // O \r força uma "quebra na linha" e reposiciona o cursor na posição inicial da linha seguinte, 
    // porém ele ainda pertence a linha de cima

    }
    /* We handle our newlines the way DOS and the BIOS do: we
    *  treat it as if a 'CR' was also there, so we bring the
    *  cursor to the margin and we increment the 'y' value */
    else if(c == '\n')
    {
        csr_x = 0;
        csr_y++;

        // o \n é criada uma nova linha, independente das linhas anteriores

    }
    /* Any character greater than and including a space, is a
    *  printable character. The equation for finding the index
    *  in a linear chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    else if(c >= ' ')
    {
        where = textmemptr + (csr_y * 80 + csr_x);
        *where = c | att;	/* Character AND attributes: color */
        csr_x++;
    }

    /* If the cursor has reached the edge of the screen's width, we
    *  insert a new line in there */
    if(csr_x >= 80)
    {
        csr_x = 0;
        csr_y++;
    }

    /* Scroll the screen if needed, and finally move the cursor */
    scroll();
    move_csr();
}

/* Uses the above routine to output a string... */
void puts(uint8_t *text)
{
    int i;

    for (i = 0; i < strlen(text); i++)
    {
        putc(text[i]);
    }
}

void putchar(const char *text)
{
    int i;

    for (i = 0; i < strlen(text); i++)
    {
        putc(text[i]);
    }
}

uint8_t *intToAscii(int number) {
    static uint8_t result[MAX_DIGITS];
    int i = MAX_DIGITS - 1;
    int isNegative = 0;

    // Lida com o caso especial de número zero
    if (number == 0) {
        result[i--] = '0';
    }
    // Lida com números negativos
    else if (number < 0) {
        isNegative = 1;
        number = -number;
    }

    // Converte cada dígito para um caractere ASCII
    while (number != 0) {
        int digit = number % 10;
        result[i--] = digit + '0';
        number /= 10;
    }

    // Adiciona o sinal negativo, se necessário
    if (isNegative) {
        result[i--] = '-';
    }

    return &result[i + 1];
}


/* Define cor principal e cor de fundo */
void settextcolor(uint8_t forecolor, uint8_t backcolor)
{
    // Os 4 bytes superiores são o plano de fundo, os 4 bytes inferiores são a cor do primeiro plano
    text_color = (backcolor << 4) | (forecolor & 0x0F);
}

/* Define o ponteiro VGA em modo de texto e limpa a tela */
void init_video(void)
{
    textmemptr = (uint16_t *)0xB8000;
    cls();
}