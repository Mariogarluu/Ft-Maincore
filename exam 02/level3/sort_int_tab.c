#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size) {
    unsigned int i, j;
    int tmp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    int t[] = {4,1,3,2};
    sort_int_tab(t, 4);
    for (int i = 0; i < 4; i++) printf("%d ", t[i]);
    printf("\n");
    return 0;
}
