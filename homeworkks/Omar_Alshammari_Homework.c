#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q1
void *my_malloc(size_t size) {
  void *result = malloc(size);
  if (result == NULL) {
    puts("Couldn't allocate memory");
    exit(EXIT_FAILURE);
  }

  return result;
}

// Q2
char *duplicate(const char *s) {
  char *dup = malloc(strlen(s) + 1);
  if (dup == NULL) {
    return NULL;
  }
  size_t counter = 0;
  while (*s != '\0') {
    dup[counter++] = *(s++);
  }
  dup[counter] = '\0';
  return dup;
}

// Q3
int *create_array(int n, int inital_value) {
  int *result = (int *)malloc(n * sizeof(int));
  if (result == NULL) {
    puts("Couldn't allocate memory");
    return NULL;
  }

  for (size_t i = 0; i < n; i++) {
    result[i] = inital_value;
  }
  return result;
}

// Q4
// struct rectangle rect = {{10, 25}, {20, 15}};
// p = &rect;

// Q5
// b, c and d are legal. a is not legal.

// q6
struct listNode {
  char data;                // each listNode contains a character
  struct listNode *nextPtr; // pointer to next node
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr;    // synonym for ListNode*

char delete (ListNodePtr *sPtr, char value) {
  // delete first node if a match is found
  if (value == (*sPtr)->data) {
    ListNodePtr tempPtr = *sPtr; // hold onto node being removed
    *sPtr = (*sPtr)->nextPtr;    // de-thread the node
    free(tempPtr);               // free the de-threaded node
    return value;
  } else {
    ListNodePtr currentPtr = (*sPtr)->nextPtr;

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->nextPtr != NULL &&
           currentPtr->nextPtr->data != value) {
      currentPtr = currentPtr->nextPtr; // ... next node
    }

    // delete node at currentPtr
    if (currentPtr->nextPtr != NULL) {
      ListNodePtr tempPtr = currentPtr;
      currentPtr = currentPtr->nextPtr;
      free(tempPtr);
      return value;
    }
  }

  return '\0';
}

// Q7
// we free p, then we try to go to next which will fail.
// for (p = first, p != NULL;) {
//  tmp = p->next
//  free(p);
//  p = tmp;
// }

// Q8 -- TODO

// Q9
// YES. The arrow operator is equivlent to (*x).a since (&x)-> a will be
// transformed to (&*x).a then the &* will cancel each other.

// Q10 -- TODO

// Q11
int find_occurences(ListNodePtr sPtr, char value) {
  int result = 0;
  for (ListNodePtr p = sPtr; p != NULL; p = p->nextPtr) {
    if (p->data == value) {
      result++;
    }
  }
  return result;
}

// Q12
ListNodePtr find_last(ListNodePtr sPtr, char value) {
  ListNodePtr result = NULL;
  for (ListNodePtr p = sPtr; p != NULL; p = p->nextPtr) {
    if (p->data == value) {
      result = p;
    }
  }
  return result;
}

// Q13
// inserting new node at the beginning will always fail.
//

// Q14 TODO

// Q15
// Program outputs 3. it shows what number multiplied by it self and then added
// to itself equals to 12.

// Q16
int sum(int (*f)(int), int start, int end) {
  int result = 0;
  while (start <= end) {
    result += (*f)(start++);
  }
  return result;
}

// Q17
// qsort(a[50], 50, sizeof(int), compare)

// Q18
int compare_parts(const void *p, const void *q) {
  return strcmp(((struct part *)q)->name, ((struct part *)p)->name);
}

// Q19
void exec_comman(const char *string) {
  for (int i = 0; i < 9; i++) {
    if (file_cmd[i].cmd_name == string) {
      (*file_cmd[i])();
    }
  }
}

int main(void) { return 0; }