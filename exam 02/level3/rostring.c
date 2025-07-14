#include <unistd.h>

int main(int ac, char **av) {
    int i = 0, j, first = 0, start = 0, end = 0, w = 0;
    if (ac > 1) {
        while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
            i++;
        start = i;
        while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        end = i;
        while (av[1][i]) {
            while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
                i++;
            if (av[1][i]) {
                if (w++) write(1, " ", 1);
                j = i;
                while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t')
                    write(1, &av[1][j++], 1);
                i = j;
            }
        }
        if (w) write(1, " ", 1);
        write(1, &av[1][start], end - start);
    }
    write(1, "\n", 1);
    return 0;
}
