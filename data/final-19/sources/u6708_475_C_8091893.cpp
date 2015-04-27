#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int yy, xx, dy, dx;

bool solve(vector<string> str, int y, int x) {
  REP(i,yy) REP(j,xx) {
    if (str[y+i][x+j] != 'X') return false;
    str[y+i][x+j] = '@';
  }
  while (true) {
    bool by = true;
    bool bx = true;
    REP(i,yy) if (str[y+i][x+xx] != 'X') bx = false;
    REP(i,xx) if (str[y+yy][x+i] != 'X') by = false;
    if (!bx && !by) break;
    if (bx && by) {
      yy += dy;
      xx += dx;
    }
    else if (bx) {
      REP(i,yy) str[y+i][x+xx] = '@';
      x++;
    }
    else {
      REP(i,xx) str[y+yy][x+i] = '@';
      y++;
    }
  }
  REP(i,str.size()) REP(j,str[0].size())
    if (str[i][j] == 'X') return false;
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> str(n);
  REP(i,n) cin >> str[i];
  REP(i,n) str[i] += ".";
  str.push_back(str[0]);
  REP(i,m+1) str[n][i] = '.';
  int y = -1, x = -1;
  REP(i,n) {
    REP(j,m) {
      if (str[i][j] == 'X') {
        y = i; x = j;
      }
      if (y >= 0) break;
    }
    if (y >= 0) break;
  }
  int res = 1000000000;

  yy = 1; xx = 1; dy = 1, dx = 0;
  while (str[y][x+xx] == 'X') xx++;
  solve(str, y, x);
  bool flag = solve(str, y, x);
  if (flag) res = min(res, yy * xx);

  yy = 1; xx = 1; dy = 0, dx = 1;
  while (str[y+yy][x] == 'X') yy++;
  solve(str, y, x);
  flag = solve(str, y, x);
  if (flag) res = min(res, yy * xx);

  if (res == 1000000000) res = -1;
  cout << res << endl;
  return 0;
}
