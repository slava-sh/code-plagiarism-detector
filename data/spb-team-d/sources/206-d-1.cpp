#include <stdio.h>
#include <string.h>
#include <vector>

void main(void)
{
  int V[1000];
  int n = 0, m = 0;
  FILE *InF, *OutF;

  InF = fopen("dunes.in", "rt");
  OutF = fopen("dunes.out", "wt");

  memset(V, 0, sizeof(V));
  fscanf(InF, "%d %d", &n, &m);
  
  for (int i = 0; i < n; i++)
  {
    int x, l, r;
    fscanf(InF, "%d %d %d", &l, &r, &x);
    r--, l--;
    for (int j = l; j <= r; j++)
    {
      if ((j - l) % 2 == 0)
        V[j] += x;
      else
        V[j] -= x;
    }
  }

  for (int j = 0; j < m; j++)
  {
    int n1;
    fscanf(InF, "%d", &n1);
    fprintf(OutF, "%d\n", V[n1 - 1]);
  }
  fclose(OutF);
  fclose(InF);
}