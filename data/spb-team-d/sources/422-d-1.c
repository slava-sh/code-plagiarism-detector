#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *IN, *OUT;
  long long i, q, l, r, x, n, m, a[10], j;

  for (i = 0; i < 10; i++)
    a[i] = 0;
  if ((IN = fopen("dunes.in", "r")) == NULL)
  {
    return 0;
    exit(0);
  }
  if ((OUT = fopen("dunes.out", "w")) == NULL)
  {
    return 0;
    exit(0);
  }
  fscanf(IN, "%lld%lld", &n, &m);
  for (j = 0; j < n; j++)
  {
    fscanf(IN, "%lld%lld%lld", &l, &r, &x);
    for (i = -1; i < r - l; i++)
    {
      if (i % 2 == 0)
        a[i + l] -= x;
      else
        a[i + l] += x;
    }
  }
  for (i = 0; i < m; i++)
  {
    fscanf(IN, "%lld", &q);
    fprintf(OUT, "%lld\n", a[q - 1]);
  }

  fclose(IN);
  fclose(OUT);
  return 0;
}