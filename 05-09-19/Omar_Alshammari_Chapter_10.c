#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value);
void unpackInteger(unsigned int a);
void reverseInteger(unsigned int a);

int main(void)
{
    unsigned int d;
    puts("Please enter a positive number: ");
    scanf("%d", &d);

    // unpackInteger(d);
    // puts("\n\n");
    reverseInteger(d);
}

void unpackInteger(unsigned int a)
{
    puts("The bits of the integer entered is: ");
    displayBits(a);
    unsigned int mask = 4278190080;
    for (size_t i = 3; i > 0; i--)
    {
        int result = a & mask;
        result >>= (8 * i);
        puts("First char bits:");
        displayBits(result);
        mask >>= 8;
    }
}

void reverseInteger(unsigned int a)
{
    puts("The bits of the integer entered before reverse is: ");
    displayBits(a);

    unsigned result = 0;
    unsigned int mask = 1 << (CHAR_BIT * (sizeof(unsigned int)) - 1);
    unsigned int mask1 = 1;

    size_t counter = 1; //
    unsigned int offset = CHAR_BIT * (sizeof(unsigned int));

    for (unsigned int c = (CHAR_BIT * (sizeof(unsigned int))) / 2; c >= 1; --c)
    {
        unsigned int temp = 0;
        temp = mask & a;
        unsigned int temp1 = 0;
        temp1 = mask1 & a;
        temp >>= offset - counter;
        temp1 <<= offset-- - counter++;
        result |= temp;
        result |= temp1;
        mask >>= 1;
        mask1 <<= 1; 
    }

    puts("The bits of the integer entered after reverse is: ");
    displayBits(result);
}

void displayBits(unsigned int value)
{
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 1 << (CHAR_BIT * (sizeof(unsigned int)) - 1);

    printf("%10u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= (CHAR_BIT * (sizeof(unsigned int))); ++c)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // shift value left by 1

        if (c % 8 == 0)
        { // output a space after 8 bits
            putchar(' ');
        }
    }

    putchar('\n');
}