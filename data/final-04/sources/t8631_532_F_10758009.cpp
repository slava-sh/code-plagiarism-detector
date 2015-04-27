#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <cassert>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)
#ifdef WIN32
#define I64d "%I64d"
#else
#define I64d "%lld"
#endif

typedef pair <int, int> pi;
typedef vector <int> vi;
typedef long long ll;

const int mod1 = 1000004249;
const int mod2 = 1000043227;
const int base1 = 398771;
const int base2 = 350729;
const int mx = 200011;
int n, m, nxt[222222], last[33], a[222222], b[222222];
queue <int> q[33];
char s[222222], t[222222];
int p1[222222], p2[222222];
int para[33];
vector<int> ans;

void process(char s[], int a[], int n) {
  memset(last, -1, sizeof(last));
  memset(nxt, -1, sizeof(nxt));
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    int l = last[c];
    if (l != -1) {
      nxt[l] = i;
      a[i] = i - l;
    } else {
      a[i] = mx;
    }
    last[c] = i;
  }
}

void calc_p(int base, int mod, int p[]) {
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = (1LL * p[i - 1] * base) % mod;
  }
}

void add_char(int& h, int c, int base, int mod) {
  h = (int)((1LL * h * base + c) % mod);
}

void update(int& h, int i, int fr, int to, int base, int mod, int p[]) {
  h = (h - 1LL * p[m - i - 1] * fr % mod + mod) % mod;
  h = (h + 1LL * p[m - i - 1] * to) % mod;
}

void rm(int &h, int x, int base, int mod, int p[]) {
  h = (h - 1LL * p[m - 1] * x % mod + mod) % mod;
}

bool ok(int i) {
  memset(para, -1, sizeof(para));
  for (int c  = 0; c < 26; ++c) {
    if (!q[c].empty()) {
      int pos = q[c].front();
      para[c] = int(t[pos - i] - 'a');
    }
  }
  for (int c = 0; c < 26; ++c) if (para[c] != -1) {
    if (para[para[c]] != c && para[para[c]] != -1) {
      return  false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  scanf("%s", t);
  process(t, b, m);
  process(s, a, n);

  calc_p(base1, mod1, p1);
  calc_p(base2, mod2, p2);

  int h1 = 0, h2 = 0;
  for (int i = 0; i < m; i++) {
    add_char(h1, b[i], base1, mod1);
    add_char(h2, b[i], base2, mod2);
  }

  int sh1 = 0, sh2 = 0;
  for (int i = 0; i < m; i++) {
    add_char(sh1, a[i], base1, mod1);
    add_char(sh2, a[i], base2, mod2);
    int c = s[i] - 'a';
    q[c].push(i);
  }
  for (int i = 0; i <= n - m; i++) {
    if (h1 == sh1 && h2 == sh2) {
      //printf("%d\n", i + 1);
      if (ok(i)) {
        ans.pb(i);
      }
    }
    if (nxt[i] != -1) {
      int pos = nxt[i];
      if (pos < i + m) {
        update(sh1, pos - i, a[pos], mx, base1, mod1, p1);
        update(sh2, pos - i, a[pos], mx, base2, mod2, p2);
      }
      a[pos] = mx;
    }
    rm(sh1, a[i], base1, mod1, p1);
    rm(sh2, a[i], base2, mod2, p2);

    q[s[i] - 'a'].pop();
    if (i + m < n) {
      add_char(sh1, a[i + m], base1, mod1);
      add_char(sh2, a[i + m], base2, mod2);
      q[s[i + m] - 'a'].push(i + m);
    }
  }

  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i] + 1);
  }
  puts("");
  return 0;
}
