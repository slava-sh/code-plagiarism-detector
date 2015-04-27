//148C Hewr
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <map>
using namespace std;
#define fo(i,a,b) for (int i = a; i <= b; ++i)
#define fd(i,a,b) for (int i = a; i >= b; --i)
#define fe(i,x) for (int i = g[x], y = E[i].y; i; i = E[i].l, y = E[i].y)
#define forall(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define pb push_back
#define SIZE(x) ((int) (x).size())
#define MP make_pair
#define fi first
#define se second
#define UNIQUE(x) x.resize(unique(x.begin(), x.end()) - x.begin())
#define clr(a,x) memset(&a, x, sizeof(a))
#define move(a,b) memcpy(&b, &a, sizeof(a))
#define Plus(a,b) (((LL) (a) + (b)) % mo)
#define Minus(a,b) ((((LL) (a) - (b) ) % mo + mo) % mo)
#define Mul(a,b) ((LL) (a) * (b) % mo)
#define updmin(a,b) (a = min(a, b))
#define updmax(a,b) (a = max(a, b))
#define sqr(x) ((x) * (x))

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

const double eps = 1e-10;
const int oo = ~0u >> 2, mo = (int) 1e9 + 7;
const int mn = 110000;

map<int, int> Q;

struct Heap{
    int m;
    PII d[mn];
    void init(){ m = 0; }
    void up(int x){
        while (x > 1 && d[x] > d[x >> 1]) swap(d[x], d[x >> 1]), x >>= 1;
    }
    void down(int x){
        while (x + x <= m){
            int y = x + x;
            if (y < m && d[y + 1] > d[y]) ++y;
            if (d[x] > d[y]) return;
            swap(d[x], d[y]), x = y;
        }
    }
    void ins(int x, int y){
        d[++m] = MP(x, y);
        up(m);
    }
    PII get(){
        PII ret = d[1];
        swap(d[1], d[m--]);
        down(1);
        return ret;
    }
} hp;

int a[mn];
int n;
struct rec{
    int a, b, c;
    rec(){}
    rec(int _a, int _b, int _c){ a = _a, b = _b, c = _c; }
};
vector<rec> Ans;

int main(){
    scanf("%d", &n);
    fo (i, 1, n){
        scanf("%d", a + i);
        ++Q[a[i]];
    }
    hp.init();
    fo (i, 1, n) if (Q[a[i]] != -1)
        hp.ins(Q[a[i]], a[i]), Q[a[i]] = -1;
    while (hp.m >= 3){
        PII l, m, r;
        l = hp.get(), m = hp.get(), r = hp.get();
        VI Q;
        Q.pb(l.se), Q.pb(m.se), Q.pb(r.se);
        sort(Q.begin(), Q.end());
        Ans.pb(rec(Q[2], Q[1], Q[0]));
        if (--l.fi) hp.ins(l.fi, l.se);
        if (--m.fi) hp.ins(m.fi, m.se);
        if (--r.fi) hp.ins(r.fi, r.se);
    }
    printf("%d\n", SIZE(Ans));
    fo (i, 0, SIZE(Ans) - 1) 
        printf("%d %d %d\n", Ans[i].a, Ans[i].b, Ans[i].c);
}
