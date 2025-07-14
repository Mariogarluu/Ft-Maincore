#include <unistd.h>
int main(int ac, char **av)
{
    int i = 0, c;
    if (ac == 2)
        while ((c = av[1][i++]))
            if ((c >= 'a' && c <= 'z'))
                write(1, &"zyxwvutsrqponmlkjihgfedcba"[c - 'a'], 1);
            else if ((c >= 'A' && c <= 'Z'))
                write(1, &"ZYXWVUTSRQPONMLKJIHGFEDCBA"[c - 'A'], 1);
            else
                write(1, &c, 1);
    write(1, "\n", 1);
    return 0;
}
