#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9+9;
const double eps = 1e-9;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

int n, m;

char type[100005];

int num[100005];

int cnt[100005];

int in[100005], out[100005];

int bal[100005];

int res[100005], sz;

bool skip[100005];

int main(void){
  #ifdef nobik
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  scanf("%d %d", &n, &m);
  bool opened = false, closed = true;
  int start = 1;
  for(int i = 1; i <= m; ++i){
    scanf(" %c %d", type + i, num + i); --num[i];
    if(type[i] == '+'){
      if(!in[num[i]]) in[num[i]] = i;
    } else {
      if(!in[num[i]]) opened = true, start = i;
      out[num[i]] = i;
    }
  }
  int cur = 0;
  for(int i = 1; i <= m; ++i){
    if(type[i] == '+'){
      ++bal[num[i]];
      ++cur;
    } else {
      if(bal[num[i]]) --cur;
      --bal[num[i]];
      bal[num[i]] = max(bal[num[i]], 0);
    }
    if(i >= start && !cur && num[i] == num[i + 1] && type[i] == '-' && type[i + 1] == '+'){
      skip[i] = true;
      skip[i + 1] = true;
    }
  }
  forn(i, n) if(bal[i]) closed = false;
  memset(in, 0, sizeof in);
  memset(out, 0, sizeof out);
  for(int i = 1; i <= m; ++i){
    if(skip[i]) continue;
    ++cnt[num[i]];
    if(type[i] == '+'){
      if(!in[num[i]]) in[num[i]] = i;
    } else {
      out[num[i]] = i;
    }
  }
  forn(i, n){
    int ok = 0;
    if(cnt[i] > 2) continue;
    if(!in[i] || (in[i] == 1 && !opened)) ++ok;
    if(!out[i] || (out[i] == m && closed)) ++ok;
    if(ok == 2) res[sz++] = i + 1;
  }
  printf("%d\n", sz);
  forn(i, sz){
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}

