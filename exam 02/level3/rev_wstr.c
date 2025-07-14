#include <unistd.h>

int main(int ac, char **av){
    int i, end, start, first=1;
    if(ac==2){
        i=0;
        while(av[1][i])i++;
        end=i-1;
        while(end>=0){
            while(end>=0&&(av[1][end]==' '||av[1][end]=='\t')) end--;
            if(end<0) break;
            start=end;
            while(start>=0&&av[1][start]!=' '&&av[1][start]!='\t') start--;
            if(!first)write(1," ",1);
            write(1,av[1]+start+1,end-start);
            first=0;
            end=start-1;
        }
    }
    write(1,"\n",1);
    return 0;
}
