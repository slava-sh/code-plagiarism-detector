#include <stdio.h>
#include <iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int a[100002];             

int main ()
{
  freopen("merlin.in", "r", stdin);
  freopen("merlin.out", "w", stdout);
  long long n, sum = 0, ans = 0, col = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  if (a[0] == a[n - 1])
  {
    cout << "0";
    return 0;
  }

  if (n == 2)
  {
    cout << "1";
    return 0;
  }

  sum = a[n - 1];
  int j = n - 1;
  long long ma = a[n - 2];

  for (int i = n - 3; i >= 0; i--)
  {
    ans += ma - a[i];
    col++;
  }
  
  if (ans < sum)
  {
    cout << "1";
    return 0;
  }

  int ANS = 1;

  while(ans > sum)
  {
    j--;
    sum += a[j];
    ma = a[j - 1];
    col--;
    ans -= ma;
    ans -= col * (a[j] - ma);    
    ANS++;
  }

  cout << ANS;

  return 0;
}