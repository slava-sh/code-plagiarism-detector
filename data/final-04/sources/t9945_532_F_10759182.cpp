// Author: Harhro94 [Harutyunyan Hrayr]
#pragma comment(linker, "/STACK:667777216")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
int rd();

const LL P = 373;
const int N = 200007;
int n, m, x[N], y[N], nxt[N];
char S[N], T[N];
LL pw[N];
vector<int> mn;
int to[26];

vector<int> work(vector<int> &ans) {
   vector<int> ret;
   for (int u : ans) {

      FOR(i, 26) {
         to[i] = -1;
      }

      bool ok = true;

      for (int pos : mn) {

         int i = S[u + pos] - 'a';
         int j = T[pos] - 'a';

         if (to[i] != -1 && to[j] == -1) {
            ok = false;
            break;
         }
         if (to[i] == -1 && to[j] != -1) {
            ok = false;
            break;
         }

         if (to[i] == -1) {
            to[i] = j;
            to[j] = i;
         }
         else {
            if (to[i] != j || to[j] != i) {
               ok = false;
               break;
            }
         }
      }
      if (ok) ret.pb(u + 1);
   }
   return ret;
}

void solve() {
   scanf("%d%d", &n, &m);
   scanf("%s%s", S, T);

   vector<int> fpos(26, -1);

   pw[0] = 1;
   FOR(i, N)
      if (i) pw[i] = P * pw[i - 1];

   FOR(i, m) {
      int c = T[i] - 'a';
      if (fpos[c] == -1) {
         x[i] = 0;
         mn.pb(i);
      }
      else x[i] = i - fpos[c];
      fpos[c] = i;
   }

   //FOR(i, m) cerr << x[i] << " "; cerr << endl;

   LL target = 0;
   FOR(i, m) target += pw[i] * (x[i] + 2);

   vector<int> ans;

   FOR(i, 26) fpos[i] = -1;
   FOR(i, m) {
      int c = S[i] - 'a';
      if (fpos[c] == -1) {
         y[i] = 0;
      }
      else {
         y[i] = i - fpos[c];
         nxt[fpos[c]] = i;
      }
      fpos[c] = i;
   }

   LL cur = 0;
   FOR(i, m) cur += pw[i] * (y[i] + 2);

   if (cur == target) ans.pb(0);

   for (int start = 1; start < n - m + 1; ++start) {
      int c = S[start - 1] - 'a';
      int newc = S[m + start - 1] - 'a';

      if (fpos[newc] == -1) {
         y[m + start - 1] = 0;
      }
      else {
         y[m + start - 1] = m + start - 1 - fpos[newc];
         nxt[fpos[newc]] = m + start - 1;
         if (y[m + start - 1] >= m) y[m + start - 1] = 0;
      }

      cur -= (y[start - 1] + 2) * pw[start - 1];
      cur += (y[m + start - 1] + 2) * pw[m + start - 1];

      int id = nxt[start - 1];
      if (id == 0 || id >= start + m - 1) {
         // nothing
      }
      else {
         cur -= (y[id] + 2) * pw[id];
         y[id] = 0;
         cur += (y[id] + 2) * pw[id];
      }

      if (pw[start] * target == cur) ans.pb(start);

      fpos[newc] = m + start - 1;
   }

   ans = work(ans);

   printf("%d\n", sz(ans));
   for (int u : ans) printf("%d ", u);
   puts("");
}

int rd() {
   return (((LL)rand() << 16) ^ rand()) % 1000000000;
}

void testGen() {
   FILE *f = fopen("input.txt", "w");
   fclose(f);
}

int main() {
#ifdef harhro94
   //testGen();
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#else
#define task "ghosts"
   //freopen(task".in", "r", stdin);
   //freopen(task".out", "w", stdout);
#endif

   cerr << fixed;
   cerr.precision(9);

   solve();

#ifdef harhro94
   cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
   return 0;
}