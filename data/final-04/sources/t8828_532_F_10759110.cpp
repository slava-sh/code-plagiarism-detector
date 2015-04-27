#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FILE ""

const int INF = 1000 * 1000 * 1000 + 5;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int N = 2 * 100000 + 5;
const ll P = 2 * 100000 + 9;
ll PS[N];
int n, m;
string s, t;
vector<int> f;
vector<int> a, b;
ll ah, bh;
vector<int> ans;

inline ll md(ll x) {
  x %= MOD;
  if (x < 0) {
    x += MOD;
  }
  return x;
}

int main() {
#ifdef HOME
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  //freopen(FILE ".in", "r", stdin);
  //freopen(FILE ".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  cin >> s >> t;
  
  PS[0] = 1;
  for (int i = 1; i < N; ++i) {
    PS[i] = (PS[i - 1] * P) % MOD;
  }
  f.assign(256, -1);
  a.resize(n);
  for (int i = n - 1; i >= 0; --i) {
    a[i] = (f[s[i]] == -1 ? N : f[s[i]] - i);
    f[s[i]] = i;
  }
  f.assign(256, -1);
  b.resize(m);
  for (int i = m - 1; i >= 0; --i) {
    b[i] = (f[t[i]] == -1 ? N : f[t[i]] - i);
    f[t[i]] = i;
  }

  for (int i = 0; i < m; ++i) {
    bh = (bh * P + b[i]) % MOD;
  }
  f.assign(256, -1);
  for (int i = 0; i < m; ++i) {
    ah = (ah * P + (i + a[i] < m ? a[i] : N)) % MOD;
    f[s[i]] = i;
  }
  for (int i = 0; i + m <= n; ++i) {
    if (ah == bh) {
      vector<int> r(26, -1);
      for (int j = 0; j < 26; ++j) {
        int x = f['a' + j];
        if (x >= i) {
          r[j] = t[x - i] - 'a';
        }
      }
      bool ok = true;
      for (int j = 0; j < 26; ++j) {
        if (r[j] != -1 && r[r[j]] != -1) {
          if (r[r[j]] != j) {
            ok = false;
            break;
          }
        }
      }
      if (ok) {
        ans.pb(i + 1);
      }
    }
    if (i + m < n) {
      int j = i + m;
      ah = md(ah - (i + a[i] < i + m ? a[i] : N) * PS[m - 1]);
      if (f[s[j]] > i) {
        int k = f[s[j]];
        ah = md(ah + (-N + a[k]) * PS[m - (k - i) - 1]);
      }
      ah = md(ah * P + N);
      f[s[j]] = j;
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
