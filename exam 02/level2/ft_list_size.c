#include <stdio.h>

typedef struct s_list{void *data;struct s_list *next;} t_list;

int ft_list_size(t_list *begin_list){
    int i=0;while(begin_list){i++;begin_list=begin_list->next;}return i;
}

int main(void){
    t_list n3={0,0},n2={0,&n3},n1={0,&n2};
    printf("%d\n", ft_list_size(&n1));
    return 0;
}
