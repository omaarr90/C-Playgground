/*
Q01: D
Q02: C
Q03: A
Q04: E
Q05: A
Q06: B
Q07: B
Q08: C
Q09: D
Q10: A
*/

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 200

void instructions(void);
int stringToInteger(char *s);
void conactinateString(char *s1, const char *s2);
void copyString(char *s1, const char *s2);
int stringLength(const char *s1);
int compareString(const char *s1, const char *s2);

int main(void) {
  char *string1 = malloc(STRING_MAX * sizeof(char));
  if (string1 == NULL) {
    puts("No memory available");
    return 0;
  }

  char *string2 = malloc(STRING_MAX * sizeof(char));
  if (string2 == NULL) {
    puts("No memory available");
    return 0;
  }

  instructions(); // display the menu
  printf("%s", "? ");
  unsigned int choice; // user's choice
  scanf("%u", &choice);

  // loop while user does not choose 3
  while (choice != 6) {
    memset(string1, '\0', STRING_MAX * sizeof(char));
    switch (choice) {
    case 1: {
      printf("%s", "Enter a string: ");
      scanf("\n%s", string1);
      int result = stringToInteger(string1);
      printf("The converted number is: %d\n", result);
    } break;
    case 2: {
      printf("%s", "Enter first string: ");
      scanf("\n%s", string1);
      printf("%s", "Enter second string: ");
      scanf("\n%s", string2);
      conactinateString(string1, string2);
      printf("string after combining is: %s\n", string1);
    } break;
    case 3: {
      printf("%s", "Enter first string: ");
      scanf("\n%s", string1);
      printf("%s", "Enter second string: ");
      scanf("\n%s", string2);
      copyString(string1, string2);
      printf("string after copying is: %s\n", string1);
    } break;
    case 4: {
      printf("%s", "Enter a string: ");
      scanf("\n%s", string1);
      long result = stringLength(string1);
      printf("The length is: %ld\n", result);
    } break;
    case 5: {
      printf("%s", "Enter first string: ");
      scanf("\n%s", string1);
      printf("%s", "Enter second string: ");
      scanf("\n%s", string2);
      if (compareString(string1, string2) == 0) {
        printf("%s\n", "The two strings are the same");
      } else {
        printf("%s\n", "The two strings are different");
      }
    } break;
    case 6:
      break;
    default: {
      puts("Invalid choice.\n");
      instructions();
    } break;
    }
    printf("%s", "? ");
    scanf("%u", &choice);
  }
}

void instructions(void) {
  puts("Enter your choice:\n"
       "   1 to convert to Integer.\n"
       "   2 Concatenate two strings.\n"
       "   3 Copy string to another string.\n"
       "   4 Calculate string length.\n"
       "   5 Compare two strings.\n"
       "   6 End Program.");
}

int stringToInteger(char *s) {
  if (*s < '0' || *s > '9')
    return 0;

  int result = *(s++) - '0';
  while (*s != '\0') {
    switch (*s) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
      int num = *(s++) - '0';
      result = result * 10 + num;
    } break;

    default:
      return result;
      break;
    }
  }
  return result;
}

void conactinateString(char *s1, const char *s2) {
  while (*s1 != '\0') {
    s1++;
  }

  while (*s2 != '\0') {
    *(s1++) = *(s2++);
  }
}

void copyString(char *s1, const char *s2) {
  while (*s2 != '\0') {
    *(s1++) = *(s2++);
  }
}

int stringLength(const char *s1) {
  int result = 0;
  while (*(s1++) != '\0') {
    result++;
  }

  return result;
}

int compareString(const char *s1, const char *s2) {
  while (*s1 != '\0') {
    if (*(s1++) == *(s2++)) {
      continue;
    } else {
      return *s1 - *s2;
    }
  }

  return *s1 - *s2;
}