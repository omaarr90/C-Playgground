// Fig. 10.7: fig10_07.c
// Displaying an unsigned int in bits
#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value); // prototype

int main(void)
{
    unsigned int x; // variable to hold user input

    printf("%s", "Enter a nonnegative int: ");
    scanf("%u", &x);

    displayBits(x);
}

// display bits of an unsigned int value
void displayBits(unsigned int value)
{
    // define displayMask and left shift 31 bits
    unsigned int displayMask = 1 << (CHAR_BIT * (sizeof(unsigned int)) - 1);

    printf("%10u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= (CHAR_BIT * (sizeof(unsigned int))); ++c)
    {
        putchar(value & displayMask ? '1' : '0');
        displayMask >>= 1; // shift value left by 1

        if (c % 8 == 0)
        { // output space after 8 bits
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
