#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second

const int MAXC = 7, MAXM = MAXC * 2, MAXN = 30, MAXD = 28;

const int dx[] = {0, 0, 1, 1};
const int dy[] = {0, 1, 0, 1};

typedef pair<int, int> Pair;

vector<Pair> pos[MAXD];
vector<Pair> sqr;
int hash[MAXC], col[MAXM], ans[MAXM];

int mat[MAXN][MAXN], id[MAXN][MAXN];
bool used[MAXN][MAXN];

int n, m;

bool check(int u) {
  static vector<Pair> l;
  int x0 = sqr[u].X, y0 = sqr[u].Y;
  l.clear();
  for (int k = 0; k < 4; ++k) {
    int xt = x0 + dx[k], yt = y0 + dy[k];
    int d = mat[xt][yt];
    if (xt == pos[d][1].X && yt == pos[d][1].Y) {
      int cx = col[id[pos[d][0].X][pos[d][0].Y]], cy = col[id[pos[d][1].X][pos[d][1].Y]];
      if (cx > cy) {
        swap(cx, cy);
      }
      if (used[cx][cy]) {
        for (size_t i = 0; i < l.size(); ++i) {
          used[l[i].X][l[i].Y] = false;
        }
        return false;
      } else {
        used[cx][cy] = true;
        l.push_back(make_pair(cx, cy));
      }
    }
  }
  return true;
}

void subtract(int u) {
  int x0 = sqr[u].X, y0 = sqr[u].Y;
  for (int k = 0; k < 4; ++k) {
    int xt = x0 + dx[k], yt = y0 + dy[k];
    int d = mat[xt][yt];
    if (xt == pos[d][1].X && yt == pos[d][1].Y) {
      int cx = col[id[pos[d][0].X][pos[d][0].Y]], cy = col[id[pos[d][1].X][pos[d][1].Y]];
      if (cx > cy) {
        swap(cx, cy);
      }
      used[cx][cy] = false;
    }
  }
}

void output() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == -1) putchar('.');
      else putchar(ans[id[i][j]] + '0');
    }
    puts("");
  }
}

int ret = 0;
void dfs(int u) {
  if (u == 14) {
    if (++ret == 1) {
      memcpy(ans, col, sizeof(col));
    }
    return;
  }
  for (int i = 0; i < MAXC; ++i) {
    if (hash[i] < 2) {
      col[u] = i;
      if (check(u)) {
        ++hash[i];
        dfs(u + 1);
        --hash[i];
        subtract(u);
      }
    }
  }
}

int main() {
  char ch;
  memset(mat, -1, sizeof(mat));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf(" %c", &ch);
      if (ch != '.') {
        int val = islower(ch) ? ch - 'a' : ch - 'A' + 26;
        pos[val].push_back(make_pair(i, j));
        mat[i][j] = val;
      }
    }
  }
  memset(used, false, sizeof(used));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!used[i][j] && mat[i][j] >= 0) {
        sqr.push_back(make_pair(i, j));
        for (int k = 0; k < 4; ++k) {
          used[i + dx[k]][j + dy[k]] = true;
          id[i + dx[k]][j + dy[k]] = sqr.size() - 1;
        }
      }
    }
  }
  for (int i = 0; i < MAXD; ++i) {
    if (id[pos[i][0].X][pos[i][0].Y] > id[pos[i][1].X][pos[i][1].Y]) {
      swap(pos[i][0], pos[i][1]);
    }
  }
  memset(used, false, sizeof(used));
  memset(hash, 0, sizeof(hash));
  dfs(0);
  printf("%d\n", ret);
  output();
  return 0;
}
