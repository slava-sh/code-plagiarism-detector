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
#define TASKNAME "a"

const int INF = (int)1e9 + 1;
const ld EPS = 1e-9;

const int maxn = (int)1e5 + 10;
int cnt[maxn];
char ans[maxn + 1];

int got[maxn], angry[maxn];

bool solve() {
  int n, k;
  if (scanf("%d%d", &n, &k) < 2) {
    return 0;
  }
  assert(n <= maxn && k <= maxn);
  --n;

  for (int i = 0; i < k; ++i) {
    scanf("%d", &cnt[i]);
    ans[i] = 'N';
  }

  for (int i = 0; i < n; ++i) {
    int t, r;
    scanf("%d%d", &t, &r);
    got[i] = t, angry[i] = r;
  }

  bool first = 1;
  int cnt0 = 0;
  for (int i = 0; i <= n; ++i) {
    if (i == n) {
      for (int i = 0; i < k; ++i) {
        if (cnt[i] <= cnt0) {
          //eprintf("i = %d, cnt[%d] = %d, cnt0 = %d\n", i, i, cnt[i], cnt0);
          ans[i] = 'Y';
        }
      }
      break;
    }
    if (angry[i] && first) {
      for (int i = 0; i < k; ++i) {
        ans[i] = 'Y';
      }
      for (int j = i; j < n; ++j) {
        if (got[j] > 0) {
          ans[got[j] - 1] = 'N';
        }
      }
      int who = -1;
      for (int i = 0; i < k; ++i) {
        if (cnt[i] > cnt0) {
          ans[i] = 'N';
        }
        if (ans[i] == 'Y') {
          //eprintf("i = %d\n", i);
          if (who == -1 || (cnt[who] > cnt[i])) {
            who = i;
          }
        }
      }
      assert(who != -1);
      //eprintf("who = %d\n", who);
      cnt0 -= cnt[who];
      cnt[who] = 0;
      first = 0;
    }
    if (got[i] == 0) {
      ++cnt0;
    } else {
      cnt[got[i] - 1] -= 1;
    }
  }

  ans[k] = 0;
  printf("%s\n", ans);
  return 1;
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out2", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  int maxt;
  while (scanf("%d", &maxt) == 1) {
    for (int t = 0; t < maxt; ++t) {
      solve();
    }
    break;
#ifdef DEBUG
    eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
