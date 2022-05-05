#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int *p = malloc(sizeof*p);
    *p = 10;
    int a = 10;
    int *q = &a;
    int **m = &q;
    printf("p = %p, *p = %d, q = %p, *q = %d\n", p, *p, q, *q);
    free(p);
    printf("p = %p, *p = %d, q = %p, *q = %d\n", p, *p, q, *q);
    printf("m = %p, *m = %p, **m = %d\n", m, *m, **m);
    return 0;
}
