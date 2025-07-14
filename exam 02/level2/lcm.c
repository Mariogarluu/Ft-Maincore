#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b){
    unsigned int l = (a > b) ? a : b;
    while (1){
        if (l % a == 0 && l % b == 0)
            return l;
        l++;
    }
}
int main(void){
    printf("%u\n", lcm(6, 8));
    return 0;
}
