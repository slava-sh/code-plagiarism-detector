#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *Fin, *Fout;
  unsigned int n = 0, i, a = 0;

  if ((Fin = fopen("abcd.in", "r")) == NULL)
    return 1;
  if ((Fout = fopen("abcd.out", "w")) == NULL)
    return 1;
  fscanf(Fin, "%d", &n);
  for (i = 0; i < n; i++)
  {
    fscanf(Fin, "%d", &a);
    if ((((a / 100) * (a / 100) + (a % 100) * (a % 100)) % 7) == 1)
      fprintf(Fout, "YES\n");
    else
      fprintf(Fout, "NO\n");
  }
  fclose(Fin);
  fclose(Fout);
  return 0;
}