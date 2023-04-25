.global disableInterrupts
disableInterrupts:
    cli 
    ret

.global enableInterrupts
enableInterrupts:
    sti
    ret 
