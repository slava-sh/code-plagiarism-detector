#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *IN, *OUT;
  long long i, q, l, r, x, n, m, a[1000] = {0}, j;  

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
    for (i = 0; i < r - l + 1; i++)
    {
      if (i % 2 == 1)
        a[i + l - 1] -= x;
      else
        a[i + l - 1] += x;
    }
  }
  for (i = 0; i < m; i++)
  {
    fscanf(IN, "%lld", &q);
    fprintf(OUT, "%lld\n", a[q - 1]);
  }

  return 0;
}