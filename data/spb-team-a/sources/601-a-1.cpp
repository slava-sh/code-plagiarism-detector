#include <stdio.h>
#include <iostream>
using namespace std;

int main ()
{
  freopen("abcd.in", "r", stdin);
  freopen("abcd.out", "w", stdout);
  long long n, c;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> c;
    if(((c / 100)*(c / 100) + (c - int(c / 100) * 100)*(c - int(c / 100) * 100)) % 7 == 1)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }

  return 0;
}