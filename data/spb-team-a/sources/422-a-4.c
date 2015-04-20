#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *IN, *OUT;
  int i, k, d, a, b;

  if ((IN = fopen("abcd.in", "r")) == NULL)
  {
    return 0;
    exit(0);
  }
  if ((OUT = fopen("abcd.out", "w")) == NULL)
  {
    return 0;
    exit(0);
  }
  fscanf(IN, "%id", &k);
  for (i = 0; i < k; i++)
  {
    fscanf(IN, "%id", &d);
    a = d / 100;
    b = d % 100;
    if (((a * a + b * b) % 7) == 1)
      fprintf(OUT, "%s", "YES\n");
    else
      fprintf(OUT, "%s", "NO\n");
  }
  fclose(IN);
  fclose(OUT);
  return 0;
}























