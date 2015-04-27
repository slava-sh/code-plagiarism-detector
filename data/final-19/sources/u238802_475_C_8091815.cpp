#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int ans, n, m, a[1001][1001], v[1001][1001], cnt;
char str[1011][1011];

inline void calc(int X1, int X2, int Y1, int Y2){
     int area = (X2 - X1 + 1) * (Y2 - Y1 + 1);
     if (area >= ans) return;
     for (int i = X1; i <= X2; i++)
          if (a[i][Y2] - a[i][Y1 - 1] != Y2 - Y1 + 1) return;
     int WW = area;
     for (;;)
     {
          bool canX = true, canY = true;
          if (Y2 == m || v[X2][Y2 + 1] - v[X1 - 1][Y2 + 1] != X2 - X1 + 1) canY = false;
          if (X2 == n || a[X2 + 1][Y2] - a[X2 + 1][Y1 - 1] != Y2 - Y1 + 1) canX = false;
          if (!canX && !canY) break;
          if (canX && canY) break;
          if (canX) 
               ++X1, ++X2, WW += Y2 - Y1 + 1;
          else ++Y1, ++Y2, WW += X2 - X1 + 1;
     }
     if (WW == cnt) ans = area;
}
          
int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++)
          scanf("%s", str[i] + 1);
     memset(a, 0, sizeof(a));
     memset(v, 0, sizeof(v));
     int initx, inity;
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= m; j++)
               a[i][j] = a[i][j - 1] + (str[i][j] == 'X'),
               v[i][j] = v[i - 1][j] + (str[i][j] == 'X');
     bool ok = false;
     for (int i = 1; i <= n && !ok; i++)
          for (int j = 1; j <= m && !ok; j++)
               if (str[i][j] == 'X') initx = i, inity = j, ok = true;
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= m; j++) cnt += str[i][j] == 'X';
     int D = 0, R = 0; ans = 1 << 30;
     for (int i = initx; i <= n; i++)
          if (str[i][inity] == 'X') D = i;
          else break;
     for (int i = inity; i <= m; i++)
          if (str[initx][i] == 'X') R = i;
          else break;
     for (int i = inity; i <= R; i++) calc(initx, D, inity, i);
     for (int i = initx; i <= D; i++) calc(initx, i, inity, R);
     if (ans == 1 << 30) printf("-1\n");
     else printf("%d\n", ans); 
}
