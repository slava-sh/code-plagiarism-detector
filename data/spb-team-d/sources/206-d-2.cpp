#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

void main(void)
{
  __int64 V[1000];
  __int64 n = 0, m = 0;
  FILE *InF, *OutF;

  InF = fopen("dunes.in", "rt");
  OutF = fopen("dunes.out", "wt");

  fscanf(InF, "%I64d %I64d", &n, &m);
  memset(V, 0, sizeof(V));

  __int64 x[1000], l[1000], r[1000];
  for (int i = 0; i < n; i++)
  {
    fscanf(InF, "%I64d %I64d %I64d", l + i, r + i, x + i);
  }

  for (int j = 0; j < m; j++)
  {
    __int64 n1, sun = 0;
    fscanf(InF, "%I64d", &n1);
    for (int i = 0; i < n; i++)
      if (n1 >= l[i] && n1 <= r[i])
      {
        if ((n1 - l[i]) % 2 == 0)
          sun += x[i];
        else
          sun -= x[i];
      }
    fprintf(OutF, "%I64d\n", sun);
  }
  fclose(OutF);
  fclose(InF);
}