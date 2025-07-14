#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end){
    int len = (start <= end ? end - start + 1 : start - end + 1);
    int *arr = malloc(sizeof(int)*len);
    int i = 0;
    while (i < len)
        arr[i++] = (start <= end ? start++ : start--);
    return arr;
}

int main(void){
    int *r = ft_range(3, 7);
    for (int i = 0; i < 5; i++)
        printf("%d ", r[i]);
    free(r);
    printf("\n");
    return 0;
}
