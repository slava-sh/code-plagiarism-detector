#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *Fin, *Fout;
  __int64 a[1000][3], res, n, m, i, j, b;

  if ((Fin = fopen("dunes.in", "r")) == NULL)
    return 1;
  if ((Fout = fopen("dunes.out", "w")) == NULL)
    return 1;
  fscanf(Fin, "%I64d%I64d", &n, &m);

  for (i = 0; i < n; i++)
    fscanf(Fin, "%I64d%I64d%I64d", &a[i][0], &a[i][1], &a[i][2]);

  for (i = 0; i < m; i++)
  {
    res = 0;
    fscanf(Fin, "%I64d", &b);
    for (j = 0; j < n; j++)
    {
      if (b >= a[j][0] && b <= a[j][1])
      {
        if (((b - a[j][0]) % 2) == 0)
          res += a[j][2];
        else
          res -= a[j][2];
      }
    }
    fprintf(Fout, "%I64d\n", res);
  }
  fclose(Fin);
  fclose(Fout);
  return 0;
}