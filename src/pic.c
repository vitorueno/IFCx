#include "pic.h"

#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_COMMAND_PORT PIC1
#define PIC1_DATA_PORT (PIC1 + 1)
#define PIC2_COMMAND_PORT PIC2
#define PIC2_DATA_PORT (PIC2 + 2)

enum
{
    WILL_HAVE_ICW4 = 0x1,
    IS_SINGLE = 0x2,
    INTERVAL4 = 0x4,
    IS_LEVEL_TRIGGERED = 0x8,
    INITIALIZE_PIC = 0x10
} ICW1;

enum
{
    POSITION_OF_PIC2 = 0b100,   // IRQ2 pin
    PIC2_CASCADE_IDENTITY = 0x2 // third pin (starts counting from 0)
} ICW3;

enum
{
    MODE_8086 = 0x1,
    AUTO_EOI = 0x2,
    BUFFERED_MODE_MASTER = 0x4,
    IS_BUFFERED_MODE = 0x8,
    SFNM = 0x10
} ICW4;

void configurePIC(uint8_t offsetPIC1, uint8_t offsetPIC2)
{
    // ICW1 => cascade mode + edge triggered mode + tell ICW4 is present
    outportb(PIC1_COMMAND_PORT, WILL_HAVE_ICW4 | INITIALIZE_PIC);
    iowait();
    outportb(PIC2_COMMAND_PORT, WILL_HAVE_ICW4 | INITIALIZE_PIC);
    iowait();

    // ICW2 => setting the offsets
    outportb(PIC1_DATA_PORT, offsetPIC1);
    iowait();
    outportb(PIC2_DATA_PORT, offsetPIC2);
    iowait();

    // ICW3 => setting master and slave to work together
    outportb(PIC1_DATA_PORT, POSITION_OF_PIC2);
    iowait();
    outportb(PIC2_DATA_PORT, PIC2_CASCADE_IDENTITY);
    iowait();

    // ICW4 => 8086 platform without auto EOI nor SFNM/BUFFERED MODE
    outportb(PIC1_DATA_PORT, MODE_8086);
    iowait();
    outportb(PIC2_DATA_PORT, MODE_8086);
    iowait();

    // clear data ports
    outportb(PIC1_DATA_PORT, 0);
    iowait();
    outportb(PIC2_DATA_PORT, 0);
    iowait();
}

// OCW1
void maskIRQ(int irq)
{
    uint8_t port;

    if (irq < 8)
        port = PIC1_DATA_PORT;
    else
    {
        port = PIC2_DATA_PORT;
        irq -= 8;
    }

    uint8_t mask = inportb(port);
    outportb(port, mask | (1 << irq));
}

// OCW1
void unmaskIRQ(int irq)
{
    uint8_t port;

    if (irq < 8)
        port = PIC1_DATA_PORT;
    else
    {
        port = PIC2_DATA_PORT;
        irq -= 8;
    }

    uint8_t mask = inportb(port);
    outportb(port, mask & ~(1 << irq));
}

void disablePIC()
{
    outportb(PIC1_DATA_PORT, 0xff);
    iowait();
    outportb(PIC2_DATA_PORT, 0xff);
    iowait();
}

enum
{
    EOI = 0x20,
    IRR = 0x0a,
    ISR = 0x0b
} PIC_CMD;

void sendEOI(int irq)
{
    if (irq >= 8)
        outportb(PIC2_COMMAND_PORT, EOI);
    outportb(PIC1_COMMAND_PORT, EOI);
}

uint16_t getIRR()
{
    outportb(PIC1_COMMAND_PORT, IRR);
    outportb(PIC2_COMMAND_PORT, IRR);
    return inportb(PIC2_COMMAND_PORT) | inportb(PIC1_COMMAND_PORT) << 8;
}

uint16_t getISR()
{
    outportb(PIC1_COMMAND_PORT, ISR);
    outportb(PIC2_COMMAND_PORT, ISR);
    return inportb(PIC2_COMMAND_PORT) | inportb(PIC1_COMMAND_PORT) << 8;
}