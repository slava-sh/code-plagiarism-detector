#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

const int MAX_N = 1000000;

int par[MAX_N], rank[MAX_N];

void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 1;
  }
}

int root(int x) {
  return par[x] == x ? x : par[x] = root(par[x]);
}

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;

  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    // if (rank[x] == rank[y]) rank[x]++;
    rank[x] += rank[y];  // modified
  }
}

bool find(int x, int y) {
  return root(x) == root(y);
}


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W;
char fld[1010][1010];

int vid(int x, int y) {
  return y * W + x;
}

int id[1000010];
vector<int> adj[1000010];

int main() {
  while (2 == scanf("%d%d", &H, &W)) {
    rep (y, H) scanf("%s", fld[y]);

    init(W * H);
    rep (y, H) rep (x, W) {
      if (fld[y][x] == '#') continue;

      int v = root(vid(x, y));
      if (rank[v] > 1) continue;

      rep (d, 4) {
        int tx = x + dx[d];
        int ty = y + dy[d];
        if (tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
        if (fld[ty][tx] == '.') {
          unite(vid(x, y), vid(tx, ty));
          // printf("%d, %d - %d %d\n", x, y, tx, ty);
          goto done;
        }
      }

      goto ng;
   done:;
    }

    rep (v, W * H) adj[v].clear();
    rep (y, H) {
      rep (x, W) {
        int v = root(vid(x, y));
        rep (d, 4) {
          int tx = x + dx[d];
          int ty = y + dy[d];
          if (tx < 0 || W <= tx || ty < 0 || H <= ty) continue;
          if (fld[ty][tx] == '.') {
            int tv = root(vid(tx, ty));
            adj[v].pb(tv);
          }
        }
      }
    }

    memset(id, -1, sizeof(id));
    rep (v, W * H) {
      int usd = 0;
      rep (i, adj[v].size()) {
        int w = adj[v][i];
        if (id[w] != -1) usd |= 1 << id[w];
      }

      rep (i, 10) {
        if (0 == (usd & (1 << i))) {
          id[v] = i;
          break;
        }
      }
    }

    rep (y, H) {
      rep (x, W) {
        if (fld[y][x] == '#') printf("#");
        else printf("%d", id[root(vid(x, y))]);
      }
      puts("");
    }

    continue;
 ng:
    puts("-1");
  }

  return 0;
}

