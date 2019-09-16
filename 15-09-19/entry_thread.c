#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *myThreadFun(void *vargp) {
  // Store the value argument passed to this thread
  int *myid = (int *)vargp;

  // Let us create a static variable to observe its changes
  static int s = 0;
  int i = 1;

  // Change static and global variables
  ++s;
  ++g;

  // Print the argument, static and global variables
  printf("Thread ID: %d, Static: %d, Global: %d, Local: %p\n", *myid, ++s, ++g, &i);
}

int main() {
  int i;
  pthread_t tid[3];
  // Let us create three threads
  for (i = 0; i < 3; i++) {
    pthread_create(&tid[i], NULL, myThreadFun, (void *)&tid[i]);
  }

  pthread_exit(NULL);
  return 0;
}