#include <cstdio>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

int eprintf(const char* format, ...) {
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
}

#define TASKNAME "graph"
#define INF 2000000000
#define MAXW 12

int n;
vector< vector< pair<int, int> > > es;
vector<int> d;

void bfs(int st) {
  d = vector<int>(n, INF);
  d[st] = 0;

  list<int> q[MAXW + 1];
  vector<bool> red(n, false); red[st] = true;
  q[0].push_back(st);

  for (;;) {
    for (int IT = 0; q[0].empty() && (IT < MAXW); IT++) {
      for (int i = 0; i < MAXW; i++)
        q[i].swap(q[i + 1]);
      q[MAXW].clear();
    }
    if (q[0].empty()) break;

    int x = *q[0].begin(); q[0].pop_front();

    for (int i = 0; i < es[x].size(); i++) {
      int b = es[x][i].first, w = es[x][i].second;
      if (d[b] > d[x] + w) {
        red[b] = true;
        d[b] = min(d[b], d[x] + w);
        q[w].push_back(b);
      }
    }
  }
}

int main() {
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);

  while (scanf("%d", &n) != EOF) {
    int m; scanf("%d", &m);

    es.resize(n, vector< pair<int, int> >());
    for (int i = 0; i < m; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w), a--, b--;
      w = 12 / w;
      es[a].push_back(make_pair(b, w));
      es[b].push_back(make_pair(a, w));
    }

    bfs(0);

    for (int i = 1; i < n; i++)
      printf("%.8lf\n", (double)d[i] / 12.0);
  }
  return 0;
}
