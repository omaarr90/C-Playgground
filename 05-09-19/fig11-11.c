// Fig. 11.11: fig11_11.c
// Writing data randomly to a random-access file
#include <stdio.h>

// clientData structure definition
struct clientData
{
   unsigned int acctNum; // account number
   char lastName[15];    // account last name
   char firstName[10];   // account first name
   double balance;       // account balance
};

int main(void)
{
   FILE *cfPtr; // accounts.dat file pointer

   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts11.dat", "rb+")) == NULL)
   {
      puts("File could not be opened.");
   }
   else
   {
      // create clientData with default information
      struct clientData client_arr[100] = {{0, "", "", 0.0}};
      size_t counter = 0;
      int acc_num = 0;
      // require user to specify account number
      printf("%s", "Enter account number"
                   " (1 to 100, 0 to end input): ");
      scanf("%d", &acc_num);

      // user enters information, which is copied into file
      while (acc_num != 0 && counter < 100)
      {
         printf("%s %d\n", "Writing Account Number", acc_num);
         // user enters last name, first name and balance
         struct clientData client = {0, "", "", 0.0};
         client.acctNum = acc_num;
         printf("%s", "Enter lastname, firstname, balance: ");
         // set record lastName, firstName and balance value
         fscanf(stdin, "%14s%9s%lf", client.lastName,
                client.firstName, &client.balance);

         // write user-specified information in file
         client_arr[acc_num - 1] = client;
         // enable user to input another account number
         printf("%s", "Enter account number: ");
         scanf("%d", &acc_num);
      }
      // fseek(cfPtr, 0, SEEK_SET);
      fwrite(client_arr, sizeof(struct clientData), sizeof client_arr, cfPtr);
      fclose(cfPtr); // fclose closes the file
   }
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
