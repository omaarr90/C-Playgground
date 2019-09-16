#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 256;
    int c = 3;
    int *p = &b;

    printf("a: %p\n", &a);
    printf("b: %p\n", &b);
    printf("c: %p\n", &c);
    printf("p: %p\n", p);

    char *q = (char *)&b;

    printf("q: %p\n", q);

    printf("\n %d %d\n", *p, *q);
    q++;
    printf("q: %p\n", q);
    printf("\n %d %d\n", *p, *q);
}