#include <unistd.h>
int main(int ac, char **av)
{
    int i = 0, start = 0;
    if (ac == 2)
    {
        while (av[1][i])
            i++;
        i--;
        while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
            i--;
        start = i;
        while (start >= 0 && av[1][start] != ' ' && av[1][start] != '\t')
            start--;
        start++;
        while (av[1][start] && av[1][start] != ' ' && av[1][start] != '\t')
            write(1, &av[1][start++], 1);
    }
    write(1, "\n", 1);
    return 0;
}
