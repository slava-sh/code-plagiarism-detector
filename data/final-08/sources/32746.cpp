#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
const int inf = 1000000005;
typedef long long ll;
using namespace std;
const double eps = 1e-9;
int m, i, j, k, n;
double p[1001], ans;

int main() {
   cin >> n;
   for (i = 0; i <= n; i++) {
      cin >> p[i];
   }
   ans = 0.0;
   if (n % 2 == 0) ans = p[n / 2];
   
   for (i = 0; i <= n; i++) if (2 * i < n)
      for (j = 0; j <= n; j++) if (2 * j > n) {
           double a = 1.0 * (n - 2 * i) / (2 * j - n);
           ans = max(ans, (p[i] + a * p[j]) / (1 + a));
           //cout << i << " " << j << " " << ans << " " << a << endl;
      }
   printf("%.10lf\n", ans);
   
   return 0;
}