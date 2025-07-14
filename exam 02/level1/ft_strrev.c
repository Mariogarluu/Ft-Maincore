#include <stdio.h>
char *ft_strrev(char *str)
{
    int i = 0, j;
    char tmp;
    while (str[i])
        i++;
    for (j = 0; j < --i; j++)
    {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
    }
    return str;
}
int main(int ac, char **av)
{
    if (ac == 2)
        printf("%s\n", ft_strrev(av[1]));
    return 0;
}
