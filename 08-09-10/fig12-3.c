// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct listNode
{
    char data;                // each listNode contains a character
    struct listNode *nextPtr; // pointer to next node
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr;    // synonym for ListNode*

// prototypes
void insert(ListNodePtr *sPtr, char value);
char delete (ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{
    ListNodePtr startPtr = NULL; // initially there are no nodes
    char item;                   // char entered by user

    instructions(); // display the menu
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf("%u", &choice);

    // loop while user does not choose 3
    while (choice != 3)
    {

        switch (choice)
        {
        case 1:
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item); // insert item in list
            printList(startPtr);
            break;
        case 2: // delete an element
            // if list is not empty
            if (!isEmpty(startPtr))
            {
                printf("%s", "Enter character to be deleted: ");
                scanf("\n%c", &item);

                // if character is found, remove it
                if (delete (&startPtr, item))
                { // remove item
                    printf("%c deleted.\n", item);
                    printList(startPtr);
                }
                else
                {
                    printf("%c not found.\n\n", item);
                }
            }
            else
            {
                puts("List is empty.\n");
            }

            break;
        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        } // end switch

        printf("%s", "? ");
        scanf("%u", &choice);
    }

    puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
    puts("Enter your choice:\n"
         "   1 to insert an element into the list.\n"
         "   2 to delete an element from the list.\n"
         "   3 to end.");
}

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // create node

    if (newPtr == NULL)
    {
        printf("%c not inserted. No memory available.\n", value);
        return;
    }
    newPtr->data = value;   // place value in node
    newPtr->nextPtr = NULL; // node does not link to another node

    if (*sPtr == NULL)
    {
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
        return;
    }
    

    // ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *sPtr;

    // loop to find the correct location in the list
    while (currentPtr->nextPtr != NULL && value > currentPtr->nextPtr->data)
    {
        //  previousPtr = currentPtr; // walk to ...
        currentPtr = currentPtr->nextPtr; // ... next node
    }

    // insert new node at beginning of list
    if (currentPtr-> data > value)
    {
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
    }
    else
    { // insert new node between previousPtr and currentPtr
        // previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = newPtr;
    }
}

// delete a list element
char delete (ListNodePtr *sPtr, char value)
{
    // delete first node if a match is found
    if (value == (*sPtr)->data)
    {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr;    // de-thread the node
        free(tempPtr);               // free the de-threaded node
        return value;
    }
    else
    {
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->nextPtr != NULL && currentPtr->nextPtr->data != value)
        {
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // delete node at currentPtr
        if (currentPtr->nextPtr != NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

// print the list
void printList(ListNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        puts("The list is:");

        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
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