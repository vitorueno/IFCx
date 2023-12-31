#include "isr.h"
#include "gdt.h"
#include "idt.h"
#include "imprime.h"

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

void __attribute((cdecl)) isr32();
void __attribute((cdecl)) isr33();
void __attribute((cdecl)) isr34();
void __attribute((cdecl)) isr35();
void __attribute((cdecl)) isr36();
void __attribute((cdecl)) isr37();
void __attribute((cdecl)) isr38();
void __attribute((cdecl)) isr39();
void __attribute((cdecl)) isr40();
void __attribute((cdecl)) isr41();
void __attribute((cdecl)) isr42();
void __attribute((cdecl)) isr43();
void __attribute((cdecl)) isr44();
void __attribute((cdecl)) isr45();
void __attribute((cdecl)) isr46();
void __attribute((cdecl)) isr47();

void initializeISRGates()
{
    setIdtGate(0, isr0, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(1, isr1, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(2, isr2, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(3, isr3, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(4, isr4, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(5, isr5, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(6, isr6, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(7, isr7, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(8, isr8, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(9, isr9, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
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
    setIdtGate(31, isr31, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);

    setIdtGate(32, isr32, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(33, isr33, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(34, isr34, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(35, isr35, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(36, isr36, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(37, isr37, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(38, isr38, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(39, isr39, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(40, isr40, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(41, isr41, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(42, isr42, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(43, isr43, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(44, isr44, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(45, isr45, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(46, isr46, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    setIdtGate(47, isr47, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
}

ISRHandler isrHandlers[256];

static const char *const exceptionMessages[] = {
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
    ""};

extern void fim();

void __attribute__((cdecl)) isrHandler(Registers *regs)
{
    if (isrHandlers[regs->interrupt] != NULL)
    {
        isrHandlers[regs->interrupt](regs);
        return;
    }

    else if (regs->interrupt < 32)
    {
        cls();

        // mostrar erro
        puts("Erro numero: ");
        puts(intToAscii(regs->interrupt));
        puts(" \'");
        putchar(exceptionMessages[regs->interrupt]);
        puts("\'\n");

        // mostrar regs
        puts("eax: ");
        puts(intToAscii(regs->eax));

        puts("\nebx: ");
        puts(intToAscii(regs->ebx));

        puts("\necx: ");
        puts(intToAscii(regs->ecx));

        puts("\nedx: ");
        puts(intToAscii(regs->edx));

        puts("\nedi: ");
        puts(intToAscii(regs->edi));

        puts("\nesi: ");
        puts(intToAscii(regs->esi));

        puts("\nebp: ");
        puts(intToAscii(regs->ebp));

        puts("\nesp: ");
        puts(intToAscii(regs->esp));

        puts("\nss: ");
        puts(intToAscii(regs->ss));

        puts("\nds: ");
        puts(intToAscii(regs->ds));

        puts("\ncs: ");
        puts(intToAscii(regs->cs));

        puts("\neflags: ");
        puts(intToAscii(regs->eflags));

        puts("\neip: ");
        puts(intToAscii(regs->eip));
    }
    else
    {
        puts("\ninterrupcao numero: ");
        puts(intToAscii(regs->interrupt));
    }
    putc('\n');
    fim();
}

void initializeISR()
{
    initializeISRGates();

    for (int i = 0; i < 256; i++)
        enableIdtGate(i); // setting the flag

    disableIdtGate(0x80);

    puts("ISRs carregadas\n");
}

void isrRegisterHandler(int interruptNumber, ISRHandler handler)
{
    isrHandlers[interruptNumber] = handler;
    enableIdtGate(interruptNumber);
}
