#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

const int maxn = 1024;
const int dx[4] = {+1, -1, 0, 0};
const int dy[4] = {0, 0, +1, -1};

char s[maxn][maxn];
int a[maxn][maxn], w[maxn][maxn], r[maxn][maxn];
int ans[maxn][maxn], n, m;
int aans[2*maxn*maxn], u[2*maxn*maxn];
bool b[maxn][maxn];

std::vector<int> e[maxn*maxn];

void dfs(int y, int x) {
  b[y][x] = true;
  w[y][x] = 1;
  ans[y][x] = y*(m+1)+x;
  aans[y*(m+1)+x] = y*(m+1)+x;
  for (int i = 0; i < 4; ++i) {
    if (!b[y+dy[i]][x+dx[i]] && !a[y+dy[i]][x+dx[i]]) {
      dfs(y+dy[i], x+dx[i]);
      if (w[y+dy[i]][x+dx[i]] == 1) {
        aans[(y+dy[i])*(m+1)+x+dx[i]] = aans[y*(m+1)+x];
        ++w[y][x];
      }
    }
  }
  for (int i = 1; i <= 9; ++i) {
    bool flag = false;
    u[y*(m+1)+x] = i;
    for (int j = 0; j < 4; ++j) {
      if (i == u[(y+dy[j])*(m+1)+x+dx[j]] && aans[y*(m+1)+x] != aans[(y+dy[j])*(m+1)+x+dx[j]]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      break;
    } 
  }
}

int get(int v) {
  if (aans[v] == v) {
    return aans[v];
  } else {
    return get(aans[v]);
  }
}

int main() {
//#define DBG
#ifdef DBG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  std::cin >> n >> m;
  for (int i = 0; i <= n+1; ++i) {
    for (int j = 0; j <= m+1; ++j) {
      a[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    std::scanf("%s", s[i]);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '#') {
        a[i][j+1] = 1;
      } else {
        a[i][j+1] = 0;
      }
    }
  }
  std::memset(b, false, sizeof(b));
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!b[i][j] && !a[i][j]) {
        dfs(i, j);
        if (w[i][j] == 1) {
          bool flag = false;
          for (int k = 0; k < 4; ++k) {
            if (a[i+dy[k]][j+dx[k]] == 0) {
              flag = true;
              aans[i*(m+1)+j] = aans[(i+dy[k])*(m+1)+j+dx[k]]; 
            }
          }
          if (!flag) {
            std::cout << "-1" << std::endl;
            std::exit(0);
          } 
        }
      }
    }
  } 


  std::memset(u, 0, sizeof(u));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!a[i][j]) {
        r[i][j] = get(aans[i*(m+1)+j]);
      }
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!u[r[i][j]]) {
        for (int k = 1; k <= 9; ++k) {
          u[r[i][j]] = k;
          bool flag = false;
          for (int y = i-4; y <= i+4; ++y) {
            for (int x = j-4; x <= j+4; ++x) {
              if (y > 0 && y < n+1 && x > 0 && x < m+1 && r[y][x] == r[i][j]) { 
                for (int q = 0; q < 4; ++q) {
                  if (r[y][x] != r[y+dy[q]][x+dx[q]] && u[r[y][x]] == u[r[y+dy[q]][x+dx[q]]]) {
                    flag = true;
                    break;
                  }
                }
              }
              if (flag) {
                break;
              }
            }
            if (flag) {
              break;
            }
          }
          if (!flag) {
            break;
          }
        }
      }
    }
  }


  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) {
        std::printf("#");
      } else {
        std::printf("%d", u[r[i][j]]);
      }
    }
    std::cout << std::endl;
  }
      

  return 0;
}
