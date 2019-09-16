#include <stdalign.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void stop_now(int i) {
  if (i > 0)
    exit(i);
}

void test() {
  int a = 10;
  int b = 20;
  printf("Added = %d\n", add(a, b));
}

struct sse_t {
  alignas(16) float sse_data[4];
};

struct data {
  char x;
  alignas(64) char cacheline[128];
};

int main(void) {
  printf("%zu\n", alignof(char));
  printf("%zu\n", alignof(max_align_t));
  printf("%zu\n", alignof(float[10]));
  printf("%zu\n", alignof(struct {
           char c;
           int n;
         }));

  alignas(4) int i = 1;
  alignas(4) int j = 2;
  alignas(4) char a = 'a';
  alignas(4) char b = 'b';
  alignas(4) char c = 'c';
  alignas(4) char d = 'd';
  int k = 3;
  printf("i = %p\n", &i);
  printf("j = %p\n", &j);
  printf("a = %p\n", &a);
  printf("b = %p\n", &b);
  printf("c = %p\n", &c);
  printf("d = %p\n", &d);
  printf("k = %p\n", &k);

  printf("sizeof(data) = %zu (1byte + 127 padding + 128byte array)\n",
         sizeof(struct data));
  printf("alignment(data) = %zu \n", alignof(struct data));

  printf("sizeof(sse_t) = %zu\n", sizeof(struct sse_t));
  printf("alignment(sse_t) = %zu\n", alignof(struct sse_t));

  alignas(2048) struct data dd;
  printf("dd = %zu\n",
         sizeof(dd));
  printf("dd = %zu (1byte + 127 padding + 128byte array)\n",
         alignof(dd));

  puts("Preparing to stop...");
  stop_now(2);
  puts("This code is never executed.");
}

int add(int x, int y) { return x + y; }
