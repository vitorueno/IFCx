#include "lib.h"


extern void *memcpy(void *dest, void *src, size_t count) {
    // convertendo para ponteiro de char
    char *char_src = (char *)src;
    char *char_dest = (char *)dest;

    for(int i=0; i < count; i++) {
        char_dest[i] = char_src[i];
    } 

    return dest;
}


extern void *memset(void *dest, char val, size_t count) {
    // convertendo para pointeiro para char
    char *char_dest = (char *)dest;

    while (count != 0) { 
        *char_dest++ = val;
        count--;
    }

    return dest;
}


extern uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count) {
    uint16_t *char_dest = (uint16_t *)dest;

    while(count != 0) { 
        *char_dest++ = val;
        count--;
    }

    return dest;
}


extern size_t strlen(const char *str) {
    size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}


extern uint8_t inportb (uint16_t _port) {
    uint8_t rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}


extern void outportb (uint16_t _port, uint8_t _data) {
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

