#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct msg {
  char c;
  int k;
} a[101010];

int x[101010];
int y[101010];
bool b[101010];
bool ok[101010];
std::vector<int> ans;

int main() {
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  memset(ok, 1, sizeof(ok));
  int n, m;
  scanf("%d %d", &n, &m);
  char s[5];
  for (int i = 1; i <= m; ++i) {
    scanf("%s %d", s, &a[i].k);
    a[i].c = s[0];
  }
  for (int i = 1; i <= m; ++i)
    if (a[i].c == '+')
      if (y[a[i].k] == 0)
        y[a[i].k] = i;
  for (int i = 1; i <= m; ++i)
    if (a[i].c == '-')
      if (y[a[i].k] == 0 || y[a[i].k] > i)        
        if (!b[a[i].k])
          b[a[i].k] = 1;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    cnt += b[i];
  for (int i = 1; i <= m; ++i) {
    if (a[i].c == '+') {
      if (cnt) {
        ok[a[i].k] = 0;
      } else {
        if (x[a[i].k] + 1 < i)
          ok[a[i].k] = 0;
      }
      if (!b[a[i].k]) {
        b[a[i].k] = 1;
        ++cnt;
      }
    } else {
      if (b[a[i].k]) {
        b[a[i].k] = 0;
        --cnt;
        x[a[i].k] = i;
        if (cnt)
          ok[a[i].k] = 0;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (x[i] > 0)
      if (x[i] < m && a[x[i] + 1].k != i)
        ok[i] = 0;
  for (int i = 1; i <= n; ++i)
    if (ok[i]) ans.push_back(i);
  printf("%d\n", ans.size());
  for (size_t i = 0; i < ans.size(); ++i)
    printf("%d ", ans[i]);
}