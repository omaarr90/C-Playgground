#include <stdio.h>

int main(void)
{
  int result = 0;
  int value;

  while (scanf("%d", &value) != EOF)
  {
    result += value;
  }
  printf("%d\n", result);
}