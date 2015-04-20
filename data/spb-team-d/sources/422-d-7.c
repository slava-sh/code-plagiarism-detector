#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *IN, *OUT;
  __int64 i, q, l, r, x, n, m, a[1000] = {0}, j;  

  if ((IN = fopen("dunes.in", "r")) == NULL)
  {
    return 0;
    exit(0);
  }
  
  fscanf(IN, "%I64d%I64d", &n, &m);
  for (j = 0; j < n; j++)
  {
    fscanf(IN, "%I64d%I64d%I64d", &l, &r, &x);
    for (i = 0; i < r - l + 1; i++)
    {
      if (i % 2 == 1)
        a[i + l - 1] -= x;
      else
        a[i + l - 1] += x;
    }
  }
  if ((OUT = fopen("dunes.out", "w")) == NULL)
  {
    return 0;
    exit(0);
  }
  for (i = 0; i < m; i++)
  {
    fscanf(IN, "%I64d", &q);
    fprintf(OUT, "%I64d\n", a[q - 1]);
  }


  return 0;
}