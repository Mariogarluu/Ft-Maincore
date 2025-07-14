#include <stdio.h>

typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;

t_list *sort_list(t_list *lst, int (*cmp)(int, int)) {
    t_list *tmp;
    int swap;
    int sorted = 0;
    if (!lst)
        return lst;
    while (!sorted) {
        sorted = 1;
        tmp = lst;
        while (tmp->next) {
            if (!cmp(tmp->data, tmp->next->data)) {
                swap = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = swap;
                sorted = 0;
            }
            tmp = tmp->next;
        }
    }
    return lst;
}
int ascending(int a, int b) { return (a <= b); }

int main(void) {
    t_list c = {3, 0}, b = {2, &c}, a = {1, &b};
    t_list *sorted = sort_list(&a, ascending);
    while (sorted) {
        printf("%d ", sorted->data);
        sorted = sorted->next;
    }
    printf("\n");
    return 0;
}
