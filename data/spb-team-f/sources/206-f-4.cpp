#include <stdio.h>
#include <math.h>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS


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

  __int64 mer = a * b;
  __int64 s = f(b, a);
  __int64 max = 1;
  __int64 sq = sqrt(mer);
  __int64 i = sq;
  if (sq > 500000000)
  {
    for (; i > 0; i--)
    {
      if (mer % i == 0 && s == f(mer / i, i))
        break;
    }
  }
  else
  {
    for (i = 1; i <= sq; i++)
    {
      if (mer % i == 0 && s == f(mer / i, i))
        break;
    }
  }
  fprintf(OutF, "%I64d %I64d", i, mer / i);
  fclose(OutF);
  fclose(InF);
}