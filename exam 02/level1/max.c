#include <stdio.h>
int max(int *tab, unsigned int len)
{
    int m = 0;
    if (len == 0) return 0;
    m = tab[0];
    for (unsigned int i = 1; i < len; i++)
        if (tab[i] > m)
            m = tab[i];
    return m;
}
int main(void)
{
    int arr[] = {7, -2, 19, 3, 8};
    printf("%d\n", max(arr, 5));
    return 0;
}
