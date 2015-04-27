#define TASKNAME "inventory"

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <ctime>

#ifdef WIN32
  #define I64d "%I64d"
#else
  #define I64d "%lld"
#endif

#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
            
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> pii;

const int MaxN = int(3e5) + 100;
const ll p = (ll)1e9 + 7;

int n, len;
char s[MaxN];
ll Hash[2][MaxN], powers[MaxN];

inline void precalc(int n)
{
  powers[0] = 1;
  for (int i = 1; i <= n; i++)
    powers[i] = powers[i - 1] * p;
}

inline ll getHash(int l, int r)
{
  return !l ? Hash[0][r] : Hash[0][r] - Hash[0][l - 1] * powers[r - l + 1];
}

inline ll getHash_rev(int l, int r)
{
  return r == len - 1 ? Hash[1][l] : Hash[1][l] - Hash[1][r + 1] * powers[r - l + 1];
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  precalc(MaxN - 1);
  while (scanf("%d\n", &n) >= 1)
  {
    for (int test = 0; test < n; ++test)
    {
      gets(s);
      len = strlen(s);
      for (int i = 0; i < len; ++i)
        s[i + len] = s[i];
      len <<= 1;

      Hash[0][0] = s[0];
      for (int i = 1; i < len; ++i)
        Hash[0][i] = Hash[0][i - 1] * p + s[i];  
      Hash[1][len - 1] = s[len - 1];
      for (int i = len - 2; i >= 0; --i)
        Hash[1][i] = Hash[1][i + 1] * p + s[i];

      bool ok = 0;
      for (int i = 0; i < (len >> 1); i++)
        if (getHash(i, i + (len >> 1) - 1) == getHash_rev(i, i + (len >> 1) - 1))
        {
          printf("%d\n", i);
          ok = 1;
          break;
        }
      if (!ok)
        puts("-1");
    }
  }
  return 0;
}
