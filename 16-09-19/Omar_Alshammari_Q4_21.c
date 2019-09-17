#include <pthread.h>
#include <stdio.h>

double average;
int minmum;
int maximum;

int a_size;

void *average_f(int a[]);
void *minmum_f(int a[]);
void *maximum_f(int a[]);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: a.out <integer value> ...\n");
    /*exit(1);*/
    return -1;
  }
  pthread_t tid[3];
  pthread_attr_t attr[3];
  void *(*stat_func[3])(int[]) = {average_f, minmum_f, maximum_f};

  a_size = argc - 1;
  int a[a_size];
  for (size_t i = 0; i < a_size; i++) {
    a[i] = atoi(argv[i + 1]);
  }

  for (size_t i = 0; i < 3; i++) {
    pthread_attr_init(&attr[i]);
    pthread_create(&tid[i], &attr[i], *stat_func[i], a);
  }
  for (size_t i = 0; i < 3; i++)
  {
    pthread_join(tid[i], NULL);
  }

  printf("Average: %.2f\n", average);
  printf("Mimum: %d\n", minmum);
  printf("Maximum: %d\n", maximum);
}

void *average_f(int a[]) {
  int sum = 0;
  for (size_t i = 0; i < a_size; i++) {
    sum += a[i];
  }
  average = 1.0 * sum / a_size;
  pthread_exit(0);
}
void *minmum_f(int a[]) {
  minmum = a[0];
  for (size_t i = 1; i < a_size; i++) {
    minmum = (a[i] < minmum) ? a[i] : minmum;
  }
  pthread_exit(0);
}
void *maximum_f(int a[]) {
  maximum = a[0];
  for (size_t i = 1; i < a_size; i++) {
    maximum = (a[i] > maximum) ? a[i] : maximum;
  }
  pthread_exit(0);
}
