#define TASKNAME "text"

#include <cstdio>
#include <iostream>

#include <cmath>
#include <algorithm>
#include <functional>

#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <ctime>
#include <cassert>

#include <map>
#include <set>
#include <vector>
 
#define EPS (1e-9)
#define INF int(1e9)
#define INFLONG (long long)(1e18)
#define sqr(a) ((a) * (a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#ifdef WIN32
  #define I64d "%I64d"
#else
  #define I64d "%lld"
#endif
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <ll> vll;
typedef vector <vll> vvll; 
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

const int maxn = 3e5 + 100;

int x[maxn], y[maxn];
vi In[maxn];

struct ST {
  vi t;
  int n;

  ST() {t.clear(), n = 0;}
  ST(vi &a) {
    int _n = sz(a);
    n = 1;
    while (n < _n)
      n <<= 1;
    t.resize(n << 1);                   
    for (int i = 0; i < _n; i++)
      t[i + n] = a[i];
    for (int i = n - 1; i > 0; i--)
      t[i] = t[i << 1] + t[(i << 1) + 1];
  }

  inline void update(int v, int x) {
    v += n;
    t[v] += x;
    v >>= 1;
    while (v)
      t[v] = t[v << 1] + t[(v << 1) + 1], v >>= 1;
  }

  inline int get(int v, int a, int b, int l, int r) {
    if (l > b || a > r)
      return 0;
    if (l <= a && b <= r)
      return t[v];
    int m = (a + b) >> 1;
    return get(v << 1, a, m, l, r) + get((v << 1) + 1, m + 1, b, l, r);
  }

  inline int get(int l, int r) {
    return get(1, n, (n << 1) - 1, l + n, r + n);
  }
};

int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif  
  int n, p;
  scanf("%d%d", &n, &p);
  vi deg(n + 10, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i], --y[i];
    ++deg[x[i]];
    ++deg[y[i]];
    In[x[i]].pb(i);
    In[y[i]].pb(i);
  }
  vi d(n + 10, 0);
  for (int i = 0; i < n; i++)
    d[deg[i]]++;
  
  ST degTree = ST(d);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int need = p - deg[i];
    if (need <= 0) {
      ans += n - 1;
      continue;
    }
    for (int j = 0; j < sz(In[i]); j++)
    {
      int v = In[i][j];
      int vertex = (x[v] == i ? y[v] : x[v]);
      degTree.update(deg[vertex], -1);
      degTree.update(deg[vertex] - 1, 1);
      --deg[vertex];
    }
    ans += degTree.get(need, n);
    if (deg[i] >= need)
      --ans;
    for (int j = sz(In[i]) - 1; j >= 0; j--) {
      int v = In[i][j];
      int vertex = (x[v] == i ? y[v] : x[v]);
      ++deg[vertex];
      degTree.update(deg[vertex] - 1, -1);
      degTree.update(deg[vertex], 1);
    }
  }
  printf("%I64d\n", ans / 2);  
  return 0;
}
