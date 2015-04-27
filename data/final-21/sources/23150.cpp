#define TASKNAME "inventory"

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;


const int MaxN = int(3e5) + 100;
const long long p = (long long)1e9 + 7;

int n, len;
char s[MaxN];
long long Hash[2][MaxN], powers[MaxN];

inline void precalc(int n)
{
  powers[0] = 1;
  for (int i = 1; i <= n; i++)
    powers[i] = powers[i - 1] * p;
}

inline long long getHash(int l, int r)
{
  return !l ? Hash[0][r] : Hash[0][r] - Hash[0][l - 1] * powers[r - l + 1];
}

inline long long getHash_rev(int l, int r)
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
