#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *IN, *OUT;

  __int64 m, n, winstolb1 = 0, winstolb2 = 0, winstolb = 0, i, stolb[100000] = { 0 }, petya = 0, vasya = 0, s[2][2], h, mold = -1;
  char flag = 1;

  if ((IN = fopen("game.in", "r")) == NULL)
  {
    return 0;
    exit(0);
  }

  fscanf(IN, "%I64d%I64d", &n, &m);

  fscanf(IN, "%I64d%I64d", &s[0][0], &s[0][1]);
  fscanf(IN, "%I64d%I64d", &s[1][0], &s[1][1]);

  for (i = 0; i < n; i++)
  {
    fscanf(IN, "%I64d", &h);
    if ((h >= s[0][0]) && (h <= s[0][1]))
      winstolb1++;
    if ((h >= s[1][0]) && (h <= s[1][1]))
      winstolb2++;
    if ((h >= s[0][0]) && (h <= s[0][1]) && (h >= s[1][0]) && (h <= s[1][1]))
      winstolb++;
    stolb[i] = h;
  }

  while (((winstolb1 >= 0) || (winstolb2 >= 0)) && (m > 0))
  {
    for (i = 0; i < n; i++)
    {
      if (flag)
      {
        if ((stolb[i] <= s[0][1]) && (stolb[i] >= s[0][0]) && (stolb[i] <= s[1][1]) && (stolb[i] >= s[1][0]))
        {
          petya++;
          winstolb1--;
          winstolb--;
          m--;
          stolb[i] = -10;
          flag = 1 - flag;
          i = 0;
        }
        else
          if (winstolb <= 0)
          {
          if ((stolb[i] <= s[0][1]) && (stolb[i] >= s[0][0]))
          {
            petya++;
            winstolb--;
            winstolb1--;
            flag = 1 - flag;
            m--;
            stolb[i] = -10;
            i = 0;
          }
          }
      }
      else
      {
        if ((stolb[i] <= s[0][1]) && (stolb[i] >= s[0][0]) && (stolb[i] <= s[1][1]) && (stolb[i] >= s[1][0]))
        {
          vasya++;
          winstolb2--;
          winstolb--;
          m--;
          stolb[i] = -10;
          flag = 1 - flag;
          i = 0;
        }
        else
          if (winstolb <= 0)
          {
          if ((stolb[i] <= s[1][1]) && (stolb[i] >= s[1][0]))
          {
            vasya++;
            winstolb--;
            winstolb2--;
            flag = 1 - flag;
            m--;
            stolb[i] = -10;
            i = 0;
          }
          }
      }
      if (winstolb1 <= 0)
        flag = 0;

      if (winstolb2 <= 0)
        flag = 1;
    }

    if (m == mold)
    {
      flag = 1 - flag;
      m--;
    }
    mold = m;
  }


  if ((OUT = fopen("game.out", "w")) == NULL)
  {
    return 0;
    exit(0);
  }

  if (vasya == petya)
    fprintf(OUT, "%s", "Draw");
  else
  {
    if (vasya > petya)
      fprintf(OUT, "%s", "Vasya");
    else
      fprintf(OUT, "%s", "Petya");
  }

  fclose(IN);
  fclose(OUT);

  return 0;
}