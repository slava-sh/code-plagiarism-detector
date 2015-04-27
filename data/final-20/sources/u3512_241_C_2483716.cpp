#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int point[105];
string f[105];
int a[105],b[105];
bool ok[105];
int ret = 0,n,hl,hr;
bool vis[105];
double eps = 1e-8;

int goUp(double sep) {
  for (int i = 1; i <= n; i++) if (f[i] == "T")
    if (a[i] - eps <= sep && sep <= b[i] + eps) return i;
  return 0;
}

int goDown(double sep) {
  for (int i = 1; i <= n; i++) if (f[i] == "F")
    if (a[i] - eps <= sep && sep <= b[i] + eps) return i;
  return 0;
}

void solve() {
  for (int layer = 1; layer <= 100; layer++) {
    bool ok = true;
    memset(vis,true,sizeof(vis));
    int Hright = (layer % 2 == 0) ? (100 * layer - hr) : (100 * (layer - 1) + hr);
    int dx = 100000,dy = Hright - hl;
    double unit = 1.0 * dy/dx;
    int cur = 0;
    for (int i = 1; i < layer; i++) {
      double sep = 1e5 * (i * 100 - hl)/dy;
      int pos;      
      if (i % 2) pos = goUp(sep); else pos = goDown(sep);
      if (!pos) ok = false;
      if (!vis[pos]) ok = false;
      vis[pos] = false;
      cur += point[pos];
    }
    if (ok) ret = max(ret,cur);
  }
}

int main() {
  scanf("%d %d %d", &hl, &hr, &n);
  for (int i = 1; i <= n; i++) {
    cin >> point[i] >> f[i] >> a[i] >> b[i];
  }

  solve();
  for (int i = 1; i <= n; i++) if (f[i] == "F") f[i] = "T"; else f[i] = "F";
  hl = 100 - hl;  hr = 100 - hr;
  solve();
  printf("%d\n", ret);
}
