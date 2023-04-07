#include "isr.h"
#include "gdt.h"
#include "idt.h"
#include "print.h"

void __attribute((cdecl)) isr0();
// void __attribute((cdecl)) ISR1();
// void __attribute((cdecl)) ISR2();
// void __attribute((cdecl)) ISR3();
// void __attribute((cdecl)) ISR4();
// void __attribute((cdecl)) ISR5();
// void __attribute((cdecl)) ISR6();
// void __attribute((cdecl)) ISR7();
// void __attribute((cdecl)) ISR8();
// void __attribute((cdecl)) ISR9();
// void __attribute((cdecl)) ISR10();
// void __attribute((cdecl)) ISR11();
// void __attribute((cdecl)) ISR12();
// void __attribute((cdecl)) ISR13();
// void __attribute((cdecl)) ISR14();
// void __attribute((cdecl)) ISR15();
// void __attribute((cdecl)) ISR16();
// void __attribute((cdecl)) ISR17();
// void __attribute((cdecl)) ISR18();
// void __attribute((cdecl)) ISR19();
// void __attribute((cdecl)) ISR20();
// void __attribute((cdecl)) ISR21();
// void __attribute((cdecl)) ISR22();
// void __attribute((cdecl)) ISR23();
// void __attribute((cdecl)) ISR24();
// void __attribute((cdecl)) ISR25();
// void __attribute((cdecl)) ISR26();
// void __attribute((cdecl)) ISR27();
// void __attribute((cdecl)) ISR28();
// void __attribute((cdecl)) ISR29();
// void __attribute((cdecl)) ISR30();
// void __attribute((cdecl)) ISR31();
// void __attribute((cdecl)) ISR32();
// void __attribute((cdecl)) ISR33();
// void __attribute((cdecl)) ISR34();
// void __attribute((cdecl)) ISR35();
// void __attribute((cdecl)) ISR36();
// void __attribute((cdecl)) ISR37();
// void __attribute((cdecl)) ISR38();
// void __attribute((cdecl)) ISR39();
// void __attribute((cdecl)) ISR40();
// void __attribute((cdecl)) ISR41();
// void __attribute((cdecl)) ISR42();
// void __attribute((cdecl)) ISR43();
// void __attribute((cdecl)) ISR44();
// void __attribute((cdecl)) ISR45();
// void __attribute((cdecl)) ISR46();
// void __attribute((cdecl)) ISR47();
// void __attribute((cdecl)) ISR48();
// void __attribute((cdecl)) ISR49();
// void __attribute((cdecl)) ISR50();
// void __attribute((cdecl)) ISR51();
// void __attribute((cdecl)) ISR52();
// void __attribute((cdecl)) ISR53();
// void __attribute((cdecl)) ISR54();
// void __attribute((cdecl)) ISR55();
// void __attribute((cdecl)) ISR56();
// void __attribute((cdecl)) ISR57();
// void __attribute((cdecl)) ISR58();
// void __attribute((cdecl)) ISR59();
// void __attribute((cdecl)) ISR60();
// void __attribute((cdecl)) ISR61();
// void __attribute((cdecl)) ISR62();
// void __attribute((cdecl)) ISR63();
// void __attribute((cdecl)) ISR64();
// void __attribute((cdecl)) ISR65();
// void __attribute((cdecl)) ISR66();
// void __attribute((cdecl)) ISR67();
// void __attribute((cdecl)) ISR68();
// void __attribute((cdecl)) ISR69();
// void __attribute((cdecl)) ISR70();
// void __attribute((cdecl)) ISR71();
// void __attribute((cdecl)) ISR72();
// void __attribute((cdecl)) ISR73();
// void __attribute((cdecl)) ISR74();
// void __attribute((cdecl)) ISR75();
// void __attribute((cdecl)) ISR76();
// void __attribute((cdecl)) ISR77();
// void __attribute((cdecl)) ISR78();
// void __attribute((cdecl)) ISR79();
// void __attribute((cdecl)) ISR80();
// void __attribute((cdecl)) ISR81();
// void __attribute((cdecl)) ISR82();
// void __attribute((cdecl)) ISR83();
// void __attribute((cdecl)) ISR84();
// void __attribute((cdecl)) ISR85();
// void __attribute((cdecl)) ISR86();
// void __attribute((cdecl)) ISR87();
// void __attribute((cdecl)) ISR88();
// void __attribute((cdecl)) ISR89();
// void __attribute((cdecl)) ISR90();
// void __attribute((cdecl)) ISR91();
// void __attribute((cdecl)) ISR92();
// void __attribute((cdecl)) ISR93();
// void __attribute((cdecl)) ISR94();
// void __attribute((cdecl)) ISR95();
// void __attribute((cdecl)) ISR96();
// void __attribute((cdecl)) ISR97();
// void __attribute((cdecl)) ISR98();
// void __attribute((cdecl)) ISR99();
// void __attribute((cdecl)) ISR100();
// void __attribute((cdecl)) ISR101();
// void __attribute((cdecl)) ISR102();
// void __attribute((cdecl)) ISR103();
// void __attribute((cdecl)) ISR104();
// void __attribute((cdecl)) ISR105();
// void __attribute((cdecl)) ISR106();
// void __attribute((cdecl)) ISR107();
// void __attribute((cdecl)) ISR108();
// void __attribute((cdecl)) ISR109();
// void __attribute((cdecl)) ISR110();
// void __attribute((cdecl)) ISR111();
// void __attribute((cdecl)) ISR112();
// void __attribute((cdecl)) ISR113();
// void __attribute((cdecl)) ISR114();
// void __attribute((cdecl)) ISR115();
// void __attribute((cdecl)) ISR116();
// void __attribute((cdecl)) ISR117();
// void __attribute((cdecl)) ISR118();
// void __attribute((cdecl)) ISR119();
// void __attribute((cdecl)) ISR120();
// void __attribute((cdecl)) ISR121();
// void __attribute((cdecl)) ISR122();
// void __attribute((cdecl)) ISR123();
// void __attribute((cdecl)) ISR124();
// void __attribute((cdecl)) ISR125();
// void __attribute((cdecl)) ISR126();
// void __attribute((cdecl)) ISR127();
// void __attribute((cdecl)) ISR128();
// void __attribute((cdecl)) ISR129();
// void __attribute((cdecl)) ISR130();
// void __attribute((cdecl)) ISR131();
// void __attribute((cdecl)) ISR132();
// void __attribute((cdecl)) ISR133();
// void __attribute((cdecl)) ISR134();
// void __attribute((cdecl)) ISR135();
// void __attribute((cdecl)) ISR136();
// void __attribute((cdecl)) ISR137();
// void __attribute((cdecl)) ISR138();
// void __attribute((cdecl)) ISR139();
// void __attribute((cdecl)) ISR140();
// void __attribute((cdecl)) ISR141();
// void __attribute((cdecl)) ISR142();
// void __attribute((cdecl)) ISR143();
// void __attribute((cdecl)) ISR144();
// void __attribute((cdecl)) ISR145();
// void __attribute((cdecl)) ISR146();
// void __attribute((cdecl)) ISR147();
// void __attribute((cdecl)) ISR148();
// void __attribute((cdecl)) ISR149();
// void __attribute((cdecl)) ISR150();
// void __attribute((cdecl)) ISR151();
// void __attribute((cdecl)) ISR152();
// void __attribute((cdecl)) ISR153();
// void __attribute((cdecl)) ISR154();
// void __attribute((cdecl)) ISR155();
// void __attribute((cdecl)) ISR156();
// void __attribute((cdecl)) ISR157();
// void __attribute((cdecl)) ISR158();
// void __attribute((cdecl)) ISR159();
// void __attribute((cdecl)) ISR160();
// void __attribute((cdecl)) ISR161();
// void __attribute((cdecl)) ISR162();
// void __attribute((cdecl)) ISR163();
// void __attribute((cdecl)) ISR164();
// void __attribute((cdecl)) ISR165();
// void __attribute((cdecl)) ISR166();
// void __attribute((cdecl)) ISR167();
// void __attribute((cdecl)) ISR168();
// void __attribute((cdecl)) ISR169();
// void __attribute((cdecl)) ISR170();
// void __attribute((cdecl)) ISR171();
// void __attribute((cdecl)) ISR172();
// void __attribute((cdecl)) ISR173();
// void __attribute((cdecl)) ISR174();
// void __attribute((cdecl)) ISR175();
// void __attribute((cdecl)) ISR176();
// void __attribute((cdecl)) ISR177();
// void __attribute((cdecl)) ISR178();
// void __attribute((cdecl)) ISR179();
// void __attribute((cdecl)) ISR180();
// void __attribute((cdecl)) ISR181();
// void __attribute((cdecl)) ISR182();
// void __attribute((cdecl)) ISR183();
// void __attribute((cdecl)) ISR184();
// void __attribute((cdecl)) ISR185();
// void __attribute((cdecl)) ISR186();
// void __attribute((cdecl)) ISR187();
// void __attribute((cdecl)) ISR188();
// void __attribute((cdecl)) ISR189();
// void __attribute((cdecl)) ISR190();
// void __attribute((cdecl)) ISR191();
// void __attribute((cdecl)) ISR192();
// void __attribute((cdecl)) ISR193();
// void __attribute((cdecl)) ISR194();
// void __attribute((cdecl)) ISR195();
// void __attribute((cdecl)) ISR196();
// void __attribute((cdecl)) ISR197();
// void __attribute((cdecl)) ISR198();
// void __attribute((cdecl)) ISR199();
// void __attribute((cdecl)) ISR200();
// void __attribute((cdecl)) ISR201();
// void __attribute((cdecl)) ISR202();
// void __attribute((cdecl)) ISR203();
// void __attribute((cdecl)) ISR204();
// void __attribute((cdecl)) ISR205();
// void __attribute((cdecl)) ISR206();
// void __attribute((cdecl)) ISR207();
// void __attribute((cdecl)) ISR208();
// void __attribute((cdecl)) ISR209();
// void __attribute((cdecl)) ISR210();
// void __attribute((cdecl)) ISR211();
// void __attribute((cdecl)) ISR212();
// void __attribute((cdecl)) ISR213();
// void __attribute((cdecl)) ISR214();
// void __attribute((cdecl)) ISR215();
// void __attribute((cdecl)) ISR216();
// void __attribute((cdecl)) ISR217();
// void __attribute((cdecl)) ISR218();
// void __attribute((cdecl)) ISR219();
// void __attribute((cdecl)) ISR220();
// void __attribute((cdecl)) ISR221();
// void __attribute((cdecl)) ISR222();
// void __attribute((cdecl)) ISR223();
// void __attribute((cdecl)) ISR224();
// void __attribute((cdecl)) ISR225();
// void __attribute((cdecl)) ISR226();
// void __attribute((cdecl)) ISR227();
// void __attribute((cdecl)) ISR228();
// void __attribute((cdecl)) ISR229();
// void __attribute((cdecl)) ISR230();
// void __attribute((cdecl)) ISR231();
// void __attribute((cdecl)) ISR232();
// void __attribute((cdecl)) ISR233();
// void __attribute((cdecl)) ISR234();
// void __attribute((cdecl)) ISR235();
// void __attribute((cdecl)) ISR236();
// void __attribute((cdecl)) ISR237();
// void __attribute((cdecl)) ISR238();
// void __attribute((cdecl)) ISR239();
// void __attribute((cdecl)) ISR240();
// void __attribute((cdecl)) ISR241();
// void __attribute((cdecl)) ISR242();
// void __attribute((cdecl)) ISR243();
// void __attribute((cdecl)) ISR244();
// void __attribute((cdecl)) ISR245();
// void __attribute((cdecl)) ISR246();
// void __attribute((cdecl)) ISR247();
// void __attribute((cdecl)) ISR248();
// void __attribute((cdecl)) ISR249();
// void __attribute((cdecl)) ISR250();
// void __attribute((cdecl)) ISR251();
// void __attribute((cdecl)) ISR252();
// void __attribute((cdecl)) ISR253();
// void __attribute((cdecl)) ISR254();
// void __attribute((cdecl)) ISR255();

void initializeISRGates() {
    setIdtGate(0, isr0, GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
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
    printStringAt("Erro", 8, 1);

    fim();
}

void initializeISR() {
    initializeISRGates();

    for (int i = 0; i < 256; i++)
        enableIdtGate(i);  // setting the flag

    disableIdtGate(0x80);

    printStringAt("ISRs carregadas com sucesso", 11, 1);
}

void isrRegisterHandler(int interruptNumber, ISRHandler handler)
{
    isrHandlers[interruptNumber] = handler;
    enableIdtGate(interruptNumber);
}
