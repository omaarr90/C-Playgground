#include <stdio.h>

int main(void)
{
    char a = 10;

    char *p = &a;

    char **q = &p;

    char ***r = &q;

    printf("%d\n", ***r);
}