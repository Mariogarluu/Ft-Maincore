#include <unistd.h>

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int main(int argc, char **argv)
{
    char buf[1000];
    if (argc == 2) {
        ft_strcpy(buf, argv[1]);
        int i = 0;
        while (buf[i])
            write(1, &buf[i++], 1);
    }
    write(1, "\n", 1);
    return 0;
}
