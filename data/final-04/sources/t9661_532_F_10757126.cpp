#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int INF = (int)1e9 + 1;
const ld EPS = 1e-9;

int Ps[2];

struct Hash {
  const static int n = 2;
  int a[n];

  Hash() {}
  Hash(long long x) {
    for (int i = 0; i < n; ++i) {
      a[i] = x % Ps[i];
      if (a[i] < 0) {
        a[i] += Ps[i];
      }
    }
  }

  inline void operator *= (const Hash &h) {
    for (int i = 0; i < n; ++i) {
      a[i] = (long long) a[i] * h.a[i] % Ps[i];
    }
  }

  inline void operator += (const Hash &h) {
    for (int i = 0; i < n; ++i) {
      if ((a[i] += h.a[i]) >= Ps[i]) {
        a[i] -= Ps[i];
      }
    }
  }

  inline void operator -= (const Hash &h) {
    for (int i = 0; i < n; ++i) {
      if ((a[i] -= h.a[i]) < 0) {
        a[i] += Ps[i];
      }
    }
  }

  inline bool operator < (const Hash &h) const {
    for (int i = 0; i < n; ++i) {
      if (a[i] != h.a[i]) {
        return a[i] < h.a[i];
      }
    }
    return 0;
  }

  inline bool operator == (const Hash &h) const {
    for (int i = 0; i < n; ++i) {
      if (a[i] != h.a[i]) {
        return 0;
      }
    }
    return 1;
  }

  inline bool operator != (const Hash &h) const {
    for (int i = 0; i < n; ++i) {
      if (a[i] != h.a[i]) {
        return 1;
      }
    }
    return 0;
  }
};

const int maxn = (int) 2e5 + 10;
char s[2][maxn + 1];
int n, m;

Hash Q;
Hash Qs[maxn + 1];

void precalc() {
  Ps[0] = (int) 1e9 + 7 + rnd(100);
  Ps[1] = Ps[0] + 2 + rnd(100);
  Q = 239017;

  Qs[0] = 1;
  for (int i = 0; i < maxn; ++i) {
    Qs[i + 1] = Qs[i], Qs[i + 1] *= Q;
  }
}

bool read() {
  if (scanf("%d%d%s%s", &n, &m, s[0], s[1]) < 4) {
    return 0;
  }
  return 1;
}

const int ci = 26;
Hash prec[2][ci][maxn + 1];

Hash getHash(int type, int ch, int l, int r) {
  Hash *cprec = prec[type][ch];

  Hash left = cprec[l];
  left *= Qs[r - l];
  Hash right = cprec[r];
  right -= left;
  return right;
}

pair<Hash, int> hashes[2][ci];

int go[ci];

bool solve(int l) {
  //eprintf("l = %d\n", l);
  for (int c = 0; c < ci; ++c) {
    hashes[0][c] = mp(getHash(0, c, l, l + m), c);
    hashes[1][c] = mp(getHash(1, c, 0, m), c);
    /*for (int it = 0; it < 2; ++it) {
      if (hashes[it][c].first != 0) {
        eprintf("hash %d,%c = %d\n", it, c + 'a', hashes[it][c].first.a[0]);
      }
    }*/
  }
  sort(hashes[0], hashes[0] + ci);
  sort(hashes[1], hashes[1] + ci);
  for (int i = 0; i < ci; ++i) {
    go[i] = -1;
  }
  for (int i = 0; i < ci; ++i) {
    if (hashes[0][i].first != hashes[1][i].first) {
      return 0;
    }
    if (hashes[0][i].first != 0) {
      go[hashes[0][i].second] = hashes[1][i].second;
    }
  }
  for (int i = 0; i < ci; ++i) {
    if (go[i] == -1) {
      continue;
    }
    if (go[i] != i) {
      if (go[go[i]] == -1) {
        go[go[i]] = i;
      } else {
        if (go[go[i]] != i) {
          return 0;
        }
      }
    }
  }
  return 1;
}

void solve() {
  for (int type = 0; type < 2; ++type) {
    for (int ch = 0; ch < ci; ++ch) {
      Hash *cprec = prec[type][ch];
      cprec[0] = 0;
      for (int i = 0; i < (!type ? n : m); ++i) {
        cprec[i + 1] = cprec[i];
        cprec[i + 1] *= Q;
        cprec[i + 1] += (s[type][i] == ('a' + ch));
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i <= n - m; ++i) {
    if (solve(i)) {
      ans.pb(i);
    }
  }

  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
    printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
  }
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
