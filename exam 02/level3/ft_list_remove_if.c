#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

int cmp(void *a, void *b) { return (*(int *)a == *(int *)b); }
void free_data(void *data) { (void)data; }
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)) {
    t_list *tmp;
    while (*begin_list) {
        if (cmp((*begin_list)->data, data_ref)) {
            tmp = *begin_list;
            *begin_list = (*begin_list)->next;
            free_fct(tmp->data);
            free(tmp);
        }
        else
            begin_list = &(*begin_list)->next;
    }
}

int main(void) {
    int a = 1, b = 2, c = 3, ref = 2;
    t_list c1 = {&c, 0}, b1 = {&b, &c1}, a1 = {&a, &b1}, *list = &a1;
    ft_list_remove_if(&list, &ref, cmp, free_data);
    while (list) { printf("%d ", *(int *)list->data); list = list->next; }
    printf("\n");
    return 0;
}
