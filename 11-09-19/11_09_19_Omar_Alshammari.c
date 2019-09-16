#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Question 1
#define CUBE(X) ((X) * (X) * (X))
#define REMAINDER(X) ((X) % 4)
#define PRODUCT_LESS_HUNDERED(X, Y) (((X) * (Y)) < 100 ? 1 : 0)

// Question 2
#define NELEMS(X) (sizeof((X)) / sizeof((X)[0]))

// Question 3
// a: 4
// b: 1
// c:
#define DOUBLE(X) ((X)*2)

// Question 4
// a: 5 * AVG(2, 2)
// b: AREA(5+2, 3)
#define AVG(X, Y) (((X) + (Y)) / 2)
#define AREA(X, Y) ((X) * (Y))

// Question 5
// a: B
// b: 1

// Question 6
#define DISP(F, X) printf(#F "(%g) = %g\n", X, F(X))
#define DISP2(F, X, Y) printf(#F "(%g, %g) = %g\n", X, Y, F(X, Y))

// Question 7
#define GENERIC_MAX(type)                                                      \
  type type##_max(type x, type y) { return x > y ? x : y }
// expands to   double double_max(double x, double y) { return x > y ? x : y };
// this does not work with unsinged long because of the spaces
// we can make this macro work for unsing long if we can replace spaces with
// underscore

// Question 8
#define LINE_FILE "Line %d of %s\n", __LINE__, __FILE__

// Question 9

// Question 10
// Functions that has a return value and/or side effects.

// Question 11
#define ERROR(X, Y) (fprintf(stderr, X, Y))

// Question 12
// e and c will fails

// Question 13

// Question 14

// Question 15
#define FRENCH
void print_message() {
#if defined(ENGLISH)
  printf("Insert disk 1\n");
#elif defined(FRENCH)
  printf("insereze le disque 1\n");
#elif defined(SPANISH)
  printf("inserte el disco 1\n");
#endif
}

// Question 16
// expanded to   _PRAGMA("ident \"foo\"");

int main(void) {
  int a = 50;
  int b = 6;
  int c = PRODUCT_LESS_HUNDERED(a, b);
  int arr[5] = {1, 2, 3, 4, 5};
  printf("%d\n", NELEMS(arr));

  DISP(sqrt, 3.0);
  //   DISP2(sqrt, 3.0, 5);
  //   GENERIC_MAX(long);
  printf(LINE_FILE);

  ERROR("Out of range: %d\n", 10);

  print_message();
}