#include <stdio.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

void ft_list_foreach(t_list *begin_list, void (*f)(void *)) {
    while (begin_list) {
        f(begin_list->data);
        begin_list = begin_list->next;
    }
}

void print_int(void *data) { printf("%d ", *(int *)data); }
int main(void) {
    int a = 1, b = 2, c = 3;
    t_list c1 = {&c, 0}, b1 = {&b, &c1}, a1 = {&a, &b1};
    ft_list_foreach(&a1, print_int);
    printf("\n");
    return 0;
}
