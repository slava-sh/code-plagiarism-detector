#include <stdio.h>
#include <iostream>
using namespace std;

struct A {
  int l;
  int r;
  int p; 
};

A v[1001];

int main ()
{
  freopen("dunes.in", "r", stdin);
  freopen("dunes.out", "w", stdout);
  int n, m;
  long long ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].l >> v[i].r >> v[i].p;
  }

  for (int j = 0; j < m; j++)
  {
    ans = 0;
    int x;
    cin >> x;
    for (int i = 0; i < n; i++)
      if ((x <= v[i].r) && (x >= v[i].l))
      {
        if (v[i].l % 2 == x % 2)
          ans += v[i].p;
        else
          ans -= v[i].p;
      }
    cout << ans << endl;
  }

  return 0;
}