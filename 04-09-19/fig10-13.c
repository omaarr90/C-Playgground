// Fig. 10.13: fig10_13.c
// Using the bitwise shift operators
#include <stdio.h>

void displayBits(unsigned int value); // prototype

int main(void)
{
    int x = 2;
    printf("%d \n", x > 4 ? 10 : 20 > 15 ? x > 8888 ? 3333 : 999 : (x=777));

    unsigned int number1;
    // demonstrate bitwise left shift
    puts("\nThe result of left shifting");
    displayBits(number1);
    // puts("8 bit positions using the left shift operator << is");

    for (size_t i = 1; i <= 8; i++)
    {
        displayBits(number1 << i);
    }

    // demonstrate bitwise right shift
    puts("\nThe result of right shifting");
    number1 <<= 8;
    displayBits(number1);
    // puts("8 bit positions using the right shift operator >> is");

    for (size_t i = 1; i <= 8; i++)
    {
        displayBits(number1 >> i);
    }
}

// display bits of an unsigned int value
void displayBits(unsigned int value)
{
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;

    printf("%7u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= 32; ++c)
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

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
