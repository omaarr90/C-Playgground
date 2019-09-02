#include <stdio.h>

int main()
{
    int a = 5;
    int b = 10;

    printf("%p\n", &a);
    printf("%p\n", &b);

    int * p = &a;
    printf("%p\n", p);

    char *q = (char *)p;

    printf("%p ", q);
    printf("[%d]\n", *q);
    printf("%p ", q+1);
    printf("[%d]\n", *(q+1));
    printf("%p ", q+2);
    printf("[%d]\n", *(q+2));
    printf("%p ", q+3);
    printf("[%d]\n", *(q+3));

    printf("%d\n", *(q+4));
    puts("\n\n");
    printf("%d\n", *(q-1));
    printf("%d\n", *(q-2));
    printf("%d\n", *(q-3));
    printf("%d\n", *(q-4));
}