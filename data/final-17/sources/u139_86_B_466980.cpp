#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <complex>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define id(x) (x) / m][(x) % m

const int kMaxN = 1000;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

char mat[kMaxN][kMaxN + 1];
int f[kMaxN * kMaxN], size[kMaxN * kMaxN];
int col[kMaxN][kMaxN];
int s[kMaxN * kMaxN];
bool used[kMaxN][kMaxN], hash[11];
int n, m, top;

inline int GetID(int x, int y) { return x * m + y; }
inline bool IsInside(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

inline int Find(int x) {
  int y = x, z;
  while (f[y] != -1) y = f[y];
  while (x != y) {
    z = x;
    x = f[x];
    f[z] = y;
  }
  return y;
}

void dfs(int u, int ff) {
  int x = u / m, y = u % m;
  used[x][y] = true;
  s[top++] = u;
  for (int i = 0; i < 4; ++i) {
    int xt = x + dx[i], yt = y + dy[i];
    if (IsInside(xt, yt) && !used[xt][yt] && Find(GetID(xt, yt)) == ff) {
      dfs(GetID(xt, yt), ff);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", mat[i]);
  }
  memset(size, 0, sizeof(size));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int id = GetID(i, j);
      if (mat[i][j] == '.') {
        size[id] = 1;
      }
      f[id] = -1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.' && f[GetID(i, j)] == -1) {
        int d = -1, s = 10;
        int xt, yt;
        for (int k = 0; k < 4; ++k) {
          xt = i + dx[k], yt = j + dy[k];
          if (!IsInside(xt, yt) || mat[xt][yt] == '#') continue;
          int ff = Find(GetID(xt, yt));
          if (size[ff] == 0) continue;
          if (size[ff] < s) {
            s = size[ff];
            d = k;
          }
        }
        if (d == -1) {
          puts("-1");
          return 0;
        }
        xt = i + dx[d], yt = j + dy[d];
        int f1 = Find(GetID(xt, yt)), f2 = Find(GetID(i, j));
        f[f1] = f2;
        size[f2] += size[f1];
        if (size[f2] > 5) {
          puts("-1");
          return 0;
        }
      }
    }
  }
  memset(used, false, sizeof(used));
  memset(col, 0, sizeof(col));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] != '.' || used[i][j]) continue;
      top = 0;
      dfs(Find(GetID(i, j)), Find(GetID(i, j)));
      memset(hash, false, sizeof(hash));
      int ff = Find(s[0]);
      for (int j = 0; j < top; ++j) {
        int x = s[j] / m, y = s[j] % m;
        for (int k = 0; k < 4; ++k) {
          int xt = x + dx[k], yt = y + dy[k];
          if (IsInside(xt, yt) && mat[xt][yt] == '.' && Find(GetID(xt, yt)) != ff) {
            hash[col[xt][yt]] = true;
          }
        }
      }
      int c = 0;
      while (hash[c]) ++c;
      for (int j = 0; j < top; ++j) {
        int x = s[j] / m, y = s[j] % m;
        col[x][y] = c;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.') putchar(col[i][j] + '0');
      else putchar(mat[i][j]);
    }
    puts("");
  }
  return 0;
}
