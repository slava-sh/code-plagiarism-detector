/* team 220. */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int i = 0; i < N; i++) \
    std::cout << Ar[i] << " ";

struct vec
{
  double x, y, z;
};

int main()
{
  freopen("dunes.in", "r", stdin);
  freopen("dunes.out", "w", stdout);
  int n, m;
  int l, r, x;

  cin >> n >> m;
  map<int, int>Ar;
  set<int> Used;

  for (int i = 0; i < n; i++)
  {
    cin >> l >> r >> x;
    l -= 1;
    r -= 1;
    for (int j = l; j <= r; j++)
    {
      Ar[j] += x;
      Used.insert(j);
      x *= -1;
    }
  }

  for (int i = 0; i < m; i++)
  {
    cin >> x;
    if (Used.find(x - 1) != Used.end())
      cout << Ar[x - 1] << endl;
    // if (Ar.find(x)))
    else
      cout << "0" << endl;
  }

  return 0;
}
