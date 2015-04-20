#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *Fin, *Fout;
  unsigned long a[200000], n, h, i, j, flag1 = 0, flag;
  __int64  res = 19999900000, res1 = 0;

  if ((Fin = fopen("seq.in", "r")) == NULL)
    return 1;
  if ((Fout = fopen("seq.out", "w")) == NULL)
    return 1;
  fscanf(Fin, "%lud", &n);
  fscanf(Fin, "%lud", &h);

  for (i = 0; i < 200000; i++)
    a[i] = 0;

  for (i = 0; i < n; i++)
    fscanf(Fin, "%lud", &a[i]);

  

  for (i = 0; i + h - 1 < n; i++)
  {
    flag = 1;
    res1 = 0;
    j = 0;
    while (j < h && flag == 1)
    {
      if (a[i + j] > j + 1)
        flag = 0;
      else
        res1 += j + 1 - a[i + j];
      j++;
    }
    if (res1 < res && flag != 0)
      res = res1;
  }
  if (i == h)
    res = -1;
  fprintf(Fout, "%I64d", res);
  fclose(Fin);
  fclose(Fout);
  return 0;
}