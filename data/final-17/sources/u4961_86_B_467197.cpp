//Authored by dolphinigle
//Yandex 3
//May 22 2011

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-8

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

char peta[1200][1200];
int color[1200][1200];
int single[1200][1200];
int downlen[1200][1200];

int digits[1200][1200];
int present[10];
int dfsed[1200][1200];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, int targetcolor) {
  if (digits[r+2][c+2] != -1) present[digits[r+2][c+2]] = 1;
  if (color[r+2][c+2] != targetcolor) return;
  if (dfsed[r+2][c+2]) return;
  dfsed[r+2][c+2] = 1;
  FORN(dir, 4) dfs(r+dr[dir], c+dc[dir], targetcolor);
}

void colorize(int r, int c, int targetcolor, int digit) {
  if (color[r+2][c+2] != targetcolor) return;
  if (digits[r+2][c+2] == digit) return;
  digits[r+2][c+2] = digit;
  FORN(dir, 4) colorize(r + dr[dir], c + dc[dir], targetcolor, digit);
}

void doit(int r, int c) {
  FORN(i, 10) present[i] = 0;
  dfs(r, c, color[r+2][c+2]);
  FORN(i, 10) if (!present[i]) {
    colorize(r, c, color[r+2][c+2], i);
    return;
  }
}

int main() {

  int n,m;
  cin >> n >> m;

  FORN(i, n) {
    scanf("%s", peta[i]);
  }

  // pertama, disweep dan warnain semua row dengan pola 2-2-2-2-2...
  FORN(i, 1200) FORN(j, 1200) color[i][j] = -1;
  int nowcolor = 0;
  FORN(i, n) {
    int carry = 0;
    ++nowcolor;
    FORN(j, m+1) {
      if (j == m || peta[i][j] == '#') {
        if (carry) {
          if (color[i+2][j-2+2] != -1)
            color[i+2][j-1+2] = color[i+2][j-2+2];
          carry = 0;
          ++nowcolor;
        }
        continue;
      }
      color[i+2][j+2] = nowcolor;
      ++carry;
      if (carry == 2) {
        ++nowcolor;
        carry = 0;
      }
    }
  }

  /*FORN(i, n) {
    FORN(j, m) cout << color[i+2][j+2];
    cout << endl;
  }*/

  // now we sweep the ones
  FORN(i, n) FORN(j, m) {
    if (peta[i][j] == '#') continue;
    if (color[i+2][j+2] == -1) color[i+2][j+2] = -2;
    if (color[i+2][j+2] != color[i+2][j+1] && color[i+2][j+2] != color[i+2][j+3]) {
      // one
      single[i+2][j+2] = 1;
      color[i+2][j+2] = color[i+1][j+2];
      if (color[i+1][j+2] == -1) {
        color[i+2][j+2] = color[i+3][j+2];
        if (color[i+2][j+2] == -1) {
          cout << -1 << endl;
          return 0;
        }
        downlen[i+2][j+2] = 1;
        continue;
      }

      downlen[i+2][j+2] = 1;

      // check for "cutting"
      if (color[i+2][j+2] == color[i+1][j+2] && single[i+1][j+2]) {
        if (downlen[i+1][j+2] == 2) {
          // concatenate this
          downlen[i+2][j+2] = 3;
        } else if (downlen[i+1][j+2] == 1) {
          // hub dua
          ++nowcolor;
          color[i+2][j+2] = color[i+1][j+2] = nowcolor;
          downlen[i+2][j+2] = 2;
        } else {
          // == 3
          // split into two
          ++nowcolor;
          color[i+2][j+2] = color[i+1][j+2] = nowcolor;
          downlen[i+2][j+2] = 2;
        }
      }
    }
  }

  // detect triplets
  FORN(i, n) FORN(j, m) if (color[i+2][j+2] != -1 &&
    color[i+2][j+2] == color[i+2][j+3] &&
    color[i+2][j+2] == color[i+2][j+4]) {
    // cut the first, if possible
    if (color[i+1][j+2] == color[i+2][j+2] ||
        color[i+3][j+2] == color[i+2][j+2]) {
      // okay cut this
      ++nowcolor;
      for (int z = 1; ; ++z) if (color[i+2+z][j+2] == color[i+2][j+2]) color[i+2+z][j+2] = nowcolor; else break;
      for (int z = 1; ; ++z) if (color[i+2-z][j+2] == color[i+2][j+2]) color[i+2-z][j+2] = nowcolor; else break;
      color[i+2][j+2] = nowcolor;
    }
  }

  FORN(i, 1200) FORN(j,1200) digits[i][j] = -1;
  FORN(i, 1200) FORN(j, 1200) dfsed[i][j] = 0;
  FORN(i, n) FORN(j, m) if (peta[i][j] != '#' && digits[i+2][j+2] == -1) doit(i, j);

  FORN(i, n) {
    FORN(j, m) {
      if (digits[i+2][j+2] == -1) printf("#"); else
      printf("%d", digits[i+2][j+2]);
    }
    printf("\n");
  }

  return 0;
}
