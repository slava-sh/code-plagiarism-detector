#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define DEBUG(x) #x << "=" << x << ", "


int T[100100],
    F[100100],
    v[1010],
    a[1010],
    b[1010];

char c[1010];

int hl, hr, n;

int vis[1010];
int sim(int l, int r, int* t, int* f) {
  int i;
  double alpha = 1e5 / r;
  int q = 0;
  int res = 0;
  REP(i, n) vis[i] = 0;
  for(int x = l; x < r; x += 100, q = !q) {
    int y = alpha * x;
    int *c = (q ? t : f);
    //cerr << DEBUG(x) << DEBUG(y) << DEBUG(q) << DEBUG(c[y]) << endl;
    if (c[y] != -1 && c[y] == c[y+1]) {
      if (vis[c[y]]) return -2;
      res += v[c[y]];
      vis[c[y]] = 1;
      //cerr << DEBUG(v[c[y]]) << endl;
    } else {
      return -1;
    }
  }
  //cerr << endl;
  return res;
}

int main(int argc, const char** argv) {
  int i, j;

  REP(i, 100100) {
    T[i] = -1;
    F[i] = -1;
  }

  cin >> hl >> hr >> n;

  REP(i, n) {
    cin >> v[i] >> c[i] >> a[i] >> b[i];
    int *q = (c[i] == 'T' ? T : F),
        l = b[i] - a[i] + 1;
    REP(j,l) q[a[i] + j] = i;
  }
/*
  cout << sim(hl, hl - hr, T, F) << endl; // no reflection
  cout << sim(hl, hl + hr + 200, T, F) << endl; // 3 reflection
  cout << sim(hl, hl + hr, T, F) << endl; // 1 reflection
  cout << sim(hl, hl - hr + 200, T, F) << endl; // 2 reflections
  cout << sim(100 - hl, 200 - hr - hl, F, T) << endl; // 1 reflection
  cout << sim(100 - hl, 200 + hr - hl, F, T) << endl; // 2 reflections
*/

  int ans = 0;
  REP(i, 501) {
    ans = max(ans, sim(hl, i * 200 + hl + hr, T, F)); // 1 reflection
    ans = max(ans, sim(hl, i * 200 + hl - hr + 200, T, F)); // 2 reflections
    ans = max(ans, sim(100 - hl, i * 200 + 200 - hr - hl, F, T)); // 1 reflection
    ans = max(ans, sim(100 - hl, i * 200 + 200 + hr - hl, F, T)); // 2 reflections
  }
  cout << ans << endl;

}
