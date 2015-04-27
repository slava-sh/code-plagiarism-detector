#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

char a[1005][1005];
int n, m;
const int INF = 1e9;

int sx, sy;
void f() {
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]=='X') { sx=i; sy=j; return; }
}

char b[1005][1005];

bool check(int xl, int xr, int yl, int yr, char c) {
  for(int i=xl;i<=xr;i++)
    for(int j=yl;j<=yr;j++)
      if(b[i][j] != c) return false;
      else b[i][j] = 'X' + '.' - c;
  return true;
}

bool test(int h, int w) {
  int nx = sx, ny = sy, flag = 1;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) b[i][j] = a[i][j];
  flag &= check(nx, nx+h-1, ny, ny+w-1, 'X');
  while(nx+h <= n && ny+w <= m && flag) {
    if(b[nx+h][ny] == 'X') { flag &= check(nx+h, nx+h, ny, ny+w-1, 'X'); ++nx; }
    else if(b[nx][ny+w] == 'X') { flag &= check(nx, nx+h-1, ny+w, ny+w, 'X'); ++ny; }
    else break;
  }
  flag &= check(0, n-1, 0, m-1, '.');
  return flag;
}

int go() {
  int h = 0, w = 0, w2 = 0;
  f();
  for(int i=sx;i<n;i++) if(a[i][sy]=='X') ++h;
  for(int j=sy;j<m;j++) if(a[sx][j]=='X') ++w;
  w2 = sy+w-1;
  for(int j=sy;j<m;j++) if(a[sx+h][j]=='X') { w2=j; break; }
  w = w + sy - w2;
  if(test(h, w)) return h*w;
  return INF;
}

void transpose() {
  for(int i=0;i<max(n, m);i++)
    for(int j=i+1;j<max(n, m);j++)
      swap(a[i][j], a[j][i]);
  swap(n, m);
}

int main(void) {
  scanf("%d%d", &n, &m);
  for(int i=0;i<n;i++) scanf("%s", a[i]);
  int ans = go();
  transpose();
  ans = min(ans, go());
  if(ans == INF) puts("-1");
  else printf("%d\n", ans);
  return 0;
}
