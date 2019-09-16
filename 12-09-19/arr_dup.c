#include <stdio.h>

void shift_array_left(int *a, int n) {
  printf("REMOVEING %d\n", a[0]);
  for (int i = 0; i < n - 1; i++) {
    a[i] = a[i + 1];
  }
  a[n - 1] = 0;
}

int removeAll(int *a, int n) {
  if (n < 2) {
    return n;
  }

  int count = 0;
  int all = n;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        shift_array_left(&a[j], n - j);
        count++;
        n--;
      }
    }
  }
  return all - count;
}

int main(void) {
  int a[] = {5, 4, 5, 7, 8, 9, 10, 8, 9, 11};
  //   int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int count = removeAll(a, 10);

  printf("count is: %d\n", count);

  for (size_t i = 0; i < count; i++) {
    printf("%d ", a[i]);
  }

  puts("");
}