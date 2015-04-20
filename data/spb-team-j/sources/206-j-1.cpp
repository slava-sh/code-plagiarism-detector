#include <stdio.h>
#include <vector>
#include <algorithm>

int main(void)
{
  std::vector<int> V;
  int n = 0, h = 0;
  FILE *InF, *OutF;

  InF = fopen("chess.in", "rt");
  OutF = fopen("chess.out", "wt");

  fscanf(InF, "%d %d", &n, &h);
  V.resize(n);
  for (int i = 0; i < n; i++)
  {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < n - h + 1; j++)
      if (i - j > a)
        V[j] += i - j - a;
  }
  std::sort(V.begin(), V.end());
  int j = 0, p = 0;
  for (int i = 0; i < n - h + 1; i++)
  {
    for (j = i; j < i + h; j++)
      if (V[j + 1] == V[j] + 1)
        break;
    if (j == i + h)
      p = 1;
  }
  if ( p != 1)
    fprintf(OutF, "%d", V[0]);
  else
    fprintf(OutF, "-1");
  fclose(OutF);
  fclose(InF);
  return 0;
}