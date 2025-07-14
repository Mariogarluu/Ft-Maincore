#include <stdlib.h>
#include <stdio.h>
char *ft_strdup(char *src)
{
    int i = 0;
    while (src[i])
        i++;
    char *dup = malloc(i + 1);
    if (!dup) return 0;
    for (int j = 0; j <= i; j++)
        dup[j] = src[j];
    return dup;
}
int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *dup = ft_strdup(av[1]);
        printf("%s\n", dup);
        free(dup);
    }
    return 0;
}
