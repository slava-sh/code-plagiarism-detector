#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef long double real;

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

#ifdef WIN32
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

using namespace std;

const int MaxN = 150, MaxL = (MaxN + 32 - 1) / 32, NA = -1, MaxC = 0x3F3F3F3F;
const int MaxD = 4, MaxBuf = 123456;
const int dx [MaxD] = {-1,  0,  1,  0},
          dy [MaxD] = { 0, -1,  0,  1};
const char dz [MaxD] = {'L', 'U', 'R', 'D'};

typedef unsigned int table [MaxN] [MaxL];

table a;
table d;
table f [2];
char s [MaxBuf];
int k, m, n, x, y;

int main (void)
{
 int b, i, j, l;
 char ch;
 bool ok;

 while (scanf (" %d %d %d", &n, &m, &k) != EOF)
 {
  memset (a, 0, sizeof (a));
  memset (d, 0, sizeof (d));
  x = y = NA;
  for (i = 0; i < n; i++)
   for (j = 0; j < m; j++)
   {
    scanf (" %c", &ch);
    switch (ch)
    {
     case 'E':
      x = i;
      y = j;
      d[i][j >> 5] |= 1u << (j & 31);
      // fallthrough!
     case '.':
      a[i][j >> 5] |= 1u << (j & 31);
      break;
     case '#':
      break;
     default:
      assert (false);
      break;
    }
   }

  b = 0;
  memmove (f[b], a, sizeof (table));
  scanf (" %s", s);

  for (l = 0; l <= k; l++)
  {
   b ^= 1;
   table & cur = f[!b];
   table & next = f[b];
   memset (next, 0, sizeof (table));

   ok = true;
   for (i = 0; ok && i < n; i++)
    for (j = 0; ok && j < MaxL; j++)
     if (cur[i][j] != d[i][j])
      ok = false;
   if (ok)
    break;

   if (l == k)
    continue;
   ch = s[l];

   switch (ch)
   {
    case 'L':
     for (i = 0; i < n; i++)
     {
      for (j = 0; j < MaxL; j++)
       next[i][j] |= (cur[i][j] >> 1) & a[i][j];
      for (j = 1; j < MaxL; j++)
       next[i][j - 1] |= ((cur[i][j] & 1u) << 31) & (a[i][j - 1] & (1u << 31));
     }
     for (i = 0; i < n; i++)
     {
      for (j = 0; j < MaxL; j++)
       next[i][j] |= cur[i][j] & ((~a[i][j]) << 1);
      for (j = 1; j < MaxL; j++)
       next[i][j] |= (cur[i][j] & 1u) & (((~a[i][j - 1]) & (1u << 31)) >> 31);
     }
     break;
    case 'U':
     for (i = 1; i < n; i++)
      for (j = 0; j < MaxL; j++)
       next[i - 1][j] |= cur[i][j] & a[i - 1][j];
     for (i = 1; i < n; i++)
      for (j = 0; j < MaxL; j++)
       next[i][j] |= cur[i][j] & ~a[i - 1][j];
     break;
    case 'R':
     for (i = 0; i < n; i++)
     {
      for (j = 0; j < MaxL; j++)
       next[i][j] |= (cur[i][j] << 1) & a[i][j];
      for (j = 0; j < MaxL - 1; j++)
       next[i][j + 1] |= (cur[i][j] >> 31) & a[i][j + 1] & 1u;
     }
     for (i = 0; i < n; i++)
     {
      for (j = 0; j < MaxL; j++)
       next[i][j] |= cur[i][j] & ((~a[i][j]) >> 1);
      for (j = 0; j < MaxL - 1; j++)
       next[i][j] |= ((cur[i][j] >> 31) & (~a[i][j + 1]) & 1u) << 31;
     }
     break;
    case 'D':
     for (i = 0; i < n - 1; i++)
      for (j = 0; j < MaxL; j++)
       next[i + 1][j] |= cur[i][j] & a[i + 1][j];
     for (i = 0; i < n - 1; i++)
      for (j = 0; j < MaxL; j++)
       next[i][j] |= cur[i][j] & ~a[i + 1][j];
     break;
    default:
     assert (false);
     break;
   }

/*
   for (i = 0; i < n; i++)
   {
    for (j = 0; j < m; j++)
    {
     putchar ((next[i][j >> 5] & (1u << (j & 31))) ? '+' : '-');
    }
    putchar ('\n');
   }
   putchar ('\n');
*/
  }

  if (l > k)
   l = NA;
  printf ("%d\n", l);
 }

 return 0;
}
