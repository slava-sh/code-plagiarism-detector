#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *Fin, *Fout;
  __int64 l1, l2, r1, r2, n, m, i, p = 0, vp = 0, v = 0, a, cp = 0, cv = 0;

  if ((Fin = fopen("game.in", "r")) == NULL)
    return 1;
  if ((Fout = fopen("game.out", "w")) == NULL)
    return 1;
  fscanf(Fin, "%I64d%I64d", &n, &m);
  fscanf(Fin, "%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2);

  for (i = 0; i < n; i++)
  {
    fscanf(Fin, "%I64d", &a);
    if (l1 <= a && r1 >= a && (l2 > a || r2 < a))
      p++;
    if (l1 <= a && r1 >= a && l2 <= a && r2 >= a)
      vp++;
    if (l2 <= a && r2 >= a && (l1 > a || r1 < a))
      v++;
  }
  if (m <= vp)
    if (m % 2 == 0)
      fprintf(Fout, "Draw\n");
    else 
      fprintf(Fout, "Petya\n");
  else
  {
    if (vp % 2 != 0)
      cp++;
    m -= vp;
    if (vp % 2 == 0)
      if (v > p)
        cv++;
      else
        cp += (m % 2 == 1), cv += (m % 2 == 0);
      
    else
      if (p > v)
        cv++;
      else
        cv += (m % 2 == 1), cp += (m % 2 == 0);
    if (cp > cv)
      fprintf(Fout, "Petya\n");
    else if (cp == cv)
      fprintf(Fout, "Draw\n");
    else
      fprintf(Fout, "Vasya\n");
  }
  
  fclose(Fin);
  fclose(Fout);
  return 0;
}