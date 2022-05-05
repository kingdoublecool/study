#include <stdio.h>
int main(void) 
{
    int a = 10;
    int * const p = &a;
    int *q = &a;
    printf("p=%d\n", *p);
    *q = 20;
    printf("a=%d\n", a);
    printf("p=%d\n", *p);
    a = 30;
    printf("a=%d\n", a);
    printf("p=%d\n", *p);
}
