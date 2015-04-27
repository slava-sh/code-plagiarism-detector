#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>

#include <array>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

typedef long long ll;

const int MAX_N = 510;

int n, m, mod;
int ct[MAX_N];
ll dp[MAX_N][MAX_N];

ll dfs(int one, int two) {
  ll &ref = dp[one][two];
  if (ref != -1) return ref;
  if (one == 0 && two == 0) return ref = 1;
  ll r = 0;
  if (one >= 2) {
    r = (r + (one * (one - 1) / 2) % mod * dfs(one - 2, two)) % mod;
  }
  if (two >= 2) {
    r = (r + (two * (two - 1) / 2) % mod * dfs(one + 2, two - 2)) % mod;
  }
  if (one >= 1 && two >= 1) {
    r = (r + one * two % mod * dfs(one - 1 + 1, two - 1)) % mod;
  }
  return ref = r;
}

int main() {
  cin >> n >> m >> mod;
  int s = 0;
  for (int i = 0; i < n; i++) {
    ct[i] = 2;
    s += 2;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        ct[j]--;
        s -= 1;
      }
    }
  }
  int L = n - m;
  if (s != 2 * L) {
    cout << 0 << endl;
    return 0;
  } else {
    bool ok = true;
    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
      if (ct[i] == 1) {
        one++;
      } else if (ct[i] == 2) {
        two++;
      } else if (ct[i] == 0) {
        // nothing
      } else {
        ok = false;
      }
    }
    if (!ok) {
      cout << 0 << endl;
      return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(one, two) << endl;
  }
}
