#include <stdio.h>

typedef struct s_list {
    int data;
    struct s_list *next;
} t_list;

int add_list(t_list *lst) {
    int sum = 0;
    while (lst) {
        sum += lst->data;
        lst = lst->next;
    }
    return sum;
}


int main(void) {
    t_list c = {3, 0}, b = {2, &c}, a = {1, &b};
    printf("%d\n", add_list(&a));
    return 0;
}
