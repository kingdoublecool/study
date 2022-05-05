#include <stdio.h>

struct STD
{
    char    a[19];
    int     b;
};

int main()
{
    struct STD data;
    printf("sizeof data = %d\n", sizeof(data));
    printf("a: %p, b: %p\n", &data.a, &data.b);
    return 0;
}
