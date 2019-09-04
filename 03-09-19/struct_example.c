#include <stdio.h>

#define SIZE 3

struct employee
{
    char name[20];
    double salary;
};

void bonus(struct employee *s[], size_t count);
void bonus2(struct employee **e, size_t count);

int main(void)
{
    struct employee *e2[SIZE];

    struct employee abdullah = {"Abdullah", 4000};
    struct employee khalid = {"Khalid", 5000};
    struct employee jamal = {"Jamal", 6000};

    e2[0] = &abdullah;
    e2[1] = &khalid;
    e2[2] = &jamal;

    puts("Printing Array Befor");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%-20s %2.2lf\n", e2[i]->name, e2[i]->salary);
    }


    // puts("\nPrinting Array After");
    // for (size_t i = 0; i < SIZE; i++)
    // {
    //     printf("%-20s %2.2lf\n", e2[i]->name, e2[i]->salary);
    // }

    struct employee **p = &e2[1];

    bonus2(p, SIZE);

    puts("\nPrinting Array After");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%-20s %2.2lf\n", e2[i]->name, e2[i]->salary);
    }

    printf("\noutside %.2lf", (*p)->salary);
}

void bonus(struct employee *s[], size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        s[i]->salary *= 1.1;
    }
}

void bonus2(struct employee **e, size_t count)
{
    // for (size_t i = 0; i < count; i++)
    // {
    //     e[i]->salary *= 1.1;
    // }

    (*e)->salary *= 1.1;
    
}