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


vector<pll> ps [MXN];

int ord [MXN];

ll vecMul( pll a, pll b ){
    return a.fi*b.se - a.se*b.fi;
}


bool lessByLeftPoint( int a, int b ){
    if(ps[a][0].se != ps[b][0].se)
        return ps[a][0].se < ps[b][0].se;
    int pa = 0, pb = 0;
    int sza = ps[a].size();
    int szb = ps[b].size();
    while(pa<sza && pb<szb){
        pll a1 = mp( ps[a][pa+1].fi - ps[a][pa].fi, ps[a][pa+1].se - ps[a][pa].se );
        pll b1 = mp( ps[b][pb+1].fi - ps[b][pb].fi, ps[b][pb+1].se - ps[b][pb].se );

        ll t = vecMul(a1,b1);
        if(t!=0){
            if(t>0) return true;
            else return false;
        }
        if(ps[a][pa+1].fi < ps[b][pb+1].fi) pa++;
        else if(ps[a][pa+1].fi > ps[b][pb+1].fi) pb++;
        else pa++, pb++;
    }

    return false;
}


bool segInter( pll a, pll b, pll c, pll d ){
    pll ca = mp( c.fi - a.fi, c.se - a.se );
    pll cb = mp( c.fi - b.fi, c.se - b.se );
    pll cd = mp( c.fi - d.fi, c.se - d.se );

    ll q1 = vecMul(cd,ca);
    if(q1>0) q1 = 1;
    else if(q1<0) q1 = -1;

    ll q2 = vecMul(cd,cb);
    if(q2>0) q2 = 1;
    else if(q2<0) q2 = -1;

    return q1*q2<0;
}

bool linkInter( int a, int b ){
    int pa = 0, pb = 0;
    int sza = ps[a].size();
    int szb = ps[b].size();

    while(pa+1<sza && pb+1<szb){
        if(segInter(ps[a][pa], ps[a][pa+1], ps[b][pb], ps[b][pb+1])){
            return true;
        }
        if(ps[a][pa+1].fi < ps[b][pb+1].fi) pa++;
        else pb++;
    }
    return false;
}

int main()
{
//    freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

    int A,B;
    scanf("%d%d", &A, &B);
    int n;
    scanf("%d", &n);
    rep(i,n){
        int l;
        scanf("%d", &l);
        rep(j,l+1){
            int x,y;
            scanf("%d%d", &x, &y);
            ps[i].pb( mp(x,y) );
        }
        ord[i] = i;
    }

    sort(ord,ord+n, lessByLeftPoint);


    bool ok = true;

    int q1 = 0, q2 = 0;

    rep(i,n-1){
        if( linkInter( ord[i], ord[i+1]) ){
            ok = false;
            q1 = ord[i];
            q2 = ord[i+1];
            break;
        }
    }

    if(ok){
        printf("Yes\n");
    }
    else{
        printf("No\n");
        printf("%d %d\n", q1+1, q2+1);
    }

    return 0;
}
