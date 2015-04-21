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

int dd [MXN];
vector<pii> ed [MXN];
pii edb [MXN];

int isin [MXN];

int d;


struct mv{
    int v,vd,t;
    mv(){}
    mv(int v, int vd, int t):v(v),vd(vd),t(t){}
};

bool nice ( ll tp, ll t ){
    if( tp - d <= t && t <= tp + d ) return true;
    else return false;
}

vector<bool> used [MXN];

void bfs( int ss, int tt ){
    rep(i,MXN){
        dd[i] = inf;
        edb[i].fi = -1;
        isin[i] = 0;
    }
    dd[ss] = 0;

    queue<mv> cur;
    rep(i,ed[ss].size())
        cur.push( mv(ss,0,ed[ss][i].se) );


    while(!cur.empty()){
        int v = cur.front().v;
        int vd = cur.front().vd;
        int tp = cur.front().t;

        cur.pop();
        if(v==tt) break;

        int sz = ed[v].size();


        /*if(edb[v].fi==-1){
            edb[v].fi = 0;
            while( edb[v].fi<sz-1 && !nice(tp, ed[v][ edb[v].fi ].se) ) edb[v].fi++;
            edb[v].se = edb[v].fi;
        }*/
        rep(q,sz){
            if(used[v][q]) continue;
            if( nice(tp, ed[v][q].se) ){
                used[v][q] = true;
                int to = ed[v][q].fi;
                dd[to] = min(dd[to], vd+1);
                cur.push( mv(to,vd+1,ed[v][q].se) );
            }
        }
    }
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
        ed[a].pb( mp(b,c) );
        if(a!=b){
            ed[b].pb( mp(a,c) );
        }
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
        rep(j,n){
            used[j].assign(ed[j].size(), false);
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
