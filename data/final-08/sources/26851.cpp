#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

double p[105];

double a[205][205], b[205][205];

int main(void) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i <= n; i++) {
    scanf("%lf", &p[i]);
  }

  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++)
      a[i][j] = -100;

  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= i && j <= n; j++) {
      int ni = n + i - j - j;
      a[i][ni] = p[j];
    }

  for (int t = 0; t <= 30; t++) {
    for (int i=0; i<=2*n; i++)
      for (int j=0; j<=2*n; j++)
        b[i][j] = -100;
    for (int i=0; i<=2*n; i++)
      for (int j=0; j<=2*n; j++)
        for (int k=0; k<=2*n; k++) {
          double t = a[i][k] + a[k][j];
          if (t > b[i][j])
            b[i][j] = t;
        }
    for (int i=0; i<=2*n; i++)
      for (int j=0; j<=2*n; j++)
        if (b[i][j] < 0)
          a[i][j] = -100;
        else
          a[i][j] = b[i][j] / 2;
  }

  double res = 0.0;
  for (int i=0; i <= 2*n; i++)
    for (int j=0; j <= 2*n; j++)
      res = max(a[i][j], res);


  printf ("%.20lf\n", res);

  return 0;
}
