#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) ((int)strlen(X))
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#else
#define FILEIO(name)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

int n,m;
ll mod;
ll d[510][510];
ll s[510][510];
char in[510][510];
int a[510];

int main()
{
    MS0(a);
    RII(n,m);
    cin>>mod;
    REP(i,0,m){
        RS(in[i]);
        REP(j,0,n){
            if(in[i][j]=='1')a[j]++;
        }
    }
    int A=0,B=0;
    REP(i,0,n){
        if(a[i]==0)A++;
        else if(a[i]==1)B++;
    }
    MS0(d);
    d[A][B]++;
    s[A][B]++;
    queue<ii> Q;
    Q.push(ii(A,B));
    while(!Q.empty()){
        ii x=Q.front();Q.pop();
        //cout<<x.F<<' '<<x.S<<' '<<d[x.F][x.S]<<endl;
        if(x.F==0&&x.S==0)continue;
        ll M=(d[x.F][x.S])%mod;
        if(x.F>=2){
            d[x.F-2][x.S+2]+=x.F*(x.F-1)/2*M;
            d[x.F-2][x.S+2]%=mod;
            if(s[x.F-2][x.S+2]==0)Q.push(ii(x.F-2,x.S+2));
            s[x.F-2][x.S+2]++;
        }
        if(x.F>=1&&x.S>=1){
            d[x.F-1][x.S]+=x.F*x.S*M;
            d[x.F-1][x.S]%=mod;
            if(s[x.F-1][x.S]==0)Q.push(ii(x.F-1,x.S));
            s[x.F-1][x.S]++;
        }
        if(x.S>=2){
            d[x.F][x.S-2]+=x.S*(x.S-1)/2*M;
            d[x.F][x.S-2]%=mod;
            if(s[x.F][x.S-2]==0)Q.push(ii(x.F,x.S-2));
            s[x.F][x.S-2]++;
        }
        s[x.F][x.S]=0;
    }
    cout<<d[0][0]<<endl;
    return 0;
}
