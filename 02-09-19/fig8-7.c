// Fig. 8.7: fig08_07.c
// Using function strtol
#include <stdio.h>
#include <stdlib.h>

int main(void)
{                  
//    const char *string = "ffff"; // initialize string pointer  
//    char *remainderPtr; // create char pointer
   
//    long x = strtol(string, &remainderPtr, 16);

//    printf("%s\"%s\"\n%s%ld\n%s\"%s\"\n%s%ld\n",
//       "The original string is ", string,
//       "The converted value is ", x,
//       "The remainder of the original string is ", 
//       remainderPtr,
//       "The converted value plus 567 is ", x + 567);

      puts("\n\n--------------------------- 8.8 ---------------------\n");

    const char *string = "-1234567abc"; // initialize string pointer
    char *remainderPtr; // create char pointer

    unsigned long int x = strtoul(string, &remainderPtr, 10);

    printf("%s\"%s\"\n%s%lu\n%s\"%s\"\n%s%lu\n",
        "The original string is ", string,
        "The converted value is ", x,
        "The remainder of the original string is ", 
        remainderPtr, 
        "The converted value minus 567 is ", x - 567);

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
