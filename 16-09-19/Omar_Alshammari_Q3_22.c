#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef __APPLE__
#include <sys/wait.h>
#else
#include <wait.h>
#endif

#define SHARED_MEMORY_NAME "Q3_22_SHARED_MEMORY"

void childe_process(int number, int shm_fd);
void parent_process(int fpid, int shm_fd);

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

  int shm_fd = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, 4096);

  pid_t fpid; /* Forked process id */
  /* Create a new process */
  fpid = fork();

  /* Both the parent and new processes continue running here */
  if (fpid < 0) {
    printf("Error Creating The New Process\n");
    exit(EXIT_FAILURE);
  } else if (fpid == 0) {
    childe_process(atoi(argv[1]), shm_fd);
  } else {
    parent_process(fpid, shm_fd);
  }
}

void childe_process(int number, int shm_fd) {
  void *ptr = mmap(0, 4069, PROT_WRITE, MAP_SHARED, shm_fd, 0);
  int count = sprintf(ptr, "%d, ", number);
  ptr += count;
  while (number != 1) {
    if ((number & 1) == 1) { // Odd
      number = 3 * number + 1;
    } else { // Even
      number /= 2;
    }
    count = sprintf(ptr, "%d, ", number);
    ptr+= count;
  }
}

void parent_process(int fpid, int shm_fd) {
  int status; /* Forked process status */

  if (wait(&status) == fpid)
    printf("Forked Process Status %d\n", WEXITSTATUS(status));
  else
    printf("Error Waiting For The Forked Process\n");

  printf("Parent Process Resuming\n");

  void *ptr = mmap(0, 4069, PROT_READ, MAP_SHARED, shm_fd, 0);

  printf("%s", (char *)ptr);
  puts("");
  shm_unlink(SHARED_MEMORY_NAME);
}