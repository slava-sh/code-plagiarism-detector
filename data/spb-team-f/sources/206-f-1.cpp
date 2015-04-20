#include <stdio.h>
#include <math.h>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

void main(void)
{
  __int64 a, b;
  FILE *InF, *OutF;

  InF = fopen("gcm.in", "rt");
  OutF = fopen("gcm.out", "wt");

  fscanf(InF, "%I64d %I64d", &a, &b);

  __int64 max = 1;
  __int64 sq = sqrt(a * b);
  for (__int64 i = sq; i >= 1; i--)
  {
    if ((a * b) % i == 0)
    {
      max = i;
      break;
    }
  }

  fprintf(OutF, "%I64d %I64d", max, (a * b) / max);
  fclose(OutF);
  fclose(InF);
}