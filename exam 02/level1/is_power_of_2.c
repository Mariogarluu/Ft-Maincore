#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return ((n & (n - 1)) == 0);
}

int main(void)
{
    printf("%d\n", is_power_of_2(4));   // 1
    printf("%d\n", is_power_of_2(5));   // 0
    printf("%d\n", is_power_of_2(16));  // 1
    printf("%d\n", is_power_of_2(0));   // 0
    return 0;
}
