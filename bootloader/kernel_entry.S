# fazendo o link do boot.asm com o código assembly
# será compilado em um object file elf para linkar 

.text     

.globl _start 

_start: 
    call main                   # chamando a função main do código C           

    #int $0x0
    #mov $10, %eax 
    #mov $0, %ebx
    #div %ebx 

.global fim 
fim: 
    hlt
    jmp fim


# funções 

.global teste
teste: 
    pushl %ebp
    movl %esp, %ebp 

    movl 8(%ebp), %eax  # first parameter

    movb $0x0E, %ah             
    movw %ax, 0xb800C           

    movl %ebp, %esp 
    popl %ebp 
    ret 


.global loadIDT 
loadIDT: 
    pushl %ebp
    movl %esp, %ebp 

    movl 8(%ebp), %eax
    lidt (%eax)            # loads idt

    movl %ebp, %esp 
    popl %ebp 
    ret 

.extern isrHandler

.global isr0
isr0: 
    push $0 
    push $0 
    jmp isr_common

isr_common:
    pusha 

    xor %eax, %eax 
    mov %ds, %ax 
    push %eax       # push ds 

    mov $0x10, %ax 
    mov %ax, %ds 
    mov %ax, %es 
    mov %ax, %fs 
    mov %ax, %gs 

    push %esp 
    call isrHandler
    add $4, %esp 

    pop %eax 
    mov %ax, %ds 
    mov %ax, %es 
    mov %ax, %fs 
    mov %ax, %gs 

    popa 
    add $8, %esp
    iret 
