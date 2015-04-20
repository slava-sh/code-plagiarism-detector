/* team 220.  */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int ArI = 0; i < N; i++) \
    std::cout << Ar[ArI] << " ";

struct vec
{
  double x, y, z;
};


int F( int x )
{
  if (int(pow(x % 100, 2) + pow((x - x % 100) / 100, 2)) % 7 == 1)
    return 1;
  return 0;
}

int main()
{
  freopen("abcd.in", "r", stdin);
  freopen("abcd.out", "w", stdout);

  int t, x;

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> x;
    cout << (F(x) ? "YES" : "NO")  << endl;
  }

  return 0;
}