#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int main(int argc, char **argv)
{
    int len = 0;
    if (argc == 2) {
        len = ft_strlen(argv[1]);
        if (len >= 10)
            write(1, &"0123456789"[len / 10], 1);
        write(1, &"0123456789"[len % 10], 1);
    }
    write(1, "\n", 1);
    return 0;
}
