// Fig. 6.18: fig06_18.c
// Linear search of an array.
#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

// function prototype
size_t linearSearch(const int array[], int key, size_t size); 

// function main begins program execution
int main(void)
{   
   int a[SIZE]; // create array a

   // create some data
   for (size_t x = 0; x < SIZE; ++x) { 
      a[x] = 2 * x;
   } 

   printf("Enter integer search key: ");
   int searchKey; // value to locate in array a
   scanf("%d", &searchKey);

   // attempt to locate searchKey in array a 
   size_t index = linearSearch(a, searchKey, SIZE);

   // display results
   if (index != -1) {
      printf("Found value at index %d\n", index);
   } 
   else {
      puts("Value not found");
   } 
}

// compare key to every element of array until the location is found 
// or until the end of array is reached; return index of element 
// if key is found or -1 if key is not found                               
size_t linearSearch(const int array[], int key, size_t size)      
{                                                                    
   // loop through array
   size_t index =  -1;                                         
   for (size_t n = 0; n < size; ++n) {                                    
                                                                     
      if (array[n] == key) {                                     
         index = n; // return location of key
         break;                      
      }                                                  
   }                                                    
                                                                     
   return index; // key not found                                    
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
