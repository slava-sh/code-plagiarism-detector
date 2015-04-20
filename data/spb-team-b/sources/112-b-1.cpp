#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *Fin, *Fout;
  unsigned int n = 0, i, a[1000], sum = 0;

  if ((Fin = fopen("chess.in", "r")) == NULL)
    return 1;
  if ((Fout = fopen("chess.out", "w")) == NULL)
    return 1;
  fscanf(Fin, "%d", &n);

  for (i = 0; i < n; i++)
  {
    fscanf(Fin, "%d", &a[i]);
    sum += a[i] > i;
  }

  fprintf(Fout, "%d\n", sum);
  
  for (i = 0; i < n; i++)
  {
    if (a[i] > i)
      fprintf(Fout, "%d %d\n", i + 1, i + 1);
  }

  fclose(Fin);
  fclose(Fout);
  return 0;
}