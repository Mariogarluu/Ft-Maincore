#include <stdio.h>

char *ft_strrrev(char *str)
{
    int len = 0, i = 0;
    char tmp;
    while (str[len])
        len++;
    len--;
    while (i < len)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    return str;
}

int main(int ac, char **av)
{
    if (ac == 2)
        printf("%s\n", ft_strrrev(av[1]));
    return 0;
}
