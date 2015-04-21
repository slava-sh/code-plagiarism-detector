#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define repe(i,n) for( i = 0; i < (n); i++ )
#define rep(i,n) forn(i,0,n)
#define fi first
#define se second

const int MXN = 100100;
const int MXK = 11;
const int inf = 1e9;
const ll linf = 1e18;

//int dp [MXN][MXN];

struct edge{
    int to, tp;
    edge *rv, *nxt, *prv;
    edge(){
        rv = nxt = prv = 0;
    }
    edge( int to, int tp):to(to),tp(tp){
        rv = nxt = prv = 0;
    }
};

int dd [MXN];
edge* ed [MXN];
edge* lst [MXN];
pii edb [MXN];

int isin [MXN];

int d;


struct mv{
    int v,vd;
    edge *ed;
    mv(){}
    mv(int v, int vd, edge *ed):v(v),vd(vd),ed(ed){}
};

bool nice ( ll tp, ll t ){
    if( tp - d <= t && t <= tp + d ) return true;
    else return false;
}

vector<bool> used [MXN];

void del( edge *s ){
    if(s->nxt){
        s->nxt->prv = s->prv;
    }
    if(s->prv){
        s->prv->nxt = s->nxt;
    }
    s->nxt = 0;
    s->prv = 0;
}

void bfs( int ss, int tt ){
    rep(i,MXN){
        dd[i] = inf;
    }
    dd[ss] = 0;

    queue<mv> cur;
    edge *q = ed[ss];
    while(q){
        cur.push( mv(ss,0,q));
        q = q->nxt;
    }


    while(!cur.empty()){
        int v = cur.front().v;
        int vd = cur.front().vd;
        edge *ved = cur.front().ed;

        cur.pop();
        if(v==tt) break;



        /*if(edb[v].fi==-1){
            edb[v].fi = 0;
            while( edb[v].fi<sz-1 && !nice(tp, ed[v][ edb[v].fi ].se) ) edb[v].fi++;
            edb[v].se = edb[v].fi;
        }*/
        edge *q = ved;
        edge *sss = ved->prv;
        while(q){
            if( nice(tp, q->tp) ){
                edge *abc = q->nxt;
                del(q);
                q = abc;
                int to = q->to;
                dd[to] = min(dd[to], vd+1);
                cur.push( mv(to,vd+1,q->rv) );
            }
            else break;
        }
        q = sss;
        while(q){
            if( nice(tp, q->tp) ){
                edge *abc = q->prv;
                del(q);
                q = abc;
                int to = q->to;
                dd[to] = min(dd[to], vd+1);
                cur.push( mv(to,vd+1,q->rv) );
            }
            else break;
        }
    }
}

void adde( int a, int b ){
    edge *tob = new edge(b,c);
    edge *toa = new edge(a,c);

    tob->rv = toa;
    toa->rv = tob;

    if(lst[a]){
        tob->prv = lst[a];
        lst[a]->nxt = tob;
    }
    if(lst[b]){
        toa->prv = lst[b];
        lst[b]->nxt = toa;
    }

    lst[a] = tob;
    lst[b] = toa;
    if(!ed[a]) ed[a] = tob;
    if(!ed[b]) ed[b] = toa;
}


int main()
{
//    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int n,m;
    scanf("%d%d%d", &n, &m, &d);
    rep(i,m){
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adde(a,b);
    }

    /*rep(i,n){
        printf("%d : ", i);
        int sz = ed[i].size();
        rep(j,sz) printf("%d ", ed[i][j].fi);
        printf("\n");
    }*/
    int q;
    scanf("%d", &q);
    rep(i,q){
        rep(i,n){
            ed[i] = lst[i] = 0;
        }
        int a,b;
        scanf("%d%d", &a, &b);
        a--, b--;
        bfs(a,b);
        if(dd[b]<inf)
            printf("%d", dd[b]);
        else printf("-1");
        printf("\n");
    }

    return 0;
}
