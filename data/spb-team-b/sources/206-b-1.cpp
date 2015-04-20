#include <stdio.h>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

void main(void)
{
  std::vector<int> V;
  int n = 0;
  FILE *InF, *OutF;

  InF = fopen("chess.in", "rt");
  OutF = fopen("chess.out", "wt");

  fscanf(InF, "%d", &n);

  for (int i = 0; i < n; i++)
  {
    int a;
    fscanf(InF, "%d", &a);
    V.push_back(a);
  }
  
  int s = 0;
  for (int i = 0; i < n; i++, s++)
    if (V[i] < i + 1)
      break;
  
  fprintf(OutF, "%d\n", s);

  for (int i = 0; i < s; i++)
    fprintf(OutF, "%d %d\n", i + 1, i + 1);

  fclose(OutF);
  fclose(InF);
}