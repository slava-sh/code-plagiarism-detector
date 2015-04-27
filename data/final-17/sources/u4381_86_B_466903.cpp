#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

#define PRINT(x) cout << "DEBUG " << #x << " = " << x <<  endl;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define frr(i, n) for(int i = 0; i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

#define move(r, c, rr, cc, i) rr = r + _my[i], cc = c + _mx[i]

int _mx[] = {0, 1, 0, -1};
int _my[] = {-1, 0, 1, 0};

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long long ll;

struct POINT { int r, c; };

int R, C;
char a[1100][1100];
int col[1100][1100];
int deg[1100][1100];
stack<POINT> bucket[5];
POINT m[20];

inline POINT point(int r, int c) {
 POINT p;
 p.r = r, p.c = c;
 return p;
}

inline bool inside(int r, int c) {
 if(r < 0 || c < 0 || r >= R || c >= C)
  return false;
 else
  return true;
}

int main()
{
 cin >> R >> C;
 frr(r, R) {
  string s;
  cin >> s;
  frr(c, C)
   a[r][c] = s[c];
 }

 frr(r, R) frr(c, C) {
  if(a[r][c] != '.')
   continue;

  frr(i, 4) {
   int move(r, c, rr, cc, i);
   if(!inside(rr, cc))
    continue;
   if(a[rr][cc] == '.')
    deg[r][c]++;
  }

  if(deg[r][c] == 0) {
   cout << -1 << endl;
   return 0;
  }
  bucket[deg[r][c]].push(point(r, c));
 }

 while(true) {
  POINT p;
  bool found = false;
  frr(i, 5) {
   while(!bucket[i].empty()) {
    p = bucket[i].top();
    bucket[i].pop();
    if(a[p.r][p.c] == '.') {
     found = true;
     break;
    }
   }

   if(found)
    break;
  }

  if(!found) break;

  POINT n;
  frr(i, 4) {
   int move(p.r, p.c, rr, cc, i);
   if(!inside(rr, cc)) continue;
   if(a[rr][cc] != '.') continue;
   deg[rr][cc]--;
   n = point(rr, cc);
  }
  m[0] = p;
  m[1] = n;
  int M = 2;
  frr(i, 4) {
   int move(n.r, n.c, rr, cc, i);
   if(!inside(rr, cc)) continue;
   if(a[rr][cc] != '.') continue;
   deg[rr][cc]--;
   if(deg[rr][cc] == 0) {
    m[M].r = rr, m[M].c = cc;
    M++;
   }
  }

  int c = 0;
  frr(i, M) {
   c |= col[m[i].r][m[i].c];
  }
  int color = 0;
  frr(i, 10) {
   if((c & (1 << i)) == 0) {
    color = i;
    break;
   }
  }
  frr(i, M) {
   p = m[i];
   a[p.r][p.c] = '0' + color;
   frr(j, 4) {
    int move(p.r, p.c, rr, cc, j);
    if(!inside(rr, cc)) continue;
    if(a[rr][cc] != '.') continue;
    col[rr][cc] |= (1 << color);
    bucket[deg[rr][cc]].push(point(rr, cc));
   }
  }
 }

 frr(r, R) {
  frr(c, C)
   cout << a[r][c];
  cout << endl;
 }

	return 0;
}
