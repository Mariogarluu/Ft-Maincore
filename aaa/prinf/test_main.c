#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    size_t counter = 0;

    ft_printf("Null string: %s\n", NULL);
    ft_printf("Null pointer: %p\n", NULL);
    ft_printf("Integer: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hex: %x\n", 42);
    ft_printf("Mixed: %s %d %u %p\n", "Hola", -123, 456u, &counter);

    return 0;
}
