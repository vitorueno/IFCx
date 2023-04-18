.global loadIDT 
loadIDT: 
    pushl %ebp
    movl %esp, %ebp 

    movl 8(%ebp), %eax
    lidt (%eax)            # loads idt

    movl %ebp, %esp 
    popl %ebp 
    ret 
