#include <algorithm>
#include <cassert>
#include <cmath>
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
typedef unsigned long long uint64;
typedef double real;

#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

const int MaxN = 103, MaxC = 0x3F3F3F3F, NA = -1;
const real eps = 1E-9;

char t [MaxN];
real a [MaxN];
real b [MaxN];
int c [MaxN];
bool d [MaxN];
real hb, he;
int n;

int main (void)
{
 int i, j, k;

 while (scanf (" %lf %lf %d", &hb, &he, &n) != EOF)
 {
  for (i = 0; i < n; i++)
   scanf (" %d %c %lf %lf", &c[i], &t[i], &a[i], &b[i]);
  int res = 0;
  for (i = -n; i <= n; i++)
  {
   real xb = 0.0;
   real yb = hb;
   real xe = 100000.0;
   real ye = (i & 1) ? (100.0 * (i + 1) - he) : (100 * i + he);
   real dx = xe - xb;
   real dy = ye - yb;
   eprintf ("%14.6lf %14.6lf -- %14.6lf %14.6lf\n", xb, yb, xe, ye);

   bool ok = true;
   memset (d, 0, sizeof (d));
   for (j = -n; j <= n; j++)
   {
    if (dy == 0.0)
     continue;
    real yc = 100.0 * j;
    real xc = xb + dx * (yc - yb) / dy;
    eprintf ("%14.6lf %14.6lf\n", xc, yc);
    if (xc < xb - eps || xc > xe + eps)
     continue;
    char ct = (j & 1) ? 'T' : 'F';
    for (k = 0; k < n; k++)
     if (t[k] == ct)
      if (a[k] - eps <= xc && xc <= b[k] + eps)
      {
       if (d[k])
        ok = false;
       d[k] = true;
       break;
      }
    eprintf ("%d: %d\n", j, k);
    if (k == n || !ok)
    {
     ok = false;
     break;
    }
   }
   if (!ok)
    continue;

   int cur = 0;
   for (k = 0; k < n; k++)
    if (d[k])
     cur += c[k];
   res = max (res, cur);
  }
  printf ("%d\n", res);
 }

 return 0;
}
