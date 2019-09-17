#include <pthread.h>
#include <stdio.h>

void *print_primes(int a);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value> \n");
    /*exit(1);*/
    return -1;
  }
  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "Argument %d must be non-negative\n", atoi(argv[1]));
    /*exit(1);*/
    return -1;
  }

  pthread_t tid;
  pthread_attr_t attr;

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, print_primes, atoi(argv[1]));
  pthread_join(tid, NULL);
}

void *print_primes(int a) {
  for (size_t i = 1; i <= a; i++) {
    int is_prime = 1;
    for (size_t j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d, ", i);
    }
  }
  puts("");
  pthread_exit(0);
}