#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int f[2][N][N];

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m, mod;
  cin >> n >> m >> mod;
  vector<int> col(n, 0);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      col[j] += s[j] == '1';
    }
  }
  int zero = 0, one = 0;
  for (int i = 0; i < n; i++) {
    zero += col[i] == 0;
    one += col[i] == 1;
  }
  auto C2 = [&mod] (int n) -> int {
    return (int)((1LL * n * (n - 1) / 2) % mod);
  };
  auto add = [&mod] (int a, int b) -> int {
    a += b;
    if (a >= mod) a -= mod;
    return a;
  };
  auto mul = [&mod] (int a, int b) -> int {
    return (int)(1LL * a * b % mod);
  };
  f[m & 1][zero][one] = 1;
  for (int i = m; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        f[~i & 1][j][k] = 0;
      }
    }
    for (int j = 0; j <= n; j++) {
      for (int k = 0; j + k <= n; k++) {
        if (f[i & 1][j][k]) {
          if (j >= 2) {
            f[~i & 1][j - 2][k + 2] = add(f[~i & 1][j - 2][k + 2], mul(f[i & 1][j][k], C2(j)));
          }
          if (j >= 1 && k >= 1) {
            f[~i & 1][j - 1][k] = add(f[~i & 1][j - 1][k], mul(f[i & 1][j][k], mul(j, k)));
          }
          if (k >= 2) {
            f[~i & 1][j][k - 2] = add(f[~i & 1][j][k - 2], mul(f[i & 1][j][k], C2(k)));
          }
        }
      }
    }
  }
  cout << f[n & 1][0][0] << endl;
  return 0;
}

