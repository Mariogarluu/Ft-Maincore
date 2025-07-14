#include <unistd.h>

char upper(char c){return (c>='a'&&c<='z')?c-32:c;}
char lower(char c){return (c>='A'&&c<='Z')?c+32:c;}

int main(int ac, char **av){
    int i=1,j, new_word;
    if(ac>1)
    while(i<ac){
        j=0; new_word=1;
        while(av[i][j]){
            if(new_word && (av[i][j]>='a'&&av[i][j]<='z'))
                av[i][j]-=32;
            else if(!new_word && (av[i][j]>='A'&&av[i][j]<='Z'))
                av[i][j]+=32;
            new_word=(av[i][j]==' '||av[i][j]=='\t'||av[i][j]==',')?1:0;
            write(1,&av[i][j],1);
            j++;
        }
        i++; if(i<ac)write(1,"\n",1);
    }
    write(1,"\n",1);
    return 0;
}
