#include<stdio.h>

int main(void)
{
    int a[] = {1,2,3,4,5};
    int *p = &a[1];
    int *q = a;
    printf("*p = %p, *q = %p\n", p, q);
    printf("p[3] = %d\n", p[3]);
    printf("q[3] = %d\n", q[3]);
    printf("*(q+3) = %d, *(a+3) = %d\n", *(q+3), *(a+3));
    printf("sizeof(a) = %ld, sizeof(q) = %ld\n", sizeof(a), sizeof(q));
    return 0;
}

