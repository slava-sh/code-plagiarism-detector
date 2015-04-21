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
ll mnt [2][MXN];
ll mxt [2][MXN];
vector<pii> ed [MXN];
pii edb [MXN];

int isin [MXN];

int d;


bool nice ( ll a, ll b, ll t ){
    if( a - d <= t && t <= b+d ) return true;
    else return false;
}

void bfs( int ss, int tt ){
    rep(i,MXN){
        dd[i] = inf;
        mnt[0][i] = mnt[1][i] = inf;
        mxt[0][i] = mxt[1][i] = -inf;
        edb[i].fi = -1;
        isin[i] = 0;
    }
    dd[ss] = 0;
    mnt[0][ss] = -inf;
    mxt[0][ss] = inf;

    queue<pii> cur;
    cur.push( mp(ss,0) );

    int frr = 0;
    int CD = 0;

    while(!cur.empty()){
        int v = cur.front().fi;
        int vd = cur.front().se;
        if(vd==CD+1){
            CD++;
            frr ^= 1;
        }

        cur.pop();
        if(v==tt) break;

        int sz = ed[v].size();

        ll mntv = mnt[frr][v];
        ll mxtv = mxt[frr][v];

        if(edb[v].fi==-1){
            edb[v].fi = 0;
            while( edb[v].fi<sz-1 && !nice(mntv, mxtv, ed[v][ edb[v].fi ].se) ) edb[v].fi++;
            edb[v].se = edb[v].fi;
        }
        while(edb[v].fi>0){
            int q = edb[v].fi-1;
            if( nice(mntv, mxtv, ed[v][q].se) ){
                edb[v].fi--;
                int to = ed[v][q].fi;
                if(mnt[ (frr^1) ][to] > ed[v][q].se || mxt[ (frr^1) ][to] < ed[v][q].se){
                    mnt[ (frr^1) ][to] = min(mnt[ (frr^1) ][to], ed[v][q].se);
                    mxt[ (frr^1) ][to] = max(mxt[ (frr^1) ][to], ed[v][q].se);
                    dd[to] = min(dd[to], vd+1);
                    if(isin[to] < vd+1){
                        cur.push( mp(to,vd+1) );
                        isin[to] = vd+1;
                    }
                }
            }
            else break;
        }
        while(edb[v].se<sz){
            int q = edb[v].se;
            if( nice(mntv, mxtv, ed[v][q].se) ){
                edb[v].se++;
                int to = ed[v][q].fi;
                if(mnt[ (frr^1) ][to] > ed[v][q].se || mxt[ (frr^1) ][to] < ed[v][q].se){
                    mnt[ (frr^1) ][to] = min(mnt[ (frr^1) ][to], ed[v][q].se);
                    mxt[ (frr^1) ][to] = max(mxt[ (frr^1) ][to], ed[v][q].se);
                    dd[to] = min(dd[to], vd+1);
                    if(isin[to] < vd+1){
                        cur.push( mp(to,vd+1) );
                        isin[to] = vd+1;
                    }
                }
            }
            else break;
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
