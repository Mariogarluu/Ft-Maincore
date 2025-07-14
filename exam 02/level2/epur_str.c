#include <unistd.h>

int main(int ac, char **av){
    int i=0, w=0;
    if(ac==2){
        while(av[1][i]){
            while(av[1][i]==' '||av[1][i]=='\t')i++;
            if(av[1][i]&&w++)write(1," ",1);
            while(av[1][i]&&av[1][i]!=' '&&av[1][i]!='\t')
                write(1,&av[1][i++],1);
        }
    }
    write(1,"\n",1);
    return 0;
}
