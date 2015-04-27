#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define INF 1000000000

long long f[555][555];
long long m, n, mod;

long long dp(long long n1, long long n0) {
  if (f[n1][n0] != -1) return f[n1][n0];
  long long res = 0;
  //chon 2 so 1
  if (n1 >= 2) {
    res += n1 * (n1 - 1) / 2 * dp(n1 - 2, n0);
    res %= mod;
  }
  //chon 2 so 0
  if (n0 >= 2) {
    res += n0 * (n0 - 1) / 2 * dp(n1 + 2, n0 - 2);
    res %= mod;
  }
  //chon 1 so 0, 1 so 1
  if (n1 && n0) {
    res += n1 * n0 * dp(n1, n0 - 1);
    res %= mod;
  }

  f[n1][n0] = res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  REP(i, 555) REP(j, 555) f[i][j] = -1;
  f[0][0] = 1;

  int cnt[555];
  memset(cnt, 0, sizeof cnt);
  cin >> n >> m >> mod;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    int cntRow = 0;
    for (int j = 0; j < s.size(); j++) if (s[j] == '1') {
      cnt[j]++;
      cntRow++;
    }
    if (cntRow != 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  int n1 = 0;
  int n0 = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 1)
      n1++;
    else if (cnt[i] == 0)
      n0++;
    else if (cnt[i] != 2){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << dp(n1, n0) << endl;

  return 0;
}
