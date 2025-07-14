#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str){
    int w = 0, i = 0, j, k;
    while(str[i]) if ((str[i++]!=' '&&str[i-1]==' ')|| (i==1 && str[0]!=' ')) w++;
    char **tab = malloc((w+1)*sizeof(char*));
    i = 0; k = 0;
    while(str[i]){
        while(str[i] == ' ') i++;
        if(str[i]){
            j = i;
            while(str[j] && str[j] != ' ') j++;
            tab[k] = malloc(j - i + 1);
            for (int l = 0; i < j; l++, i++) tab[k][l] = str[i];
            tab[k++][i-j] = 0;
        }
    }
    tab[k] = 0;
    return tab;
}



int main(void){
    char **tab = ft_split("Hola 42 Malaga");
    for(int i=0;tab[i];i++) printf("%s",tab[i]);
    return 0;
}
