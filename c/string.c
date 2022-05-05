#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    #if 0
    char str[3] = "";
    str[0] = 'a';
    printf("str = %s\n", str);
    return 0;

    char str_a[30];
    char *str_b = str_a;
    printf("Please input string:\n");
    fgets(str_a, 29, stdin);
    printf("str_a = %s\n", str_a);
    scanf("%s", str_b);
    printf("str_b = %s\n", str_b);
    printf("str_a = %s\n", str_a);
    return 0;

    char *str_b = (char*)malloc(20);
    strncpy(str_b, "i love you", 10);
    printf("str_b = %s\n", str_b);
    free(str_b);
    return 0;
    #endif

    char *str_a;
    str_a = NULL;
    str_a = "I love you, a";
    printf("str_a = %p, %s\n", &str_a, str_a);
    str_a = "I love you, c";
    printf("str_a = %p, %s\n", &str_a, str_a);
    strncpy(str_a, "I love you, b", 10);
    printf("str_a = %p, %s\n", &str_a, str_a);
    return 0;
}
