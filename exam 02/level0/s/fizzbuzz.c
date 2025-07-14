#include <unistd.h>

void putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int main(void)
{
    int i = 1;
    while (i <= 100) {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            putnbr(i);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}
