.text     

.globl _start 

_start: 
    call main                           

    # some random values that we'll be able to see in exceptions
    # movl $123456, %eax
    # movl $123456, %eax
    # movl $2345678, %ebx
    # movl $777, %ecx
    # movl $2442, %edx
    # movl $3, %edi
    # movl $5, %esi

    # testing exceptions (works from 0 to 31)
    # int $0
    # int $1
    
    # division by zero 
    #mov $10, %eax 
    #mov $0, %ebx
    #div %ebx 

.global fim 
fim: 
    hlt
    jmp fim

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

# functions
.include "io.S"

.include "idt.S"

.include "isr.S"

