#include <stdio.h>
#include <vector>

int main(void)
{
  std::vector<int> V;
  __int64 n, m;
  __int64 l1, l2, r1, r2, p = 0, per = 0, v = 0, i, VA, PE;
  __int64 L, R;
  FILE *InF, *OutF;

  InF = fopen("game.in", "rt");
  OutF = fopen("game.out", "wt");

  fscanf(InF, "%I64d %I64d %I64d %I64d %I64d %I64d", &n, &m, &l1, &r1, &l2, &r2);
  if (l1 <= l2)
    L = l2;
  else
    L = l1;
  if (r1 <= r2)
    R = r1;
  else
    R = r2;
  while ((fscanf(InF, "%I64d", &i) != EOF))
    if ((L <= i && i <= R))
      per++;
    else if (l1 <= i && i <= r1)
      p++;
    else if (l2 <= i && i <= r2)
      v++;
    VA = per / 2;
    PE = per - VA;
    int Ans = 100;
    if (m <= per)
      if (m % 2 == 0)
        Ans = 0;
      else
        Ans = 1;
    if (m >= per + v + p)
      if (p + PE > v + VA)
        Ans = 1;
      else if (p + PE < v + VA)
        Ans = -1;
    __int64 r = m - per;
    if (per % 2)
    {
      if (v > (r - r / 2))
        VA += r - r / 2;
      else
        VA += v;
      if (p > r / 2)
        PE += r / 2;
      else
        PE += p;
    }
    else
    {
      if (p > (r -  r / 2))
        PE += r - r / 2;
      else
        PE += p;
      if (v > r / 2)
        VA += r / 2;
      else
        VA += v;
    }
    if (Ans == 100)
      if (PE > VA)
        Ans = 1;
      else if (PE < VA)
        Ans = -1;
      else
        Ans = 0;
      if (Ans == 1)
        fprintf(OutF, "Petya");
      else if (Ans == -1)
        fprintf(OutF, "Vasya");
      else
        fprintf(OutF, "Draw");

  fclose(OutF);
  fclose(InF);

  return 0;
}