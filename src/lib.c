#include "lib.h"

void *memcpy(void *dest, void *src, size_t count)
{
    char *char_src = (char *)src;
    char *char_dest = (char *)dest;

    for (int i = 0; i < count; i++)
    {
        char_dest[i] = char_src[i];
    }

    return dest;
}

void *memset(void *dest, char val, size_t count)
{
    char *char_dest = (char *)dest;

    while (count != 0)
    {
        *char_dest++ = val;
        count--;
    }

    return dest;
}

uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count)
{
    uint16_t *char_dest = (uint16_t *)dest;

    while (count != 0)
    {
        *char_dest++ = val;
        count--;
    }

    return dest;
}

size_t strlen(const char *str)
{
    size_t length;
    for (length = 0; *str != '\0'; str++)
    {
        length++;
    }

    return length;
}

size_t numlen(const uint64_t num)
{
    size_t length = 0;
    uint64_t temp = num;
    
    if (temp == 0) {
        return 1;
    }
    
    while (temp != 0) {
        temp /= 10;
        length++;
    }
    
    return length;
}

