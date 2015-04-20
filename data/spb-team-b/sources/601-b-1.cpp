#include <stdio.h>
#include <iostream>
using namespace std;

int m[1003][1003];


int main ()
{
  freopen("chess.in", "r", stdin);
  freopen("chess.out", "w", stdout);
  int n, i, x, j, sum = 0;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    cin >> x;
    for (j = 1; j <= x; j++)
      m[i][j] = 1;
  }

  i = 1;
  while (m[i][i] != 0)
  {
    sum++; 
    i++;
  }
  cout << sum << endl;
  for (i = 1; i <= sum; i++)
    cout << i << " " << i << endl;

  return 0;
}