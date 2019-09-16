/* Figure 14.6  Program to Be Launched from the Program in Figure 14.5 (child.c)
 */
/* Read a newline delimited string from the standard */
/* input and print the string to the standard output */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  char text[64]; /* Message buffer */

  /* Display the child process ID */
  printf(" Child Process ID %d\n", getpid());

  /* Read a newline delimited string from the standard input */
  if (fgets(text, sizeof(text) - 1, stdin) == NULL)
    printf("Error Reading Standard Input\n");

  /* Display the message read from standard input */
  printf(" Child Process Reading '%s'\n", text);
  printf(" Child Process Stopping\n");

  /* Return 1 to parent to indicate successful completion */
  return (1);
}