#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

int v[105];
char t[105];
int type[105];
ld lb[105];
ld rb[105];
const ld eps = 1e-7;
int main()
{
   ld h1, h2;
   int n;
   cin >> h1 >> h2 >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> v[i] >> t[i] >> lb[i] >> rb[i];
      if (t[i] == 'F') type[i] = 0;
      else type[i] = 1;
   }
   int maxpt = 0;
   for (int p = 0; p < 2; p++) 
     for (int k = 0; k <= n; k++)
     {
         ld h1_ = (p&1?100.-h1:h1);
         ld h2_ = ((k+p)&1?100.-h2:h2);
      //   cout << "p = " << p << " k = " << k << endl;
      //   cout << "h1_ = " << h1_ << " h2_ = " << h2_ << endl;
         ld c = 1e5 / ((ld)k + h1_ / 1e2 + h2_ / 1e2);
         ld a = c * h1_ / 1e2;
         ld b = c * h2_ / 1e2;
         
         assert(fabs(c*(ld)k + a + b - 1e5) < 1e-8);
       //  cout << "a = " << a << " b = " << b << " c = " << c << endl;
         ld cur = a;
         int curh = p;
         vector<bool> used(n, 0);
         int pt = 0;
         bool corr = 1;
         for (int i = 0; i <= k; i++)
         {
             bool ok = 0;
             for (int j = 0; j < n; j++)
                 if (curh == type[j] && lb[j] - eps < cur && cur < rb[j] + eps && !used[j])
                 {
                    used[j] = 1;
                 //   cout << "got " << j << endl;
                    pt += v[j];
                    ok = 1;
                    break;
                 }

             if (!ok) {corr = 0; break;}
             cur += c;
             curh ^= 1; 
         }
      //   cout << "corr = " << corr << endl;
      //   cout << endl;
         if (corr) maxpt = max(maxpt, pt);
     }
   cout << maxpt << endl;
   return 0;
}