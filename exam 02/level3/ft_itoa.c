#include <stdlib.h>
char *ft_itoa(int n) {
    int tmp = n, len = (n <= 0);
    while (tmp && ++len) tmp /= 10;
    char *s = malloc(len + 1);
    if (!s) return 0;
    s[len] = 0;
    if (n == 0) s[0] = '0';
    if (n < 0) s[0] = '-', n = -n;
    while (n && len--)
        s[len] = n % 10 + '0', n /= 10;
    return s;
}
#include <stdio.h>
int main(void){printf("%s\n", ft_itoa(-2147483648));return 0;}
