#include <stdio.h>

int main(int ac, char **av){
    if(ac==3){
        int a=atoi(av[1]),b=atoi(av[2]),r=1;
        for(int i=1;(i<=a&&i<=b);i++)
            if(a%i==0&&b%i==0)r=i;
        printf("%d\n",r);
    }
    else printf("\n");
    return 0;
}
