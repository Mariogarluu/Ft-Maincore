#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point {
    int x;
    int y;
}               t_point;

void fill(char **tab, int x, int y, char to_fill, int max_x, int max_y) {
    if (x < 0 || y < 0 || x >= max_x || y >= max_y || tab[y][x] != to_fill)
        return;
    tab[y][x] = 'F';
    fill(tab, x + 1, y, to_fill, max_x, max_y);
    fill(tab, x - 1, y, to_fill, max_x, max_y);
    fill(tab, x, y + 1, to_fill, max_x, max_y);
    fill(tab, x, y - 1, to_fill, max_x, max_y);
}

void flood_fill(char **tab, t_point size, t_point begin) {
    fill(tab, begin.x, begin.y, tab[begin.y][begin.x], size.x, size.y);
}
