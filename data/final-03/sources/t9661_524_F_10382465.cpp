/* --- author: enot-the-rockstar ---*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

static inline unsigned long long rdtsc() { unsigned long long d; __asm__ __volatile__ ("rdtsc" : "=A" (d) ); return d; }

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const dbl eps = 1e-9;

/* --- main part --- */

#define TASK "a"

const int maxn = (int)2e6 + 10;
const int N = 1 << 21;

struct tree
{
    int t[2 * N];
    
    tree()
    {
        memset(t, 0, sizeof t);
    }

    void clear()
    {
        memset(t, 0, sizeof t);
    }

    inline int get(int l, int r)
    {
        l += N;
        r += N;
        int res = inf;
        while (l <= r)
        {
            if ((l & 1) == 1) res = min(res, t[l]);
            if ((r & 1) == 0) res = min(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    inline void upd(int x, int val)
    {
        x += N;
        t[x] = val;
        while (x > 1)
        {
            x >>= 1;
            t[x] = min(t[2 * x], t[2 * x + 1]);
        }
    }    
};



int ar[maxn * 2 + 1];

const int ci = 3;
int cnt[ci];

int tmp[6][maxn];
int *head = tmp[0];
int *next = tmp[1];
int *col = tmp[2], *coln = tmp[3];
int *pos = tmp[4], *posn = tmp[5];
         
int MOD;
inline int mmod(int x) {
    return x >= MOD ? x - MOD : x;
}

void getp(int n, int *s, int *p) {
  // n = 2 * len + 1
  // s = qq0 q_i = 1 or 2
  // p = res!

  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++)
    cnt[s[i]]++;
  
  head[0] = 0;
  for (int i = 1; i < ci; i++) {
    head[i] = head[i - 1] + cnt[i - 1];
  }

  for (int i = 0; i < n; i++) {
    pos[head[s[i]]++] = i;
    col[i] = s[i];
  }
  
  head[0] = 0;
  for (int i = 1; i < ci; i++) {
    head[i] = head[i - 1] + cnt[i - 1];
  }

  MOD = n;
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i++) {
      int in = pos[i] - len;
      if (in < 0)
        in += n;
      posn[head[col[in]]++] = in;
    }
    head[0] = 0;
    coln[posn[0]] = 0;
    for (int i = 1; i < n; i++) {
      coln[posn[i]] = coln[posn[i - 1]];
      if (col[posn[i]] != col[posn[i - 1]] || col[mmod(posn[i] + len)] != col[mmod(posn[i - 1] + len)]) {
        head[++coln[posn[i]]] = i;
      }
    }

    swap(col, coln);
    swap(pos, posn);
    if (col[pos[n - 1]] == n - 1) {
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i] = pos[i];
  }
}

char s[maxn];


/*bool solve() {
  if (scanf("%s", s) < 1) {
    return 0;
  }
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    ar[i] = ar[i + n] = 1 + (s[i] == ')');
  }
  ar[2 * n] = 0;
  int len = 2 * n + 1;
  getp(len, ar, p);
  for (int i = 0; i < len; ++i) {
    eprintf("%d%c", p[i], " \n"[i == len - 1]);
  }
  return 1;
} */

int p[maxn];
tree T;

char res[maxn];
int resc = 0;

int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%s", s);
    int n = strlen(s);
    forn(i, n) s[i + n] = s[i];
    int bal = 0;
    forn(i, 2 * n)
    {
        T.upd(i, bal);
        if (s[i] == '(') bal += 1;
        else bal -= 1;
    }
    T.upd(2 * n, bal);
    bal /= 2;

    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif

    for (int i = 0; i < n; ++i) {
      ar[i] = 1 + (s[i] == ')');
    }
    getp(n, ar, p);

    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    
    
    forn(i, n)
    {
        int x = p[i];
        if (x >= n) continue;
        int mn = T.get(x, x + n) - T.get(x, x);
        if (bal >= 0 && mn >= 0)
        {   
            for (int j = x; j < x + n; ++j) res[resc++] = s[j];
            forn(j, bal) res[resc++] = ')';
            break;
        }        
        if (bal < 0 && mn - bal >= 0)
        {
            forn(j, -bal) res[resc++] = '(';
            for (int j = x; j < x + n; ++j) res[resc++] = s[j];
            break;
        }
    }
    printf("%s\n", res);    
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 