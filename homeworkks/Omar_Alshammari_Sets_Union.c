#include <stdio.h>

#define MAX_SIZE 10

size_t set_union(const int a[], size_t a_size, const int b[], size_t b_size, int c[]);
void print_array(const int const a[], size_t count);

int main (void)
{
    int a[MAX_SIZE];// = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    puts("Enter first set of of numbers");
    scanf("%d %d %d %d %d %d %d %d %d %d", 
    &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);

    int b[MAX_SIZE];// = {10, 6, 3, 4, 11, 12, 13, 14, 15, 22};
    puts("Enter second set of of numbers");
    scanf("%d %d %d %d %d %d %d %d %d %d", 
    &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9]);

    int c[MAX_SIZE];
    size_t count = set_union(a, MAX_SIZE, b, MAX_SIZE, c);

    puts("\nThe similar elements are:");
    print_array(c, count);
}

size_t set_union(const int a[], size_t a_size, const int b[], size_t b_size, int c[])
{
    size_t count = 0;
    for (int i = 0; i < a_size; ++i)
    {
        for (int j = 0; j < b_size; ++j)
        {
            if (a[i] == b[j]) {
                c[count++] = a[i];
                break;// no need to continue
            }
        }
    }
    return count;
}

void print_array(const int const a[], size_t count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%d ", a[i]);
    }
    puts("");
}