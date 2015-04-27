#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

#define eps (1e-7)
const double Pi = 2*acos(0.0);
int n;
int d[100000];
set<pi> S;

struct T {
   int a, b, c;
};

void solution()
{
   scanf("%d", &n);
   rep(i, n)
      scanf("%d", d+i);
   sort(d, d+n);
   rep(i, n) {
      int j = i;
      while (j+1 < n && d[j+1] == d[i])
         j++;
      int cnt = j-i+1;
      S.insert(mp(cnt, d[i]));
      i = j;
   }
   vector<T> ret;
   set<pi>::iterator it1, it2, it3;
   vi V(3);
   while (l(S) >= 3) {
      it1 = --S.end();
      it2 = --(--S.end());
      it3 = --(--(--S.end()));
      V[0] = it1->y;
      V[1] = it2->y;
      V[2] = it3->y;
      pi A = *it1, B = *it2, C = *it3;
      S.erase(it1);
      S.erase(it2);
      S.erase(it3);
      if (--A.x > 0) S.insert(A);
      if (--B.x > 0) S.insert(B);
      if (--C.x > 0) S.insert(C);
      sort(V.begin(), V.begin()+3);
      T cur;
      cur.c = V[0];
      cur.b = V[1];
      cur.a = V[2];
      ret.pb(cur);
   }
   printf("%d\n", l(ret));
   rep(i, l(ret))
      printf("%d %d %d\n", ret[i].a, ret[i].b, ret[i].c);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("my.in", "rt", stdin);
   //freopen("my.out", "wt", stdout);
#endif
   solution();
#ifndef ONLINE_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}

