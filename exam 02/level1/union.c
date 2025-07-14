#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int used[256] = {0}, i = 0, c;
        while (av[1][i])
        {
            c = (unsigned char)av[1][i];
            if (!used[c])
            {
                write(1, &av[1][i], 1);
                used[c] = 1;
            }
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            c = (unsigned char)av[2][i];
            if (!used[c])
            {
                write(1, &av[2][i], 1);
                used[c] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
