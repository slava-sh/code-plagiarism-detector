#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char a[1005][1005];

int col[1000];
int tx[1000], ty[1000], tn;

int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, -1, 1};

inline int ne(int x, int y) {
  int res = 0;
  for (int i=0; i<4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if (a[nx][ny] == '.')
      res++;
  }
  return res;
}


int dfs(int x, int y, int f) {
  fprintf(stderr, "%d %d %d\n", x, y, f); 
  a[x][y] = '?';
  tx[tn] = x;
  ty[tn++] = y;
  for (int i=0; i<4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if (a[nx][ny] >= '0' && a[nx][ny] <= '9') {
      col[a[nx][ny] - '0'] = 1;
    }
    if (a[nx][ny] == '.' && ne(nx, ny) == 0) {
      dfs(nx, ny, ++f);
    }
  }
  if (f == 1) {
    for (int i=0; i<4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if (a[nx][ny] == '.') {
        dfs(nx, ny, ++f);
        break;
      }
    }
  }
  return f > 1;
}

int main(void) {
  int m, n;
  scanf("%d%d", &m, &n);
  memset(a, '#', sizeof(a));
  for (int i=1; i<=m; i++) {
    scanf("%s", a[i] + 1);
  }

  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      if (a[i][j] == '.') {
        memset (col, 0, sizeof(col));
        tn = 0;

        if (!dfs(i, j, 1)) {
          printf ("%d\n", -1);
          return 0;
        }

        int c = 0;
        while (col[c])
          c++;
        assert (tn <= 5 && c <= 9);
        for (int k=0; k<tn; k++)
          a[tx[k]][ty[k]] = c + '0';
      }

  for (int i=1; i<=m; i++)
    puts(a[i] + 1);

  return 0;
}
