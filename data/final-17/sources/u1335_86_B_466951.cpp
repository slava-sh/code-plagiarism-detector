#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPC(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int, int> pii;

char buf[1002];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  int h, w;
  while (scanf("%d%d", &h, &w) == 2)
  {
    vector<string> f(h);
    REP(y, h)
    {
      scanf("%s", buf);
      f[y] = buf;
    }

    bool ans = true;
    REP(y, h)
      REP(x, w)
        if (f[y][x] == '.')
        {
          char col = 3 * (y % 3) + (x % 3) + '0';
          if (x + 1 < w && f[y][x + 1] == '.')
            f[y][x] = f[y][x + 1] = col;
          else if (y + 1 < h && f[y + 1][x] == '.')
            f[y][x] = f[y + 1][x] = col;
        }
    REP(y, h)
      REP(x, w)
        if (f[y][x] == '.')
        {
          if (y > 0 && f[y - 1][x] != '#')
            f[y][x] = f[y - 1][x];
          else if (x > 0 && f[y][x - 1] != '#')
            f[y][x] = f[y][x - 1];
          else if (x + 1 < w && f[y][x + 1] != '#')
            f[y][x] = f[y][x + 1];
          else if (y + 1 < h && f[y + 1][x] != '#')
            f[y][x] = f[y + 1][x];
          else
          {
            printf("-1\n");
            ans = false;
            y = h, x = w;
          }
        }
    if (ans)
      REP(y, h)
        printf("%s\n", f[y].c_str());
  }
  return 0;
}
