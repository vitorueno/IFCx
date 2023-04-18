#include "isr.h"
#include "gdt.h"
#include "idt.h"
#include "print.h"

void __attribute((cdecl)) isr0();
void __attribute((cdecl)) isr1();
void __attribute((cdecl)) isr2();
void __attribute((cdecl)) isr3();
void __attribute((cdecl)) isr4();
void __attribute((cdecl)) isr5();
void __attribute((cdecl)) isr6();
void __attribute((cdecl)) isr7();
void __attribute((cdecl)) isr8();
void __attribute((cdecl)) isr9();
void __attribute((cdecl)) isr10();
void __attribute((cdecl)) isr11();
void __attribute((cdecl)) isr12();
void __attribute((cdecl)) isr13();
void __attribute((cdecl)) isr14();
void __attribute((cdecl)) isr15();
void __attribute((cdecl)) isr16();
void __attribute((cdecl)) isr17();
void __attribute((cdecl)) isr18();
void __attribute((cdecl)) isr19();
void __attribute((cdecl)) isr20();
void __attribute((cdecl)) isr21();
void __attribute((cdecl)) isr22();
void __attribute((cdecl)) isr23();
void __attribute((cdecl)) isr24();
void __attribute((cdecl)) isr25();
void __attribute((cdecl)) isr26();
void __attribute((cdecl)) isr27();
void __attribute((cdecl)) isr28();
void __attribute((cdecl)) isr29();
void __attribute((cdecl)) isr30();
void __attribute((cdecl)) isr31();


void initializeISRGates() {
    setIdtGate(0,  isr0, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(1,  isr1, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(2,  isr2, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(3,  isr3, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(4,  isr4, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(5,  isr5, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(6,  isr6, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(7,  isr7, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(8,  isr8, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(9,  isr9, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(10, isr10, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(11, isr11, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(12, isr12, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(13, isr13, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(14, isr14, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(15, isr15, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(16, isr16, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(17, isr17, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(18, isr18, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(19, isr19, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(20, isr20, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(21, isr21, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(22, isr22, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(23, isr23, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(24, isr24, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(25, isr25, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(26, isr26, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(27, isr27, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(28, isr28, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(29, isr29, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(30, isr30, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(33, isr31, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
}

ISRHandler isrHandlers[256];

static const char* const exceptionMessages[] = {
    "Divide by zero error",
    "Debug",
    "Non-maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Invalid TSS",
    "Segment Not Present",
    "Stack-Segment Fault",
    "General Protection Fault",
    "Page Fault",
    "",
    "x87 Floating-Point Exception",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating-Point Exception",
    "Virtualization Exception",
    "Control Protection Exception ",
    "",
    "",
    "",
    "",
    "",
    "",
    "Hypervisor Injection Exception",
    "VMM Communication Exception",
    "Security Exception",
    ""
};


extern void fim();

void __attribute__((cdecl)) isrHandler(Registers *regs) {
    if (regs->interrupt <=32) {
        // mostrar erro 
        printStringAt("Erro numero: ", 1, 1);
        printNumAt(regs->interrupt,1, 1+strlen("Erro numero: "));
        printStringAt("\"", 1, 17);
        printStringAt(exceptionMessages[regs->interrupt],1,18);
        printStringAt("\"", 1, 18+strlen(exceptionMessages[regs->interrupt]));

        // mostrar regs 
        printStringAt("eax: ", 2, 1);
        printNumAt(regs->eax, 2, 1 + strlen("eax: "));

        printStringAt("ebx: ", 3, 1);
        printNumAt(regs->ebx, 3, 1 + strlen("ebx: "));

        printStringAt("ecx: ", 4, 1);
        printNumAt(regs->ecx, 4, 1 + strlen("ecx: "));

        printStringAt("edx: ", 5, 1);
        printNumAt(regs->edx, 5, 1 + strlen("edx: "));

        printStringAt("edi: ", 6, 1);
        printNumAt(regs->edi, 6, 1 + strlen("edi: "));

        printStringAt("esi: ", 7, 1);
        printNumAt(regs->esi, 7, 1 + strlen("esi: "));

        printStringAt("ebp: ", 8, 1);
        printNumAt(regs->ebp, 8, 1 + strlen("ebp: "));

        printStringAt("esp: ", 9, 1);
        printNumAt(regs->esp, 9, 1 + strlen("ebp: "));

        printStringAt("ss: ", 10, 1);
        printNumAt(regs->ss, 10, 1 + strlen("ss: "));

        printStringAt("ds: ", 11, 1);
        printNumAt(regs->ds, 11, 1 + strlen("ds: "));

        printStringAt("cs: ", 12, 1);
        printNumAt(regs->cs, 12, 1 + strlen("cs: "));

        printStringAt("eflags: ", 13, 1);
        printNumAt(regs->eflags, 13, 1 + strlen("eflags: "));

        printStringAt("eip: ", 14, 1);
        printNumAt(regs->eip, 14, 1 + strlen("eip: "));

        fim();
    } else {
        printStringAt("interrupcao numero: ", 1, 1);
        printNumAt(regs->interrupt, 1, 1+strlen("interrupcao numero: "));

    }
}

void initializeISR() {
    initializeISRGates();

    for (int i = 0; i < 256; i++)
        enableIdtGate(i);  // setting the flag

    disableIdtGate(0x80);

    printStringAt("ISRs carregadas", 24, 1);
}

void isrRegisterHandler(int interruptNumber, ISRHandler handler)
{
    isrHandlers[interruptNumber] = handler;
    enableIdtGate(interruptNumber);
}
