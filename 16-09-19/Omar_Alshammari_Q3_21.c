#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __APPLE__
#include <sys/wait.h>
#else
#include <wait.h>
#endif

void childe_process(int number);
void parent_process(int fpid);

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }
  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "Argument %d must be non-negative\n", atoi(argv[1]));
    /*exit(1);*/
    return -1;
  }

  pid_t fpid; /* Forked process id */
  /* Create a new process */
  fpid = fork();

  /* Both the parent and new processes continue running here */
  if (fpid < 0) {
    printf("Error Creating The New Process\n");
    exit(EXIT_FAILURE);
  } else if (fpid == 0) {
    childe_process(atoi(argv[1]));
  } else {
    parent_process(fpid);
  }
}

void childe_process(int number) {
  printf("%d, ", number);
  while (number != 1) {
    if ((number & 1) == 1) { // Odd
      number = 3 * number + 1;
    } else { // Even
      number /= 2;
    }
    printf("%d, ", number);
  }
  puts("");
}

void parent_process(int fpid) {
  int status; /* Forked process status */

  if (wait(&status) == fpid)
    printf("Forked Process Status %d\n", WEXITSTATUS(status));
  else
    printf("Error Waiting For The Forked Process\n");
}