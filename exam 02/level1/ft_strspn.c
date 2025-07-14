#include <stdio.h>

size_t ft_strspn(const char *s1, const char *s2)
{
    size_t i = 0, j;
    int found;
    while (s1[i])
    {
        found = 0;
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                found = 1;
                break;
            }
            j++;
        }
        if (!found)
            return i;
        i++;
    }
    return i;
}

int main(int ac, char **av)
{
    if (ac == 3)
        printf("%zu\n", ft_strspn(av[1], av[2]));
    return 0;
}
