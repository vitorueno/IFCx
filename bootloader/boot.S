# código para mudar para 32 bits adpatado de https://www.linuxquestions.org/questions/programming-9/help-loading-up-gdt-switching-to-protected-mode-assembly-at-and-t-syntax-205639/
# restante do código baseado em https://youtu.be/EpFUzjYehxs?list=PLm3B56ql_akNcvH8vvJRYOc7TbYhRs19M

.code16                   
.text                     

.globl _start;


.equ KERNEL_LOCATION, 0x1000                    # onde vamos carregar o Kernel (C)

_start:
    movb %dl, BOOT_DISK                         # salvando o número do disco em uma var


    # inicializando o ambiente seguindo o Tiny model 
    xor %ax, %ax                                # zerando o ax 
    movw %ax, %es                               # es = 0
    movw %ax, %ds                               # ds = 0 
    movw $0x8000, %bp                           # bp = 0x8000 -> valor comum para não ter chance de atrapalhar código (cresce para baixo)
    movw %bp, %sp                               # facilitar acesso aos elementos da stack 

    # dois regs  que serão usadas no futuro
    movw $KERNEL_LOCATION, %bx                  # bx = posição que queremos carregar o Kernel
    movb $20, %dh                                # quantos setores queremos carregar (será atribuído a al)

    # carregando blocos do disco para a memória
    movb $0x02, %ah                             # int 0x13 função 0x2
    movb %dh, %al                               # número de setores a ler
    movb $0x00, %ch                             # número do cilindo (0)
    movb $0x00, %dh                             # número da cabeça (0)
    movb $0x02, %cl                             # número do setor  (2)
    movb BOOT_DISK, %dl                         # número do disco (iniciou em dl)
    int $0x13                                   # chamada 0x13
    jc disk_error                               # tratamento de erro (CF = 1 => erro)


    # entrando no modo de vídeo 3 e limpando a tela 
    movb $0x3, %al                              # modo 0x3 (80x25) - modo texto 
    movb $0x0, %ah                              # função para mudar vídeo
    int  $0x10                                  # chamada de bios relacionadas a vídeo


    cli                                         # bloqueando interrupções

    movw $0, %ax                                # explicitando que queremos estar no setor 0
    movw %ax, %ds                               # setor 0 


    # GDT a seguir (alerta de código macarrônico -> ir para código NASM para entender)
    #################################################################
    gdt: 
        # null_descriptor = enviando dois double words 0x0 (8 bytes) 
        movl $0x0, 0x800                       # 4 primeiros bytes do null_descriptor 
        movl $0x0, 0x804                       # 4 ultimos bytes do null_descriptor

        # data segment descriptor
        movl $0x0000ffff, 0x808                # enviando primeiros 16 bits de limit
        movl $0x00CF9200, 0x80C                # read/write

        # code segment descriptor
        movl $0x0000FFFF, 0x810                # enviando primeiros 16 bits de limit
        movl $0x00CF9800, 0x814                # execute/read
    ##################################################################

    # entrando no modo 32 bits
    lgdt gdt_reg                               # carregando a GDT 

    # alterando o bit menos significativo de um reg especial para 1 (32 )
    movl %cr0, %eax                            # não podemos fazer isso diretamente
    or $0x01, %al                              # definindo último bit como 1
    movl %eax, %cr0                            # enviando valor de volta (32 bits!!!!!)

    jmp $0x10, $start32                        # indo para o código 32 bits (far jump)


    # variável que guarda endereços da GDT 
    ##################################################################
    gdt_reg:
        .word 0x0017                           # tamanho da gdt
        .long 0x00000800                       # endereço inicial de gdt_start
    ##################################################################

    # variável que guarda o número do disco 
    BOOT_DISK: 
        .byte 0

    # trecho de código de tratamento de erro -> escreve um 'F' no terminal
    disk_error:
        movb $'F' , %al                         # caracter a ser printado ('F')
        movb $0x0e, %ah                         # função de imprimir caracter
        int  $0x10                              # chamada de vídeo da bios


# parte do código que será em 32 bits
.code32                                         # dizendo para o compilador que aqui é 32 bits
start32:
    # definindo seg. registers e stack
    movw $0x8, %ax                              # ax = novo DATA_SEG 
    movw %ax, %ds                               # ds = ax
    movw %ax, %ss                               # ss = ax
    movw %ax, %es                               # es = ax
    movw %ax, %fs                               # fs = ax 
    movw %ax, %gs                               # gs = ax 
    movl $0x90000, %ebp                         # nova %ebp -> stack (não atrapalhar) 
    movl %ebp, %esp                             # esp = ebp -> facilitar acesso aos elementos da stack

    # movw $0x741, 0xb8000                      # imprimir 'A' para testes
 
    jmp KERNEL_LOCATION                         # pulando para a posição do Kernel


# fim do programa - adicinando bytes 0x55 0xaa ao fim do programa
fim:
    . = _start + 510      
    .byte 0x55            
    .byte 0xaa            
