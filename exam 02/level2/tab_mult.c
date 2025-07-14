#include <unistd.h>

int ft_atoi(char *s){int r=0;while(*s)r=r*10+*s++-'0';return r;}
void putnbr(int n){if(n>9)putnbr(n/10);char c=n%10+'0';write(1,&c,1);}
int main(int ac, char **av){
    int n;
    if(ac==2){
        n=ft_atoi(av[1]);
        for(int i=1;i<=9;i++){
            putnbr(i);write(1," x ",3);putnbr(n);write(1," = ",3);putnbr(i*n);write(1,"\n",1);
        }
    }
    else write(1,"\n",1);
    return 0;
}
