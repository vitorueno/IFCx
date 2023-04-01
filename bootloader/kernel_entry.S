# fazendo o link do boot.asm com o código assembly
# será compilado em um object file elf para linkar 

.text     

.globl _start 

_start: 
    call main                   # chamando a função main do código C

    mov $'Z', %al               # caracter a imprimir
    mov $0x0f, %ah              # formatação texto branco
    mov %ax, 0xb800C            # adicionando o caracter + formatação na memória de vídeo após os anteriores

loop:
    hlt                         # loop infinito
    jmp loop

