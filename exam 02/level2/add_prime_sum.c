#include <unistd.h>

int ft_atoi(char *s){int r=0;while(*s)r=r*10+*s++-'0';return r;}

int is_prime(int n){if(n<2)return 0;for(int i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}

void putnbr(int n){if(n>9)putnbr(n/10);char c=n%10+'0';write(1,&c,1);}

int main(int ac, char **av){
    int n=0,s=0;
    if(ac==2){n=ft_atoi(av[1]);for(int i=2;i<=n;i++)if(is_prime(i))s+=i;}
    putnbr(s);write(1,"\n",1);return 0;
}
