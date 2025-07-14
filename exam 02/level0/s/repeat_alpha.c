#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0, j;
    if (argc == 2) {
        while (argv[1][i]) {
            j = 1;
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                j = argv[1][i] - 'A' + 1;
            else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                j = argv[1][i] - 'a' + 1;
            while (j--)
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
