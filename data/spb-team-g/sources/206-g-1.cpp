#include <stdio.h>
#include <vector>
#include <algorithm>

bool Compare(__int64 a, __int64 b)
{
  return a > b;
}

int main(void)
{
  std::vector<__int64> V;
  int n = 0;
  FILE *InF, *OutF;

  InF = fopen("merlin.in", "rt");
  OutF = fopen("merlin.out", "wt");

  fscanf(InF, "%d", &n);
  __int64 sum = 0;

  for (int j = 0; j < n; j++)
  {
    __int64 a;
    fscanf(InF, "%I64d", &a);
    sum += a;
    V.push_back(a);
  }

  std::sort(V.begin(), V.end(), Compare);
  __int64 i = 0;
  for (; i < n; i++)
    if (((double)sum / (n - i) ) >= V[i])
      break;
    
  fprintf(OutF, "%I64d", i);

  fclose(OutF);
  fclose(InF);
  return 0;
}