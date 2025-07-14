#include <unistd.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base){
    int i=0, sign=1, r=0;
    if(*str=='-'){sign=-1;str++;}
    while(str[i]){
        int d=0;
        if(str[i]>='0'&&str[i]<='9')d=str[i]-'0';
        else if(str[i]>='A'&&str[i]<='F')d=str[i]-'A'+10;
        else if(str[i]>='a'&&str[i]<='f')d=str[i]-'a'+10;
        else break;
        if(d>=str_base)break;
        r=r*str_base+d;
        i++;
    }
    return sign*r;
}


int main(int ac, char **av){
    if(ac==3)printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
    return 0;
}
