#include <stdio.h>

int main(void)
{
  FILE *IN, *OUT;
  int i, k;;
  unsigned long b, a, d;

  if ((IN = fopen("abcd.in", "r")) == NULL)
    return 0;
  if ((OUT= fopen("abcd.out", "w")) == NULL)
    return 0;
  fscanf(IN, "%i", &k);
  for (i = 0; i < k; i++)
  {
    fscanf(IN, "%lld", &d);

    a = d / 100;
    b = d % 100;
    if ((a * a + b * b) % 7 == 1)
      fprintf(OUT, "%s", "YES\n");
    else
      fprintf(OUT, "%s", "NO\n");
  }
  fclose(IN);
  fclose(OUT);
  return 0;
}























