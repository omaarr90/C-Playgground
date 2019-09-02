#include <stdio.h>

int main(void)
{
    int a = 8; 
    int b = 20;

    if (a > b) {
        a = a - b;
        b += a;
        a = b - a;
    } else {
        b = b - a;
        a += b;
        b = a - b;
    }
    printf("%d\n", a);
    printf("%d\n", b);
}