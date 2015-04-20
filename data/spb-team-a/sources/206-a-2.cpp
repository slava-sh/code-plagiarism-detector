#include <vector>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int f(int a)
{
  
  int cd = a % 100, ab = a / 100;

  if ((cd * cd + ab * ab) % 7 == 1)
    return 1;
  return 0;
}

int main(void)
{
  int t;
  FILE *InF, *OutF;

  InF = fopen("abcd.in", "rt");
  OutF = fopen("abcd.out", "wt");

  fscanf(InF, "%d", &t);
  for (int i = 0; i < t; i++)
  {
    int a;
    fscanf(InF, "%d", &a);
    if (f(a))
      fprintf(OutF, "YES\n");
    else
      fprintf(OutF, "NO\n");
  }
  fclose(OutF);
  fclose(InF);
  return 0;
}