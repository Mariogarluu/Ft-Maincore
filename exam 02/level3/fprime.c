#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av){
    int n, i=2, first=1;
    if(ac==2 && (n=atoi(av[1]))>0){
        while(n>1){
            if(n%i==0){
                if(!first)printf("*");
                printf("%d",i); n/=i; first=0;
            }else i++;
        }
    }
    printf("\n");
    return 0;
}
