/**
 * This program forks a separate process using the fork()/exec() system calls.
 *
 * Figure 3.09
 *
 * @author Silberschatz, Galvin, and Gagne
 * Operating System Concepts  - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid;

  /* fork a child process */
  pid = fork();

  if (pid < 0) { /* error occurred */
    fprintf(stderr, "Fork Failed\n");
    return 1;
  } else if (pid == 0) { /* child process */
    printf("I am the child %d\n", pid);
    execlp("/bin/ls", "ls", NULL);
  } else { /* parent process */
    /* parent will wait for the child to complete */
    printf("I am the parent %d\n", pid);
    wait(NULL);

    printf("Child Complete\n");
  }

  return 0;
}
