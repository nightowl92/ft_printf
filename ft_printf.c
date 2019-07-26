#include "printf.h"

int ft_printf(char *s, int num, ...)
{
    va_list valist;

    va_start(valist, num);
while (*s)
{
    write(1, s, 1);
s++;
}

va_end(valist);
    return (0);
}