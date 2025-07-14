#include <stdio.h>
int ft_atoi(const char *s)
{
    int r = 0, sign = 1;
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
        if (*s++ == '-')
            sign = -1;
    while (*s >= '0' && *s <= '9')
        r = r * 10 + (*s++ - '0');
    return (sign * r);
}
int main(int ac, char **av)
{
    if (ac == 2)
        printf("%d\n", ft_atoi(av[1]));
    return 0;
}
