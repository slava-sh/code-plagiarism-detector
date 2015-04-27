#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int maxn = 110;
int v[maxn], a[maxn], b[maxn];
string c[maxn];
int hl, hr, n; 
const double eps = 1e-10;
int solve() {
  int yl = 100-hl;
  int yr = 100-hr;
  int best = 0;
  for (int cnt = 0; cnt < 110; ++cnt) {
    set<int> has;
    bool ok = true;
    int curres = 0;
    for (int i = 0; i < cnt; ++i) {
      if (!ok) break;
      int yy = 100*(i+1);
      char need = 'F';
      if (i&1) need = 'T';
      double xpos = (yy-yl)/(yr-yl+.0)*100000.;
      bool cc = false;
      for (int j = 0; j < n; ++j) {
        if (a[j]-eps<=xpos && xpos <= b[j]+eps && need == c[j][0]) {
          if (has.count(j)) {
            ok = false;
            break;
          }
          has.insert(j);
          curres += v[j];
          cc = true;
        }
      }
      if (!cc) ok = false;
    }
    if (ok) best = max(best, curres);
    yr = 2*(100*(cnt+1))-yr;
  }
  return best;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
  scanf("%d%d%d", &hl, &hr, &n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> c[i] >> a[i] >> b[i];
  }
  int ans = 0;
  ans = solve();
  hl = 100-hl;
  hr = 100-hr;
  for (int i = 0; i < n; ++i) c[i][0] ^= 'T'^'F';
  int ans2 = solve();
  ans = max(ans,ans2);
  printf("%d\n", ans);
	return 0;
}