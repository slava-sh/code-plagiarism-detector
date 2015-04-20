#include <stdio.h>
#include <math.h>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#define MIN(A, B) (A) > (B) ? (B) : (A)
#define MAX(A, B) (A) < (B) ? (B) : (A)


__int64 f(__int64 a, __int64 b)
{
  __int64 c = 1;
  while (c != 0)
  {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

void main(void)
{
  __int64 a, b;
  FILE *InF, *OutF;

  InF = fopen("gcm.in", "rt");
  OutF = fopen("gcm.out", "wt");

  fscanf(InF, "%I64d %I64d", &a, &b);

  __int64 s = f(MAX(a, b), MIN(a, b));
  __int64 max = 1;
  __int64 sq = sqrt(a * b);
  for (__int64 i = sq; i > 1; i--)
  {
    if ((a * b) % i == 0)
    {
      max = i;
      if (s == f(i, (a * b) / i))
        break;
    }
  }

  fprintf(OutF, "%I64d %I64d", max, (a * b) / max);
  fclose(OutF);
  fclose(InF);
}