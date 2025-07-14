#include <unistd.h>

char upper(char c){return (c>='a'&&c<='z')?c-32:c;}
char lower(char c){return (c>='A'&&c<='Z')?c+32:c;}

int main(int ac, char **av){
    int i=1,j;
    if(ac>1)
    while(i<ac){
        j=0;
        while(av[i][j]){
            if(j==0||(av[i][j-1]==' '||av[i][j-1]=='\t'))
                write(1,&upper(av[i][j]),1);
            else
                write(1,&lower(av[i][j]),1);
            j++;
        }
        i++; if(i<ac)write(1,"\n",1);
    }
    write(1,"\n",1);
    return 0;
}
