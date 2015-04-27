#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <sstream>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MaxN = 1003, MaxC = 0x3F3F3F3F, NA = -1, MaxD = 4, Base = 10;
const int dx [MaxD] = {-1,  0,  1,  0},
          dy [MaxD] = { 0, -1,  0,  1};

char a [MaxN] [MaxN];
int m, n;

int main (void)
{
 int c, d, i, j;
 bool ok;
 while (scanf (" %d %d", &n, &m) != EOF)
 {
  memset (a, '#', sizeof (a));
  for (i = 1; i <= n; i++)
   for (j = 1; j <= m; j++)
    scanf (" %c", &a[i][j]);
  ok = true;
  for (i = 1; i <= n; i++)
   for (j = 1; j <= m; j++)
    if (a[i][j] == '.')
    {
     for (d = 0; d < MaxD; d++)
      if (a[i + dx[d]][j + dy[d]] == '.')
       break;
     if (d < MaxD)
     {
      c = (i % 3) * 3 + (j % 3);
      a[i][j] = '0' + c;
      a[i + dx[d]][j + dy[d]] = '0' + c;
     }
     else
     {
      for (d = 0; d < MaxD; d++)
       if (a[i + dx[d]][j + dy[d]] != '#')
        break;
      if (d < MaxD)
      {
       a[i][j] = a[i + dx[d]][j + dy[d]];
      }
      else
      {
       ok = false;
      }
     }
    }
  if (!ok)
  {
   printf ("-1\n");
  }
  else
  {
   for (i = 1; i <= n; i++)
   {
    for (j = 1; j <= m; j++)
     putchar (a[i][j]);
    putchar ('\n');
   }
  }
 }
 return 0;
}
