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

bool used[1000005];

int res[1000005], sz;

int e[1000005], r;

struct treap {
    typedef struct _node {
        int x, y, val, w;
        _node *l, *r;
        _node () {l = r = 0; y = random; w = 0;}
        _node (int val): val(val) {y = random; x = 1; l = r = 0; w = 0;}
        int get(_node *t) {
            if(!t) return 0;
            return t->x;
        }
        void recalc() {
            if(this) this->x = get(this->l) + get(this->r) + 1;
        }
    } *node;
    node root;
    treap() {root = 0;}
    node merge(node &l, node &r) {
        node t = 0;
        if(!l || !r) t = l ? l : r; else
        if(l->y > r->y) l->r = merge(l->r,r), t = l; else
        r->l = merge(l,r->l), t = r;
        t->recalc();
        return t;
    }
    void split(node t, int x, node &l, node &r, int add = 0) {
        if(!t) return void(l = r = 0);
        ll cur = add + t->l->get(t->l);
        if(x <= cur) split(t->l,x,l,t->l,add), r = t; else
        split(t->r,x,t->r,r,cur+1), l = t;
        t->recalc(); l->recalc(); r->recalc();
    }
    void print(node t) {
        if(!t) return;
        print(t->l);
        res[t->val] = t->w;
       // cout << t->val << " ";
        print(t->r);
    }
    void Add(int val, int w) {
        node buf = new _node(val), l, r;
        buf->w = w;
        split(root,val-1,l,r);
        root = merge(l,buf);
        root = merge(root,r);
        root->recalc();
    }
    void now(int x, int y, int cur, bool ok) {
        node l, m, r;
        l = r = m = 0;
        split(root,x-1,l,r);
        split(r,y-x+1,m,r);
        int now = m->w;
        if(ok){
          if(used[cur] && now != cur){
            puts("-1");
            exit(0);
          }
          if(now != 0 && now != cur){
            puts("-1");
            exit(0);
          }
          used[cur] = true;
          m->w = cur;
        }
        l = merge(m,l);
        root = merge(l,r);
        root->recalc();
    }
};

int n, m;

int x[1000005], y[1000005];

int main(void){
  #ifdef nobik
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  #endif
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  treap t;
  for(int i = 1; i <= n; ++i) t.Add(i, 0);
  forn(i, m){
   // cout << i << endl;
    scanf("%d %d", x + i, y + i);
    t.now(y[i], y[i], x[i], true);
  }
  t.print(t.root); // cout << endl;
  for(int i = 1; i <= n; ++i) if(!used[i]) e[r++] = i;
  r = 0;
  for(int i = 1; i <= n; ++i){
    if(res[i] == 0) res[i] = e[r++];
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}

