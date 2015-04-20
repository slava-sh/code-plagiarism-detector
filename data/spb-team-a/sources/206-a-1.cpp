#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
  __int64 a = 1 , b = 1, n;
 
  scanf("%I64d", &n);
  while (b != 0)
  {
    printf("%I64d\n", (a + n) / 2);
    scanf("%I64d", &b);
    fflush(stdout);

    if (b == 1)
      a = (a + n) / 2 + 1;
    else
      n = (a + n) / 2 - 1;
  }

	return 0;
}