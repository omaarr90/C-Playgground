// Fig. 14.7: fig14_07.c
// Using the goto statement
#include <stdio.h>

int main(void) {
  int count = 0; // initialize count
  int value;
  puts("Please enter a number: EOF to end");
start:
  printf("%s", "> ");
  if (fscanf(stdin, "%d", &value) == EOF)
    goto end;
  count += value;
  goto start;

end:
  fprintf(stdout, "\nSum is: %d", count);
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
